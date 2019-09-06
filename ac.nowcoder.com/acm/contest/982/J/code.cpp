#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;
const int mod = 1e6 + 3;
int T, N, L, R;
int fac[mod + 5], inv[mod + 5];

inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * x * ans % mod; return ans; }
int C( int x, int y ){
	if ( x < y ) return 0;
	return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int lucas( int x, int y ){
	if ( x < y ) return 0; if ( y == 0 ) return 1;
	if ( x < mod && y < mod ) return C( x, y );
	return 1ll * lucas( x / mod, y / mod ) * C( x % mod, y % mod ) % mod;
}

signed main(){
	read(T); fac[0] = inv[0] = 1;
	fp( i, 1, mod ) fac[i] = 1ll * fac[i - 1] * i % mod, inv[i] = Pow(fac[i]);
	while( T-- ){
		read(N), read(L), read(R);
		printf( "%d\n", ( lucas( R + N - L + 1, N ) + mod - 1 ) % mod );
	}
	return 0;
}

