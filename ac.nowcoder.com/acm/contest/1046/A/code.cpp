#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;

int H, W;
i64 f[15][2222]; i64 ans[12][12];
bool g[2222];
void Calc( int W ){
	f[0][0] = 1;
	fp( i, 0, (1<<W)-1 ){
		bool a(0), b(0);
		fp( j, 0, W - 1 ) if ( (i>>j) & 1 ) a |= b, b = 0; else b ^= 1;
		g[i] = !(a | b);
	}
	fp( i, 1, 11 ) fp( j, 0, (1<<W)-1 ){
		f[i][j] = 0;
		fp( k, 0, (1<<W)-1 ) if ( !(k & j) && g[j | k] ) f[i][j] += f[i - 1][k];
	}
	fp( i, 1, 11 ) ans[i][W] = f[i][0];
}

signed main(){
	t_bg = clock();
	fp( i, 1, 11 ) Calc(i);
	while( ~scanf( "%d%d", &W, &H ) && W && H ) printf( "%lld\n", ans[W][H] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

