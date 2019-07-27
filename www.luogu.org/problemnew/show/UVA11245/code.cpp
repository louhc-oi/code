#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
using namespace std;
#define MAXN 10005

struct vec{
	double x, y; vec(){}
	bool operator < ( const vec &t )const{ return x == t.x ? y < t.y : x < t.x; }
	vec( double a, double b ):x(a), y(b){}
	vec operator - ( const vec &t ){ return vec( x - t.x, y - t.y ); }
	double length(){ return sqrt( x * x + y * y ); } 
}a[MAXN]; int b[MAXN], c[MAXN];

int N;
bool cmp( int x, int y ){ return a[x].y < a[y].y; }

double work( int l, int r ){
	if ( l == r ) return 1e12;
	if ( l + 1 == r ) return a[l].y > a[r].y ? b[l]^=b[r]^=b[l]^=b[r] : 0, ( a[l] - a[r] ).length();
	int mid((l + r) >> 1), n(0); double d1, d2, d, m(a[mid].x);
	d = min( d1 = work( l, mid ), d2 = work( mid + 1, r ) );
	merge( b + l, b + mid + 1, b + mid + 1, b + r + 1, c, cmp );
	memcpy( b + l, c, ( r - l + 1 ) << 2 );
	for ( int i = l; i <= r; ++i ) if ( abs( a[b[i]].x - m ) <= d ) c[++n] = b[i];
	for ( int i = 1; i <= n; ++i ) for ( int j = i + 1; j <= n && a[c[j]].y - a[c[i]].y <= d; ++j )
		d = min( d, ( a[c[i]] - a[c[j]] ).length() );
	return d;
}

signed main(){
	while( ~scanf( "%d", &N ) && N ){
		for ( int i = 1; i <= N; ++i ) scanf( "%lf%lf", &a[i].x, &a[i].y ), b[i] = i;
		sort( a + 1, a + N + 1 );
		double d(work(1, N));
		if ( d < 1e4 ) printf( "%.4lf\n", d );
		else printf( "INFINITY\n" );
	}
	return 0;
}

