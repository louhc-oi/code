#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int f[15][15], w[15], n;
int calc( int x ){
	if ( !x ) return 0;
	n = 0; while( x ) w[++n] = x % 10, x /= 10;
	int ans(0), c(88); fd( i, n - 1, 1 ) fp( j, 1, 9 ) ans += f[i][j];
	fd( i, n, 1 ){
		fp( j, i == n, w[i] - 1 ){
			if ( abs(j - c) > 1 ){
				ans += f[i][j];
			}
		} if ( abs(w[i] - c) > 1 ) c = w[i]; else return ans;
	} return ans + 1;
}

signed main(){
	t_bg = clock();
	fp( i, 0, 9 ) f[1][i] = 1;
	fp( i, 2, 10 ) fp( j, 0, 9 ){
		fp( k, 0, j - 2 ) f[i][j] += f[i - 1][k];
		fp( k, j + 2, 9 ) f[i][j] += f[i - 1][k];
	} int x, y; scanf( "%d%d", &x, &y ), printf( "%d\n", calc(y) - calc(x - 1) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

