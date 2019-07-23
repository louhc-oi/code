#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 500005

int N, a[20];
LL f[MAXN], B1, B2;
bool vis[MAXN]; queue<int> Q;

void SPFA(){
	for ( int i = 1; i < a[N]; ++i ) f[i] = B2 + 1;
	Q.push(0); int t, c, i;
	while( !Q.empty() ){
		t = Q.front(); Q.pop(); vis[t] = 0;
		for ( i = 1; i < N; ++i ){
			c = ( t + a[i] ) % a[N];
			if ( f[c] > f[t] + a[i] ){ f[c] = f[t] + a[i]; if ( !vis[c] ) vis[c] = 1, Q.push(c); }
		}
	}
}

int main(){
	scanf( "%d%lld%lld", &N, &B1, &B2 ); B1--; 
	for ( int i = 1; i <= N; ++i ) scanf( "%d", &a[i] ); 
	SPFA(); LL ans(0);
	for ( int i = 0; i < a[N]; ++i ){
		if ( f[i] <= B2 ) ans += ( B2 - f[i] ) / a[N] + 1;
		if ( f[i] <= B1 ) ans -= ( B1 - f[i] ) / a[N] + 1;
	}
	printf( "%lld\n", ans );
	return 0;
} 
