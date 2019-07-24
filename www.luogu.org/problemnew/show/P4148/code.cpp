#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005

const double alpha = 3.1415927 / 4;

int w;

struct point{
	int x[2], w;
	point( int a, int b, int c ){ x[0] = a, x[1] = b, w = c; }
};

struct node *pl[MAXN], *null, *rt; int pit;
struct node{
	int sz, mx[2], mn[2]; point p; node *l, *r;
	inline bool check(){ return l->sz * alpha > r->sz || r->sz * alpha > l->sz; }
};

node* New( point x ){
	node *t(pit ? pl[pit--] : new node()); t->l = t->r = null, t->sz = 1,
	t->mn[0] = t->mn[1] = INT_MAX, t->mx[0] = t->mx[1] = INT_MIN, t->p = x;
	return t;
} inline void Del( node *t ){ pl[++pit] = t; }

int v[MAXN], cnt;
void flatten( node *c ){
	if ( c->l != null ) flatten( c->l );
	v[++cnt] = c->v, Del(c);
	if ( c->r != null ) flatten( c->r );
}node* build( int l, int r ){
	if ( l > r ) return null;
	if ( l == r ) return New(v[l]);
	int mid((l + r) >> 1); node *t(New(v[mid]));
	t->l = build( l, mid - 1 ),
	t->r = build( mid + 1, r ); return t;
} inline rebuild( node *&c ){ cnt = 0, flatten(c), c = build( 1, cnt ); }

void Ins( node *&c, int v ){
	if ( c == null ) c->v = c->mn[0] = c->mn[1] = c->mx
	if ( v < c->v )
}

int main(){
	rt = null = new node();
	cerr << ( INT_MAX + 1 );
	return 0;
}
