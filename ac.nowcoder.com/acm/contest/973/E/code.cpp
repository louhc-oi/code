#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N, M;
int f[10][10][10];
int w[15], n;

int calc( int x ){
	n = 0; while( x ) w[++n] = x % 10, x /= 10;
	w[n + 1] = 0; int ans(0);
	fd( i, n, 1 ){
		fp( j, 0, w[i] - 1 ) ans += f[i][j][w[i + 1]];
		if ( ( w[i + 1] == 6 && w[i] == 2 ) || w[i] == 4 ) return ans;
	} return ans + 1;
}

signed main(){
	t_bg = clock();
	fp( i, 0, 9 ) fp( j, 0, 9 ) if ( i != 4 && j != 4 && ( i != 2 || j != 6 ) ) f[1][i][j] = 1;
	fp( i, 2, 8 ) fp( j, 0, 9 ) fp( k, 0, 9 )
		if ( j != 4 && k != 4 && ( j != 2 || k != 6 ) )
			fp( t, 0, 9 ) f[i][j][k] += f[i - 1][t][j];
	int x, y; while( ~scanf( "%d%d", &x, &y ) && ( x || y ) ) printf( "%d\n", calc(y) - calc(x - 1) );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

