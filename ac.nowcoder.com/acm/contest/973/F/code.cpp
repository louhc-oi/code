#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
const int mod = 1e9 + 7;
int T; i64 L, R;
int w[20], n, s[20][7][7][2], g[20][7][7][2], f[20][7][7][2];
void work( int a, int b, int c, int d, int x, int y, int z ){
	s[a][b][c][d] = ( s[a][b][c][d] + x ) % mod, g[a][b][c][d] = ( g[a][b][c][d] + y ) % mod, f[a][b][c][d] = ( f[a][b][c][d] + z ) % mod;
}
inline int calc( i64 x ){
	memset( s, 0, sizeof s ), memset( g, 0, sizeof g ), memset( f, 0, sizeof f );
	n = 0; while( x ) w[++n] = x % 10, x /= 10;
	fp( i, 0, w[n] ) if ( i != 7 ) work(n, i % 7, i % 7, i == w[n], 1, i, i * i);
	fd( i, n, 2 ) fp( j, 0, 6 ) fp( k, 0, 6 ){
		const int a(w[i - 1]), s0 = s[i][j][k][0], g0 = g[i][j][k][0], f0 = f[i][j][k][0], s1 = s[i][j][k][1], g1 = g[i][j][k][1], f1 = f[i][j][k][1];
		fp( t, 0, 9 ) if ( t != 7 )
			work(i - 1, (j + t) % 7, (k * 10 + t) % 7, 0, s0, (g0 * 10ll + (i64)t * s0) % mod, (100ll * f0 + 20ll * g0 % mod * t + (i64)s0 * t * t) % mod);
		fp( t, 0, a ) if ( t != 7 )
			work(i - 1, (j + t) % 7, (k * 10 + t) % 7, t==a, s1, (g1 * 10ll + (i64)t * s1) % mod, (100ll * f1 + 20ll * g1 % mod * t + (i64)s1 * t * t) % mod);
	} int ans(0); fp( i, 1, 6 ) fp( j, 1, 6 ) ans = ( ans + f[1][i][j][0] ) % mod, ans = ( ans + f[1][i][j][1] ) % mod;
	return ans;
}

signed main(){
	t_bg = clock();
	scanf( "%d", &T ); i64 x, y;
	while( T-- ) scanf( "%lld%lld", &x, &y ), printf( "%d\n", ( calc(y) - calc(x - 1) + mod) % mod );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

