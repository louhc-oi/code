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

int N, K;
i64 pw[10005], p[10005][105], C[105][105];
i64 f[105][105][105];
inline i64 dec( i64 x ){ return x >= mod ? x - mod : x; }
inline i64 Pow( i64 x, i64 y ){ i64 ans(1); for ( ; y; y >>= 1, x = x * x % mod ) if ( y & 1 ) ans = ans * x % mod; return ans; }

int main(){
//	open("timegate");
	t_bg = clock();
	read(N), read(K);
	if ( K >= N ) return printf( "0\n" ), 0;
	pw[0] = 1; fp( i, 1, 1e4 ) pw[i] = dec(pw[i - 1] << 1);
	fp( i, 1, 1e4 ){ p[i][0] = 1; fp( j, 1, 1e2 ) p[i][j] = p[i][j - 1] * ( pw[i] - 1 ) % mod; }
	fp( i, 0, 100 ){ C[i][0] = 1; fp( j, 1, i ) C[i][j] = dec( C[i - 1][j - 1] + C[i - 1][j] ); }
	f[0][1][1] = 1;
	i64 ans(0);
	fp( i, 1, K ) fp( j, i + 1, N - K + i ) fp( k, 1, j - i ){
		int s(i < K ? C[N - j + k - 1][k] : C[N - j + k - 1][k - 1]);
		fp( x, 1, j - k ) f[i][j][k] = ( f[i][j][k] + f[i-1][j-k][x] * p[x][k] % mod * pw[k*(k-1)/2] % mod * s ) % mod;
		if ( i == K ) ans = ( ans + f[i][j][k] * pw[(N-j)*k+(N-j)*(N-j-1)/2] ) % mod;
	}
	printf( "%lld\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
