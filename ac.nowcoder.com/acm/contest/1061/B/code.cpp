#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXM 300005
#define LL long long

int N, K;
int hd[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot(1);
int dfn[MAXN], low[MAXN], num, c[MAXN], cnt, stk[MAXN], tp, s[MAXN], f[MAXN];
int X, A, B;
int o[MAXN], sm, in[MAXN];

void Add( int x, int y, int z ){ nxt[++tot] = hd[x]; hd[x] = tot; to[tot] = y; val[tot] = z; }

struct sta{ int x, stp; };
sta make( int xx, int yy ){ sta t; t.x = xx; t.stp = yy; return t; }

stack<sta> S;

void Tarjan( int xx ){
	S.push(make( xx, -1 ));
	
	while( !S.empty() ){
		sta cur(S.top()); S.pop();
		int x(cur.x);
		if ( cur.stp == -1 ){
			dfn[x] = low[x] = ++num; stk[++tp] = x;
			bool fg(1);
			
			for ( int i = hd[x]; i; i = nxt[i] )
				if ( !dfn[to[i]] ){ cur.stp = i, S.push( cur ); S.push( make( to[i], -1 ) ); fg = 0; break; }
				else if ( !c[to[i]] ) low[x] = min( low[x], dfn[to[i]] );
			if ( fg && low[x] == dfn[x] ){
				c[x] = ++cnt, s[cnt]++;
				while( stk[tp] != x ) c[stk[tp--]] = cnt, s[cnt]++;
				tp--;
			}
			
		} else{
			low[x] = min( low[x], low[to[cur.stp]] );
			
			bool fg(1);
			for ( int i = nxt[cur.stp]; i; i = nxt[i] )
				if ( !dfn[to[i]] ){ cur.stp = i, S.push( cur ); S.push( make( to[i], -1 ) ); fg = 0; break; }
				else if ( !c[to[i]] ) low[x] = min( low[x], dfn[to[i]] );
			
			if ( fg && low[x] == dfn[x] ){
				c[x] = ++cnt, s[cnt]++;
				while( stk[tp] != x ) c[stk[tp--]] = cnt, s[cnt]++;
				tp--;
			}
		}
	}
}

queue<int> Q;
void topo(){
	for ( int i = N + 1; i <= cnt; ++i ) if ( in[i] == 0 ) Q.push(i);
	while( !Q.empty() ){
		int t(Q.front()); Q.pop();
		for ( int i = hd[t]; i; i = nxt[i] ){
			in[to[i]]--; if ( in[to[i]] == 0 ) Q.push( to[i] );
		}
		o[++sm] = t;
	}
}

int main(){
	scanf( "%d%d", &N, &K ); cnt = N;
	for ( int i = 1; i <= K; ++i ){
		scanf( "%d%d%d", &X, &A, &B );
		if ( X == 1 ) Add( A, B, 0 ), Add( B, A, 0 );
		if ( X == 2 ) Add( A, B, 1 );
		if ( X == 3 ) Add( B, A, 0 );
		if ( X == 4 ) Add( B, A, 1 );
		if ( X == 5 ) Add( A, B, 0 );
	}
	
	for ( int i = 1; i <= N; ++i ) if ( !c[i] ) Tarjan(i);
	
	for ( int i = 1; i <= N; ++i )
		for ( int j = hd[i]; j; j = nxt[j] ){
			if ( c[i] != c[to[j]] ) Add( c[i], c[to[j]], val[j] ), in[c[to[j]]]++;
			else if ( val[j] ){ printf( "-1\n" ); return 0; }
		}
	
	topo();
	LL ans(0);
	
	for ( int i = N + 1; i <= cnt; ++i ) f[i] = 1;
	
	for ( int i = 1; i <= sm; ++i ){
		int t(o[i]);
		for ( int j = hd[t]; j; j = nxt[j] ) f[to[j]] = max( f[to[j]], f[t] + val[j] );
		ans += 1ll * f[t] * s[t];
	}
	printf( "%lld\n", ans );
	return 0;
}
