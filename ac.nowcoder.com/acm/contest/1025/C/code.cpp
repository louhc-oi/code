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
const int mod = 1007;
struct node{
	int c; double a[505];
	bool operator < ( const node &t )const{ return c < t.c; }
}z[505]; int a[505];
int N, M, ans1, ans2;

signed main(){
	t_bg = clock();
	read(N), read(M); int t;
	fp( i, 1, N ) fp( j, 1, M ) read(t), z[i].a[j] = t;
	fp( i, 1, N ) read(z[i].c);
	sort( z + 1, z + N + 1 );
	
	fp( i, 1, N ){
		fp( j, 1, M ) if ( abs(z[i].a[j]) > 1e-5 ){
			if ( a[j] ){
				double t(z[i].a[j]);
				fp( k, j, M ) z[i].a[k] -= t * z[a[j]].a[k];
			}else{
				double t(1. / z[i].a[j]); a[j] = i;
				fp( k, j, M ) z[i].a[k] *= t;
				++ans1, ans2 += z[i].c; break;
			}
		}
	} printf( "%d %d\n", ans1, ans2 );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

