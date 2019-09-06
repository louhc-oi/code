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
const int MAXN = 2e3 + 5, MAXM = 6e3 + 5;
int N, M, K;
int hd[MAXN], nxt[MAXM], to[MAXM], tot;
int a[MAXN], d[MAXN]; bool vis[MAXN], g[MAXN];
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}
void DFS( int u ){
	vis[u] = 1;
	if ( !hd[u] ) return a[u] = 0, void();
	go( i, hd[u] ) if ( !vis[v] ) DFS(v);
	go( i, hd[u] ) d[a[v]] = u;
	fp( i, 0, N ) if ( d[i] != u ){ a[u] = i; break; }
}

signed main(){
	t_bg = clock();
	read(N), read(M), read(K); int x, y;
	fp( i, 1, M ) read(x), read(y), addedge( x, y ), g[y] = 1;
	fp( i, 1, N ) if ( !g[i] ) DFS(i);
	int ans(0); while( K-- ) read(x), ans ^= a[x];
	printf( ans ? "win\n" : "lose\n" );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

