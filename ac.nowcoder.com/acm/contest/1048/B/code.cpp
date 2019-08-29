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
int T, N, M, n;
const int MAXN = 1005, mod = 1e9 + 7;
int a[MAXN], b[MAXN], c[MAXN];
int f[2][MAXN];
inline int dec( int x ){ return x >= mod ? x - mod : x; }
inline void Add( int x, int y ){ for ( ; x <= n; x += x & -x ) c[x] = dec( c[x] + y ); }
inline int Get( int x ){ int ans(0); for ( ; x; x -= x & -x ) ans = dec( ans + c[x] ); return ans; }

signed main(){
	t_bg = clock();
	read(T);
	fp( Ti, 1, T ){
		read(N), read(M);
		fp( i, 1, N ) read(a[i]), b[i] = a[i];
		sort( b + 1, b + N + 1 ), n = unique( b + 1, b + N + 1 ) - b - 1;
		fp( i, 1, N ) a[i] = lower_bound( b + 1, b + n + 1, a[i] ) - b;
		int t(0); fp( i, 1, N ) f[0][i] = 1;
		fp( i, 2, M ){
			t ^= 1, memset( c, 0, sizeof c );
			fp( j, 1, N ) f[t][j] = Get(a[j] - 1), Add(a[j], f[t ^ 1][j] );
		} int ans(0); fp( i, 1, N ) ans = dec( f[t][i] + ans );
		printf( "Case #%d: %d\n", Ti, ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

