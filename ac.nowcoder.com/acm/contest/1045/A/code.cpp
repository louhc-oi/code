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
int N, B, ans;
const int MAXN = 3831;
int U[MAXN], f[2][MAXN][2];

signed main(){
	t_bg = clock();
	read(N), read(B);
	fp( i, 1, N ) read(U[i]);
	memset( f, 0xf7, sizeof f );
	f[1][0][0] = f[1][1][1] = 0;
	fp( i, 2, N ){
		int c(i & 1), d((i + 1) & 1);
		fp( j, 0, B )
			f[c][j][0] = max( f[d][j][0], f[d][j][1] ),
			f[c][j][1] = j ? max( f[d][j - 1][1] + U[i], f[d][j - 1][0] ) : 0xf7f7f7f7;
	} ans = max( f[N & 1][B][1], f[N & 1][B][0] );
	memset( f, 0xf7, sizeof f );
	f[1][0][0] = 0, f[1][1][1] = U[1];
	fp( i, 2, N ){
		int c(i & 1), d((i + 1) & 1);
		fp( j, 0, B )
			f[c][j][0] = max( f[d][j][0], f[d][j][1] ),
			f[c][j][1] = j ? max( f[d][j - 1][1] + U[i], f[d][j - 1][0] ) : 0xf7f7f7f7;
	} cmax( ans, f[N & 1][B][1] ), printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

