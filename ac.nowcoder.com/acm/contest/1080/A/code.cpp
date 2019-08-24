#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N; char s[1000];
bool v[256];

int main(){
	t_bg = clock();
	scanf( "%d", &N );
	scanf( "%s", s + 1 );
	fp( i, 1, N ){
		if ( s[i] == s[i - 1] || !v[s[i]] ){
			v[s[i]] = 1;
		} else return printf( "NO\n" ), 0;
	} printf( "YES\n" );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

