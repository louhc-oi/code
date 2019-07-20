#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define p 1000000009

int N, Q, a[MAXN], f[MAXN];
int s[MAXN << 2], tu[MAXN << 2], tv[MAXN << 2];
inline int dec( int x ){ return x >= p ? x - p : x; }
inline int rec( int x ){ return x < 0 ? x + p : x; }
inline int _( int w, int u, int v ){ return w > 1 ? ( 1ll * f[w - 2] * u + 1ll * f[w - 1] * v ) % p : u; }
inline int S( int w, int u, int v ){ return ( u + 1ll * ( f[w] + p - 1 ) * u + 1ll * ( f[w + 1] + p - 1 ) * v ) % p; }

int L, R;
#define ls c << 1
#define rs c << 1 | 1
inline void tag( int c, int l, int r, int u, int v ){
	tu[c] = dec( tu[c] + u ), tv[c] = dec( tv[c] + v ),
	s[c] = dec( s[c] + S(r - l + 1, u, v) );
}
inline void pushdown( int c, int l, int r ){
	if ( tu[c] || tv[c] ){
		int mid((l + r) >> 1); tag( ls, l, mid, tu[c], tv[c] ),
		tag( rs, mid + 1, r, _(mid - l + 2, tu[c], tv[c]), _(mid - l + 3, tu[c], tv[c]) ),
		tu[c] = tv[c] = 0;
	}
}
void Add( int c, int l, int r ){
	if ( l > R || L > r ) return;
	if ( L <= l && r <= R ) return tag( c, l, r, f[l - L + 1], f[l - L + 2] );
	int mid((l + r) >> 1); pushdown( c, l, r );
	Add( ls, l, mid ), Add( rs, mid + 1, r );
	s[c] = dec( s[ls] + s[rs] );
}
int Get( int c, int l, int r ){
	if ( l > R || L > r ) return 0;
	if ( L <= l  && r <= R ) return s[c];
	int mid((l + r) >> 1); pushdown( c, l, r );
	return dec( Get( ls, l, mid ) + Get( rs, mid + 1, r ) );
}

int main(){
	scanf( "%d%d", &N, &Q );
	for ( int i = 1; i <= N; ++i ) scanf( "%d", a + i ), a[i] = dec( a[i] + a[i - 1] );
	f[1] = f[2] = 1;
	for ( int i = 1; i <= N + 1; ++i ) f[i + 2] = dec( f[i] + f[i + 1] );
	while( Q-- ){
		int opt; scanf( "%d%d%d", &opt, &L, &R );
		(opt & 1) ? Add( 1, 1, N ), 1 : printf( "%d\n", dec( Get( 1, 1, N ) + rec( a[R] - a[L - 1] ) ) );
	}
	return 0;
}
