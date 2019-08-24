#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;

int N, M, P;
i64 a[133][133], b[133][133], c[133][133];

int main(){
	t_bg = clock();
	read(N), read(M); fp( i, 1, N ) fp( j, 1, M ) read(a[i][j]); 
	read(P); fp( i, 1, M ) fp( j, 1, P ) read(b[i][j]);
	fp( i, 1, N ) fp( j, 1, M ) fp( k, 1, P ) c[i][k] += a[i][j] * b[j][k];
	fp( i, 1, N ) fp( j, 1, P ) printf( "%lld%c", c[i][j], " \n"[j == P] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

