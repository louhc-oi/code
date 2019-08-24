#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 500005
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int N, S, pre[MAXN], e, mxd;
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], val[MAXN<<1], tot(1);
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
} void DFS( int u, int d ){
	if ( d > mxd ) e = u, mxd = d;
	go( i, hd[u] ) if ( i != pre[u] )
		pre[v] = i ^ 1, DFS(v, d + val[i]);
} bool bl[MAXN]; int s[MAXN], n;
void Find( int u, int fa, int d = 2333 ){
	if ( bl[u] ) d = 0;
	cmax( mxd, d );
	go( i, hd[u] ) if ( v != fa ) Find(v, u, d + val[i]);
}

int main(){
	read(N), read(S); int x, y, z, cur(0), sl(0), sr(0), l, r;
	fp( i, 1, N - 1 ) read(x), read(y), read(z), addedge(x, y, z);
	DFS(1, 0), mxd = 0, pre[e] = 0, DFS(e, 0);
	for ( x = e; pre[x]; x = to[pre[x]] ) bl[x] = 1, s[++n] = val[pre[x]];
	bl[x] = 1, mxd = 0, Find(e, 0); fp( i, 1, n ) cur += s[i];
	l = 1, r = n;
	while( l <= r && sl + s[l] <= mxd ) sl += s[l++];
	while( l <= r && sr + s[r] <= mxd ) sr += s[r--];
	while( l <= r && cur - sl - sr > S ){
		if ( sl + s[l] <= sr + s[r] ){
			sl += s[l++]; while( l <= r && sr + s[r] <= sl ) sr += s[r--];
		}else{
			sr += s[r--]; while( l <= r && sl + s[l] <= sr ) sl += s[l--];
		}
	} printf( "%d\n", max( max( sl, sr ), mxd ) );
	return 0;
}

