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
const int MAXN = 1e3 + 5;
int T, N, a[MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];

signed main(){
	t_bg = clock();
	read(T);
	while( T-- ){
		read(N);
		fp( i, 1, N ) read(a[i]), L[i][i] = R[i][i] = a[i];
		fp( len, 2, N ) fp( i, 1, N - len + 1 ){
			int j = i + len - 1, l, r, x;
			l = L[i][j - 1], r = R[i][j - 1], x = a[j];
			if ( x == r ) L[i][j] = 0;
			else if ( ( x < l && x < r ) || ( x > l && x > r ) ) L[i][j] = x;
			else if ( l <= x && x < r ) L[i][j] = x + 1;
			else L[i][j] = x - 1;
			l = L[i + 1][j], r = R[i + 1][j], x = a[i];
			if ( l == x ) R[i][j] = 0;
			else if ( ( x < l && x < r ) || ( x > l && x > r ) ) R[i][j] = x;
			else if ( r <= x && x < l ) R[i][j] = x + 1;
			else R[i][j] = x - 1;
		} printf( a[1] == L[2][N] ? "0\n" : "1\n" );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

