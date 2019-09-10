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
int T, N;
const int MAXN = 2e4 + 5;
struct node{
	i64 a, b;
	bool operator < ( const node &t )const{
		if ( (a < b) != (t.a < t.b) ) return (a < b) > (t.a < t.b);
		return a < b ? a < t.a : b > t.b;
	}
}a[MAXN];

signed main(){
	t_bg = clock();
	read(T);
	while( T-- ){
		read(N);
		fp( i, 1, N ) read(a[i].a), read(a[i].b);
		sort( a + 1, a + N + 1 );
		fp( i, 1, N )
			a[i].a += a[i - 1].a,
			a[i].b += max( a[i - 1].b, a[i].a );
		printf( "%lld\n", a[N].b );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

