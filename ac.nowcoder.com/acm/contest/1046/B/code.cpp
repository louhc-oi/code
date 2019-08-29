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

int N, M, c[105];
int s[88], d[88], n;
int f[105][88][88];

void print( int x ){
	fp( i, 0, M - 1 ) printf( "%d", (x >> i) & 1 );
	puts("");
}

signed main(){
	t_bg = clock();
	read(N), read(M);
	fp( i, 1, N ) fp( j, 1, M ){
		char t; while( (t = getchar()) != 'P' && t != 'H' );
		c[i] = c[i] << 1 | ( t == 'H' );
	}
	fp( i, 0, (1 << M) - 1 ){
		bool flg(0); int x(0);
		fp( j, 0, M - 1 ){
			if ( ((i>>j)&1) && (((i>>(j+1))&1) || ((i>>(j+2))&1)) ) flg = 1;
			if ( (i>>j) & 1 ) ++x;
		} if ( !flg ) s[++n] = i, d[n] = x;
	}
	fp( t, 1, N ) fp( i, 1, n ) fp( j, 1, n ) fp( k, 1, n ){
		if ( ( s[i] & s[j] ) || ( s[j] & s[k] ) || ( s[i] & s[k] ) || ( s[i] & c[t] ) || ( s[j] & c[t - 1] ) || ( s[k] & c[max(0, t - 2)] ) ) continue;
		cmax( f[t][i][j], f[t - 1][j][k] + d[i] );
	} int ans(0); fp( i, 1, n ) fp( j, 1, n ) cmax( ans, f[N][i][j] );
	printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

