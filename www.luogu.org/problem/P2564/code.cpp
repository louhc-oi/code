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
int N, K, m;
const int MAXN = 1e6 + 5;
struct node{
	int c, x;
	bool operator < ( const node &t )const{ return x < t.x; }
}a[MAXN];
int v[77], q[MAXN], hd, tl, s;

signed main(){
	t_bg = clock();
	read(N), read(K), N = 0;
	fp( i, 1, K ){
		read(m); fp( j, 1, m ) read(a[++N].x), a[N].c = i;
	} sort( a + 1, a + N + 1 ), hd = 1; int ans = INT_MAX;
	fp( i, 1, N ){
		q[++tl] = i, s += ( ++v[a[i].c] == 1 );
		while( hd <= tl && v[a[q[hd]].c] > 1 ) --v[a[q[hd++]].c];
		if ( s >= K ) cmin( ans, a[i].x - a[q[hd]].x );
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

