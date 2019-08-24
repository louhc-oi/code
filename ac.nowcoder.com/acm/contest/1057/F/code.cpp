#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 100005
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
int hd[MAXN], nxt[MAXN<<1], to[MAXN<<1], val[MAXN<<1], tot;
inline void addedge( int x, int y, int z ){
	nxt[++tot] = hd[x], hd[x] = tot, to[tot] = y, val[tot] = z,
	nxt[++tot] = hd[y], hd[y] = tot, to[tot] = x, val[tot] = z;
}
int f[MAXN][20], dfn[MAXN], rev[MAXN], dep[MAXN], cnt; i64 s[MAXN]; 
void DFS( int u ){
	rev[dfn[u] = ++cnt] = u, dep[u] = dep[f[u][0]] + 1;
	fp( i, 1, 16 ) f[u][i] = f[f[u][i - 1]][i - 1];
	go( i, hd[u] ) if ( v != f[u][0] ) s[v] = s[u] + val[i], f[v][0] = u, DFS(v);
}
set<int> S;
#define IT set<int>::iterator 
i64 get( int x, int y ){ i64 ans(s[x] + s[y]);
	if ( dep[x] < dep[y] ) x^=y^=x^=y;
	fd( i, 16, 0 ) if ( dep[f[x][i]] > dep[y] ) x = f[x][i];
	if ( dep[x] != dep[y] ) x = f[x][0];
	fd( i, 16, 0 ) if ( f[x][i] != f[y][i] ) x = f[x][i], y = f[y][i];
	x = ( x != y ? f[x][0] : x ); return ans - (s[x] << 1);
}

int main(){
	t_bg = clock();
	read(N); int x, y, z;
	fp( i, 1, N - 1 ) read(x), read(y), read(z), addedge( x, y, z );
	char opt; i64 ans(0); DFS(1), read(M);
	while( M-- ){
		while( (opt = getchar()) != '+' && opt != '-' && opt != '?' ); 
		if ( opt == '+' ){
			read(x);
			if ( S.size() ){
				IT c = S.lower_bound(dfn[x]), t = c;
				if ( c != S.begin() ) --t;
				if ( c != S.begin() && c != S.end() ) ans -= get(rev[*c], rev[*t]);
				if ( c != S.end() ) ans += get(x, rev[*c]);
				if ( c != S.begin() ) ans += get(x, rev[*t]);
			} S.insert(dfn[x]);
		}else if ( opt == '-' ){
			read(x);
			IT c = S.lower_bound(dfn[x]), t(c), u(c); ++u;
			if ( c != S.begin() ) --t;
			if ( c != S.begin() ) ans -= get(x, rev[*t]);
			if ( u != S.end() ) ans -= get(x, rev[*u]);
			if ( c != S.begin() && u != S.end() ) ans += get(rev[*t], rev[*u]);
			S.erase(dfn[x]);
		} else printf( "%lld\n", S.size() > 1 ? (ans + get(rev[*S.begin()], rev[*S.rbegin()])) >> 1 : 0ll );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

