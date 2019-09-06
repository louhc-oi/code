#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
int S;
int p[50005], tot; bool vis[50005];
int a[500005], cnt;

bool isprime( int x ){
	if ( x == 1 ) return 0;
	if ( x <= 44721 ) return !vis[x];
	for ( int i = 1; i <= tot && p[i] * p[i] <= x; ++i ) if ( x % p[i] == 0 ) return 0;
	return 1;
}

void DFS( int c, int w, int r ){
	if ( c == 1 ) return a[++cnt] = r, void();
	if ( c - 1 >= p[w] && isprime(c - 1) ) a[++cnt] = r * (c - 1);
	for ( ; 1 + ( p[w] + 1 ) * p[w] <= c; ++w ){
		i64 x(1 + p[w]), y(p[w]);
		for ( ; x <= c; y *= p[w], x += y ) if ( c % x == 0 )
			DFS( c / x, w + 1, r * y );
	}
}

signed main(){
	t_bg = clock();
	fp( i, 2, 44721 ){
		if ( !vis[i] ) p[++tot] = i;
		for ( int j = 1; j <= tot && p[j] * i <= 44721; ++j ){
			vis[i * p[j]] = 1;
			if ( i % p[j] == 0 ) break;
		}
	}
	
	while( ~scanf( "%d", &S ) ){
		cnt = 0, DFS( S, 1, 1 );
		sort( a + 1, a + cnt + 1 ), printf( "%d\n", cnt );
		fp( i, 1, cnt ) printf( "%d%c", a[i], "\n "[i < cnt] );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

