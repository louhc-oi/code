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
const int MAXN = 1e4 + 5;
int K, M, N;
int s[105], d[MAXN], sg[MAXN], x;

signed main(){
	t_bg = clock();
	while( ( read(K), K ) ){
		fp( i, 1, K ) read(s[i]);
		memset( d, 0, sizeof d );
		fp( i, 1, 1e4 ){
			fp( j, 1, K ) if ( s[j] <= i ) d[sg[i - s[j]]] = i;
			fp( j, 0, K ) if ( d[j] != i ){ sg[i] = j; break; }
		} read(M);
		while( M-- ){
			read(N); int ans(0);
			fp( i, 1, N ) read(x), ans ^= sg[x];
			putchar(ans ? 'W' : 'L');
		} putchar('\n');
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

