#include<bits/stdc++.h>
using namespace std;
#define MAXN 3005
#define MAXM 400555

int N, K;
int hd[MAXM], nxt[MAXM], to[MAXM], val[MAXM], fee[MAXM], tot(1);
int a[505][505];
int S, T;
queue<int> Q;
int dis[MAXM], pre[MAXM];
bool vis[MAXM];
int ans;

void Add( int x, int y, int z, int fe ){
	nxt[++tot] = hd[x]; hd[x] = tot; to[tot] = y; val[tot] = z; fee[tot] = fe;
	nxt[++tot] = hd[y]; hd[y] = tot; to[tot] = x; val[tot] = 0; fee[tot] = -fe;
}

bool SPFA(){
	for ( int i = 0; i <= T; ++i ) dis[i] = INT_MIN;
	memset( pre, 0, sizeof pre );
	memset( vis, 0, sizeof vis );
	Q.push(S); dis[S] = 0; vis[S] = 1;
	while( !Q.empty() ){ 
		int t(Q.front()); Q.pop(); vis[t] = 0;
		for ( int i = hd[t]; i; i = nxt[i] ){
			if ( val[i] && dis[to[i]] < dis[t] + fee[i] ){
				dis[to[i]] = dis[t] + fee[i]; pre[to[i]] = i;
				if ( !vis[to[i]] ) vis[to[i]] = 1, Q.push(to[i]);
			}
		}
	} 
	if ( dis[T] == INT_MIN ) return 0;
	int t(INT_MAX);
	for ( int i = T; i != S; i = to[pre[i] ^ 1] ) t = min( t, val[pre[i]] );
	for ( int i = T; i != S; i = to[pre[i] ^ 1] ) ans += t * fee[pre[i]], val[pre[i]] -= t, val[pre[i] ^ 1] += t;
	return 1;
}

#define GetID(x,y) ( (x) - 1 ) * N + y

int main(){
	scanf( "%d%d", &N, &K );
	for ( int i = 1; i <= N; ++i )
		for ( int j = 1; j <= N; ++j )
			scanf( "%d", &a[i][j] );
	S = 0; T = N * N * 2 + 1;
	for ( int i = 1; i <= N; ++i )
		for ( int j = 1; j <= N; ++j ){
			Add( GetID( i, j ), GetID( i, j ) + N * N, 1, a[i][j] );
			Add( GetID( i, j ), GetID( i, j ) + N * N, INT_MAX, 0 );
			
			if ( i < N ) Add( GetID( i, j ) + N * N, GetID( i + 1, j ), INT_MAX, 0 );
			if ( j < N ) Add( GetID( i, j ) + N * N, GetID( i, j + 1 ), INT_MAX, 0 );
		}
	Add( S, 1, K, 0 ); Add( N * N * 2, T, K, 0 );
	while( SPFA() );
	printf( "%d\n", ans );
	return 0;
}
