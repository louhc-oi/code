#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define MAXN 105
#define rgt register

struct hs{
	const static int N = 19260817; int hd[N], nt[N], v[N], w[N], tot;
	inline void init(){ memset( hd, 0, sizeof hd ), tot = 0; }
	inline int Find( int x ){ int i(hd[x % N]); for ( ; i; i = nt[i] ) if ( v[i] == x ) return w[i]; return -1; }
	inline int Ins( int x, int y ){ int i(x % N); nt[++tot] = hd[i], hd[i] = tot, v[tot] = x, w[tot] = y; return y; }
}h;

int T, N, M, a[MAXN], v[MAXN], g[105][105];

inline int dec( int x ){ return x >= p ? x - p : x; }
#define ID(a, b, c, d) ( ( ( a * 100 + b ) * 100 + c ) * 100 + d )
int work( int c, int x, int y, int z ){
	if ( c == 3 ) return 1;
	rgt int r(c - 3), ans;
	if ( (ans = h.Find(ID(c, x, y, z))) >= 0 ) return ans;
	ans = 0;
	for ( rgt int i = a[r] ? a[r] : 1, I = a[r] ? a[r] : M; i <= I; ++i )
		ans = dec( ans + 1ll * v[g[z][i]] * work( c - 1, i, g[i][x], g[i][y] ) % p );
	return h.Ins(ID(c, x, y, z), ans);
} inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % p ) if ( y & 1 ) ans = 1ll * ans * x % p; return ans; }

int main(){
	scanf( "%d", &T );
	for ( int i = 0; i <= 100; ++i ) g[0][i] = g[i][0] = i;
	for ( int i = 1; i <= 100; ++i )
		for ( int j = 1; j <= i; ++j )
			g[i][j] = g[j][i] = g[i % j][j];
	while( T-- ){
		scanf( "%d%d", &N, &M );
		for ( int i = 1; i <= N; ++i ) scanf( "%d", a + i );
		for ( int i = 1; i <= M; ++i ) scanf( "%d", v + i );
		int ans(0), ct(0); h.init();
		for ( int i(a[N] ? a[N] : 1), I(a[N] ? a[N] : M), t; i <= I; ++i )
		for ( int j(a[N-1] ? a[N-1] : 1), J(a[N-1] ? a[N-1] : M); j <= J; ++j )
		for ( int k(a[N-2] ? a[N-2] : 1), K(a[N-2] ? a[N-2] : M); k <= K; ++k )
			t = g[j][k], ans = dec( ans + work( N, k, t, g[i][t] ) );
		for ( int i = 1; i <= N; ++i ) ct += !a[i];
		printf( "%d\n", 1ll * ans * Pow( Pow( M, ct ), p - 2 ) % p );
	}
	return 0;
}
