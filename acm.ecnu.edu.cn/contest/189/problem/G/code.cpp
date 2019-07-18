#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 1000005
#define MAXM 2000005

int N, M, K, r[MAXN];
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot;
inline void addedge( int x, int y, int z ){ nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z; }

int main(){
	scanf( "%d%d%d", &N, &M, &K );
	for ( int i = 1, x, y, z; i <= M; ++i )
		scanf( "%d%d%d", &x, &y, &z ),
		addedge( x, y, z ), addedge( y, x, z );
	
	return 0;
}

