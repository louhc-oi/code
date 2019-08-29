#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;
int N, M, K, a[16][16];
int f[16][16][16][230][2][2];

signed main(){
	t_bg = clock();
	read(N), read(M), read(K);
	fp( i, 1, N ){
		fp( j, 1, M ) read(a[i][j]);
		a[i][j] += a[i][j - 1];
	}
	fp( t, 1, N ) fp( l, 1, M ) fp( r, l, M ){
		int h(r - l + 1), s(a[t][r] - a[t][l - 1]);
		f[t][l][r][h][0][0] = f[t][l][r][h][0][1] = f[t][l][r][h][1][0] = f[t][l][r][h][1][1] = s;
		fp( i, 1, M ) fp( j, i, M ) fp( k, h, K ){
			if ( )
		}
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

