#include<bits/stdc++.h>
using namespace std;
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp(i, b, e) for ( int i(b), I(e); i <= I; ++i )
#define fd(i, b, e) for ( int i(b), I(e); i >= I; --i )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ x > y ? x = y : x; }
//#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf, p1 == p2 ) ? EOF : *p1++ )
//char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T> void read( T &x ){ x = 0; char t(getchar()), flg(0);
	for ( ; t > '9' || t < '0'; t = getchar() ) flg = t == '-';
	for ( ; t <= '9' && t >= '0'; t = getchar() ) x = x * 10 + (t & 15);
	flg ? x = -x : x;
}

const int MAXN = 405;
int N, K;
int a[MAXN];
int f[MAXN][MAXN];

int main(){
	read(N), read(K), ++K;
	fp( i, 1, N ) read(a[i;
	memset( f, 0x3f, sizeof f ),
	memset( f[0], 0, sizeof f[0] );
	fp( i, 1, N ) fp( j, 1, K ){
		int mx(a[i]), s(a[i]);
		fd( k, i - 1, 0 ){
			cmin( f[i][j], f[k][j - 1] + mx * ( i - k ) - s ),
			cmax( mx, a[k] ), s += a[k];
		}
	} printf( "%d\n", f[N][K] );
	return 0;
}
