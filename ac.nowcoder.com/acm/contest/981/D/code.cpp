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

int N, M;

struct mat{
	int a[2][2];
	mat operator * ( mat t ){
		mat r; memset( r.a, 0, 16 );
		fp( i, 0, 1 ) fp( k, 0, 1 ) fp( j, 0, 1 ) r.a[i][j] = ( r.a[i][j] + 1ll * a[i][k] * t.a[k][j] ) % M;
		return r;
	}
}o, t;

int main(){
	t_bg = clock();
	read(N), read(M);
	t.a[0][0] = t.a[0][1] = 1;
	o.a[0][0] = o.a[1][0] = o.a[0][1] = 1;
	for ( int i = N + 1; i; i >>= 1, o = o * o ) if ( i & 1 ) t = t * o;
	printf( "%lld\n", ( 1ll * N * t.a[0][1] + M - t.a[0][0] + 2 ) % M );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

