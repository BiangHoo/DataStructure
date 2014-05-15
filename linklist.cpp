//BiangHoo,May 2014
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef struct node{
	int value;
	struct node* pNext;
}Node;
class List{
	private:
		node* head;
	public:
	List(int val){
		head = new Node;
		head->value =val;
		head->pNext =NULL;
	}
	void add(int val){
		cout<<"add"<<val<<endl;
		if(head ==NULL){
			head= new Node;
			head->value=val;
			head->pNext=NULL;
		}else{
			node * tmp =head;
			while(tmp->pNext!=NULL){
				tmp=tmp->pNext;
			}
			node* pNew = new Node;
			pNew->value=val;
			pNew->pNext=NULL;
			tmp->pNext=pNew;
		}
		
	}
	node* next(node* tmp){
		if(tmp->pNext!=NULL){
			return tmp->pNext;
		}
		return NULL;
	}
	void print(){
		if(head ==NULL){
			cout<<"the link list is empty"<<endl;
		}else{
			node *tmp = head;
			while(tmp->pNext!=NULL){
				cout<<tmp->value;
				tmp=tmp->pNext;
			}
			cout<<tmp->value;
			cout<<endl;
		}
	}
	int length(){
		int i=0;
		if(head==NULL){
			return 0;
		}else{
			i++;
			node *tmp = head;
                        while(tmp->pNext!=NULL){
				i++;
                                tmp=tmp->pNext;
                        }
		}
		return i;
	}
	int delAt(int k){
		node *tmp =head;
		if(head==NULL||k<0||k>this->length()-1){
			return -1;
		}
		if(k==0){
			head =tmp->pNext;
			delete tmp;
			return 0;
		}
		if(k==this->length()-1){
			tmp=head;
			while(tmp->pNext->pNext!=NULL){
				tmp=tmp->pNext;
			}
			node* pTail = tmp->pNext;
			tmp->pNext =NULL;
			delete pTail;
			return 0;
		}
		tmp=head;
		int i=0;
		while(i<k-1){
			tmp=tmp->pNext;
			i++;
		}
		node *pDel =tmp->pNext;
		tmp->pNext=tmp->pNext->pNext;
		delete pDel;
		return 0;
	}
	int insertAt(int val,int k){
		node* tmp;
		node* p1;
		node* p2;
		if(head==NULL||k<0||k>this->length()-1){
			return -1;
		}
		if(k=0){
			tmp=head;
			node* pNew = new Node;
			pNew->value=val;
			pNew->pNext=NULL;
			head=pNew;
			pNew->pNext=tmp;
		}
	}
};
int main(){
	List list(0);
	for(int i=1;i<5;i++){
		list.add(i);
	}
	cout<<"------"<<endl;
	list.print();
	cout<<list.length()<<endl;
	cout<<"------"<<endl;
	list.delAt(2);
	list.print();
	cout<<list.length()<<endl;
	cout<<"------"<<endl;
	list.delAt(0);
	list.print();
	cout<<list.length()<<endl;
	cout<<"------"<<endl;
	list.delAt(list.length()-1);
	list.print();
	cout<<list.length()<<endl;
	return 0;
}