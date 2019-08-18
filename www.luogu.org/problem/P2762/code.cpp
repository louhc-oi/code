#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXM 50005

int M, N;
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot(1);
int d[MAXN]; queue<int> Q;
int S, T;
bool vs[MAXN];

char bf[1<<21], *p;
int read(){
	int ans(0);
	while( !isdigit(*p) ) p++;
	while( isdigit(*p) ) ans = ans * 10 + ((*p) ^ '0'), p++;
	return ans;
}

void Add( int x, int y, int z ){
	nxt[++tot] = hd[x]; hd[x] = tot; to[tot] = y; val[tot] = z;
	nxt[++tot] = hd[y]; hd[y] = tot; to[tot] = x; val[tot] = 0;
}

bool BFS(){
	while( !Q.empty() ) Q.pop();
	memset( d, 0, sizeof d );
	Q.push( S ); d[S] = 1;
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		for ( int i = hd[t]; i; i = nxt[i] ){
			if ( val[i] && !d[to[i]] ){
				Q.push(to[i]); d[to[i]] = d[t] + 1;
				if ( to[i] == T ) return 1;
			}
		}
	}
	return 0;
}

int DFS( int x, int fl ){
	if ( x == T ) return fl;
	int res(fl), k;
	for ( int i = hd[x]; i && res; i = nxt[i] ){
		if ( val[i] && d[to[i]] == d[x] + 1 ){
			k = DFS( to[i], min( val[i], res ) );
			if ( !k ) d[to[i]] = 0;
			res -= k; val[i] -= k; val[i ^ 1] += k;
		}
	}
	return fl - res;
}

void print(){
	for ( int i = S; i <= T; ++i )
	    for ( int j = hd[i]; j; j = nxt[j] )
	        if ( j % 2 == 0 ) printf( "%d %d %d\n", i, to[j], val[j] );
}

int main(){
	bf[fread( bf, 1, 1 << 21, stdin )] = '\0', p = bf;
	
	M = read(); N = read();
	S = 0; T = 1 + N + M;
	int k, ans(0);
	
	for ( int i = 1; i <= M; ++i ){
		int s, t;
		s = read(); Add( S, i + N, s ); ans += s;
		while ( (*p) != '\n' && (*p) != '\r' ) t = read(), Add( i + N, t, INT_MAX );
	}
	for ( int i = 1; i <= N; ++i ) k = read(), Add( i, T, k );
	
	while( BFS() ) while( ( k = DFS( S, INT_MAX ) ) ) ans -= k;
	
	for ( int i = 1; i <= M; ++i )
		if ( d[i + N] ){
			printf( "%d ", i );
			for ( int j = hd[i + N]; j; j = nxt[j] ) vs[to[j]] = 1;
		}
	
	putchar('\n');
	
	for ( int i = 1; i <= N; ++i )
		if ( vs[i] ) printf( "%d ", i );
	
	printf( "\n%d\n", ans );
	return 0;
}
