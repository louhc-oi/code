#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

int N;
const int MAXN = 55;
double ans(1), a[MAXN][MAXN], b[MAXN][MAXN];

signed main(){
	scanf( "%d", &N );
	fp( i, 1, N ) fp( j, 1, N ){
		scanf( "%lf", &a[i][j] );
		if ( fabs(1 - a[i][j]) < 1e-7 ) a[i][j] -= 1e-7;
		if ( i < j ){
			double t(a[i][j]/(1 - a[i][j]));
			b[i][j] = b[j][i] = -t, b[i][i] += t, b[j][j] += t, ans *= 1 - a[i][j];
		}
	} --N;
	fp( i, 1, N ){
		int w(-1);
		fp( j, i, N ) if ( fabs(b[i][i]) > 1e-8 ){ w = j; break; }
		if ( w < 0 ) return printf("0\n"), 0;
		if ( w != i ) fp( j, i, N ) swap(b[i][j], b[w][j]);
		fp( j, i + 1, N ) b[i][j] /= b[i][i]; 
		ans *= b[i][i], b[i][i] = 1;
		fp( j, i + 1, N ) fp( k, i + 1, N )
			b[j][k] -= b[j][i] * b[i][k];
	} printf( "%lf\n", fabs(ans) );
	return 0;
}

