#include<bits/stdc++.h>
using namespace std;
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
inline int get(){ int n; scanf( "%d", &n ); fp( i, 1, n ) scanf( "%*d" ); return n; }

int main(){
	do{ cout << "next 0" << endl, get(), cout << "next 0 1" << endl; }while( get() != 2 );
	do{ cout << "next 0 1 2 3 4 5 6 7 8 9" << endl; }while( get() != 1 );
	cout << "done" << endl;
	return 0;
}

