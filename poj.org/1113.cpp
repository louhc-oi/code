#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 1005
#define pi 3.1415927

struct vec{
	int x, y; vec( int a, int b ):x(a), y(b){} vec(){};
	inline vec operator + ( const vec &t ){ return vec( x + t.x, y + t.y ); }
	inline vec operator - ( const vec &t ){ return vec( x - t.x, y - t.y ); }
	inline int operator * ( const vec &t ){ return x * t.y - y * t.x; }
	inline bool operator < ( const vec &t )const{ return x == t.x ? y < t.y : x < t.x; }
	inline float length(){ return sqrt( x * x + y * y ); }
}v[MAXN];

int N, L; float ans;
int s[MAXN << 1], tp;

int main(){
	scanf( "%d%d", &N, &L );
	for ( int i = 1; i <= N; ++i ) scanf( "%d%d", &v[i].x, &v[i].y );
	sort( v + 1, v + N + 1 ), s[tp = 1] = 1;
	for ( int i = 2; i <= N; s[++tp] = i, ++i ) while( tp > 1 && ( v[s[tp]] - v[s[tp - 1]] ) * ( v[i] - v[s[tp - 1]] ) <= 0 ) --tp; 
	for ( int i = N-1, t(tp); i; s[++tp] = i, --i ) while( tp > t && ( v[s[tp]] - v[s[tp - 1]] ) * ( v[i] - v[s[tp - 1]] ) <= 0 ) --tp;
	for ( int i = 1; i < tp; ++i ) ans += ( v[s[i]] - v[s[i + 1]] ).length();
	printf( "%.0f\n", ans + 2 * pi * L );
	return 0;
}
