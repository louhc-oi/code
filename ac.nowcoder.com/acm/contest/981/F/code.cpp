#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;

int N, M, K;
struct mat{
	int a[21][21];
	mat operator * ( mat t ){
		mat r; memset( r.a, 0, sizeof r.a );
		fp( i, 0, M ) fp( k, 0, M ) fp( j, 0, M )
			r.a[i][j] = ( r.a[i][j] + 1ll * a[i][k] * t.a[k][j] ) % K;
		return r;
	}
}o, ans;
char s[25];
int p[25];

int main(){
	t_bg = clock();
	scanf( "%d%d%d", &N, &M, &K ), --M;
	if ( N < M ){
		int ans(1); fp( i, 1, N ) ans = ans * 10 % K;
		printf( "%d\n", ans ); return 0;
	}
	scanf( "%s", s ), p[0] = -1; int c = -1;
	fp( i, 1, M ){
		while( c >= 0 && s[c + 1] != s[i] ) c = p[c];
		if ( s[c + 1] == s[i] ) ++c;
		p[i] = c;
	}
	fp( i, 0, M ) fp( j, '0', '9' ){
		int c = i - 1;
		while( c >= 0 && s[c + 1] != j ) c = p[c];
		if ( s[c + 1] == j ) ++c;
		++o.a[i][c + 1];
	}
	ans.a[0][0] = 1;	
	for ( ; N; N >>= 1, o = o * o ) if ( N & 1 ) ans = ans * o;
	int res(0); fp( i, 0, M ) res = ( res + ans.a[0][i] ) % K; printf( "%d\n", res );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

