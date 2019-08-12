#include<bits/stdc++.h>
using namespace std;
#define MAXN 4111
#define MAXM 31111
#define int long long

int N, S, T, ans, nd[MAXN];
int p, m, f, n, s;
int hd[MAXN], nxt[MAXM], val[MAXM], to[MAXM], c[MAXM], tot(1);
int d[MAXN]; queue<int> Q;
bool vis[MAXN];
int pre[MAXN];

void Add( int x, int y, int z, int cs ){
	nxt[++tot] = hd[x]; hd[x] = tot; to[tot] = y; val[tot] = z; c[tot] = cs;
	nxt[++tot] = hd[y]; hd[y] = tot; to[tot] = x; val[tot] = 0; c[tot] = -cs;
}

bool SPFA(){
	while( !Q.empty() ) Q.pop();
	memset( d, 0x3f, sizeof d ), memset( vis, 0, sizeof vis ), memset( pre, 0, sizeof pre );
	d[S] = 0; Q.push(S); vis[S] = 1;
	while( !Q.empty() ){
		int t(Q.front()); Q.pop(); vis[t] = 0;
		for ( int i = hd[t]; i; i = nxt[i] ){
			if ( val[i] && d[to[i]] > d[t] + c[i] ){
				d[to[i]] = d[t] + c[i]; pre[to[i]] = i;
				if ( !vis[to[i]] ) vis[to[i]] = 1, Q.push( to[i] );
			}
		}
	}
	if ( d[T] >= 0x3f3f3f3f3f3f3f3f ) return 0;
	int fl(LONG_LONG_MAX);
	for ( int i = T; i != S; i = to[pre[i] ^ 1] ) fl = min( fl, val[pre[i]] );
	for ( int i = T; i != S; i = to[pre[i] ^ 1] ) val[pre[i]] -= fl, val[pre[i] ^ 1] += fl;
	ans += fl * d[T];
	return 1;
}

signed main(){
	scanf( "%lld", &N );
	S = 0; T = N + N + 1;
	for ( int i = 1; i <= N; ++i ) scanf( "%lld", &nd[i] ), Add( i, T, nd[i], 0 );
	scanf( "%lld%lld%lld%lld%lld", &p, &m, &f, &n, &s );
	for ( int i = 1; i <= N; ++i ){
		Add( S, i, LONG_LONG_MAX, p );
		if ( i < N ) Add( i, i + 1, LONG_LONG_MAX, 0 );
		if ( i + m <= N || i + n <= N ) Add( S, i + N, nd[i], 0 );
		if ( i + m <= N ) Add( i + N, i + m, LONG_LONG_MAX, f );
		if ( i + n <= N ) Add( i + N, i + n, LONG_LONG_MAX, s );
	}
	while( SPFA() );
	printf( "%lld\n", ans );
	return 0;
}
