#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 1000000007
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

const int s = (1 << 20) - 1;
int N, a[1 << 20];
inline int rec( int x ){ return x < 0 ? x + mod : x; }
inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int main(){
	t_bg = clock();
	read(N); int x; fp( i, 1, N ) read(x), ++a[x];
	fp( i, 0, 19 ) fp( j, 0, s ) if (!(j & (1 << i))) a[j] = a[j] + a[1 << i | j];
	fp( i, 0, s ) a[i] = Pow( 2, a[i] );
	fp( i, 0, 19 ) fp( j, 0, s ) if (!(j & (1 << i)) ) a[j] = rec( a[j] - a[1 << i | j] );
	printf( "%d\n", a[0] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
