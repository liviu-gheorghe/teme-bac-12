#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;
ifstream fin("trei.in");
/**
9
6 2 34 789 17 89 3456 23456 15
**/

bool scara(unsigned int x) {
	if(x/10 == 0) {
		return false;
	}
	int c = x%10;
	x /= 10;
	while(x != 0) {
		if(x%10 != c-1) return false;
		else c = x%10;
		x /= 10;
	}
	return true;
}

bool secv_scara(unsigned int *v, unsigned int n, unsigned int i1, unsigned int i2) {
	for(unsigned int i=i1;i<=i2;i++) {
		if(scara(v[i]) == false) return false;
	}
	return true;
}

int main() {

	unsigned int V[100],n;
	fin>>n;
	for(unsigned int i=1;i<=n;i++) {
		fin>>V[i];
	}

	int prim = -1, ultim = -1;
	for(unsigned int i = 1;i<=n;i++) {
		if(scara(V[i])) {
			prim = i;
			break;
		}
	}

		for(unsigned int i = n;i>=0;i--) {
		if(scara(V[i])) {
			ultim = i;
			break;
		}
	}

	if(prim == -1 || ultim == -1) {
		cout<<"NU EXISTA";
		return 0;
	} else 
	cout<<prim<<' '<<ultim<<'\n';

	if(prim == ultim) return 0;
	int st,dr, l_max_secv, l_secv, st_max, dr_max;
	l_max_secv = 0; l_secv = 0; st = 1; dr = 1;
	st_max = dr_max = 1;


/*	while(dr <= n) {
		if(scara(V[dr])) {
			l_secv++;
		}
		if(dr == n || scara(V[dr]) == false) {
			if(l_secv > l_max_secv) {
				l_max_secv = l_secv;
				st_max = st;
				dr_max = st + l_secv -1;
			}
			st = dr+1;
			if(scara(V[dr]) == false)
			l_secv = 0;
		}
		dr++;
	}

	if(l_max_secv > 1) {
		cout<<l_max_secv<<'\n';
		for(unsigned int i = st_max; i<=dr_max;i++) {
			cout<<V[i]<<' ';
		}
	}*/

	l_max_secv = 0;
	for(unsigned int i = prim; i<ultim; i++)
		for(unsigned int j= i+1;j<=ultim;j++) {
			if(secv_scara(V,n,i,j)) {
				l_secv = j-i+1;
				if(l_secv > l_max_secv) {
					l_max_secv = l_secv;
					st_max = i;
					dr_max = j;
				}
			}
		}
	if(l_max_secv > 1) {
		cout<<l_max_secv<<'\n';
		for(unsigned int i = st_max; i<=dr_max;i++) {
			cout<<V[i]<<' ';
		}
	}
	return 0;
}