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
const int MAXN = 105, MAXM = 1005;
int N, M, K;
int hd[MAXN], nxt[MAXM], to[MAXM], tot;
int mc[MAXN]; bool vis[MAXN];
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
	while( ( read(N), N ) ){
		read(M), read(K); int x, y, ans(0);
		memset( mc, 0, sizeof mc ), memset( hd, 0, sizeof hd ), tot = 0;
		fp( i, 1, K ) read(x), read(x), read(y), x && y ? addedge( x, y ) : void();
		fp( i, 1, N - 1 ) memset( vis, 0, sizeof vis ), ans += DFS(i);
		printf( "%d\n", ans );
	} 
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

