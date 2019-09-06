#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N, c1, c2;
i64 ans1, ans2;

signed main(){
	t_bg = clock();
	while( ~scanf( "%d", &N ) ){
		ans1 = ans2 = 1, c1 = 0;
		for ( int i = 2; i * i <= N; ++i ){
			c2 = 0;
			while( N % i == 0 ) ans1 *= ++c1, ans2 *= ++c2, N /= i;
		} if ( N > 1 ) ans1 *= ++c1;
		printf( "%d %lld\n", c1, ans1 / ans2 );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

