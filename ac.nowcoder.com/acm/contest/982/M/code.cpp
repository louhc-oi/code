#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int N, M;
int a[1000005], na, b[1000005], nb;
int s[10005];

void Mul( int *a, int &n, int x ){
	fp( i, 1, n ) a[i] *= x;
	fp( i, 1, n ){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	} while( a[n + 1] ) ++n, a[n + 1] += a[n] / 10, a[n] %= 10; 
}

void C( int *a, int &n, int x, int y ){
	memset( s, 0, sizeof s );
	fp( i, y + 1, x ) ++s[i];
	fp( i, 1, x - y ) --s[i];
	fd( i, x, 2 ){
		int t(i);
		for ( int j = 2; j * j <= t; ++j )
			while( t % j == 0 ) s[j] += s[i], t /= j;
		if ( t == i ) while( s[i]-- ) Mul( a, n, i );
		else if ( t > 1 ) s[t] += s[i];
	}
}

int main(){
	t_bg = clock();
	scanf( "%d%d", &N, &M );
	a[na = 1] = b[nb = 1] = 1;
	C( a, na, N + M, M );
	C( b, nb, N + M, M - 1 );
	fp( i, 1, na ){
		a[i] -= b[i];
		if ( a[i] < 0 ) a[i] += 10, --a[i + 1]; 
	} while( !a[na] ) --na;
	fd( i, na, 1 ) printf( "%d", a[i] ); printf("\n");
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

