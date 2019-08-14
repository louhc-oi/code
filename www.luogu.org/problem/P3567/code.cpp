#include<bits/stdc++.h>
using namespace std;
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

int N, M, x;

#define MAXN 500000 * 30
struct node{
	int ls, rs, s;
}t[MAXN]; int tot;
int rt[500005];
void Ins( int c, int b, int x, int l, int r ){
	t[c] = t[b], ++t[c].s;
	if ( l == r ) return;
	int mid((l + r) >> 1);
	if ( x <= mid ) Ins( t[c].ls = ++tot, t[b].ls, x, l, mid );
	else Ins( t[c].rs = ++tot, t[b].rs, x, mid + 1, r );
}
int Get( int c, int b, int k, int l, int r ){
	if ( l == r ) return t[c].s > k ? l : 0;
	int mid((l + r) >> 1);
	if ( t[t[c].ls].s - t[t[b].ls].s > k ) return Get( t[c].ls, t[b].ls, k, l, mid );
	if ( t[t[c].rs].s - t[t[b].rs].s > k ) return Get( t[c].rs, t[b].rs, k, mid + 1, r );
	return 0;
}

signed main(){
	t_bg = clock();
	read(N), read(M);
	fp( i, 1, N ) read(x), Ins(rt[i] = ++tot, rt[i - 1], x, 1, N);
	while( M-- ){
		int l, r; read(l), read(r),
		printf( "%d\n", Get(rt[r], rt[l - 1], ( r - l + 1 ) >> 1, 1, N) );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
