#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define rgt register
#define pi 3.1415926535898
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

int N, n, m;
int r[1<<22];

struct Complex{
	double r, i; inline Complex( double x = 1e-9, double y = 1e-9 ):r(x), i(y){}
	inline Complex operator + ( Complex t ){ return Complex( r + t.r, i + t.i ); }
	inline Complex operator - ( Complex t ){ return Complex( r - t.r, i - t.i ); }
	inline Complex operator * ( Complex t ){ return Complex( r * t.r - i * t.i, r * t.i + i * t.r ); }
}A[1<<22], B[1<<22];

//c[N + k] = \sigma a[i] * b[N + k - i]

void FFT( Complex *A, int on ){
	fp( i, 0, n - 1 ) if ( i > r[i] ) swap( A[i], A[r[i]] );
	for ( int l = 2; l <= n; l <<= 1 ){
		Complex o(cos(2 * pi / l), sin(on * 2 * pi / l)), c, x, y;
		for ( int i = 0; i < n; i += l ){
			c = Complex(1, 0);
			fp( j, i, j + (l >> 1) - 1 )
				x = A[j], y = A[j + (l >> 1)] * c,
				A[j] = x + y, A[j + (l >> 1)] = x - y, c = c * o;
		}
	} if ( on < 0 ) fp( i, 0, n - 1 ) A[i].r /= n;
}

int main(){
	t_bg = clock();
	read(N); int x;
	fp( i, 0, N - 1 ) read(x), A[i].r = x, read(x), B[N - i].r = x;
	for ( n = 1, m = 0; n < (N << 1); n <<= 1, ++m );
	fp( i, 0, n - 1 ) r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << (m - 1) );
	FFT(A, 1), FFT(B, 1);
	fp( i, 0, n - 1 ) A[i] = A[i] * B[i];
	FFT(A, -1);
	fp( i, N, (N<<1) - 1 ) printf( "%d\n", (int)( A[i].r + .5 ) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

