#include<bits/stdc++.h>
using namespace std;
#define mod 10000
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

int N;

struct mat{
	int a[2][2];
	mat operator * ( mat t ){
		mat r; memset( r.a, 0, 16 );
		fp( i, 0, 1 ) fp( k, 0, 1 ) fp( j, 0, 1 ) r.a[i][j] = ( r.a[i][j] + 1ll * a[i][k] * t.a[k][j] ) % mod;
		return r;
	}
}o[55], t;

int main(){
	t_bg = clock();
	o[0].a[0][0] = o[0].a[1][0] = o[0].a[0][1] = 1;
	fp( i, 1, 31 ) o[i] = o[i - 1] * o[i - 1];
	while( (read(N), N >= 0) ){
		if ( N <= 1 ){
			printf( "%d\n", N ); continue;
		}
		t.a[0][0] = t.a[0][1] = 1, N -= 2;
		fp( i, 0, 31 ) if ( ( N >> i ) & 1 ) t = t * o[i];
		printf( "%d\n", t.a[0][0] );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

