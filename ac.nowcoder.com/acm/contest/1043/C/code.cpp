#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

const int MAXN = 305, mod = 1e9;
int N, f[MAXN][MAXN];
char s[MAXN];

int solve( int l, int r ){
	if ( l == r ) return 1;
	if ( l > r || s[l] != s[r] ) return 0;
	if ( f[l][r] >= 0 ) return f[l][r];
	f[l][r] = 0;
	fp( i, l + 2, r ) if ( s[i] == s[l] )
		f[l][r] = ( f[l][r] + 1ll * solve(l + 1, i - 1) * solve(i, r) ) % mod;
	return f[l][r];
}

signed main(){
	scanf( "%s", s + 1 );
	N = strlen( s + 1 ), memset( f, -1, sizeof f );
	printf( "%d\n", solve( 1, N ) );
	return 0;
}

