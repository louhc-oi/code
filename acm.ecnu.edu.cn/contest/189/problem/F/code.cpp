#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define p 998244353

int N, M;
int a[MAXN], b[MAXN], sa[MAXN], sb[MAXN];
int tgu[MAXN << 2], tgv[MAXN << 2], s[MAXN << 2];
inline int dec( int x ){ return x >= p ? x - p : x; }

#define ls c << 1
#define rs c << 1 | 1
inline int get( int w, int u, int v ){ return ( 1ll * a[w] * u + 1ll * b[w] * v ) % p; }
inline void tag( int c, int l, int r, int u, int v ){
	s[c] = ( s[c] + 1ll * sa[r - l + 1] * u + 1ll * sb[r - l + 1] * v ) % p,
	tgu[c] = dec( tgu[c] + u ), tgv[c] = dec( tgv[c] + v );
}
inline void pushdown( int c, int l, int r ){
	if ( tgu[c] || tgv[c] ){
		if ( r == l + 1 ) s[ls] = dec( s[ls] + tgu[c] ), s[rs] = dec( s[rs] + tgv[c] );
		else{ int mid((l + r) >> 1); tag( ls, l, mid, tgu[c], tgv[c] ),
			tag( rs, mid + 1, r, get( mid - l + 2, tgu[c], tgv[c] ), get( mid - l + 3, tgu[c], tgv[c] ) );
		} tgu[c] = tgv[c] = 0;
	}
}
int L, R, u, v;
void Add( int c, int l, int r ){
	if ( L <= l && r <= R ) return tag( c, l, r, get( l - L + 1, u, v ), get( l - L + 2, u, v ) );
	if ( l > R || L > r ) return;
	int mid((l + r) >> 1); pushdown(c, l, r),
	Add( ls, l, mid ), Add( rs, mid + 1, r ), s[c] = dec( s[ls] + s[rs] );
}
int Query( int c, int l, int r ){
	if ( L <= l && r <= R ) return s[c];
	if ( l > R || L > r ) return 0;
	int mid((l + r) >> 1); pushdown(c, l, r);
	return dec( Query( ls, l, mid ) + Query( rs, mid + 1, r ) );
}

int main(){
	scanf( "%d%d", &N, &M );
	a[1] = 1, b[2] = 1, sa[1] = sa[2] = 1, sb[2] = 1;
	for ( int i = 3; i <= N + 3; ++i )
		a[i] = dec( a[i - 1] + a[i - 2] ), b[i] = dec( b[i - 1] + b[i - 2] ),
		sa[i] = dec( a[i] + sa[i - 1] ), sb[i] = dec( b[i] + sb[i - 1] );
	while( M-- ){
		int opt; scanf( "%d", &opt );
		if ( opt == 1 ) scanf( "%d%d%d%d", &L, &R, &u, &v ), Add( 1, 1, N );
		else scanf( "%d%d", &L, &R ), L > R ? L^=R^=L^=R : L, printf( "%d\n", Query( 1, 1, N ) );
	}
	return 0;
}
