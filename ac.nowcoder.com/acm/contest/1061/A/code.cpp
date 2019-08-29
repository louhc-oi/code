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
int N, hd[MAXN], nxt[MAXN*MAXN], to[MAXN*MAXN], tot;
inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y;
}

int dfn[MAXN], low[MAXN], num, c[MAXN], cnt, stk[MAXN], tp;
bool v1[MAXN], v2[MAXN];
void tarjan( int u ){
	low[u] = dfn[u] = ++num, stk[++tp] = u;
	go( i, hd[u] )
		if ( !dfn[v] ) tarjan(v), cmin( low[u], low[v] );
		else if ( !c[v] ) cmin( low[u], dfn[v] );
	if ( low[u] == dfn[u] ){
		c[u] = ++cnt;
		while( stk[tp] != u ) c[stk[tp--]] = cnt;
		--tp;
	}
}

signed main(){
	t_bg = clock();
	read(N);
	fp( i, 1, N ){
		int x; while( (read(x), x) ) addedge( i, x );
	} fp( i, 1, N ) if ( !c[i] ) tarjan(i);
	fp( u, 1, N ) go( i, hd[u] ) if ( c[u] != c[v] ) v1[c[v]] = 1, v2[c[u]] = 1;
	int r1(0), r2(0); fp( i, 1, cnt ) r1 += !v1[i], r2 += !v2[i];
	printf( "%d\n%d\n", r1, cnt == 1 ? 0 : max( r1, r2 ) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

