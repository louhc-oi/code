#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 250005
#define MAXK 10
#define i64 long long
#define INF 0x3f3f3f3f3f3f3f3fll
#define rgt register

int N, K; i64 w[MAXN];
i64 f[MAXN][MAXK][MAXK][4];
inline void cmin( i64 &x, i64 y ){ x > y ? x = y : 0; }

int main(){
	scanf( "%d%d", &N, &K );
	for ( int i = 1; i <= N; ++i ) scanf( "%I64d", w + i );
	memset( f, 0x3f, sizeof f ), f[0][0][0][1] = 0;
	for ( rgt int i = 0; i < N; ++i )
		for ( rgt int j = 0; j <= K; ++j )
			for ( rgt int k = 0; k <= K; ++k )
				for ( rgt int x = 0; x < 3; ++x )if( f[i][j][k][x] < INF ){
					const i64 &r = f[i][j][k][x];
					cmin(f[i+1][j][k][0], r+w[i+1]);
					if ( k != K ) cmin(f[i+1][j][k+1][0], r);
					if ( x < 2 ){
						cmin(f[i+1][j][k][x+1], r);
						if ( j != K ) cmin( f[i+1][j+1][k][x+1], r+w[i+1] );
					}
				}
	rgt i64 ans(INF);
	for ( rgt int i = 0; i <= K; ++i )
		for ( rgt int j = 0; j < 2; ++j )
			cmin( ans, f[N][i][i][j] );
	printf( "%lld\n", ans );
	return 0;
}
