#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005

int N, M;
int f[MAXN], s[MAXN];
int T[MAXN], L[MAXN * 80], R[MAXN * 80], v_f[MAXN * 80], v_s[MAXN * 80], tot;
int X(MAXN * 80 - 1);

int Modify( int pre, int c, int l, int r, int x ){
	if ( l == r ) return v_f[c] = v_f[pre], v_s[c] = v_s[pre], c;
	int mid((l + r) >> 1);
	if ( x <= mid ) return R[c] = R[pre], Modify( L[pre], L[c] = ++tot, l, mid, x );
	return L[c] = L[pre], Modify( R[pre], R[c] = ++tot, mid + 1, r, x );
}

int Get( int c, int l, int r, int x ){
	if ( l == r ) return c;
	int mid( ( l + r ) >> 1);
	if ( x <= mid ) return Get( L[c], l, mid, x );
	return Get( R[c], mid + 1, r, x );
}

int find( int c, int x ){
	int fa(v_f[Get( c, 1, N, x )]);
	return fa == x ? x : find( c, fa );
}

void Merge( int pre, int c, int x, int y ){
	int sx(v_s[Get( pre, 1, N, x )]), sy(v_s[Get( pre, 1, N, y )]);
	if ( sx > sy ) swap( x, y ), swap( sx, sy );
	L[X] = R[X] = 0;
	v_f[Modify( pre, X, 1, N, x )] = y;
	v_s[Modify( X, c, 1, N, y )] = sx + sy;
}

void Build( int c, int l, int r ){
	if ( l == r ){ v_f[c] = f[l], v_s[c] = s[l]; return; }
	int mid((l + r) >> 1); Build( L[c] = ++tot, l, mid ); Build( R[c] = ++tot, mid + 1, r );
}

int main(){
	scanf( "%d%d", &N, &M );
	for ( int i = 1; i <= N; ++i ) f[i] = i, s[i] = 1;
	Build( T[0] = ++tot, 1, N );
	int last_ans(0);
	for ( int i = 1; i <= M; ++i ){
		int op, x, y;
		scanf( "%d%d", &op, &x );
		if ( op == 1 ){
			scanf( "%d", &y );
			x = find( T[i - 1], x ^ last_ans ); y = find( T[i - 1], y ^ last_ans );
			if ( x == y ){ T[i] = T[i - 1]; continue; }
			Merge( T[i - 1], T[i] = ++tot, x, y );
		}
		if ( op == 2 ) T[i] = T[x ^ last_ans];
		if ( op == 3 ) scanf( "%d", &y ), T[i] = T[i - 1], printf( find( T[i], x ^ last_ans ) == find( T[i], y ^ last_ans ) ? "1\n" : "0\n" );
	}
	return 0;
}
