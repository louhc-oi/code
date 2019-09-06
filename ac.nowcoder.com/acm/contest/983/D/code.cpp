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
int N, M, n, a[15], b[15];
int sg[1005], d[1005];

signed main(){
	t_bg = clock();
	read(N);
	fp( i, 1, N ) read(a[i]), cmax(n, a[i]);
	read(M);
	fp( i, 1, M ) read(b[i]);
	sg[0] = 0;
	fp( i, 1, n ){
		fp( j, 1, M ) if ( i >= b[j] )
			d[sg[i - b[j]]] = i;
		else break;
		fp( j, 0, M ) if ( d[j] != i ){ sg[i] = j; break; }
	} int ans(0);
	fp( i, 1, N ) ans ^= sg[a[i]];
	if ( ans ){
		printf("YES\n");
		for ( int i = 1; i <= N; ++i ){
			int t(ans ^ sg[a[i]]);
			fp( j, 1, M ) if ( a[i] >= b[j] && sg[a[i] - b[j]] == t )
				return printf( "%d %d\n", i, b[j] ), 0;
		}
	}else printf("NO\n");
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

