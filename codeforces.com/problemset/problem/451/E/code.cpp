#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )

i64 N, S, ans;
i64 f[25], inv[25];
const int mod = 1e9 + 7;

inline i64 C( i64 n, i64 m ){
	if ( n < m ) return 0;
	i64 t(1);
	for ( i64 i = n - m + 1; i <= n; ++i ) t = i % mod * t % mod;
	for ( i64 i = 2; i <= m; ++i ) t = t * inv[i] % mod; 
	return t;
}

signed main(){
	scanf( "%I64d%I64d", &N, &S );
	fp( i, 1, N ) scanf( "%I64d", f + i );
	inv[1] = 1; fp( i, 2, N ) inv[i] = mod - mod / i *  inv[mod % i] % mod;
	fp( i, 0, (1 << N) - 1 ){
		i64 t(S + N - 1), o(1);
		fp( j, 0, N - 1 ) if ( (i >> j) & 1 )o = mod - o, t -= f[j + 1] + 1;
		ans = ( ans + o * C(t, N - 1) ) % mod;
	} printf( "%I64d\n", ans );
	return 0;
}

