#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 500005

int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;

inline void addedge( int x, int y ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x;
}

int N, M, D, w[MAXN]; char v[MAXN];
int f[MAXN][25], g[MAXN][26];

inline void cmin( int &x, int y ){ x > y ? x = y : x; }

void DFS( int x, int fa ){
	if ( v[x] ) f[x][0] = g[x][0] = w[x];
	for ( int i = 1; i <= D; ++i ) g[x][i] = w[x];
	g[x][D + 1] = 0x3f3f3f3f;
	for ( int i = hd[x], y; i; i = nxt[i] ) if ( ( y = to[i] ) != fa ){
		DFS(y, x);
		for ( int j = D; j >= 0; --j ) g[x][j] += f[y][j], cmin( g[x][j], f[x][j + 1] + g[y][j + 1] );
		for ( int j = D; j >= 0; --j ) cmin( g[x][j], g[x][j + 1] );
		f[x][0] = g[x][0];
		for ( int j = 1; j <= D + 1; ++j ) f[x][j] += f[y][j - 1];
		for ( int j = 1; j <= D + 1; ++j ) cmin( f[x][j], f[x][j - 1] );
	}
}

int main(){
	scanf( "%d%d", &N, &D );
	for ( int i = 1; i <= N; ++i ) scanf( "%d", w + i );
	scanf( "%d", &M );
	for ( int i = 1, x; i <= M; ++i ) scanf( "%d", &x ), v[x] = 1;
	for ( int i = 1, x, y; i < N; ++i ) scanf( "%d%d", &x, &y ), addedge( x, y );
	DFS(1, 0), printf( "%d\n", g[1][0] );
	return 0;
}
