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

int N, M;
namespace nwf{
	const int MAXV = 210, MAXE = 40005;
	int S, T, _s, _S, _T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE], c[MAXE], tot(1);
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
} using nwf::addedge; using nwf::S; using nwf::T; using nwf::_S; using nwf::_T; using nwf::_s;

int d[210];
inline void Ins( int x, int y, int l, int r, int c ){ if ( l < r ) addedge( x, y, r - l, c ); d[x] -= l, d[y] += l; }

int main(){
	t_bg = clock();
	read(N), read(M), _S = 0, _s = N << 1 | 1, _T = _s + 1, S = _T + 1, T = S + 1; int x; Ins( _s, _S, M, M, 0 );
	fp( i, 1, N ) read(x), Ins( _S, i, 0, M, 0 ), Ins( i + N, _T, 0, M, 0 ), Ins( i, i + N, x, x, 0 );
	Ins( _T, _s, 0, M, 0 );
	fp( i, 1, N ) fp( j, i + 1, N ){
		read(x); if ( x >= 0 ) Ins( i + N, j, 0, M, x );
	} fp( i, _S, _T ) if ( d[i] > 0 ) addedge( S, i, d[i], 0 ); else addedge( i, T, -d[i], 0 );
	printf( "%d\n", nwf::calc() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

