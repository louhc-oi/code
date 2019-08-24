#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 100005
#define MAXM 300005
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

int N, M;

struct edge{
	int x, y, z; bool cs;
	bool operator < ( const edge &t )const{ return z < t.z; }
}e[MAXM]; int fa[MAXN];
int find( int x ){ return fa[x] > 0 ? fa[x] = find(fa[x]) : x; }

void Max( int &x, int &y, int a, int b, int c, int d ){
	if ( a > c ){ x = a; if ( a == c ) y = b; else y = max( b, c ); }
	else{ x = c; if ( a == c ) y = d; else y = max( a, d ); }
}

int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], val[MAXN<<1], tot;
int f[MAXN][20], m1[MAXN][20], m2[MAXN][20], dep[MAXN];
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
}
void DFS( int u ){
	dep[u] = dep[f[u][0]] + 1;
	fp( i, 1, 18 ) f[u][i] = f[f[u][i - 1]][i - 1],
		Max( m1[u][i], m2[u][i], m1[u][i - 1], m2[u][i - 1], m1[f[u][i - 1]][i - 1], m2[f[u][i - 1]][i - 1] );
	go( i, hd[u] ) if ( v != f[u][0] )
		f[v][0] = u, m1[v][0] = val[i], DFS(v);
}

inline void up( int &x, int s, int &r1, int &r2 ){
	Max( r1, r2, r1, r2, m1[x][s], m2[x][s] ), x = f[x][s];
} inline void LCA( int x, int y, int &r1, int &r2 ){
	r1 = r2 = INT_MIN; if ( dep[x] < dep[y] ) x^=y^=x^=y;
	fd( i, 18, 0 ) if ( dep[f[x][i]] > dep[y] ) up( x, i, r1, r2 );
	if ( dep[x] > dep[y] ) up( x, 0, r1, r2 );
	fd( i, 18, 0 ) if ( f[x][i] != f[y][i] ) up( x, i, r1, r2 ), up( y, i, r1, r2 );
	if ( x != y ) up(x, 0, r1, r2), up(y, 0, r1, r2);
}

int main(){
	t_bg = clock();
	read(N), read(M);
	fp( i, 1, M ) read(e[i].x), read(e[i].y), read(e[i].z);
	sort( e + 1, e + M + 1 ), memset( fa, -1, sizeof fa );
	i64 ans(0);
	fp( i, 1, M ){
		int x(find(e[i].x)), y(find(e[i].y)), z(e[i].z);
		if ( x == y ) continue;
		ans += e[i].z, e[i].cs = 1, addedge( e[i].x, e[i].y, z );
		if ( fa[x] < fa[y] ) fa[x] += fa[y], fa[y] = x;
		else fa[y] += fa[x], fa[x] = y;
	} fp( i, 1, N ) fp( j, 0, 18 ) m1[i][j] = m2[i][j] = INT_MIN;
	DFS(1); i64 res(LONG_LONG_MAX);	
	fp( i, 1, M ) if ( !e[i].cs ){
		int a, b; LCA( e[i].x, e[i].y, a, b );
		if ( a != e[i].z ) cmin( res, ans + e[i].z - a );
		else cmin( res, ans + e[i].z - b );
	} printf( "%lld\n", res );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

