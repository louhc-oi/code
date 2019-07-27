#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf ) == p2 ? EOF : *p1++ )
using namespace std;
#define MAXN 200005

char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t, flg(0);
	for ( t = getchar(); !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 ); x = flg ? -x : x;
}

int N;

struct node{
	int l, r;
	bool operator < ( const node &t )const{ return r < t.r; }
}a[MAXN];

signed main(){
	read(N);
	for ( int i = 1, x, y; i <= N; ++i ) read(x), read(y), a[i].l = x - y, a[i].r = x + y;
	sort( a + 1, a + N + 1 );
	int ans(0);
	for ( int i = 1, c(INT_MIN); i <= N; ++i )
		if ( c <= a[i].l ) c = a[i].r, ++ans;
	printf( "%d\n", ans );
	return 0;
}

