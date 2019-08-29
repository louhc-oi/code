#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#pragma GCC optimize("Ofast")
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

const int MAXN = 5e5 + 5;
int K, N, M; i64 T;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

bool check( int l, int m, int r ){
	if ( r > N ) return 0;
	fp( i, l, m ) c[i] = b[i];
	fp( i, m + 1, r ) c[i] = a[i];
	sort( c + m + 1, c + r + 1 );
	int i(l), j(m+1), k(l);
	while( i <= m && j <= r ) d[k++] = c[i] < c[j] ? c[i++] : c[j++];
	while( i <= m ) d[k++] = c[i++];
	while( j <= r ) d[k++] = c[j++];
	i64 s(0); int t(M); i = l, j = r;
	while( s <= T && i < j && t-- ) s += 1ll * (d[j] - d[i]) * (d[j] - d[i]), ++i, --j;
	if ( s <= T ) fp( i, l, r ) b[i] = d[i];
	return s <= T;
}

signed main(){
	read(K);
	while( K-- ){
		read(N), read(M), read(T);
		fp( i, 1, N ) read(a[i]);
		int x(1), y(1), ans(0), len(1); b[1] = a[1];
		while( x < N ){
			if ( !len ) ++ans, len = 1, x = ++y, b[x] = a[x];
			else if ( check(x, y, y + len) ) y += len, len <<= 1;
			else len >>= 1;
		} printf( "%d\n", ans + ( x == N ) );
	}
	return 0;
}

