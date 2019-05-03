#include<iostream>
#include"Node.h"


using namespace std;

int main(){

	DisjointSet ds;
	int crit;
	cout<<"Ingresa el criterio 1) Arbitrario 2) Por altura 3) Size :";
	cin>>crit;
		
	ds.unionset(1,2,crit);
	ds.unionset(3,4,crit);
	ds.unionset(3,5,crit);
	ds.unionset(1,7,crit);
	ds.unionset(3,6,crit);
	ds.unionset(8,9,crit);
	ds.unionset(1,8,crit);
	ds.unionset(3,10,crit);
	ds.unionset(3,11,crit);
	ds.unionset(3,12,crit);
	ds.unionset(3,13,crit);
	ds.unionset(14,15,crit);
	ds.unionset(16,1,crit);
	ds.unionset(14,16,crit);
	ds.unionset(1,3,crit);
	ds.unionset(1,14,crit);
	for(int i=1;i<17;i++)
		ds.print(i);

	return 0;
}
