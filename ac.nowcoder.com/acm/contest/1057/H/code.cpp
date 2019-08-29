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
const int MAXN = 50005;
int N, M;
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], val[MAXN<<1], tot;
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
}
int fa[MAXN][20], dep[MAXN], w[MAXN], n, m; i64 s[MAXN], h[MAXN], g[MAXN];
bool b[MAXN];
vector<i64> v[MAXN];

void DFS( int u ){
	dep[u] = dep[fa[u][0]] + 1;
	fp( i, 1, 15 ) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != fa[u][0] ) fa[v][0] = u, s[v] = s[u] + val[i], DFS(v);
}
void dfs( int u ){
	if ( !b[u] ){
		if ( nxt[hd[u]] ) b[u] = 1;
		go( i, hd[u] ) if ( v != fa[u][0] ) dfs(v), b[u] &= b[v];
	}
	if ( dep[u] == 2 && v[u].size() ){
		if ( b[u] ) fp( i, 0, v[u].size() - 1 ) h[++n] = v[u][i] - s[u];
		else{ b[u] = 1, sort( v[u].begin(), v[u].end() ); fp( i, 1, (int)v[u].size() - 1 ) h[++n] = v[u][i] - s[u]; }
	}
} bool cmp( int x, int y ){ return x > y; }

bool check( i64 S ){
	n = m = 0;
	memset( b, 0, sizeof b );
	fp( i, 1, N ) v[i].clear();
	fp( i, 1, M ){
		int x(w[i]), t(x); i64 y(S);
		fd( j, 15, 0 ) if ( fa[t][j] > 1 && s[x] - s[fa[t][j]] <= y ) t = fa[t][j];
		y -= s[x] - s[t];
		if ( dep[t] == 2 && y >= (s[t] << 1) ) h[++n] = y - s[t];
		else if ( dep[t] == 2 && y >= s[t] ) v[t].push_back(y);
		else b[t] = 1;
	} dfs(1);
	go( i, hd[1] ) if ( !b[v] ) g[++m] = s[v];
	if ( n < m ) return 0;
	sort( h + 1, h + n + 1, cmp ), sort( g + 1, g + m + 1, cmp );
	fp( i, 1, m ) if ( h[i] < g[i] ) return 0;
	return 1;
}

signed main(){
	t_bg = clock();
	read(N); int x, y, z; i64 l(1), r(0), mid, ans(-1);
	fp( i, 2, N ) read(x), read(y), read(z), addedge( x, y, z ), r += z;
	DFS(1), read(M); fp( i, 1, M ) read(w[i]);
	while( l <= r ){
		mid = ( l + r ) >> 1;
		if ( check(mid) ) r = mid - 1, ans = mid;
		else l = mid + 1;
	} printf( "%lld\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

