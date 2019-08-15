#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;

const int s = (1 << 20) - 1;
int N, a[300005], f[1 << 20];

int query( int w, int x ){
	int ans(0);
	fd( i, 19, 0 ) if ( (x >> i) & 1 )
		if ( f[1 << i | ans] <= w ) ans |= 1 << i;
	return ans;
}

int main(){
	memset( f, 0x3f, sizeof f );
	read(N); fp( i, 1, N ) read(a[i]), a[i] ^= a[i - 1], cmin( f[a[i]], i );
	fp( i, 0, 19 ) fp( j, 0, s ) if ( !(j & (1 << i)) ) cmin( f[j], f[j ^ (1 << i)] );
	fp( i, 1, N ) printf( "%d\n", a[i] + ( query(i, a[i] ^ s) << 1 ) );
	return 0;
}
