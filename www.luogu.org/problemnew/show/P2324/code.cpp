#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
using namespace std;

int T;
int mx;

int a[5][5] = {
	{ 1, 1, 1, 1, 1 },
	{ 0, 1, 1, 1, 1 },
	{ 0, 0, 2, 1, 1 },
	{ 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0 }
}, b[5][5], c[5][5];

const int d[][2] = { 1, 2, 2, 1, -1, 2, 2, -1, 1, -2, -2, 1, -1, -2, -2, -1 };

inline void swp( int &x, int &y ){ x^=y^=x^=y; }

bool check( int x, int y, int stp, int lx = -1, int ly = -1 ){
	int s(0);
	for ( int i = 0; i < 5; ++i )
		for ( int j = 0; j < 5; ++j )
			s += c[i][j] != b[i][j] && c[i][j] != 2;
	if ( stp < s ) return 0;
	if ( !s ) return 1;
	for ( int i = 0, tx, ty; i < 8; ++i ){
		tx = x + d[i][0], ty = y + d[i][1];
		if ( tx < 0 || ty < 0 || tx > 4 || ty > 4 || ( tx == lx && ty == ly ) ) continue;
		swp( c[x][y], c[tx][ty] );
		if ( check( tx, ty, stp - 1, x, y ) ) return 1; 
		swp( c[x][y], c[tx][ty] );
	} return 0;
}

signed main(){
	scanf( "%d", &T );
	while( T-- ){
		for ( int i = 0; i < 5; ++i )
			for ( int j = 0; j < 5; ++j ){
				while( ( b[i][j] = getchar() ) != '0' && b[i][j] != '1' && b[i][j] != '*' );
				b[i][j] = b[i][j] != '0' ? b[i][j] != '1' ? 2 : 1 : 0;
			}
		for ( mx = 0; mx <= 15; ++mx ){
			memcpy( c, a, 100 );
			if ( check( 2, 2, mx ) ){ printf( "%d\n", mx ); break; }
		}
		if ( mx > 15 ) printf( "-1\n" );
	}
	return 0;
}
