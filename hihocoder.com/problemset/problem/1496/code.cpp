#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
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
const int MAXN = 1 << 20;
int T, N; int a[MAXN], b[MAXN];

int main(){
	t_bg = clock();
	read(T);
	while( T-- ){
		memset( a, 0, sizeof a ), memset( b, 0, sizeof b ); i64 ans(0);
		read(N); int x; fp( i, 1, N ) read(x), (a[x] ? b[x] : a[x]) = x;
		fp( i, 0, 19 ) fp( j, 0, (1 << 20) - 1 )
			if ( !(j & (1 << i)) ){
				int t(j ^ (1 << i));
				if ( a[t] > a[j] ) b[j] = a[j], a[j] = a[t];
				else if ( a[t] > b[j] ) b[j] = a[t];
				cmax( b[j], b[t] );
			}
		fp( i, 0, (1 << 20) - 1 ) cmax( ans, 1ll * a[i] * b[i] * i );
		printf( "%lld\n", ans );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

