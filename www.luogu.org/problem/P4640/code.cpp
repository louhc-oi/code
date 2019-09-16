#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )

const int MAXN = 1e5 + 5;
int N, T, M, P;
int b[20], fac[MAXN], inv[MAXN];

inline int C( int n, int m ){ return n >= m ? 1ll * fac[n] * inv[m] % P * inv[n - m] % P : 0; }
inline int lucas( int n, int m ){
	i64 ans(1); for ( ; m && ans; n /= P, m /= P ) ans = ans * C(n % P, m % P) % P;
	return ans;
}

signed main(){
	scanf( "%d%d%d%d", &N, &T, &M, &P );
	fp( i, 1, T ) scanf( "%d", b + i );
	inv[1] = inv[0] = fac[1] = fac[0] = 1;
	fp( i, 2, P - 1 ) inv[i] = P - 1ll * P / i * inv[P % i] % P;
	fp( i, 2, P - 1 ) fac[i] = 1ll * fac[i - 1] * i % P, inv[i] = 1ll * inv[i - 1] * inv[i] % P;
	i64 ans(0);
	fp( i, 0, (1 << T) - 1 ){
		i64 t(N + M), o(1);
		fp( j, 0, T - 1 ) if ( (i >> j) & 1 ) t -= b[j + 1] + 1, o = P - o;
		if ( t > 0 ) ans = ( ans + lucas(t, N) * o ) % P;
	} printf( "%lld\n", ans );
	return 0;
}

