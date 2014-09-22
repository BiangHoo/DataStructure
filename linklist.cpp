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
		if(k==0){
			tmp=head;
			node* pNew = new Node;
			pNew->value=val;
			pNew->pNext=NULL;
			pNew->pNext=tmp;
			head=pNew;
		}else{
			tmp = head;
			int i=0;
			while(i<k-1){
				tmp=tmp->pNext;
				i++;
			}
			p1=tmp->pNext;
			node *pNew =new Node;
			pNew->value=val;
			pNew->pNext=NULL;
			tmp->pNext=pNew;
			pNew->pNext=p1;
		}
		return 0;
	}
	int getHeadVal(){
		return head->value;
	
	}
	int findVal(int val){
		int i=0;
		node* tmp =head;
		while(tmp!=NULL){
			if(tmp->value == val){
				return i;
			}
			tmp=tmp->pNext;
			i++;
		}
		return -1;
	}
	void sort(){
		int n= this->length();
		node* p1;
		node* p2;
		for(int i=0;i<n-1;i++){
			p1=head;
			for(int j=0;j<n-1-i;j++){
				p2=p1->pNext;
				if(p1->value>p2->value){
					int num = p1->value;  
                    			p1->value = p2->value;  
                    			p2->value = num;
				}
				p1 =p1->pNext;
			}
		}

	}
	int reverse(){
		node *p1,*p2,*p3;
		if(head==NULL||head->pNext==NULL){
			return -1;
		}
		p1=head;
		p2=head->pNext;
		while(p2){
			p3=p2->pNext;
			p2->pNext=p1;
			p1=p2;
			p2=p3;
		}
		head->pNext=NULL;
		head=p1;
	}
	int InsertSort(){//无链表头的链表插入排序
		node *insert = head->pNext;
		head->pNext=NULL;
		Node *pre;
		while(insert){
			node * nInsert = insert->pNext;
			node *cur=head;
			while(cur!=NULL&&(cur->value<insert->value)){
				pre=cur;
				cur=cur->pNext;		
			}
			if(cur==head){//插在第一个节点之前
			    head = insert;
			}else{//pre是Cur的前驱，且pre<insert然后insert<cur或者cur为NULL
				pre->pNext=insert;
			}
			insert->pNext=cur;
			insert=nInsert;
		}
		return 0;
	}
	int InsertSortwithNode(){//带链表头的插入排序
		node * insert = head->pNext;
		head->pNext=NULL;//空链表
		//Node * pre;
		while(insert){
			node *pre=head;//前驱节点
			node *cur=head->pNext;
			while(cur!=NULL&&(cur->value<insert->value)){
				pre = cur;
				cur = cur->pNext;//后继节点
			}
			Node * nInsert = insert->pNext;
			pre->pNext=insert;
			insert->pNext=cur;
			insert=nInsert;	
		}
		return 0;
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
	cout<<"head: "<<list.getHeadVal()<<endl;
	cout<<"------"<<endl;
	list.delAt(2);
	list.print();
	cout<<list.length()<<endl;
	cout<<"------"<<endl;
	list.delAt(0);
	list.print();
	cout<<list.length()<<endl;
	cout<<"head :"<<list.getHeadVal()<<endl;
	cout<<"------"<<endl;
	list.delAt(list.length()-1);
	list.print();
	cout<<"head: "<<list.getHeadVal()<<endl;
	cout<<list.length()<<endl;
	cout<<"---------------------"<<endl;
	list.insertAt(5,0);
	list.print();
	cout<<"head: "<<list.getHeadVal()<<endl;
	list.insertAt(7,1);
	list.print();
	cout<<"head :"<<list.getHeadVal()<<endl;
	cout<<list.length()<<endl;
	cout<<list.findVal(7)<<endl;
	cout<<"......................"<<endl;
	list.sort();
	list.print();
	list.reverse();
	list.print();
	//list.InsertSort();
	//list.print();
	list.InsertSortwithNode();
	list.print();
	return 0;
}