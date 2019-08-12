#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define i64 long long
#define INF 0x7f7f7f7f
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

int N, M, P, n, m;
int a[MAXN], b[MAXN<<1];
int l, r, mid, ans;

inline int Abs( int x ){
	return x < 0 ? -x : x;
}

bool v[MAXN<<1];
inline bool check( int d ){
	memset( v, 0, sizeof v );
	int i(1), j(n), p(1);
	while( i <= j ){
		while( p <= m && ( v[p] || Abs(a[i] - b[p]) + Abs(P - b[p]) > d ) ) ++p;
		if ( p > m ) break; else v[p] = 1;
		++i;
	} p = M;
	while( i <= j ){
		while( p > m && ( v[p] || Abs(a[j] - b[p]) + Abs(P - b[p]) > d ) ) --p;
		if ( p <= m ) return 0; else v[p] = 1;
		--j;
	}

	i = n + 1, j = N, p = 1;
	while( i <= j ){
		while( p <= m && ( v[p] || Abs(a[i] - b[p]) + Abs(P - b[p]) > d ) ) ++p;
		if ( p > m ) break; else v[p] = 1;
		++i;
	} p = M;
	while( i <= j ){
		while( p > m && ( v[p] || Abs(a[j] - b[p]) + Abs(P - b[p]) > d ) ) --p;
		if ( p <= m ) return 0; else v[p] = 1;
		--j;
	} return 1;
}

int main(){
	// open("key");
	t_bg = clock();
	read(N), read(M), read(P);
	fp( i, 1, N ) read(a[i]), cmax( l, Abs(P - a[i]) );
	fp( i, 1, M ) read(b[i]);
	sort( a + 1, a + N + 1 ), sort( b + 1, b + M + 1 );
	n = lower_bound( a + 1, a + N + 1, P ) - a; if ( a[n] != P ) --n;
	m = lower_bound( b + 1, b + M + 1, P ) - b; if ( b[m] != P ) --m;
	r = 2e9; while( l <= r ) check(mid = ((i64)l + (i64)r) >> 1) ? r = (ans = mid) - 1 : l = mid + 1;
	printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
