#include <fstream>
#include <iostream>
using namespace std;

#define INF -1000000000

void intersectie(int a, int b, int c,int d, int &x, int &y) {

	x = y = INF;
	if(b<c || d<a) return;
	if(a<c) x = a;
	else x = c;
	if(b<d) y = b;
	else y = d;

}

int nr_intervale(int *v, int *u, int n, int poz) {

	int nr = 0; int x, y;
	for(int i=poz+1;i<=n;i++) {
		intersectie(v[poz],u[poz],v[i],u[i],x,y);
		if(x != INF && y != INF) {
			nr++;
		}
	}
	return nr;
}

int main() {

	ifstream fin("patru.in");
	/**
	4
	1 8
	2 6
	3 10
	4 5
	**/
	int n, v[1000], u[1000];
	fin>>n;
	for(int i=1;i<=n;i++) {
		fin>>v[i]>>u[i];
	}
	int nr = nr_intervale(v,u,n,1);
	cout<<n-nr-1<<"\n";
	bool intersect = true;
	for(int i=1;i<n;i++) {
		if(nr_intervale(v,u,n,i) == 0) {
			intersect = false;
			break;
		}
	}
	if(intersect) cout<<"DA";
	else cout<<"NU";
	return 0;
}