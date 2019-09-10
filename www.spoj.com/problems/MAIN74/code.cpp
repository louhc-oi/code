#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mod 1000000007

struct matrix{
	LL a[2][2];
	matrix operator * ( matrix t ){
		matrix ans;
		memset( ans.a, 0, sizeof ans.a );
		for ( int i = 0; i < 2; ++i )
			for ( int k = 0; k < 2; ++k )
				for ( int j = 0; j < 2; ++j )
					ans.a[i][j] = ( ans.a[i][j] + a[i][k] * t.a[k][j] ) % mod;
		return ans;
	}
}cur, t;

int T;
LL N;

int main(){
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%lld", &N );
		if ( !N ){ printf("0\n"); continue; }
		if ( N == 1 ){ printf("2\n"); continue; }
		t.a[0][0] = t.a[1][0] = t.a[0][1] = 1, t.a[1][1] = 0;
		cur.a[0][0] = cur.a[0][1] = 1, cur.a[1][0] = cur.a[1][1] = 0;
		for ( LL i = N + 1; i; i >>= 1 ){
			if ( i & 1 ) cur = cur * t;
			t = t * t;
		} printf( "%lld\n", cur.a[0][0] );
	}
	return 0;
}
