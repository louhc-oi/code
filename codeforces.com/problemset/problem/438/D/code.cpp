#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf ) == p2 ? EOF : *p1++ )
using namespace std;
#define MAXN 100005

char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t, flg(0);
	for ( t = getchar(); !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 ); x = flg ? -x : x;
}

int N, M, a[MAXN];
i64 tr[MAXN << 2];
int mx[MAXN << 2];
#define pushup tr[c] = tr[ls] + tr[rs], mx[c] = max( mx[ls], mx[rs] )

void Build( int c, int l, int r ){
	if ( l == r ) return tr[c] = mx[c] = a[l], void();
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Build( ls, l, mid ), Build( rs, mid + 1, r );
	pushup;
}

int x, y, p;
void Modify( int c, int l, int r ){
	if ( l == r ) return tr[c] = mx[c] = y, void();
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( x <= mid ) Modify( ls, l, mid );
	else Modify( rs, mid + 1, r );
	pushup;
}

void Mo( int c, int l, int r ){
	if ( mx[c] < p || l > y || x > r ) return;
	if ( l == r ) return tr[c] = ( mx[c] %= p ), void();
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	Mo( ls, l, mid ), Mo( rs, mid + 1, r );
	pushup;
}

i64 Query( int c, int l, int r ){
	if ( l > y || x > r ) return 0;
	if ( x <= l && r <= y ) return tr[c];
	int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	return Query( ls, l, mid ) + Query( rs, mid + 1, r );
}

signed main(){
	read(N), read(M);
	for ( int i = 1; i <= N; ++i ) read(a[i]);
	Build( 1, 1, N );
	for ( int i = 1, opt; i <= M; ++i ){
		read(opt);
		if ( opt == 1 ) read(x), read(y), printf( "%I64d\n", Query( 1, 1, N ) );
		else if ( opt == 2 ) read(x), read(y), read(p), Mo( 1, 1, N );
		else read(x), read(y), Modify( 1, 1, N );
	}
	return 0;
}
