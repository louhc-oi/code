#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
const int MAXN = 55, MAXV = 2505, MAXE = 2505;
int N, M;
char s[MAXN][MAXN];
int b1[MAXN][MAXN], b2[MAXN][MAXN], n, m;
int hd[MAXV], nxt[MAXE], to[MAXE], tot;
int mc[MAXV]; bool vis[MAXV];
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
	scanf( "%d%d", &N, &M );
	fp( i, 1, N ) scanf( "%s", s[i] + 1 );
	fp( i, 1, N ) fp( j, 1, M ) if ( s[i][j] == '*' ){
		if ( s[i][j - 1] == '*' ) b1[i][j] = b1[i][j - 1];
		else b1[i][j] = ++n;
		if ( s[i - 1][j] == '*' ) b2[i][j] = b2[i - 1][j];
		else b2[i][j] = ++m;
		addedge( b1[i][j], b2[i][j] );
	} int ans(0); fp( i, 1, n ) memset( vis, 0, sizeof vis ), ans += DFS(i);
	printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

