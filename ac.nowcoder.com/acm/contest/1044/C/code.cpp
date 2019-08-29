#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
const int MAXN = 2e5 + 5;
int T, N;
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], val[MAXN<<1], tot;
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
}
int f[MAXN], g[MAXN]; bool b[MAXN];
void DFS1( int u, int fa ){
	b[u] = 1, f[u] = 0;
	go( i, hd[u] ) if ( v != fa ){
		DFS1(v, u), b[u] = 0;
		f[u] += min( f[v], val[i] );
	} if ( b[u] ) f[u] = INT_MAX;
}
void DFS2( int u, int fa, int vl ){
	g[u] = b[u] ? 0 : f[u], g[u] += vl;
	go( i, hd[u] ) if ( v != fa ) DFS2(v, u, min(g[u] - min(val[i], f[v]), val[i]));
}

signed main(){
	t_bg = clock();
	read(T);
	while( T-- ){
		read(N); int x, y, z; memset( hd, 0, sizeof hd ), tot = 0;
		fp( i, 2, N ) read(x), read(y), read(z), addedge( x, y, z );
		DFS1(1, 0), DFS2(1, 0, 0); int ans(0);
		fp( i, 1, N ) cmax( ans, g[i] );
		printf( "%d\n", ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

