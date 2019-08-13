#include<bits/stdc++.h>
using namespace std;
#define MAXN 44
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
const int MAXV = MAXN*MAXN*MAXN, MAXE = 10*MAXN*MAXN*MAXN;

int P, Q, R, D, S, T, w[MAXN][MAXN][MAXN], ct;
namespace nwf{
	int hd[MAXV], HD[MAXV], nxt[MAXE], to[MAXE], val[MAXE], tot(1);
	inline void addedge( int x, int y, int z = INF ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0;
	}
	int d[MAXV]; queue<int> Q;
	bool BFS(){
		while( !Q.empty() ) Q.pop();
		memset( d, 0, sizeof d );
		Q.push(S), d[S] = 1;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop();
			go( i, hd[u] ) if ( val[i] && !d[v] ){
				d[v] = d[u] + 1, Q.push(v);
				if ( v == T ) return 1;
			}
		} return 0;
	}
	int DFS( int u, int fl ){
		if ( u == T ) return fl;
		int r(fl), k;
		for ( int &i = HD[u], v; i && r; i = nxt[i] ) if ( val[i] && d[v = to[i]] == d[u] + 1 ){
			k = DFS( v, min( r, val[i] ) );
			if ( !k ) d[v] = 0;
			r -= k, val[i] -= k, val[i ^ 1] += k;
		} return fl - r;
	}
	int MaxFlow(){
		int ans(0), x;
		while( BFS() ){ memcpy( HD, hd, sizeof hd ); while((x = DFS( S, INF ))) ans += x; }
		return ans;
	}
}
using nwf::addedge;

int main(){
	t_bg = clock();
	read(P), read(Q), read(R), read(D); int x;
	fp( i, 1, P ) fp( j, 1, Q ) fp( k, 1, R ) w[i][j][k] = ++ct;
	T = ++ct;
	fp( i, 1, P ) fp( j, 1, Q ) addedge( w[i][j][R], T );
	fp( k, 1, R ) fp( i, 1, P ) fp( j, 1, Q )
		read(x), addedge( w[i][j][k - 1], w[i][j][k], x );
	fp( i, 1, P ) fp( j, 1, Q ) fp( k, D + 1, R ){
		if ( i > 1 ) addedge( w[i][j][k], w[i - 1][j][k - D] );
		if ( i < P ) addedge( w[i][j][k], w[i + 1][j][k - D] );
		if ( j > 1 ) addedge( w[i][j][k], w[i][j - 1][k - D] );
		if ( j < Q ) addedge( w[i][j][k], w[i][j + 1][k - D] );
	}
	printf( "%d\n", nwf::MaxFlow() );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
