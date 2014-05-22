//BiangHoo May 2014
//reference:http://www.cnblogs.com/skywang12345/p/3576373.html
#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
#include<iostream>
using namespace std;
template<class T>
class BinaryNode{
	public:
		T val;
		BinaryNode *parent;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(T val,BinaryNode *p,BinaryNode *left,BinaryNode *right):val(val),parent(p),left(left),right(right){}
};
template<class T>
class BSTree{
	private:
		BinaryNode<T> *root;
	public:
		BSTree();
		~BSTree();
		T  findMin();
		T  findMax();
		BinaryNode<T> * search(T val);
		void preOrderTravesal();
		void midOrderTravesal();
		void postOrderTravesal();
		void insert(const T  x);
		void remove(const T  val);
		void printTree() const;
		void destroy();
		//BinaryNode<T>* successor(BinaryNode<T> *x);
		//BinaryNode<T>* predecessor(BinaryNode<T> *x);
	private:
		BinaryNode<T>* search(BinaryNode<T>* x,T val)const;
		BinaryNode<T>* findMin(BinaryNode<T>* tree);
		BinaryNode<T>* findMax(BinaryNode<T>* tree);
		void preOrderTravesal(BinaryNode<T>* tree)const;
		void midOrderTravesal(BinaryNode<T>* tree)const;
		void postOrderTravesal(BinaryNode<T>* tree)const;
		void insert(BinaryNode<T>* & tree,BinaryNode<T>* z);
		void printTree(BinaryNode<T>* tree,T val,int dir);
		void destroy(BinaryNode<T>* &tree);
		void remove(const T val,BinaryNode<T> *t);//BiangHoo
};
template <class T>
BSTree<T>::BSTree():root(NULL)
{
}
template <class T>
BSTree<T>::~BSTree(){
	destroy();
}
template <class T>
void BSTree<T>::preOrderTravesal(BinaryNode<T>* tree) const{
	if(tree!=NULL){
		cout<<tree->val<<" ";
		preOrderTravesal(tree->left);
		preOrderTravesal(tree->right);
	}
}
template <class T>
void BSTree<T>::preOrderTravesal(){
	preOrderTravesal(root);
}
template <class T>
void BSTree<T>::midOrderTravesal(BinaryNode<T>* tree) const{
	if(tree!=NULL){
		midOrderTravesal(tree->left);
		cout<<tree->val<<" ";
		midOrderTravesal(tree->right);
	}
}
template <class T>
void BSTree<T>::midOrderTravesal(){
	midOrderTravesal(root);
}
template <class T>
void BSTree<T>::postOrderTravesal(BinaryNode<T>* tree) const{
	if(tree!=NULL){
		postOrderTravesal(tree->left);
		postOrderTravesal(tree->right);
		cout<<tree->val<<" ";
	}
}
template <class T>
void BSTree<T>::postOrderTravesal(){
	postOrderTravesal(root);
}
template <class T>
BinaryNode<T>* BSTree<T>::search(BinaryNode<T>* x,T val)const{
	if(x==NULL ||x->val==val){
		return x;
	}
	if(val<x->val){
		return search(x->left,val);
	}else{
		return search(x->right,val);
	}
}
template<class T>
BinaryNode<T>* BSTree<T>::search(T key){
	search(root,key);
}
template<class T>
BinaryNode<T>* BSTree<T>::findMin(BinaryNode<T>* tree){
	if(NULL==tree){
		return NULL;
	}
	while(tree->left !=NULL){
		tree = tree->left;
	}
	return tree;
}
template<class T>
T BSTree<T>::findMin(){
	BinaryNode<T> *p = findMin(root);
	if(p != NULL){
		return p->key;
	}
	return (T)NULL;
}
template<class T>
BinaryNode<T>* BSTree<T>::findMax(BinaryNode<T>* tree){
	if(NULL==tree){
		return NULL;
	}
	while(tree->right !=NULL){
		tree = tree->right;
	}
	return tree;
}
template<class T>
T BSTree<T>::findMax(){
	BinaryNode<T> *p = findMax(root);
	if(p != NULL){
		return p->key;
	}
	return (T)NULL;
}
template <class T>
void BSTree<T>::insert(BinaryNode<T>* &tree,BinaryNode<T>* z){
	BinaryNode<T> *y = NULL;
	BinaryNode<T> *x = tree;
	while(x != NULL){
		y = x;
		if(z->val<x->val){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->parent =y;
	if(y==NULL){
		tree = z;
	}else if(z->val<y->val){
		y->left = z;	
	}else{
		y->right = z;
	}
}
template <class T>
void BSTree<T>::insert(T val){
	BinaryNode<T> *z = NULL;
	if (NULL==(z=new BinaryNode<T>(val,NULL,NULL,NULL))){
		return ;
	}
	insert(root,z);
}
/*template<class T>
BinaryNode<T>* BSTree<T>::remove(BinaryNode<T>* &tree,BinaryNode<T> *z){
	BinaryNode<T> *x = NULL;
	BinaryNode<T> *y = NULL;
	
}*/
template<class T>
void BSTree<T>::remove(const T val,BinaryNode<T> *t){
	if(NULL == t){
		return ;
	}else if(val<(t->val)){
		remove(val,t->left);
	}else if(val>(t->val)){
		remove(val,t->right);
	}else if(t->left !=NULL && t->right != NULL){
		t->val=findMin(t->right)->val;
		remove(t->val,t->right);
	}else{
		BinaryNode<T> *tmp=t;
		BinaryNode<T> *pNode =t->parent;
		cout<<"PNode:"<<pNode->val<<endl;
		if(t->left==NULL&&t->right==NULL){
			if(pNode->left==t){
				pNode->left=NULL;
			}else{
				pNode->right=NULL;
			}
		}else{
			t=((t->left!=NULL)?t->left:t->right);
			cout<<"t :"<<t->val<<endl;
			t->parent=pNode;
			if(pNode->left==tmp){
				pNode->left=t;
			}else{
				pNode->right=t;
			}
		}
		delete tmp;
	}
}
template<class T>
void BSTree<T>::remove(const T val){
	remove(val,root);
}
#endif