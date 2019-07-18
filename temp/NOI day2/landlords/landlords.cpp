#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )

int n, m, type, Q, a[500005], c[500005];
int bf_f[15], bf_r[15];

inline int Pow( int x, int y ){ int ans(1); for ( ; y; x = 1ll * x * x % p, y >>= 1 ) if ( y & 1 ) ans = 1ll * ans * x % p; return ans; }

#define f bf_f
#define r bf_r
int MID;
void bruteforce( int x, int y, int ps ){
	if ( x > MID && y > n ){
		for ( int i = 1; i <= n; ++i ) f[i] = ( f[i] + 1ll * r[i] * ps ) % p;
		return; 
	}
	int s1(MID - x + 1), s2(n - y + 1);
	if ( x <= MID ){
		r[x+y-MID-1] = x;
		bruteforce( x + 1, y, 1ll * ps * s1 % p * Pow( s1 + s2, p - 2 ) % p );
	}
	if ( y <= n ){
		r[x+y-MID-1] = y;
		bruteforce( x, y + 1, 1ll * ps * s2 % p * Pow( s1 + s2, p - 2 ) % p );
	}
}
#undef f
#undef r

int main(){
	open("landlords");
	scanf( "%d%d%d", &n, &m, &type );
	for ( int i = 1; i <= m; ++i ) scanf( "%d", a + i );
	scanf( "%d", &Q );
	for ( int i = 1; i <= Q; ++i ) scanf( "%d", c + i );
	MID = a[1], bruteforce(1, a[1] + 1, 1);
	for ( int i = 1; i <= Q; ++i ) printf( "%d\n", bf_f[c[i]] );
	return 0;
}
