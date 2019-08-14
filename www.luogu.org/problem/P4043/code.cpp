#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x7f7f7f7f
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
int N, ans;

namespace nwf{
	const int MAXV = 305, MAXE = 20005;
	int S, T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE], c[MAXE], tot(1);
	inline void addedge( int x, int y, int z, int s ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z, c[tot] = s;
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0, c[tot] = -s;
	} queue<int> Q; int res, d[MAXE], l[MAXE]; bool vis[MAXE];
	bool SPFA(){
		Q.push(S), memset( d, 0x7f, sizeof d ), memset( vis, 0, sizeof vis ), d[S] = 0;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop(), vis[u] = 0;
			go( i, hd[u] ) if ( val[i] && d[v] > d[u] + c[i] ){
				d[v] = d[u] + c[i], l[v] = i;
				if ( !vis[v] ) Q.push(v), vis[v] = 1;
			}
		} if ( d[T] >= INF ) return 0;
		int ans(INF);
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) cmin( ans, val[l[i]] );
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) val[l[i]] -= ans, val[l[i] ^ 1] += ans;
		return res += ans * d[T], 1;
	} int calc(){ res = 0; while( SPFA() ); return res; }
} using nwf::addedge; using nwf::S; using nwf::T;

int s[305];

int main(){
	t_bg = clock();
	read(N), S = 0, T = N + 1;
	fp( i, 1, N ){
		int k, b, t; read(k), s[i] -= k; if ( i > 1 ) addedge( i, 1, INF, 0 );
		fp( j, 1, k ) read(b), read(t), ans += t, ++s[b], addedge( i, b, INF, t );
	} fp( i, 1, N ) if ( s[i] > 0 ) addedge( S, i, s[i], 0 ); else if ( s[i] < 0 ) addedge( i, T, -s[i], 0 );
	printf( "%d\n", ans + nwf::calc() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
