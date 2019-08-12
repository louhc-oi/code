#include<bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
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

int N, M, S, T, a[105], w[105][105], w1[1005], ct;
int hd[11005], HD[11005], nxt[70007], to[70007], val[70007], tot(1);
void addedge( int x, int y, int z = INF ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0;
}

queue<int> Q; int d[11005];
bool BFS(){
	while( !Q.empty() ) Q.pop();
	memset( d, 0, sizeof d ), Q.push(S), d[S] = 1;
	while( !Q.empty() ){
		int u(Q.front()); Q.pop();
		go( i, hd[u] ) if ( !d[v] && val[i] ){
			d[v] = d[u] + 1, Q.push(v);
			if ( v == T ) return 1;
		}
	} return 0;
}
int DFS( int u, int fl ){
	if ( u == T ) return fl;
	int r(fl), k;
	for ( int &i = HD[u], v; i && r; i = nxt[i] ) if ( val[i] && d[v = to[i]] == d[u] + 1 ){
		k = DFS( v, min( r, val[i] ) );
		if ( !k ) d[v] = 0;
		r -= k, val[i] -= k, val[i ^ 1] += k;
	} return fl - r;
}

int main(){
	t_bg = clock();
	read(N), read(M), S = 0, T = ct = 1; int x, ans(0);
	fp( i, 1, N ) fp( j, i, N ) w[i][j] = ++ct;
	fp( i, 1, N ){
		read(a[i]); if( !w1[a[i]] ) w1[a[i]] = ++ct, addedge( ct, T, M * a[i] * a[i] );
		addedge( w[i][i], w1[a[i]] );
	}
	fp( i, 1, N ) fp( j, i, N ){
		read(x); if ( i == j ) x -= a[i];
		if ( x >= 0 ) addedge( S, w[i][j], x ), ans += x; else addedge( w[i][j], T, -x );
		if ( i < j ) addedge( w[i][j], w[i][j - 1] ), addedge( w[i][j], w[i + 1][j] );
	}
	while( BFS() ){
		memcpy( HD, hd, sizeof hd );
		while( ( x = DFS( S, INT_MAX ) ) ) ans -= x;
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
