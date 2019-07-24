#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005

int N;
int a[MAXN], b[MAXN], sa[MAXN], sb[MAXN];
int c[MAXN], tr[MAXN << 2];

void Build( int c, int l, int r ){
	if ( l == r ) return tr[c] = 1, void();
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Build( ls, l, mid ), Build( rs, mid + 1, r ), tr[c] = tr[ls] + tr[rs];
}
int Get( int c, int l, int r, int k ){
	--tr[c]; if ( l == r ) return l;
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( tr[ls] < k ) return Get( rs, mid + 1, r, k - tr[ls] );
	return Get( ls, l, mid, k );
}

int main(){
	scanf( "%d", &N );
	for ( int i = 1; i <= N; ++i ) scanf( "%d", a + i ), ++a[i];
	for ( int i = 1; i <= N; ++i ) scanf( "%d", b + i ), ++b[i];
	for ( int i = N; i >= 1; --i ){
		for ( int j = a[i]; j; j -= j & -j ) sa[i] += c[j];
		for ( int j = a[i]; j <= N; j += j & -j ) ++c[j];
	} memset( c, 0, sizeof c );
	for ( int i = N; i >= 1; --i ){
		for ( int j = b[i]; j; j -= j & -j ) sb[i] += c[j];
		for ( int j = b[i]; j <= N; j += j & -j ) ++c[j];
	}
	for ( int i = N, j = 1; i >= 1; --i, ++j ){
		sa[i] += sb[i];
		if ( sa[i] >= j ) sa[i] -= j, ++sa[i - 1];
	}
	Build( 1, 0, N - 1 );
	for ( int i = 1, j = N; i <= N; ++i, --j )
		printf( "%d ", Get( 1, 0, N - 1, sa[i] + 1 ) );
	return 0;
} 
