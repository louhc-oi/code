#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
const int mod = 1e5 + 3;
int a, b, c, d, k, ans;
int fac[2005], inv[2005];
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }
inline int C( int n, int m ){
	if ( n < m ) return 0;
	return 1ll * fac[n] * inv[m] * inv[n - m] % mod;
}

signed main(){
	t_bg = clock();
	scanf( "%d%d%d%d%d", &a, &b, &c, &d, &k ), fac[0] = inv[0] = 1;
	fp( i, 1, 2000 ) fac[i] = 1ll * i * fac[i - 1] % mod, inv[i] = Pow(fac[i]);
	fp( i, max( 0, k - d ), min( k, min( a, b ) ) )
		ans = ( ans + 1ll * C(b, i) * C(a, i) * fac[i] % mod * C(d, k - i) * C(a + c - i, k - i) % mod * fac[k - i] ) % mod;
	printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

