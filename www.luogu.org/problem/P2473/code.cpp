#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int K, N, S, p[105], s[105];
double f[105][1<<15];

signed main(){
	scanf( "%d%d", &K, &N ), S = (1 << N) - 1;
	fp( i, 0, N - 1 ){
		int x; scanf( "%d", p + i );
		while( (scanf("%d", &x), x) )
			s[i] |= 1 << (x - 1);
	}
	fd( i, K, 1 ) fp( j, 0, S ){
		fp( k, 0, N - 1 ) if ( ( s[k] & j ) == s[k] )
			f[i][j] += max( f[i + 1][j], f[i + 1][j | 1 << k] + p[k] );
		else f[i][j] += f[i + 1][j];
		f[i][j] /= N;
	} printf( "%.6lf\n", f[1][0] );
	return 0;
}

