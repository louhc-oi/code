#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }

clock_t t_bg, t_ed;
const int MAXN = 105;

int n1, n2, l1, l2;
char s1[MAXN], s2[MAXN];
int nt[MAXN][26];
int f[MAXN][27], s[MAXN][27];
bool vis[26], flg;

signed main(){
	t_bg = clock();
	while( cin >> ( s2 + 1 ) >> n2 >> ( s1 + 1 ) >> n1 ){
		l1 = strlen( s1 + 1 ), l2 = strlen( s2 + 1 );
		
		memset( vis, 0, sizeof vis ), flg = 0;
		fp( i, 1, l1 ) vis[(int)(s1[i]-='a')] = 1;
		fp( i, 1, l2 ) if ( !vis[(int)(s2[i]-='a')] ) flg = 1;
		if ( flg ){ printf("0\n"); continue; }
		
		memset( nt, 0, sizeof nt );
		fd( i, l1, 1 ){
			fp( j, 0, 25 ) nt[i][j] = nt[i + 1][j];
			nt[i][(int)s1[i]] = i;
		}
		
		memset( f, 0, sizeof f );
		memset( s, 0, sizeof s );
		fp( i, 1, l1 ){
			int &t(f[i][0]), &c(s[i][0]); t = i;
			fp( j, 1, l2 )
				if ( nt[t+1][(int)s2[j]] ) t = nt[t+1][(int)s2[j]];
				else t = nt[1][(int)s2[j]], ++c;
		}
		fp( i, 1, 26 ) fp( j, 1, l1 )
			f[j][i] = f[f[j][i - 1]][i - 1],
			s[j][i] = min( s[j][i - 1] + s[f[j][i - 1]][i - 1], n1 + 1 );
		
		int t(l1), c(0), ans(0);
		fd( i, 26, 0 ) if ( c + s[t][i] <= n1 ) c += s[t][i], t = f[t][i], ans |= 1 << i;
		printf( "%d\n", ans / n2 );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}

