#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
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
int N, K, ans;
int hd[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot(1);

inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z;
}

int w, mx, l[MAXN];
void DFS( int u, int d ){
	if ( l[u] && d > mx ) mx = d, w = u;
	go( i, hd[u] ) if ( i != l[u] ) l[v] = i ^ 1, DFS(v, d + val[i]);
}

int DP( int u, int fa ){
	int mx1(0), mx2(0), t;
	go( i, hd[u] ) if ( v != fa ){
		t = DP( v, u ) + val[i];
		if ( t > mx1 ) mx2 = mx1, mx1 = t;
		else cmax( mx2, t );
	} cmax( mx, mx1 + mx2 ); return mx1;
}

int main(){
	t_bg = clock();
	read(N), read(K), ans = K + ( (N - 1) << 1 ); int x, y;
	fp( i, 2, N ) read(x), read(y), addedge( x, y, 1 ), addedge( y, x, 1 );
	l[1] = 0, DFS(1, 0), mx = -1e9, l[w] = 0, DFS(w, 0), ans -= mx, mx = -1e9;
	if ( K == 1 ) return printf( "%d\n", ans ), 0;
	while( l[w] ) val[l[w]] = val[l[w] ^ 1] = -val[l[w]], w = to[l[w]];
	DP( 1, 0 ), printf( "%d\n", ans - mx );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
