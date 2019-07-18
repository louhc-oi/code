#include<bits/stdc++.h>
using namespace std;

int N;
bool check( int N ){
	for ( int i = 2; i * i <= N; ++i )
		if ( N % i == 0 ) return 0;
	return 1;
}
int main(){
	scanf( "%d", &N );
	printf( "%d\n", N == 4 ? 2 : ( check(N) ? N - 1 : 0 ) );
	return 0;
}
