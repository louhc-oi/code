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
int N, T;
const int MAXN = 50115;
struct node{
	int l, r;
	bool operator < ( const node &t )const{ return r < t.r; }
}p[MAXN>>1];
int b[MAXN];

int tr[MAXN<<2], n;
void Update( int c ){ for ( c >>= 1; c; c >>= 1 ) tr[c] = min( tr[c << 1], tr[c << 1 | 1] ); }
int Get( int l, int r ){
	int ans(INT_MAX);
	for ( l += n - 1, r += n + 1; l ^ r ^ 1; l >>= 1, r >>= 1 ){
		if ( ~l & 1 ) cmin( ans, tr[l ^ 1] );
		if ( r & 1 ) cmin( ans, tr[r ^ 1] );
	} return ans;
}


signed main(){
	t_bg = clock();
	read(N), read(T), b[1] = T, b[2] = 0, T = 2;
	fp( i, 1, N ){
		read(p[i].l), read(p[i].r), cmin( p[i].r, b[1] ), --p[i].l;
		if ( p[i].l >= p[i].r ) --N, --i;
		else b[++T] = p[i].l, b[++T] = p[i].r;
	} sort( b + 1, b + T + 1 ), T = unique( b + 1, b + T + 1 ) - b - 1;
	for ( n = 2; n - 2 < T; n <<= 1 );
	memset( tr, 0x3f, sizeof tr ), tr[n + 1] = 0;
	sort( p + 1, p + N + 1 );
	fp( i, 1, N ){
		int l, r, t;
		l = lower_bound( b + 1, b + T + 1, p[i].l ) - b;
		r = lower_bound( b + 1, b + T + 1, p[i].r ) - b;
		t = Get( l, r - 1 ) + 1; if ( t < tr[r += n] ) tr[r] = t, Update(r);
	} printf( "%d\n", tr[T + n] > N ? -1 : tr[T + n] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

