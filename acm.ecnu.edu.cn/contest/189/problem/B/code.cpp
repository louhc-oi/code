#include<bits/stdc++.h>
using namespace std;

int N, M, Q, c[500005];
int mx, s, n;
long long all;

long long gcd( long long x, long long y ){
	while( y ) x %= y, x^=y^=x^=y;
	return x;
}

struct node{
	int x, w;node(){} node( int _x, int _w ):x(_x), w(_w){}
	bool operator < ( const node &t )const{ return x < t.x; }
}a[500005];
inline void cmax( int &x, int y ){ x < y ? x = y : 0; }

int main(){
	scanf( "%d%d", &N, &M );
	for ( int i = 1, s, t; i <= N; ++i ) scanf( "%d%d", &s, &t ), a[++n] = node(s, 1), a[++n] = node(t + 1, -1);
	sort( a + 1, a + n + 1 );
	for ( int i = 1, s(0); i <= n; ++i ){
		s += a[i].w;
		while( a[i + 1].x == a[i].x ) s += a[++i].w;
		cmax( mx, s ), all += 1ll * ( a[i + 1].x - a[i].x ) * s;
	} scanf( "%d", &Q );
	if ( Q & 1 ) printf( "%d\n", mx );
	if ( Q & 2 ) mx = gcd( all, M ), printf( "%lld/%lld\n", all / mx, M / mx );
	return 0;
}
