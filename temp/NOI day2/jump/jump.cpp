#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;
#define MAXN 70005
#define i64 long long
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )

int n, m, w, h;

struct node{
	int x, y; node(){} node(int _x, int _y):x(_x), y(_y){}
	bool operator < ( const node &t )const{ return x > t.x; }
}a[MAXN];
struct mch{
	int p, t, L, R, D, U;
}c[150005];
unordered_map<i64,int> mp;
#define ID(x,y) (1ll * n * (x-1) + (y-1))

vector<int> v[MAXN];
vector<node> e[MAXN << 2];
priority_queue<node> Q;
int d[MAXN]; char vis[MAXN];

inline void addedge( int x, int y, int z = 0 ){ /*printf( "add edge %d -> %d : %d\n", x, y, z ),*/ e[x].push_back(node(y, z)); }

#define ls c << 1
#define rs c << 1 | 1
void Build( int c, int l, int r ){
	if ( l == r ){
		for ( vector<int>::iterator i = v[l].begin(); i != v[l].end(); ++i ) addedge( c + n, *i );
		return;
	} int mid((l + r) >> 1);
	addedge( c + n, (ls) + n ), addedge( c + n, (rs) + n ),
	Build( ls, l, mid ), Build( rs, mid + 1, r );
}

int edge_x, edge_v, L, R;
void work( int c, int l, int r ){
	if ( L <= l && r <= R ) return addedge( edge_x, c + n, edge_v );
	if ( l > R || r < L ) return;
	int mid((l + r) >> 1);
	work( ls, l, mid ), work( rs, mid + 1, r );
}

inline void SPFA(){
	queue<int> q;
	memset( d, 0x7f, sizeof d ), d[1] = 0, q.push(1), vis[1] = 1;
	while( !q.empty() ){
		int x(q.front()), y; q.pop(); vis[x] = 0;
		for ( vector<node>::iterator i = e[x].begin(); i != e[x].end(); ++i ){
			y = i->x;
			if ( d[y] > d[x] + i->y ){
				d[y] = d[x] + i->y;
				if ( !vis[y] ) vis[y] = 1, q.push(y);
			}
		}
	} for ( int i = 2; i <= n; ++i ) printf( "%d\n", d[i] );
}

inline void Solve(){
	memset( d, 0x7f, sizeof d ), d[1] = 0, Q.push(node(0, 1));
	while( !Q.empty() ){
		int x(Q.top().y), y; Q.pop();
		if ( vis[x] ) continue;
		vis[x] = 1;
		for ( vector<node>::iterator i = e[x].begin(); i != e[x].end(); ++i ){
			y = i->x;
			if ( !vis[y] && d[y] > d[x] + i->y )
				d[y] = d[x] + i->y, Q.push(node(d[y], y));
		}
	} for ( int i = 2; i <= n; ++i ) printf( "%d\n", d[i] );
}

int main(){
	open("jump1");
	scanf( "%d%d%d%d", &n, &m, &w, &h );
	for ( int i = 1; i <= n; ++i ) scanf( "%d%d", &a[i].x, &a[i].y ), mp[ID(a[i].x,a[i].y)] = i;
	for ( int i = 1; i <= m; ++i ) scanf( "%d%d%d%d%d%d", &c[i].p, &c[i].t, &c[i].L, &c[i].R, &c[i].D, &c[i].U );
	if ( h == 1 ){
		for ( int i = 1; i <= n; ++i ) v[a[i].x].push_back(i);
		Build(1, 1, n);
		for ( int i = 1; i <= m; ++i ) edge_x = c[i].p, edge_v = c[i].t,
			L = c[i].L, R = c[i].R, work( 1, 1, n );
	}else{
		for ( int i = 1; i <= m; ++i )
			for ( int x = c[i].L; x <= c[i].R; ++x )
				for ( int y = c[i].D; y <= c[i].U; ++y )
					if ( mp.count(ID(x,y)) ) addedge( c[i].p, mp[ID(x, y)], c[i].t);
	} Solve();
	return 0;
} 
