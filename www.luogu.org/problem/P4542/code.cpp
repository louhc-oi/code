#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define INF 0x3f3f3f3f
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

namespace nwf{
	const int MAXV = 355, MAXE = 100005;
	int S, T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE], c[MAXE], tot(1);
	queue<int> Q; int d[MAXE], l[MAXE], res; bool vis[MAXE];
	inline void addedge( int x, int y, int z, int s ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z, c[tot] = s,
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0, c[tot] = -s;
	} bool SPFA(){
		memset( d, 0x7f, sizeof d ), memset( vis, 0, sizeof vis ), Q.push(S), d[S] = 0;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop(), vis[u] = 0;
			go( i, hd[u] ) if ( val[i] && d[v] > d[u] + c[i] ){
				d[v] = d[u] + c[i], l[v] = i; if ( !vis[v] ) vis[v] = 1, Q.push(v);
			}
		} if ( d[T] >= INF ) return 0;
		int fl(INF);
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) cmin( fl, val[l[i]] );
		for ( int i = T; i != S; i = to[l[i] ^ 1] ) val[l[i]] -= fl, val[l[i] ^ 1] += fl;
		return res += fl * d[T], 1;
	} inline int calc(){ res = 0; while(SPFA()); return res; }
} using nwf::addedge; using nwf::S; using nwf::T;
int d[355];
inline void Ins( int x, int y, int l, int r, int s ){
	if ( l < r ) addedge( x, y, r - l, s );
	nwf::res += s * l, d[x] -= l, d[y] += l;
}

int N, M, K, a[305][305];

int main(){
	t_bg = clock();
	read(N), read(M), read(K), ++N, S = 0, T = N << 1 | 1;
	int x, y, z; memset( a, 0x3f, sizeof a );
	fp( i, 1, M ) read(x), read(y), read(z), ++x, ++y, cmin( a[x][y], z ), a[y][x] = a[x][y];
	fp( k, 1, N ){
		fp( i, 1, k - 1 ) if ( a[i][k] < INF ) Ins( i + N, k, 0, M, a[i][k] );
		fp( i, 1, N ) fp( j, 1, N ) cmin( a[i][j], a[i][k] + a[k][j] );
	} Ins( 1, 1 + N, 0, K, 0 ); fp( i, 2, N ) Ins( i + N, 1, 0, K, 0 ), Ins( i, i + N, 1, K, 0 );
	fp( i, 1, N << 1 ) if ( d[i] > 0 ) addedge( S, i, d[i], 0 ); else if ( d[i] < 0 ) addedge( i, T, -d[i], 0 );
	printf( "%d\n", nwf::calc() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

