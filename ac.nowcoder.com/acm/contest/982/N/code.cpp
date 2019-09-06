#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;

int N, NN, P, ans(1);
const int MAXN = 2e6 + 5;
int s[MAXN], p[MAXN]; bool vis[MAXN];
inline int Pow( int x, int y ){ int ans(1); for ( ; y; y >>= 1, x = 1ll * x * x % P ) if ( y & 1 ) ans = 1ll * ans * x % P; return ans; }

signed main(){
	t_bg = clock();
	scanf( "%d%d", &N, &P ), NN = N << 1;
	fp( i, N + 2, NN ) ++s[i];
	fp( i, 2, N ) --s[i];
	fp( i, 2, NN ) if ( !vis[i] ){
		for ( int j = i + i; j <= NN; j += i )
			vis[j] = 1, p[j] = i;
	}
	fd ( i, NN, 2 ){
		if ( !vis[i] ) ans = 1ll * ans * Pow( i, s[i] ) % P;
		else s[i / p[i]] += s[i], s[p[i]] += s[i];
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

