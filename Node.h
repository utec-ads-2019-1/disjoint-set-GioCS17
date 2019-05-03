#include<iostream>
#include<unordered_map>
#include<time.h>
using namespace std;
struct Node{
	int data;
	Node* parent;
	int range;
	int size;
	Node(int d){data=d;range=0;size=1;}
};
class DisjointSet{
private:
		//int size;
		//bool states[size]={0};
		unordered_map<int,Node*> dict;
		unordered_map<int,bool> states;
public:
	void unionset(int elem1,int elem2,int criterio){
		Node *n1,*n2;
		if(!states[elem1]){
			n1=new Node(elem1);
			n1->parent=n1;
			states[elem1]=1;
			dict[elem1]=n1;
		}
		else
			n1=dict[elem1];
		if(!states[elem2]){
			n2=new Node(elem2);
			n2->parent=n2;
			states[elem2]=1;
			dict[elem2]=n2;
		}
		else
			n2=dict[elem2];

		if(criterio==1){
			while(n1->parent!=n1) n1=n1->parent;
			while(n2->parent!=n2) n2=n2->parent;
			if(n1!=n2){
				n2->parent=n1;
			}
		}
		else if(criterio==2){
			while(n1->parent!=n1) n1=n1->parent;
			while(n2->parent!=n2) n2=n2->parent;
			if(n1!=n2){
				if(n1->range>=n2->range){
					n2->parent=n1;
					if(n1->range==n2->range)
						n1->range++;
				}
				else
					n1->parent=n2;
			}
		}
		else if(criterio==3){
			while(n1->parent!=n1) n1=n1->parent;
			while(n2->parent!=n2) n2=n2->parent;
			if(n1!=n2){
				if(n1->size>=n2->size){
					n2->parent=n1;
					n1->size+=n2->size;
				}
				else{
					n1->parent=n2;
					n2->size+=n1->size;
				}
			}
		}
	}
	void print(int num){
		Node*n=dict[num];
		while(n->parent!=n) n=n->parent;
		cout<<"Elemento "<<num<<" esta en "<<(n->data)<<endl;
	}
};

