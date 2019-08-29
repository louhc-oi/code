#include<bits/stdc++.h>
using namespace std;
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define MAXN 1000005

int N, T;
char s[MAXN];
int f[MAXN];

int main(){
	while( ~scanf( "%d", &N ) && N ){
		scanf( "%s", s + 1 ); T++;
		printf( "Test case #%d\n", T );
		int t(0); f[1] = 0;
		for ( int i = 2; i <= N; ++i ){
			while ( s[i] != s[t + 1] && t ) t = f[t];
			if ( s[i] == s[t + 1] ) t++;
			f[i] = t;
			if ( f[i] != 0 && i % ( i -  f[i] ) == 0 ) printf( "%d %d\n", i, i / ( i - f[i] ) );
		}
		putchar('\n');
	}
	return 0;
}
