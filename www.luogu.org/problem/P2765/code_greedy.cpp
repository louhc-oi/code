#include<bits/stdc++.h>
using namespace std;
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define MAXN 99

int N;
vector<int> a[MAXN];
int sum[MAXN];
int t(1);

bool check( int x ){
	int tp((int)sqrt(x)); 
	return tp * tp == x;
}

int main(){
	scanf( "%d", &N );
	while( 1 ){
		bool flg(1);
		for ( int i = 1; i <= N; ++i )
			if ( a[i].size() == 0 || check( a[i][a[i].size() - 1] + t ) ){
				a[i].push_back( t ); flg = 0; break;
			}
		if ( flg ) break;
		t++;
	}
	printf( "%d\n", t - 1 );
	for ( int i = 1; i <= N; ++i, putchar('\n') )
		for ( int j = 0; j < (int)a[i].size(); ++j )
			printf( "%d ", a[i][j] );
	return 0;
}
