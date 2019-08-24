#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 100005
#define mod 998244353
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N; char str[MAXN];
int s[MAXN], f[MAXN];
inline int dec( int x ){
	return x >= mod ? x - mod : x;
}

int main(){
	t_bg = clock();
	scanf( "%d", &N );
	scanf( "%s", str + 1 );
	fp( i, 1, N ) s[i] = ( s[i - 1] + (str[i] & 15) ) % 3;
	f[0] = 1; int sum(0);
	fp( i, 1, N ){
		if ( !s[i] ) f[i] = dec( sum + f[i - 1] );
		if ( str[i] != '0' ) sum = dec( sum + f[i - 1] );
	}
	printf( "%d\n", f[N] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

