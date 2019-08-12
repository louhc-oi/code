#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 105
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

int N, M, NM, S, T, ct, x, ans;
int w[MAXN][MAXN];

int hd[MAXN*MAXN*3], HD[MAXN*MAXN*3], nxt[MAXN*MAXN*28], to[MAXN*MAXN*28], val[MAXN*MAXN*28], tot(1);
inline void addedge( int x, int y, int z = INF ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0;
}
queue<int> Q; int d[MAXN*MAXN*3];
bool BFS(){
	while( !Q.empty() ) Q.pop();
	memset( d, 0, sizeof d );
	d[S] = 1, Q.push(S);
	while( !Q.empty() ){
		int u(Q.front()); Q.pop();
		go( i, hd[u] ) if ( !d[v] && val[i] ){
			d[v] = d[u] + 1, Q.push(v);
			if ( v == T ) return 1;
		}
	} return 0;
}
int DFS( int x, int fl ){
	if ( x == T ) return fl;
	int r = fl, k;
	for ( int &i = HD[x], v; i && r; i = nxt[i] ) if ( val[i] && d[v = to[i]] == d[x] + 1 ){
		k = DFS( v, min( r, val[i] ) );
		if ( !k ) d[v] = 0;
		r -= k, val[i] -= k, val[i ^ 1] += k;
	} return fl - r;
}

int main(){
	t_bg = clock();
	read(N), read(M), T = ++ct;
	fp( i, 1, N ) fp( j, 1, M ) read(x), ans += x, addedge( S, w[i][j] = ++ct, x );
	fp( i, 1, N ) fp( j, 1, M ) read(x), ans += x, addedge( w[i][j], T, x );
	fp( i, 1, N ) fp( j, 1, M ){
		read(x), ans += x, addedge( S, ++ct, x ), addedge( ct, w[i][j] );
		if ( i > 1 ) addedge( ct, w[i - 1][j] );
		if ( i < N ) addedge( ct, w[i + 1][j] );
		if ( j > 1 ) addedge( ct, w[i][j - 1] );
		if ( j < M ) addedge( ct, w[i][j + 1] );
	}
	fp( i, 1, N ) fp( j, 1, M ){
		read(x), ans += x, addedge( ++ct, T, x ), addedge( w[i][j], ct );
		if ( i > 1 ) addedge( w[i - 1][j], ct );
		if ( i < N ) addedge( w[i + 1][j], ct );
		if ( j > 1 ) addedge( w[i][j - 1], ct );
		if ( j < M ) addedge( w[i][j + 1], ct );
	}
	while( BFS() ){
		memcpy( HD, hd, sizeof hd );
		while( (x = DFS(S, INF)) ) ans -= x;
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
