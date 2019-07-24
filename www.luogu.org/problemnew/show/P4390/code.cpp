#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005

inline void read( int &x ){ x = 0; char t;
	for ( t = getchar(); !isdigit(t); t = getchar() );
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
}

int N, opt, tot;
int ans[10005], n;
int c[2000005];

inline void Add( int x, int y ){ for ( ; x <= N; x += x & -x ) c[x] += y; }
inline int Get( int x ){ int ans(0); for ( ; x; x -= x & -x ) ans += c[x]; return ans; }

struct node{
	int t, x, y, v; char flg, o; node(){}
	node( int ti, int a, int b, int w, char opt, char k = 0 ):t(ti), x(a), y(b), v(w), o(opt), flg(k){}
}q[MAXN];

inline bool cmpx( node a, node b ){ return a.x == b.x ? a.t < b.t : a.x < b.x; }

void CDQ( int l, int r ){
	if ( l == r ) return;
	int mid((l + r) >> 1); CDQ( l, mid ), CDQ( mid + 1, r ), sort( q + l, q + r + 1, cmpx );
	for ( int i = l; i <= r; ++i ){
		if ( q[i].o == 1 && q[i].t <= mid ) Add( q[i].y, q[i].v );
		else if ( q[i].o == 2 && q[i].t > mid ) q[i].flg ? ans[q[i].v] += Get(q[i].y) : ans[q[i].v] -= Get(q[i].y);
	} for ( int i = l; i <= r; ++i ) if ( q[i].o == 1 && q[i].t <= mid ) Add( q[i].y, -q[i].v );
}

signed main(){
	read(N), read(N), ++N; int x, y, a, b;
	while( ( read(opt), opt != 3 ) ){
		if ( opt == 1 ) read(x), read(y), read(a), ++tot, q[tot] = node(tot, x+1, y+1, a, 1);
		else read(x), read(y), read(a), read(b), ++a, ++b, ++n, ++tot, q[tot] = node(tot, a, b, n, 2, 1),
			++tot, q[tot] = node(tot, x, y, n, 2, 1), ++tot, q[tot] = node(tot, a, y, n, 2), ++tot, q[tot] = node(tot, x, b, n, 2);	
	} CDQ(1, tot); for ( int i = 1; i <= n; ++i ) printf( "%d\n", ans[i] );
	return 0;
}
