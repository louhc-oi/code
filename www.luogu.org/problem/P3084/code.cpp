#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int a, b;

signed main(){
	scanf( "%d%d", &a, &b ); if ( a > b ) swap( a, b );
	printf( (int)((b - a) * (1 + sqrt(5)) / 2) == a ? "0\n" : "1\n" ); 
	return 0;
}

