#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define i64 long long
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( T &x ){ x = 0; char t(getchar()), flg(0);
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

int N, M, w[MAXN], r[MAXN], c[MAXN]; i64 h[MAXN], v[MAXN], s[MAXN], t1[MAXN], t2[MAXN];
int d[MAXN], ls[MAXN], rs[MAXN], f[MAXN], a[MAXN], ans[MAXN], sm[MAXN];
inline void swp( int &x, int &y ){ x^=y^=x^=y; }
inline void tag1( int c, i64 x ){ if ( c ) t1[c] += x, s[c] += x; }
inline void tag2( int c, i64 x ){ if ( c ) t2[c] *= x, t1[c] *= x, s[c] *= x; }
inline void pushdown( int c ){
	if ( t2[c] != 1 ) tag2(ls[c], t2[c]), tag2(rs[c], t2[c]), t2[c] = 1;
	if ( t1[c] ) tag1(ls[c], t1[c]), tag1(rs[c], t1[c]), t1[c] = 0;
}

int Merge( int x, int y ){
	if ( !x || !y ) return x | y;
	pushdown(x), pushdown(y);
	if ( s[x] > s[y] ) swp(x, y);
	rs[x] = Merge( rs[x], y );
	if ( d[ls[x]] < d[rs[x]] ) swp( ls[x], rs[x] );
	d[x] = d[rs[x]] + 1; return x;
} inline void pop( int &x ){ pushdown(x), x = Merge( ls[x], rs[x] ); }

int main(){
	read(N), read(M);
	for ( int i = 1; i <= N; ++i ) read(h[i]);
	for ( int i = 2; i <= N; ++i ) read(f[i]), read(a[i]), read(v[i]);
	for ( int i = 1; i <= M; ++i )
		t2[i] = 1, read(s[i]), read(c[i]), r[c[i]] = Merge( r[c[i]], i );
	for ( int i = 1; i <= N; ++i ) w[i] = w[f[i]] + 1;
	for ( int i = N; i; --i ){
		while( r[i] && s[r[i]] < h[i] ) sm[r[i]] = w[c[r[i]]] - w[i], pop(r[i]), ++ans[i];
		a[i] ? tag2(r[i], v[i]) : tag1(r[i], v[i]),
		r[f[i]] = Merge( r[f[i]], r[i] );
	} while( r[0] ) sm[r[0]] = w[c[r[0]]], pop(r[0]);
	for ( int i = 1; i <= N; ++i ) printf( "%d\n", ans[i] );
	for ( int i = 1; i <= M; ++i ) printf( "%d\n", sm[i] );
	return 0;
}
