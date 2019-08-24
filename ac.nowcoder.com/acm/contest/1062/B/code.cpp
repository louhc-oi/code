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
const int MAXN = 105;
int N, M, mc[MAXN*MAXN];
int hd[MAXN*MAXN], nxt[MAXN*MAXN*2], to[MAXN*MAXN*2], tot;
bool v[MAXN][MAXN], vis[MAXN*MAXN];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

bool DFS( int u ){
	go( i, hd[u] ) if ( !vis[v] ){
		vis[v] = 1; if ( !mc[v] || DFS(mc[v]) ) return mc[v] = u, 1;
	} return 0;
}

int main(){
	t_bg = clock();
	read(N), read(M);
	while( M-- ){ int x, y; read(x), read(y), v[x][y] = 1; }
	fp( i, 1, N ) v[i][0] = v[0][i] = v[i][N + 1] = v[N + 1][i] = 1;
	fp( i, 1, N ) fp( j, 1, N ) if ( ((i + j + 1) & 1) && !v[i][j] ){
		int p((i - 1) * N + j);
		if ( !v[i][j + 1] ) addedge( p, p + 1 );
		if ( !v[i + 1][j] ) addedge( p, p + N );
		if ( !v[i][j - 1] ) addedge( p, p - 1 );
		if ( !v[i - 1][j] ) addedge( p, p - N );
	} int ans(0); fp( i, 1, N ) fp( j, 1, N ) if ( (i + j + 1) & 1 ) memset( vis, 0, sizeof vis ), ans += DFS((i - 1) * N + j);
	printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

