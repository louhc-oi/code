#include<bits/stdc++.h>
using namespace std;
#define i64 long long
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
struct node{
	int x, w; node( int a, int b ):x(a), w(b){}
	bool operator < ( const node &t )const{ return x > t.x; }
};
const int MAXN = 1e5 + 5;
int N, K, a[MAXN], l[MAXN], r[MAXN];
bool d[MAXN];
struct cmp{
	bool operator () ( int x, int y ){ return a[x] > a[y]; }
};
priority_queue<int, vector<int>, cmp> Q;

signed main(){
	t_bg = clock();
	read(N), read(K);
	fp( i, 1, N ) read(a[i]);
	fp( i, 1, --N ) a[i] = a[i + 1] - a[i], Q.push(i), l[i] = i + 1, r[i] = i - 1;
	a[0] = a[N + 1] = 0x3f3f3f3f; int ans(0);
	while( K-- ){
		int p(Q.top()); Q.pop();
		while( d[p] ) p = Q.top(), Q.pop();
		ans += a[p], a[p] = -a[p];
		a[p] += a[r[p]], d[r[p]] = 1, r[p] = r[r[p]], l[r[p]] = p;
		a[p] += a[l[p]], d[l[p]] = 1, l[p] = l[l[p]], r[l[p]] = p;
		Q.push(p);
	} printf( "%d\n", ans );
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

