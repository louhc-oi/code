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

const int MAXN = 3e5 + 5;
int N, M;
int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
int w[MAXN], dep[MAXN], fa[MAXN][20], r[MAXN], s[MAXN<<2];
int cs[MAXN];
vector<int> v1[MAXN], v2[MAXN], vt[MAXN];

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}

void DFS( int u ){
	dep[u] = dep[fa[u][0]] + 1;
	fp( i, 1, 18 ) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != fa[u][0] )
		fa[v][0] = u, DFS(v);
}
inline int LCA( int x, int y ){
	if ( dep[x] < dep[y] ) x^=y^=x^=y;
	fd( i, 18, 0 ) if ( dep[fa[x][i]] > dep[y] ) x = fa[x][i];
	if ( dep[x] > dep[y] ) x = fa[x][0];
	fd( i, 18, 0 ) if ( fa[x][i] != fa[y][i] ) x = fa[x][i], y = fa[y][i];
	return x == y ? x : fa[x][0];
}
void DFS1( int u ){
	int t(s[dep[u] + w[u]]);
	go( i, hd[u] ) if ( v != fa[u][0] ) DFS1(v);
	s[dep[u]] += cs[u], r[u] += s[dep[u] + w[u]] - t;
	fp( i, 0, (int)v1[u].size() - 1 ) --s[v1[u][i]];
}
void DFS2( int u ){
	int t(s[w[u] - dep[u] + N]);
	go( i, hd[u] ) if ( v != fa[u][0] ) DFS2(v);
	fp( i, 0, (int)vt[u].size() - 1 ) ++s[vt[u][i]];
	r[u] += s[w[u] - dep[u] + N] - t;
	fp( i, 0, (int)v2[u].size() - 1 ) --s[v2[u][i]];
}

signed main(){
	read(N), read(M); int x, y;
	fp( i, 1, N - 1 ) read(x), read(y), addedge(x, y);
	fp( i, 1, N ) read(w[i]);
	DFS(1); fp( i, 1, M ){
		int x, y, l;
		read(x), read(y), l = LCA(x, y);
		if ( dep[x] == w[l] + dep[l] ) --r[l];
		++cs[x], v1[l].push_back(dep[x]);
		vt[y].push_back(dep[x] - (dep[l] << 1) + N),
		v2[l].push_back(dep[x] - (dep[l] << 1) + N);
	} DFS1(1), memset( s, 0, sizeof s ), DFS2(1);
	fp( i, 1, N ) printf( "%d ", r[i] );
	return 0;
}

