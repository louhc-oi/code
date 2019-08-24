#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 998244353
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
//#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

#define MAXN 200005
int N, M;
int p[MAXN], fac[MAXN], inv[MAXN];
vector<int> v[MAXN];
priority_queue<pair<int, int> > Q;
inline int Get( int x ){ int ans(1); while( ans < x ) ans <<= 1; return ans; }
inline i64 Pow( i64 x, i64 y ){ i64 ans(1); for ( ; y; y >>= 1, x = x * x % mod ) ( y & 1 ) ? ans = ans * x % mod : 0; return ans; }
inline int C( int x, int y ){ return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod; }
#define inv(x) Pow( x, mod - 2 )
inline int dec( int x ){ return x > mod ? x - mod : x; }
inline int rec( int x ){ return x < 0 ? x + mod : x; }
int f[20][1<<20];

void NTT( vector<int> &a, int N, int opt ){ int o(opt == 1 ? 3 : 332748118);
	int n(0); for ( int i = 1; i < N; i <<= 1, ++n ); --n;
	for ( int i = 0; i < N; ++i ) f[n][i] > i ? swap( a[f[n][i]], a[i] ) : void();
	for ( int len = 1, pn, cur; len < N; len <<= 1 ){
		cur = len << 1, pn = Pow(o, 998244352 / cur);
		for ( int i = 0, w; i < N; i += cur ){ w = 1;
			for ( int j = 0, x, y; j < len; ++j, w = (1ll * w * pn) % mod )
				x = a[i + j], y = 1ll * a[i + j + len] * w % mod,
				a[i + j] = dec(x + y), a[i + j + len] = rec(x - y);
		}
	} if ( opt == -1 ){ for ( int i = 0, t(inv(N)); i < N; ++i ) a[i] = ( (i64)a[i] * t ) % mod; }
}

int main(){
	read(N), p[0] = 1, fac[0] = 1, inv[0] = 1;
	fp( i, 1, 2e5 ) fac[i] = 1ll * fac[i - 1] * i % mod, inv[i] = inv(fac[i]), p[i] = p[i - 1] * 2 % mod;
	fp( i, 0, 19 ) fp( j, 0, (1 << (i + 1)) - 1 ) f[i][j] = ( f[i][j >> 1] >> 1 ) | ((j & 1) << i);
	
	fp( i, 1, N ){
		int a, b, l; read(a), read(b);
		v[i].resize(l = Get(a + 1)), v[i][0]= p[b] - 1;
		fp( j, 1, a ) v[i][j] = C(a, j);
		Q.push(make_pair(-l, i));
		M += a;
	} while( Q.size() > 1 ){
		int a, b, l;
		a = Q.top().second, Q.pop();
		b = Q.top().second, Q.pop();
		l = v[b].size() << 1;
		v[a].resize(l), v[b].resize(l);
		NTT(v[a], l, 1), NTT(v[b], l, 1);
		for ( int i = 0; i < l; ++i )
			v[a][i] = 1ll * v[a][i] * v[b][i] % mod;
		NTT(v[a], l, -1); v[b].clear();
		Q.push(make_pair(-l, a));
	} int a(Q.top().second); for ( int i = 0; i <= M; ++i ) printf( "%d ", v[a][i] );
	return 0;
}

