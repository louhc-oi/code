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
const int MAXN = 2005;
int T, P, W, AP[MAXN], BP[MAXN], AS[MAXN], BS[MAXN];
i64 f[MAXN][MAXN]; int q[MAXN], hd, tl;
#define g f[c]

signed main(){
	t_bg = clock();
	read(T), read(P), read(W), W = - W - 1;
	fp( i, 1, T ) read(AP[i]), read(BP[i]), read(AS[i]), read(BS[i]);
	memset( f[0], 0xf7, sizeof f[0] ), f[0][0] = 0;
	fp( t, 1, T ){
		const int c = max( ++W, 0 );
		fp( i, 0, P ) f[t][i] = f[t - 1][i];
		hd = 1, tl = 0;
		if ( AS[t] ) fp ( i, 0, P ){
			while( hd <= tl && q[hd] < i - AS[t] ) ++hd;
			if ( hd <= tl ) cmax( f[t][i], g[q[hd]] + ( q[hd] - i ) * AP[t] );
			while( hd <= tl && g[q[tl]] + q[tl] * AP[t] < g[i] + i * AP[t] ) --tl;
			q[++tl] = i;
		} hd = 1, tl = 0;
		if ( BS[t] ) fd( i, P, 0 ){
			while( hd <= tl && q[hd] > i + BS[t] ) ++hd;
			if ( hd <= tl ) cmax( f[t][i], g[q[hd]] + ( q[hd] - i ) * BP[t] );
			while( hd <= tl && g[q[tl]] + q[tl] * BP[t] < g[i] + i * BP[t] ) --tl;
			q[++tl] = i;
		}
	} printf( "%lld\n", f[T][0] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

