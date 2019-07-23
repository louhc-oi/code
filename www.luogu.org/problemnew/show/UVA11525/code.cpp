#include<bits/stdc++.h>
using namespace std;
#define MAXN 50005

int T, N, tr[MAXN << 2];

void Build( int c, int l, int r ){
	if ( l == r ) return tr[c] = 1, void();
	int mid((l + r) >> 1), ls(c << 1), rs(c << 1 | 1);
	Build( ls, l, mid ), Build( rs, mid + 1, r ),
	tr[c] = tr[ls] + tr[rs];
}

int Get( int c, int l, int r, int k ){
	--tr[c]; if ( l == r ) return l;
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( tr[ls] < k ) return Get( rs, mid + 1, r, k - tr[ls] );
	return Get( ls, l, mid, k );
}

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &N ), Build( 1, 1, N );
		for ( int i = 1, s; i <= N; ++i )
			scanf( "%d", &s ), printf( "%d%c", Get(1, 1, N, s + 1), "\n "[i < N] );
	} return 0;
}
