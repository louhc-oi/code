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
int T, N, Q;
i64 f[70]; int s[70];

signed main(){
	t_bg = clock();
	read(T);
	fp( Ti, 1, T ){
		read(N); i64 t; int c(0);
		memset( f, 0, sizeof f ), memset( s, 0, sizeof s );
		fp( i, 1, N ){
			read(t);
			fd( j, 62, 0 ) if ( ( t >> j ) & 1 ){
				if ( f[j] ) t ^= f[j]; else{ f[j] = t; break; }
			} if ( !t ) ++c;
		} fp( i, 0, 62 ){
			if ( f[i] ) ++s[i];
			s[i + 1] = s[i];
		}
		read(Q);
		printf( "Case #%d:\n", Ti );
		while( Q-- ){
			i64 k, ans(0), t;
			read(k);
			fd( i, 62, 0 )if ( f[i] ){
				if ( i ) t = 1 << min( s[i - 1] + c, 62 ); else t = 1 << min( c, 62 );
				if ( k > t ) k -= t, ans ^= f[i];
			} printf( "%lld\n", k > 1 ? -1 : ans );
		}
	}
	
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

