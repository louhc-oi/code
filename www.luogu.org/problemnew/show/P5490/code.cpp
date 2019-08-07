#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define i64 long long
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

int T, N, NN, n;
int a[MAXN << 1], b[MAXN << 1]; i64 ans;
struct node{
	int x, u, d, v;
	bool operator < ( const node &t )const{ return x < t.x; }
}q[MAXN << 1];

int tr[MAXN << 3]; int s[MAXN << 3];

void Add( int c, int l, int r, int L, int R, int v ){
	if ( L > r || l > R ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( L <= l && r <= R ) return tr[c] = !(s[c] += v) ? l == r ? 0 : tr[ls] + tr[rs] : ( b[r + 1] - b[l] ), void();
	Add( ls, l, mid, L, R, v ), Add( rs, mid + 1, r, L, R, v );
	!s[c] ? tr[c] = tr[ls] + tr[rs] : 0;
}

signed main(){
	t_bg = clock();
	read(N); NN = N << 1;
	for ( int i = 0; i < NN; i += 2 )
		read(q[i].x), read(a[i]), read(q[i + 1].x), read(a[i + 1]),
		b[i] = a[i], b[i + 1] = a[i + 1], q[i].v = 1, q[i + 1].v = -1;
	sort( b, b + NN ), n = unique( b, b + NN ) - b;	
	for ( int i = 0, t1, t2; i < NN; i += 2 )
		t1 = lower_bound( b, b + n, a[i] ) - b, q[i].d = q[i+1].d = t1,
		t2 = lower_bound( b, b + n, a[i+1] ) - b, q[i].u = q[i+1].u = t2;
	sort( q, q + NN ), Add(1, 0, n - 2, q[0].d, q[0].u - 1, q[0].v);
	
	fp( i, 1, NN - 1 )
		ans += 1ll * tr[1] * ( q[i].x - q[i - 1].x ),
		Add( 1, 0, n - 2, q[i].d, q[i].u - 1, q[i].v );
	printf( "%lld\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
