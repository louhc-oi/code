#include "explore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int a[200005], b[200005], c[200005];
int f[200005];

void fz( int l, int r ){
	if ( l + 1 == r ) return report(a[l], a[r]);
	int m((r - l + 1) >> 2), ct(0);
	for ( int i = l; i <= r; ++i ) b[i] = 0;
	for ( int i = l; i <= r; ++i )
		if ( query(a[i]) != f[a[i]] ) f[a[i]] = !f[a[i]];
		else if ( ct < m ) modify(a[i]), b[i] = 1, ++ct;
	for ( int i = l, p1(l), p2(l + (m << 1)); i <= r; ++i )
		if ( b[i] ) c[p1++] = a[i]; else c[p2++] = a[i];
	for ( int i = l; i <= r; ++i ) a[i] = c[i];
	fz( l, l + (m << 1) - 1 ), fz( l + (m << 1), r );
}

void explore(int N, int M) {
	memset( f, 0, sizeof f );
	if ( N <= 500 && M <= 500 ){
		for ( int i = 1; i < N; ++i ){
			modify(i);
			for ( int j = 0; j < N; ++j ) if ( f[j] != query(j) ) f[j] = !f[j], i > j ? report(i, j), 1 : 1;
		}
	}else{
		for ( int i = 1; i <= N; ++i ) a[i] = i;
		fz( 1, N );
	}
}
