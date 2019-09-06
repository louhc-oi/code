#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int K, B, X, Y, w[50], n, ans;
int f[50][50];

int calc( int x ){
	n = 0; while( x ) w[++n] = x % B, x /= B;
	int ans(0), c(0);
	fd( i, n, 1 ){
		if ( w[i] == 1 ){
			ans += f[i - 1][K - c];
			if ( ++c > K ) return ans;
		} else if ( w[i] > 1 )
			return ans += f[i][K - c];
	} return ans + ( c == K );
}

signed main(){
	t_bg = clock();
	scanf( "%d%d%d%d", &X, &Y, &K, &B );
	f[0][0] = 1;
	fp( i, 1, 30 ){
		f[i][0] = 1;
		fp( j, 1, 30 ) f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	} printf( "%d\n", calc(Y) - calc(X - 1) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

