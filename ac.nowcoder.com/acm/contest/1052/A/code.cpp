#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
const int MAXN = 2e5 + 5, mod = 1e9 + 7;
int H, W, N, n;
int fac[MAXN], inv[MAXN];
struct node{
	int x, y;
	bool operator < ( const node &t )const{ return x == t.x ? y < t.y : x < t.x; }
}a[2005]; int f[2005];
inline int Pow( int x, int y = mod - 2 ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % mod ) if ( y & 1 ) ans = 1ll * ans * x % mod; return ans; }
inline int C( int x, int y ){ return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod; }

signed main(){
	t_bg = clock();
	read(H), read(W), read(N), n = H + W, fac[0] = inv[0] = 1;
	fp( i, 1, n ) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = Pow(fac[n]); fd( i, n - 1, 1 ) inv[i] = 1ll * inv[i + 1] * ( i + 1 ) % mod;
	fp( i, 1, N ) read(a[i].x), read(a[i].y);
	sort( a + 1, a + N + 1 );
	a[0].x = 1, a[0].y = 1, a[N + 1].x = H, a[N + 1].y = W;
	f[0] = 1; fp( i, 1, N + 1 ){
		f[i] = C( a[i].x + a[i].y - 2, a[i].x - 1 );
		fp( j, 1, i - 1 ) if ( a[i].x >= a[j].x && a[i].y >= a[j].y )
			f[i] = ( f[i] - 1ll  * f[j] * C( a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x ) ) % mod;
	} printf( "%d\n", ( f[N + 1] + mod ) % mod );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

