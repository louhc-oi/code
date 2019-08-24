#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
#define MAXN 9999
#define MAXM 999999

int N, M, Ti;
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot(1);
int d[MAXN]; queue<int> Q;
int S, T;

char bf[1<<21], *p;
int read( int len = INT_MAX ){
	int ans(0);
	while( !isdigit(*p) ){
		p++; if ( *p == '\0' ) return -12345;
	}
	while( isdigit(*p) && len-- ) ans = ans * 10 + ((*p) ^ '0'), p++;
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

int main(){
	#ifdef LOCAL
	freopen( "1.in", "r", stdin );
	#endif
	memset( bf, 0, sizeof bf );
	bf[fread( bf, 1, 1 << 21, stdin )] = '\0'; p = bf;
	
	while( ( N = read() ) >= 0 ){
		M = read();
		memset( hd, 0, sizeof hd ); tot = 1;
		for ( int i = 1; i <= N; ++i ) Add( i, i + N, 1 );
		
		for ( int i = 1; i <= M; ++i ){
			int x, y; x = read() + 1; y = read() + 1;
			Add( x + N, y, INT_MAX ), Add( y + N, x, INT_MAX );
		}
		int res(N);
		for ( int i = 1; i <= N; ++i )
			for ( int j = i + 1; j <= N; ++j ){
				
				for ( int k = 2; k <= tot; k += 2 ) val[k] += val[k ^ 1], val[k ^ 1] = 0;
				S = i + N; T = j;
				
				bool flg(0);
				for ( int k = hd[S]; k; k = nxt[k] )
					if ( to[k] == T ){
						flg = 1; break;
					}
				if ( flg ) continue;
				
				int cur(0), t;
				while( BFS() ) while( ( t = DFS( S, N ) ) ) cur += t;
				
				res = min( res, cur );
			}
		printf( "%d\n", res );
	}
	return 0;
}
