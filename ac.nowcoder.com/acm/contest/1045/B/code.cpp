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
const int MAXN = 2e6;
int N, a[MAXN], q[MAXN], hd, tl, ans;

signed main(){
	t_bg = clock();
	read(N);
	fp( i, 1, N ) read(a[i]), a[i + N] = a[i];
	q[hd = tl = 1] = 1;
	fp( i, 2, N << 1 ){
		while( hd <= tl && ( ( i - q[hd] ) << 1 ) > N ) ++hd;
		cmax( ans, a[q[hd]] + a[i] + i - q[hd] );
		while( hd <= tl && a[i] - i >= a[q[tl]] - q[tl] ) --tl;
		q[++tl] = i;
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

