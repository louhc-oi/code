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
int N, M, A, B, C, D;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int q[MAXN], hd, tl;

int Get( int x, int y, int xx, int yy ){
	return a[xx][yy] - a[x][yy] - a[xx][y] + a[x][y];
}

signed main(){
	t_bg = clock();
	read(N), read(M), read(A), read(B), read(C), read(D);
	fp( i, 1, N ) fp( j, 1, M )
		read(a[i][j]), a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
	fp( i, 0, N - C ) fp( j, 0, M - D )
		b[i+1][j+1] = Get( i, j, i + C, j + D );
	
	int t;
	fp( i, 1, N ){
		hd = 1, tl = 0;
		fp( j, 1, B - D - 1 ){
			while( hd <= tl && b[i][j] <= b[i][q[tl]] ) --tl;
			q[++tl] = j;
		} fp( j, 1, M - B + 1 ){
			while( hd <= tl && q[hd] <= j ) ++hd;
			t = j + B - D - 1;
			while( hd <= tl && b[i][t] <= b[i][q[tl]] ) --tl;
			q[++tl] = t, c[i][j] = b[i][q[hd]];
		}
	}
	
	int ans(0);
	fp( j, 1, M - B + 1 ){
		hd = 1, tl = 0;
		fp( i, 1, A - C - 1 ){
			while( hd <= tl && c[i][j] <= c[q[tl]][j] ) --tl;
			q[++tl] = i;
		}
		fp( i, 1, N - A + 1 ){
			while( hd <= tl && q[hd] <= i ) ++hd;
			t = i + A - C - 1;
			while( hd <= tl && c[t][j] <= c[q[tl]][j] ) --tl;
			q[++tl] = t, cmax( ans, Get(i-1,j-1,i+A-1,j+B-1) - c[q[hd]][j] );
		}
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

