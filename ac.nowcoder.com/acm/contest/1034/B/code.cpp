#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAXN 250005
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

#if _WIN64 
template<typename ...Args>
inline void err( Args ...args ){
	fprintf( stderr, args... );
}
#else
void err(...){}
#endif

clock_t t_bg, t_ed;

int P, N, B; i64 R, X, Y, x, y;
inline i64 sqr( i64 x ){ return x * x; }
struct node{
	int m, p; i64 r, d;
	bool operator < ( const node &t )const{ return d < t.d; }
}a[MAXN]; i64 b[MAXN];
bool cmp( node x, node y ){ return x.m < y.m; }
bool vs[MAXN]; int p[505], e[505], ans;
queue<int> Q;

int main(){
	t_bg = clock();
	read(X), read(Y), read(a[0].p), read(a[0].r), read(N), a[0].r = sqr(a[0].r);
	fp( i, 1, N ) b[i] = i, read(x), read(y), a[i].d = sqr(x - X) + sqr(y - Y),
		read(a[i].m), read(a[i].p), read(a[i].r), a[i].r = sqr(a[i].r);
	sort( a + 1, a + N + 1 ), B = sqrt(N);
	fp( i, 1, N ) b[i] = a[i].d;
	fp( i, 0, (N - 1) / B ) e[i] = p[i + 1] = i * B + 1,
		sort(a + i * B + 1, a + min((i + 1) * B, N ) + 1, cmp);
	e[(N - 1) / B + 1] = N + 1;
	Q.push(0);
	while( !Q.empty() ){
		int c(Q.front()), u; ++ans, Q.pop();
		u = upper_bound( b + 1, b + N + 1, a[c].r ) - b;
		if ( b[u] != a[c].r ) --u;
		fp( i, (u - 1) / B * B + 1, min( ( (u - 1) / B + 1 ) * B, N ) )
			if ( a[c].r >= a[i].d && a[c].p >= a[i].m && !vs[i] )
				vs[i] = 1, Q.push(i);
		fp( i, 1, (u - 1) / B )
			for ( ; p[i] < e[i] && a[c].p >= a[p[i]].m; ++p[i] )
				if ( !vs[p[i]] ) vs[p[i]] = 1, Q.push(p[i]);
	} printf( "%d\n", ans - 1 );
	t_ed = clock();
	err( "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

