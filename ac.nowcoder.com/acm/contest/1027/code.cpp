#include<bits/stdc++.h>
using namespace std;
#define MAXN 50000

int T;
int mu[MAXN + 5], p[MAXN + 5], tot;
bool v[MAXN + 5];

int Work( int N, int M ){ int ans(0); if ( N > M ) swap( N, M );
	for ( int i = 1, j; i <= N; i = j + 1 ){
		j = min( N / ( N / i ), M / ( M / i ) );
		ans += ( N / i ) * ( M / i ) * ( mu[j] - mu[i - 1] );
	} return ans;
}

int main(){
	scanf( "%d", &T ); mu[1] = 1;
	for ( int i = 2; i <= MAXN; ++i ){
		if ( !v[i] ) p[++tot] = i, mu[i] = -1;
		for ( int j = 1; j <= tot && i * p[j] <= MAXN; ++j ){
			v[i * p[j]] = 1; mu[i * p[j]] = i % p[j] ? -mu[i] : 0;
			if ( i % p[j] == 0 ) break;
		}
	}
	for ( int i = 1; i <= MAXN; ++i ) mu[i] += mu[i - 1];
	while( T-- ){
		int a, b, d;
		scanf( "%d%d%d", &a, &b, &d ); a /= d; b /= d;
		printf( "%d\n", Work( a, b ) );
	}
	return 0;
}
