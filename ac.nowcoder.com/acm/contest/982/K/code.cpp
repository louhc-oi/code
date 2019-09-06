#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
const int P = 2333;
int T; i64 N, M;
int c[2433][2433], s[2433][2433];
inline int dec( int x ){ return x >= P ? x - P : x; }
int lucas( i64 n, i64 m ){
	if ( m == 0 ) return 1;
	if ( n < m ) return 0;
	if ( n < P && m < P ) return c[n][m];
	return lucas( n / P, m / P ) * c[n % P][m % P] % P;
}
inline int S( i64 n, i64 m ){
	cmin( m, n ); if ( n < P && m < P ) return s[n][m];
	return ( S(n / P, m / P - 1) * S(n % P, P - 1) + S(n % P, m % P) * lucas(n / P, m / P) ) % P;
}

signed main(){
	t_bg = clock();
	read(T);
	fp( i, 0, 2332 ){
		s[i][0] = c[i][0] = 1;
		fp( j, 1, i ) s[i][j] = dec( s[i][j - 1] + ( c[i][j] = dec( c[i - 1][j] + c[i - 1][j - 1] ) ) );
	} while( T-- ) read(N), read(M), printf( "%d\n", S( N, M ) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

