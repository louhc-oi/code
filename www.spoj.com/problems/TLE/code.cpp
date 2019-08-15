#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 1000000000
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;

int T, N, M, c, s;
int f[2][1<<15], cr, lt;
inline int dec( int x ){ return x >= mod ? x - mod : x; }

int main(){
	t_bg = clock();
	read(T);
	while( T-- ){
		read(N), read(M), cr = 0, lt = 1, s = (1 << M) - 1;
		read(c); fp( i, 0, s ) if ( i % c ) f[cr][i] = 1; else f[cr][i] = 0;
		fp( i, 2, N ){
			swap( cr, lt ); read(c);
			fp( j, 0, s ) f[cr][j] = f[lt][j^s];
			fp( j, 0, M - 1 ) fp( k, 0, s ) if (!(k & (1 << j))) f[cr][k] = dec(f[cr][k] + f[cr][k ^ (1 << j)]);
			fp( j, 0, s / c ) f[cr][c * j] = 0;
		} int ans(0); fp( i, 0, s ) ans = dec( ans + f[cr][i] );
		printf( "%d\n", ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
