#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 100005
#define MAXM 200005
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;
int N, M, S, T;
int hd[MAXN], nxt[MAXM], to[MAXM], v1[MAXM], v2[MAXM], tot;
i64 ans[MAXN], d1[MAXN], d2[MAXN]; bool vis[MAXN];
priority_queue<pair<i64, int> > Q;
inline void addedge( int x, int y, int z1, int z2 ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, v1[tot] = z1, v2[tot] = z2;
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, v1[tot] = z1, v2[tot] = z2;
}
void Dij( int S, i64 *d, int *val ){
	memset( vis, 0, sizeof vis );
	memset( d, 0x3f, (N+1) << 3 );
	d[S] = 0, Q.push(make_pair(0, S));
	while( !Q.empty() ){
		int u(Q.top().second); Q.pop();
		if ( vis[u] ) continue;
		vis[u] = 1;
		go( i, hd[u] ) if ( d[v] > d[u] + val[i] ){
			d[v] = d[u] + val[i]; Q.push(make_pair(-d[v], v));
		}
	}
}

int main(){
	t_bg = clock();
	read(N), read(M); int x, y, z1, z2;
	fp( i, 1, M ) read(x), read(y), read(z1), read(z2), addedge( x, y, z1, z2 );
	read(S), read(T);
	Dij( S, d1, v1 ), Dij( T, d2, v2 ), ans[N + 1] = LONG_LONG_MAX;
	fd( i, N, 1 ) ans[i] = min( ans[i + 1], d1[i] + d2[i] );
	fp( i, 1, N ) printf( "%lld\n", ans[i] );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

