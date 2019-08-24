#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 20005
#define MAXM 200005
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

clock_t t_bg, t_ed;
int N, M;
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot;
int l(0), r(1e9), mid, ans;
int c[MAXN];

inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}

bool DFS( int u ){
	go( i, hd[u] )if ( val[i] > mid ){
		if ( !c[v] ){
			c[v] = 3 - c[u];
			if ( !DFS(v) ) return 0;
		} else if ( c[v] + c[u] != 3 ) return 0;
	} return 1;
}

bool check(){
	memset( c, 0, sizeof c );
	fp( i, 1, N ){
		if ( !c[i] ){
			c[i] = 1;
			if ( !DFS(i) ) return 0;
		}
	}
	return 1;
}

int main(){
	t_bg = clock();
	read(N), read(M); int x, y, z;
	fp( i, 1, M ) read(x), read(y), read(z), addedge( x, y, z ), addedge( y, x, z );
	while( l <= r ){
		mid = ( l + r ) >> 1;
		if ( check() ) r = mid - 1, ans = mid;
		else l = mid + 1;
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

