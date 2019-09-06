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
const int MAXN = 1e3 + 5;
int N, M, rt; bool mp[MAXN][MAXN]; vector<int> e[MAXN], dcc[MAXN];
inline void addedge( int x, int y ){ e[x].push_back(y), e[y].push_back(x); }
int dfn[MAXN], num, low[MAXN], stk[MAXN], tp, cnt;
int c[MAXN]; bool d[MAXN], ok[MAXN];
void tarjan( int u ){
	low[u] = dfn[u] = ++num, stk[++tp] = u;
	if ( u == rt && !e[u].size() ) return dcc[++cnt].push_back(u), void();
	for ( int v : e[u] ) if ( !dfn[v] ){
		tarjan(v), cmin( low[u], low[v] );
		if ( low[v] >= dfn[u] ){
			int z; dcc[++cnt].push_back(u);
			do dcc[cnt].push_back(z = stk[tp--]); while( z != v );
		}
	} else cmin( low[u], dfn[v] );
}

bool DFS( int u ){
	for ( int v : e[u] )if ( d[v] ){
		if ( !c[v] ){
			c[v] = 3 - c[u]; if ( !DFS(v) ) return 0;
		} else if ( c[v] + c[u] != 3 ) return 0;
	} return 1;
}

signed main(){
	t_bg = clock();
	while( ( read(N), read(M), N && M ) ){
		int x, y, ans(0); memset( mp, 0, sizeof mp ), cnt = num = tp = 0;
		fp( i, 1, N ) e[i].clear(), dcc[i].clear();
		fp( i, 1, M ) read(x), read(y), mp[x][y] = mp[y][x] = 1;
		fp( i, 1, N ) fp( j, i + 1, N ) if ( !mp[i][j] ) addedge( i, j );
		memset( dfn, 0, sizeof dfn );
		fp( i, 1, N ) if ( !dfn[i] ) rt = i, tarjan(i);
		fp( k, 1, cnt ){
			for ( int i : dcc[k] ) d[i] = 1;
			if ( !DFS(dcc[k][0]) ) for ( int i : dcc[k] ) ok[i] = 1;
			for ( int i : dcc[k] ) d[i] = 0, c[i] = 0;
		} fp( i, 1, N ) ans += !ok[i], ok[i] = 0;
		printf( "%d\n", ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

