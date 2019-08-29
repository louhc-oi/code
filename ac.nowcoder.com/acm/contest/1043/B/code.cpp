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
const int MAXN = 105;
int N;
char s[MAXN];
int f1[MAXN][55], f2[MAXN][55];

signed main(){
	t_bg = clock();
	read(N);
	fp( i, 1, N ){
		char t(getchar()); while( t != 't' && t != 'x' ) t = getchar();
		read(f1[i][1]), f2[i][1] = f2[i + N][1] = f1[i + N][1] = f1[i][1], s[i] = s[i + N] = t;
	}
	fp( l, 2, N ){
		fp( i, 1, (N<<1) - l ){
			f1[i][l] = INT_MAX, f2[i][l] = INT_MIN;
			fp( k, 1, l - 1 ){
				if ( s[i + k] == 't' )
					cmin( f1[i][l], f1[i][k] + f1[i + k][l - k] ),
					cmax( f2[i][l], f2[i][k] + f2[i + k][l - k] );
				else{
					int a(f1[i][k] * f1[i + k][l - k]), b(f1[i][k] * f2[i + k][l - k]), c(f2[i][k] * f1[i + k][l - k]), d(f2[i][k] * f2[i + k][l - k]);
					cmin( f1[i][l], min( min( a, b ), min( c, d ) ) ),
					cmax( f2[i][l], max( max( a, b ), max( c, d ) ) );
				}
			}
		}
	} int ans(1);
	fp( i, 2, N ) if ( f2[i][N] > f2[ans][N] ) ans = i;
	printf( "%d\n", f2[ans][N] );
	fp( i, 1, N ) if ( f2[i][N] == f2[ans][N] ) printf( "%d ", i );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

