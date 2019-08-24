#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 100005
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

int N, M, hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
} int dep[MAXN], f[MAXN][20];
int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) x^=y^=x^=y;
	fd( i, 18, 0 ) if ( dep[f[x][i]] > dep[y] ) x = f[x][i];
	if ( dep[x] > dep[y] ) x = f[x][0];
	fd( i, 18, 0 ) if ( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}
void DFS( int u ){
	dep[u] = dep[f[u][0]] + 1;
	fp( i, 1, 18 ) f[u][i] = f[f[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != f[u][0] )
		f[v][0] = u, DFS(v);
} int s[MAXN], ans;
void dfs( int u ){
	go( i, hd[u] ) if ( v != f[u][0] )
		dfs(v), s[u] += s[v];
	if ( u > 1 && s[u] == 1 ) ++ans;
	else if ( u > 1 && !s[u] ) ans += M;
}

int main(){
	t_bg = clock();
	read(N), read(M); int x, y;
	fp( i, 1, N - 1 ) read(x), read(y), addedge( x, y );
	DFS(1); fp( i, 1, M ) read(x), read(y), ++s[x], ++s[y], s[LCA(x, y)] -= 2;
	dfs(1), printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

