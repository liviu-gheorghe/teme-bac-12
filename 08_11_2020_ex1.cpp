#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


#define u_int unsigned int

u_int nr_divizori_proprii(u_int x) {
	u_int nr = 0;
	for(u_int d=2;d*d<=x;d++) {
		if(x%d == 0) {
			nr++;
			if(x/d>d) nr++;
		}
	}
	return nr;
}


void inserare(u_int* v ,u_int n, u_int x, u_int poz ) {
	
	if(poz < 0 || poz > n-1) return;
	for(int j=n+1;j>poz;j--) {
		v[j] = v[j-1];
	}
	v[poz] = x;
}


int main() {
	u_int V[1000],n,i;
	bool prime = true;
	ifstream fin("unu.in");
	fin>>n;
	for(i=0;i<n;i++) {
		fin>>V[i];
		if(nr_divizori_proprii(V[i]) > 0) prime = false;
	}
	cout << (prime ? "DA" : "NU\n");
	if(prime) return 0;

	i = 0;
	while(i<n) {
		if(nr_divizori_proprii(V[i]) > 0) {
			int d1,d2;
			d2 = V[i]/2;
			while(V[i]%d2) d2--;
			d1 = d2-1;
			while(V[i]%d1) d1--;
			inserare(V,n++,d1,i);
			inserare(V,n++,d2,i+1);
			i += 3;
		}
		else i++;
	}

	for(i=0;i<n;i++) cout<<V[i]<<(i == n-1 ? '\n' : ' ');
	return 0;
}