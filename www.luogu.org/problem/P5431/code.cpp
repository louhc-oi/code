#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define rgt register
#define fp( i, b, e ) for ( rgt int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( rgt int i(b), I(e); i >= I; --i )
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t(getchar()), flg(0);
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : 0;
}

const int MAXN = 5e6 + 5;
int N, p, k, a[MAXN], s[MAXN], sv[MAXN], ans(0), t(1);
inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = (i64)x * x % p ) if ( y & 1 ) ans = (i64)ans * x % p; return ans; }

signed main(){
	read(N), read(p), read(k), s[0] = 1;
	fp( i, 1, N ) read(a[i]), s[i] = (i64)a[i] * s[i - 1] % p;
	sv[N] = Pow( s[N], p - 2 ); fd( i, N - 1, 1 ) sv[i] = (i64)sv[i + 1] * a[i + 1] % p;
	fp( i, 1, N ) ans = ( ans + (i64)(t = (i64)t * k % p) * s[i - 1] % p * sv[i] ) % p;
	printf( "%d\n", ans );
	return 0;
} 
