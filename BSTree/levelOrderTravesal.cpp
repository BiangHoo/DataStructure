#include<iostream>
using namespace std;
void levelOrderTravesal(Tree * root){
	//借助队列，二叉树层次遍历
	queue<Tree> q;
	Tree *p=NULL;
	if(root){
		q.pop(root);
	}
	while(!q.empty()){
		p=q.front();
		q.pop();
		cout<<p->val<<" ";
		if(p->left){
			q.push(p->left);
		}
		if(p->right){
			q.push(p->right);
		}
		
	}
}