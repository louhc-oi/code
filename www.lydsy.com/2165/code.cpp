#include<bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
#define rgt register
#define getchar() ( p1 == p2 && ( p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 = bf ) == p2 ? EOF : *p1++ )
using namespace std;

char bf[1 << 21], *p1, *p2;
template<typename T>
inline void read( rgt T &x ){ x = 0; rgt char t, flg(0);
	for ( t = getchar(); !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 ); x = flg ? -x : x;
}

int T, N, n, x, y; i64 M, z;

inline void cmax( i64 &x, i64 y ){ x < y ? x = y : x; }

struct node{
	i64 a[105][105];
	node(){
		memset( a, 0xf7, sizeof a );
		for ( int i = 1; i <= N; ++i ) a[i][i] = 0;
	}
	node operator * ( const node &t ){
		node ans;
		for ( int i = 1; i <= N; ++i )
			for ( int k = 1; k <= N; ++k )
				for ( int j = 1; j <= N; ++j )
					cmax( ans.a[i][j], a[i][k] + t.a[k][j] );
		return ans;
	}
	bool check(){
		for ( int i = 1; i <= N; ++i )
			if ( a[1][i] >= M ) return 1;
		return 0;
	}
}A[105], u, v;
i64 ans;

signed main(){
	read(T);
	while( T-- ){
		read(N), read(M);
		for ( int i = 1; i <= N; ++i )
			for ( int j = 1; j <= N; ++j ){
				read(A[0].a[i][j]);
				if ( !A[0].a[i][j] && i != j ) A[0].a[i][j] = 0xf7f7f7f7f7f7f7f7;
			}
		n = 0, u = node(), ans = 0;
		while( !A[n].check() ) A[n + 1] = A[n] * A[n], ++n;
		for ( int i = n - 1; i >= 0; --i ){
			v = u * A[i];
			if ( !v.check() ) ans |= 1ll << i, u = v;
		} printf( "%lld\n", ans + 1 );
	}
	return 0;
}
