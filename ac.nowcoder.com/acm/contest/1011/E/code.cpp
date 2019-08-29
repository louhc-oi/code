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
#define pr pair<i64, int>
int N, K; i64 ans;
priority_queue<pr> Q;

signed main(){
	t_bg = clock();
	read(N), read(K); i64 x;
	fp( i, 1, N ) read(x), Q.push(make_pair(-x, 0));
	if ( ( N - 1 ) % ( K - 1 ) ) fp( i, 1, K - 1 - ( N - 1 ) % ( K - 1 ) ) Q.push(make_pair(0, 0));
	while( Q.size() > 1 ){
		i64 t(0); int d(0);
		fp( i, 1, K ) t += Q.top().first, cmin( d, Q.top().second ), Q.pop();
		Q.push(make_pair(t, d - 1)), ans -= t;
	} printf( "%lld\n%d\n", ans, -Q.top().second );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

