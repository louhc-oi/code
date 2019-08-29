#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 1005
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N, R, a[MAXN];
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], tot;
int h[MAXN], s[MAXN], fa[MAXN], nt[MAXN], ed[MAXN];
bool vis[MAXN];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

void DFS( int u ){
	go( i, hd[u] ) if ( v != fa[u] ) fa[v] = u, DFS(v);
}

signed main(){
	t_bg = clock();
	while( ~scanf( "%d%d", &N, &R ) && N && R ){
		fa[R] = 0; int x, y; fp( i, 1, N ) scanf( "%d", a + i );
		memset( hd, 0, sizeof hd ), memset( vis, 0, sizeof vis ), tot = 0;
		fp( i, 2, N ) scanf( "%d%d", &x, &y ), addedge(x, y), addedge(y, x);
		DFS(R); fp( i, 1, N ) h[i] = 1, s[i] = a[i], ed[i] = i, nt[i] = 0;
		fp( T, 2, N ){
			int w(-1), t;
			fp( i, 1, N ) if ( i != R && !vis[i] && ( w < 0 || s[i] * h[w] > s[w] * h[i] ) ) w = i;
			t = fa[w]; while( vis[t] ) t = fa[t];
			vis[w] = 1, s[t] += s[w], h[t] += h[w], nt[ed[t]] = w, ed[t] = ed[w];
		} int ans(0), c(0);
		for ( int i = R; i; i = nt[i] ) ans += (++c) * a[i];
		printf( "%d\n", ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

