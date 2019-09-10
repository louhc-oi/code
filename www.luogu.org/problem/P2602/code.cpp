#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

i64 a, b, s[15], p[15];
int w[15], n;

signed main(){
	scanf( "%lld%lld", &a, &b ), --a, p[0] = 1;
	fp( i, 1, 13 ) p[i] = p[i - 1] * 10;
	n = 0; while( b ) w[++n] = b % 10, b /= 10;
	fp( i, 1, n ){
		fp( j, i == n, w[i] - 1 ){
			s[j] += p[i - 1]; fp( k, 0, 9 ) s[k] += p[i - 1] * (i - 1) / 10;
		} s[w[i]] += b + 1, b = b + w[i] * p[i - 1];
	}
	fp( i, 1, n - 1 ) fp( j, 1, 9 ){
		s[j] += p[i - 1]; fp( k, 0, 9 ) s[k] += p[i - 1] * (i - 1) / 10;
	}
	
	n = 0; while( a ) w[++n] = a % 10, a /= 10;
	fp( i, 1, n ){
		fp( j, i == n, w[i] - 1 ){
			s[j] -= p[i - 1]; fp( k, 0, 9 ) s[k] -= p[i - 1] * (i - 1) / 10;
		} s[w[i]] -= a + 1, a = a + w[i] * p[i - 1];
	}
	fp( i, 1, n - 1 ) fp( j, 1, 9 ){
		s[j] -= p[i - 1]; fp( k, 0, 9 ) s[k] -= p[i - 1] * (i - 1) / 10;
	}
	
	fp( i, 0, 9 ) printf( "%lld ", s[i] );
	return 0;
}
