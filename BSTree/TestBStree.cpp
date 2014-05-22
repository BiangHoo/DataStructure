#include<iostream>
#include"BSTree.h"
using namespace std;
int main(){
	BSTree<int>* tree = new BSTree<int>();
	cout<<"soga"<<endl;
	int arr[]={1,5,4,3,2,6};
	for(int i=0;i<6;i++){
		tree->insert(arr[i]);
	}
	cout<<"pre:"<<endl;
	tree->preOrderTravesal();
	tree->remove(4);
	cout<<"pre:"<<endl;
	tree->preOrderTravesal();
	cout<<"mid:"<<endl;
	tree->midOrderTravesal();
	cout<<endl;
	return 0;
}