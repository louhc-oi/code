#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;

int N;
int a[305][305]; char s[305];
inline void swp( int &x, int &y ){ x^=y^=x^=y; }
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }

int main(){
	t_bg = clock();
	scanf( "%d", &N ), --N;
	fp( i, 0, N ){
		scanf( "%s", s );
		fp( j, 0, N ) if ( s[j] == '1' )
			--a[i][j], ++a[j][j];
	} fp( i, 1, N ) fp( j, 1, N ) if ( a[i][j] < 0 ) a[i][j] += mod;
	
	int ans(1); fp( i, 1, N ){
		int t(-1); fp( j, i, N ) if ( a[j][i] ){ t = j; break; }
		if ( t == -1 ) return printf( "0\n" ), 0;
		if ( t != i ){ ans = mod - ans; fp( j, i, N ) swp( a[i][j], a[t][j] ); }
		t = Pow(a[i][i]), ans = 1ll * ans * a[i][i] % mod;
		fp( j, 1, N ) a[i][j] = 1ll * a[i][j] * t % mod;
		fp( j, i + 1, N ){
			t = a[j][i]; if ( j != i ) fp( k, i, N )
				a[j][k] -= 1ll * t * a[i][k] % mod,
				a[j][k] < 0 ? a[j][k] += mod : 0;
		}
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
