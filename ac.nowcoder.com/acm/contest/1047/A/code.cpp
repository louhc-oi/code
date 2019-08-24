#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf ) == p2 ? EOF : *p1++ )
using namespace std;
#define MAXN 100005

char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t, flg(0);
	for ( t = getchar(); !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 ); x = flg ? -x : x;
}

clock_t __t_bg, __t_ed;
int N, H[MAXN], b[MAXN], lp[MAXN], rp[MAXN], w[MAXN], mn1[MAXN], mn2[MAXN];
int fa[MAXN][20], fb[MAXN][20], f[MAXN][20];
inline int Abs( int x ){ return x < 0 ? -x : x; }
inline int dis( int x, int y ){ return y <= N ? Abs( b[H[x]] - b[H[y]] ) : 0x3f3f3f3f; }

void Get( int s, int x, int &sa, int &sb ){
	sa = sb = 0;
	for ( rgt int i = 17; i >= 0; --i )
		if ( fa[s][i] < 1e9 && fb[s][i] < 1e9 && sa + sb + fa[s][i] + fb[s][i] <= x )
			sa += fa[s][i], sb += fb[s][i], s = f[s][i];
	if ( fa[s][0] + sa + sb <= x ) sa += fa[s][0];
}

signed main(){
	__t_bg = clock(); read(N);
	for ( rgt int i = 1; i <= N; ++i ) read(H[i]), b[i] = H[i];
	sort( b + 1, b + N + 1 ), lp[N + 1] = N, b[N + 1] = INT_MAX >> 1, mn1[N + 1] = mn2[N + 1] = rp[N + 1] = H[N + 1] = w[N + 1] = N + 1;
	for ( rgt int i = 1; i <= N; ++i ) w[H[i] = lower_bound( b + 1, b + N + 1, H[i] ) - b] = i, lp[i] = i - 1, rp[i] = i + 1;
	for ( rgt int i = 1, h; i <= N; ++i ){
		h = H[i];
		if ( lp[h] && b[h] - b[lp[h]] <= b[rp[h]] - b[h] ) mn1[i] = w[lp[h]], mn2[i] = lp[lp[h]] && b[h] - b[lp[lp[h]]] <= b[rp[h]] - b[h] ? w[lp[lp[h]]] : w[rp[h]];
		else mn1[i] = w[rp[h]], mn2[i] = lp[h] && b[h] - b[lp[h]] <= b[rp[rp[h]]] - b[h] ? w[lp[h]] : w[rp[rp[h]]];
		rp[lp[h]] = rp[h], lp[rp[h]] = lp[h];
	} memset( fa, 0x3f, sizeof fa ), memset( fb, 0x3f, sizeof fb );
	for ( rgt int i = 1; i <= N; ++i ) for ( rgt int j = 0; j <= 17; ++j ) f[i][j] = N + 1;
	for ( rgt int i = N; i >= 1; --i ){
		fa[i][0] = dis( i, mn2[i] ), fb[i][0] = dis( mn2[i], mn1[mn2[i]] ), f[i][0] = mn1[mn2[i]];
		for ( rgt int j = 1; 1; ++j ){
			if ( f[i][j - 1] > N ) break;
			fa[i][j] = fa[i][j - 1] + fa[f[i][j - 1]][j - 1],
			fb[i][j] = fb[i][j - 1] + fb[f[i][j - 1]][j - 1],
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	rgt int M, s, x, sa, sb, ans(1), ta(1e9), tb(1); read(x);
	for ( rgt int i = 1; i < N; ++i ){
		Get( i, x, sa, sb );
		if ( sa && sb && ( 1ll * sa * tb < 1ll * ta * sb || ( H[i] > H[ans] && 1ll * sa * tb == 1ll * ta * sb ) ) ) ans = i, ta = sa, tb = sb;
	} printf( "%d\n", ans ), read(M);
	while( M-- ) read(s), read(x), Get( s, x, sa, sb ), printf( "%d %d\n", sa, sb );
	__t_ed = clock(), fprintf( stderr, "time: %.5lfs\n", double( __t_ed - __t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
