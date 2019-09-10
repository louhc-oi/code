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

const int MAXN = 100005;
struct node{
	i64 s1, s2, s3;
	node(){}; node( i64 x, i64 y, i64 z ):s1(x), s2(y), s3(z){}
	node operator + ( const node &t )const{ return node( s1 + t.s1, s2 + t.s2, s3 + t.s3 ); }
}tr[MAXN << 2];
i64 tg[MAXN << 2];
inline i64 sum1( int x ){ return 1ll * x * (x + 1) / 2; }
inline i64 sum2( int x ){ return 1ll * x * (x + 1) * (2 * x + 1) / 6; }

inline void tag( int c, int l, int r, int d ){
	tg[c] += d, tr[c].s1 += (i64)(r - l + 1) * d,
	tr[c].s2 += (sum1(r)-sum1(l - 1)) * d,
	tr[c].s3 += (sum2(r)-sum2(l - 1)) * d;
}
inline void pushdown( int c, int l, int r ){
	if ( tg[c] ){
		const int mid((l + r) >> 1);
		tag( c << 1, l, mid, tg[c] ),
		tag( c << 1 | 1, mid + 1, r, tg[c] ),
		tg[c] = 0;
	}
}
int L, R, d;
void Add( int c, int l, int r ){
	if ( l > R || L > r ) return;
	if ( L <= l && r <= R ) return tag(c, l, r, d);
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	pushdown(c, l, r), Add( ls, l, mid ),
	Add( rs, mid + 1, r ), tr[c] = tr[ls] + tr[rs];
}
node Get( int c, int l, int r ){
	if ( l > R || L > r ) return node(0, 0, 0);
	if ( L <= l && r <= R ) return tr[c];
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	pushdown(c, l, r);
	return Get( ls, l, mid ) + Get( rs, mid + 1, r );
} i64 gcd( i64 x, i64 y ){ return y ? gcd(y, x % y) : x; }

int N, M;

signed main(){
	read(N), read(M); --N;
	char opt; node t; i64 ans1, ans2, g;
	while( M-- ){
		while( (opt = getchar()) != 'C' && opt != 'Q' );
		if ( opt == 'C' ) read(L), read(R), --R, read(d), Add( 1, 1, N );
		else{
			read(L), read(R), --R;
			t = Get(1, 1, N);
			ans1 = t.s2 * (L + R) - t.s3 - t.s1 * (L - 1) * (R + 1);
			ans2 = 1ll * (R - L + 1) * (R - L + 2) / 2;
			g = gcd( ans1, ans2 );
			printf( "%lld/%lld\n", ans1 / g, ans2 / g );
		}
	}
	return 0;
}

