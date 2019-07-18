#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;
#define MAXN 70005
#define i64 long long

int n, m, w, h;

struct node{
	int x, y; node(){} node(int _x, int _y):x(_x), y(_y){}
	bool operator < ( const node &t )const{ return x > t.x; }
}a[MAXN];
struct mch{
	int p, t, L, R, D, U;
}c[150005];
unordered_map<i64,int> mp;
#define ID(x,y) (1ll * N * x + y)

//bool checkE(){
//	for ( int i = 1; i <= m; ++i ) if ( L != R || D != U ) return 0;
//	return 1;
//}

vector<node> e[MAXN];
priority_queue<node> Q;
int d[MAXN];

int main(){
	scanf( "%d%d%d%d", &n, &m, &w, &h );
	for ( int i = 1; i <= n; ++i ) scanf( "%d%d", &a[i].x, &a[i].y ), mp[ID(a[i].x,a[i].y)] = i;
	for ( int i = 1; i <= m; ++i ) scanf( "%d%d%d%d%d%d", &c[i].p, &c[i].t, &c[i].L, &c[i].R, &c[i].D, &c[i].U );
	for ( int i = 1; i <= m; ++i )
		for ( int x = c[i].L; x <= c[i].R; ++x )
			for ( int y = c[i].D; y <= c[i].U; ++y )
				if ( mp.count(ID(x,y)) ) e[c[i].p].push_back(node( mp[ID(x, y)], c[i].t ));
	memset( d, 0x7f, sizeof d ), d[1] = 0, Q.push(node(0, 1));
	while( !Q.empty() ){
		int x(Q.top().y); Q.pop();
		for ( int i = hd[x]; i; i = nxt[i] ){
			
		}
	}
	return 0;
} 
