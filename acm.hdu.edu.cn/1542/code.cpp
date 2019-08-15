#include<bits/stdc++.h>
using namespace std;
#define MAXN 105

int T, N, NN, n;
double a[MAXN << 1], b[MAXN << 1], ans;
struct node{
	int u, d, v; double x;
	bool operator < ( const node &t )const{ return x < t.x; }
}q[MAXN << 1];

double tr[MAXN << 3]; int s[MAXN << 3];

void Add( int c, int l, int r, int L, int R, int v ){
	if ( L > r || l > R ) return;
	const int mid((l + r) >> 1), ls(c << 1), rs(ls | 1);
	if ( L <= l && r <= R ) return tr[c] = !(s[c] += v) ? l == r ? 0 : tr[ls] + tr[rs] : ( b[r + 1] - b[l] ), void();
	Add( ls, l, mid, L, R, v ), Add( rs, mid + 1, r, L, R, v );
	!s[c] ? tr[c] = tr[ls] + tr[rs] : 0;
}

int main(){
	while ( ~scanf( "%d", &N ) && N ){
		NN = N << 1;
		for ( int i = 0; i < NN; i += 2 )
			scanf( "%lf%lf%lf%lf", &q[i].x, a + i, &q[i + 1].x, a + i + 1 ),
			b[i] = a[i], b[i + 1] = a[i + 1], q[i].v = 1, q[i + 1].v = -1;
		sort( b, b + NN ), n = unique( b, b + NN ) - b;
		for ( int i = 0, t1, t2; i < NN; i += 2 )
			t1 = lower_bound( b, b + n, a[i] ) - b, q[i].d = q[i + 1].d = t1,
			t2 = lower_bound( b, b + n, a[i+1] ) - b, q[i].u = q[i + 1].u = t2;
		sort( q, q + NN ), Add( 1, 0, n - 2, q[0].d, q[0].u - 1, q[0].v );
		ans = 0;
		for ( int i = 1; i < NN; ++i )
			ans += tr[1] * ( q[i].x - q[i - 1].x ),
			Add( 1, 0, n - 2, q[i].d, q[i].u - 1, q[i].v );
		printf( "Test case #%d\nTotal explored area: %.2lf\n\n", ++T, ans );
	}
	return 0;
}
