#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x7f7f7f7f7f7f7f7fll
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
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
#define MAXN 20
int A, B, P, Q, d[MAXN][MAXN], ct;

namespace nwf{
	const int MAXV = 300, MAXE = 5005;
	int S, T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE]; i64 c[MAXE], tot(1);
	inline void addedge( int x, int y, int z, i64 s ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z, c[tot] = s;
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0, c[tot] = -s;
	} queue<int> Q; i64 res, d[MAXE]; int l[MAXE]; bool vis[MAXE];
	bool SPFA(){
		Q.push(S), memset( d, 0x7f, sizeof d ), memset( vis, 0, sizeof vis ), d[S] = 0;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop(), vis[u] = 0;
			go( i, hd[u] ) if ( val[i] && d[v] > d[u] + c[i] ){
				d[v] = d[u] + c[i], l[v] = i;
				if ( !vis[v] ) Q.push(v), vis[v] = 1;
			}
		} if ( d[T] >= INF ) return 0;
		int ans(INT_MAX);
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) cmin( ans, val[l[i]] );
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) val[l[i]] -= ans, val[l[i] ^ 1] += ans;
		return res += ans * d[T], 1;
	} i64 calc(){ res = 0; while( SPFA() ); return res; }
} using nwf::addedge; using nwf::S; using nwf::T;

int main(){
	t_bg = clock(); int x, y, k;
	read(A), read(B), read(P), read(Q); S = 0, T = 1, ct = 1; fp( i, 0, P ) fp( j, 0, Q ) d[i][j] = ++ct;
	fp( i, 0, P ) fp( j, 1, Q ) read(x), addedge( d[i][j - 1], d[i][j], 1, -x ), addedge( d[i][j - 1], d[i][j], INT_MAX, 0 );
	fp( j, 0, Q ) fp( i, 1, P ) read(x), addedge( d[i - 1][j], d[i][j], 1, -x ), addedge( d[i - 1][j], d[i][j], INT_MAX, 0 );
	fp( i, 1, A ) read(k), read(x), read(y), addedge( S, d[x][y], k, 0 );
	fp( i, 1, B ) read(k), read(x), read(y), addedge( d[x][y], T, k, 0 );
	printf( "%lld\n", -nwf::calc() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

