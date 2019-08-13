#include<bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
#define MAXN 18
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

int R, C, w[MAXN][MAXN], ct;

namespace nwf{
	const int MAXV = 2*MAXN*MAXN, MAXE = 12*MAXN*MAXN;
	int S, T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE], c[MAXE], tot(1);
	inline void addedge( int x, int y, int z, int s ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z, c[tot] = s;
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0, c[tot] = -s;
	}
	queue<int> Q;
	int d[MAXV], pre[MAXV], res; char vis[MAXV];
	bool SPFA(){
		while( !Q.empty() ) Q.pop();
		memset( d, 0x7f, sizeof d ),
		memset( vis, 0, sizeof vis );
		Q.push(S), d[S] = 0;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop(), vis[u] = 0;
			go( i, hd[u] ) if ( val[i] && d[v] > d[u] + c[i] )
				d[v] = d[u] + c[i], pre[v] = i,
				!vis[v] ? Q.push(v), vis[v] = 1 : 1;
		}
		if ( d[T] >= INF ) return 0;
		int ans(INF);
		for ( int i = T; i != S; i = to[pre[i] ^ 1] ) cmin( ans, val[pre[i]] );
		for ( int i = T; i != S; i = to[pre[i] ^ 1] ) val[pre[i]] -= ans, val[pre[i] ^ 1] += ans;
		res += ans * d[T];
		return 1;
	}
	int calc(){ while( SPFA() ); return res; }
}
using nwf::addedge;
using nwf::S;
using nwf::T;

int main(){
	t_bg = clock();
	read(R), read(C), T = ++ct;
	fp( i, 1, R ) fp( j, 1, C ) addedge( S, w[i][j] = ++ct, 1, 0 ), addedge( w[i][j] + R*C, T, 1, 0 );
	fp( i, 1, R ) fp( j, 1, C ){
		char t; while( (t = getchar()) < 'A' || t > 'Z' );
		addedge( w[i][j], w[i > 1 ? i - 1 : R][j] + R*C, 1, t != 'U' );
		addedge( w[i][j], w[i < R ? i + 1 : 1][j] + R*C, 1, t != 'D' );
		addedge( w[i][j], w[i][j > 1 ? j - 1 : C] + R*C, 1, t != 'L' );
		addedge( w[i][j], w[i][j < C ? j + 1 : 1] + R*C, 1, t != 'R' );
	}
	printf( "%d\n", nwf::calc() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

