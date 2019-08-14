#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define rgt register
#pragma GCC optimize(3)
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;

int N, M, e[1005][2];
int n, a[105], dg[105];

#define LD double
namespace nwf{
	const int MAXV = 105, MAXE = 2405; queue<int> Q;
	int S, T, hd[MAXV], HD[MAXV], nxt[MAXE], to[MAXE], tot(1), d[MAXE]; LD val[MAXE];
	inline void init(){ memset( hd, 0, sizeof hd ), tot = 1; }
	inline void addedge( int x, int y, LD z ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0;
	}
	void dfs( int u ){
		++n, a[u] = 1;
		go( i, hd[u] ) if ( val[i] > 0 && !a[v] ) dfs(v);
	}
	bool BFS(){
		while( !Q.empty() ) Q.pop();
		memset( d, 0, sizeof d );
		Q.push(S), d[S] = 1;
		while( !Q.empty() ){
			int u(Q.front()); Q.pop();
			go( i, hd[u] ) if ( val[i] > eps && !d[v] ){
				d[v] = d[u] + 1, Q.push(v);
				if ( v == T ) return 1;
			}
		} return 0;
	}
	LD DFS( rgt int u, rgt LD fl ){
		if ( u == T ) return fl;
		rgt LD r(fl), k;
		for ( rgt int &i = HD[u], v; i && r > eps; i = nxt[i] ) if ( val[i] > eps && d[v = to[i]] == d[u] + 1 ){
			k = DFS( v, min( r, val[i] ) );
			if ( abs(k) < eps ) d[v] = 0;
			r -= k, val[i] -= k, val[i ^ 1] += k;
		} return fl - r;
	}
	inline LD MaxFlow(){
		rgt LD ans(0), x;
		while( BFS() ){ memcpy( HD, hd, (T+1)<<2 ); while((x = DFS( S, 1e9 )) >= eps) ans += x; }
		return ans;
	}
} using nwf::init; using nwf::addedge; using nwf::S; using nwf::T;

inline bool check( LD x ){
	S = 0, T = 1 + N, init();
	fp( i, 1, M ) addedge( e[i][0], e[i][1], 1 ), nwf::val[nwf::tot] = 1;
	fp( i, 1, N ) addedge( S, i, M ), addedge( i, T, M + 2 * x - dg[i] );
	return N * M - nwf::MaxFlow() > 1e-5;
}

int main(){
	t_bg = clock();
	bool flg(0);
	while( ~scanf( "%d%d", &N, &M ) ){
		if ( flg ) putchar('\n');
		flg = 1, memset( dg, 0, sizeof dg );
		if ( !M ){ printf( "1\n1\n" ); continue; }
		fp( i, 1, M ) scanf( "%d%d", e[i], e[i] + 1 ), ++dg[e[i][0]], ++dg[e[i][1]];
		LD l(0), r(M), mid;
		while( r - l > 1e-6 ){
			mid = ( l + r ) / 2.;
			if ( check(mid) ) l = mid; else r = mid;
		} check(l), n = 0, memset( a, 0, sizeof a ), nwf::dfs(S), printf( "%d\n", n - 1 );
		fp( i, 1, N ) if ( a[i] ) printf( "%d\n", i );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
