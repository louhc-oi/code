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

clock_t t_bg, t_ed;
int N, V; string a[105], x, y;
map<string, int> mp;

namespace nwf{
	const int MAXV = 205, MAXE = 22222;
	int S, T, hd[MAXV], nxt[MAXE], to[MAXE], val[MAXE], c[MAXE], tot(1);
	inline void addedge( int x, int y, int z, int s ){
		nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z, c[tot] = s;
		nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = 0, c[tot] = -s;
	} queue<int> Q; int res, sum, d[MAXE], l[MAXE]; bool vis[MAXE];
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
		return res += ans, sum += ans * d[T], 1;
	}
	int ans[205], n;
	void DFS( int u ){
		vis[u] = 1, ans[++n] = u;
		if ( u == N ) return;
		go( i, hd[u + N] ) if ( !vis[v] && val[i ^ 1] ) return DFS(v);
	}
	void work(){
		res = 0; while( SPFA() );
		if ( res < 2 ) return printf("No Solution!\n"), void();
		cout << -sum - 2 << endl;
		memset( vis, 0, sizeof vis );
		DFS(S); fp( i, 1, n ) cout << a[ans[i]] << endl;
		n = 0; DFS(S); while( n >= 1 ) cout << a[ans[n--]] << endl;
	}
} using nwf::addedge; using nwf::S; using nwf::T;

int main(){
	t_bg = clock();
	cin >> N >> V;
	fp( i, 1, N ) cin >> a[i], mp[a[i]] = i;
	fp( i, 1, V ) cin >> x >> y, addedge( mp[x] + N, mp[y], INF, 0 );
	addedge( 1, 1 + N, 2, -1 ), addedge( N, N << 1, 2, -1 ), S = 1; fp( i, 2, N - 1 ) addedge( i, i + N, 1, -1 );
	S = 1, T = N + N, nwf::work();
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
