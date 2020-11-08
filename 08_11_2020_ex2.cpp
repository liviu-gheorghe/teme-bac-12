#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


#define u_int unsigned int


u_int nr_aparitii(u_int* v,u_int n, u_int x) {
	
	u_int nr = 0;
	for(u_int i=0;i<n;i++) {
		nr += (v[i] == x);
	}
	return nr;
}

void stergere(u_int* v, u_int n, int X,int Y) {

	if(X>Y || X<0 || X>n-1) return;
	for(int i=0;i<(Y-X+1);i++) {
		for(int j=X;j<n-1;j++) {
			v[j] = v[j+1];
		}
	}
}

int main() {

	u_int W[1000],n,i;
	ifstream fin("doi.in");
	bool distincte = true;
	fin>>n;
	for(i=0;i<n;i++) {
		fin>>W[i];
	}

	for(i=0;i<n;i++) {
		if(nr_aparitii(W,n,W[i]) > 1) {
			distincte = false;
			break;
		}
	}

	cout << (distincte ? "DA" : "NU\n");
	if(distincte) return 0;

	i = 0;
	while(i<n) {
		int nr_ap = nr_aparitii(W,n,W[i]);
		if(nr_ap > 1) {
			stergere(W,n,i+1,i+nr_ap-1);
			n -= (nr_ap-1);
		} else i++;
	}

	for(i=0;i<n;i++) cout<<W[i]<<(i == n-1 ? '\n' : ' ');
	return 0;
}