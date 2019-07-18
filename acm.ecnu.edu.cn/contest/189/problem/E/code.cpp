#include<bits/stdc++.h>
using namespace std;

char a[100005];
int tp;
long long s[100005];

int Get( int &i ){
	if ( !isdigit(a[i]) ) return 1;
	int ans(0);
	while( isdigit(a[i]) ) ans = ans * 10 + ( a[i] & 15 ), ++i; 
	return ans;
}

int main(){
	scanf( "%s", a + 1 );
	for ( int i = 1; a[i] != '\0'; ){
		while( a[i] == '(' || a[i] == ')' ){
			while( a[i] == '(' ) ++i, ++tp, s[tp] = 0;
			while( a[i] == ')' ) ++i, --tp, s[tp] += 1ll * s[tp + 1] * Get(i);
		} if ( a[i] == '\0' ) break;
		char t(a[i]); ++i; int sm(Get(i));
		s[tp] += 1ll * sm * ( t != 'H' ? ( t != 'O' ? 4 : -2 ) : 1 );
	} if ( s[0] & 1 ) printf( "%lld/4\n", s[0] );
	else if ( s[0] & 3 ) printf( "%lld/2\n", s[0] >> 1 );
	else printf( "%lld/1\n", s[0] >> 2 );
	return 0;
}
