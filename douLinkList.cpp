//BiangHoo May 2014
//Description:linklist
#include<iostream>
using namespace std;
typedef struct node{
	int val;
	struct node* pPre;
	struct node* pNext;
}Node,*pNode;
class LinkList{
	private:
		pNode head;
	public:
		LinkList(int val){
			head = new Node;
			head->val=val;
			head->pPre=NULL;
			head->pNext=NULL;
		}
		~LinkList(){

		}
		int addElement(int val){
			pNode p1,p2;
			if(head==NULL){
				head= new Node;
 				head->val=val;
                        	head->pPre=NULL;
                        	head->pNext=NULL;
				return 0;
			}
			p1 =head;
			while(p1->pNext!=NULL){
				p1=p1->pNext;
			}
			p2 = new Node;
			p2->val=val;
			p2->pPre=p1;
			p2->pNext=NULL;
			p1->pNext=p2;
			return 0;
		
		}
		int length(){
			if(head==NULL){
				return 0;
			}
			int i=0;
			pNode p1,p2;
			p1 = head;
			i++;
			while(p1->pNext!=NULL){
				i++;
				p1=p1->pNext;
			}
			return i;
		}
		int insert(int loc,int val){
			while(head==NULL||loc<0||loc>length()-1){
				return -1;
			}
			pNode p1,p2;
			if(0==loc){
				p1=new Node;
				p1->val=val;
				p1->pNext=head;
				p1->pPre=NULL;
				head->pPre=p1;
				head=p1;
				return 0;
			}
			if(length()-1==loc){
				p1=head;
				while(p1->pNext!=NULL){
					p1=p1->pNext;
				}
				p2 = new Node;
				p2->val=val;
				p2->pPre=p1;
				p1->pNext=p2;
				p2->pNext=NULL;
				return 0;
			}
			p1=head;
			int i=0;
			while(i<loc-1){
				p1=p1->pNext;
				i++;
			}
			p2 = new Node;
                        p2->val=val;
                        p2->pPre=p1;
			pNode p3=p1->pNext;
                        p3->pPre=p2;
                        p2->pNext=p3;
			p1->pNext=p2;
                        return 0;
		}
		int delAt(int loc){
			while(head==NULL||loc<0||loc>length()-1){
				return -1;
			}
			pNode p1,p2,p3;
			int i=0;
			if(0==loc){
				p1=head;
				p2=head->pNext;
				p2->pPre=NULL;
				head=p2;
				delete p1;
				return 0;
			}
			if(length()-1==loc){
				p1=head;
				while(p1->pNext->pNext!=NULL){
					p1=p1->pNext;
				}
				p2=p1->pNext;
				p1->pNext=NULL;
				delete p2;
				return 0;	
			}
			p1=head;
			while(i<loc-1){
				p1=p1->pNext;
				i++;
			}
			p2=p1->pNext;
			p3=p2->pNext;
			p1->pNext=p3;
			p3->pPre=p1;
			delete p2;
			return 0;
		}
		int print(){
			pNode p1,p2;
			if(head==NULL){
				return 0;
			}
			p1=head;
			while(p1->pNext!=NULL){
				cout<<p1->val<<" ";
				p1=p1->pNext;
			}
			cout<<p1->val<<endl;
		}
		
};
int main(){
	LinkList list(0);
	for(int i=1;i<5;i++){
		list.addElement(i);
	}
	list.print();
	cout<<"___________"<<endl;
	list.insert(0,10);
	list.print();
	list.insert(3,12);
	list.print();
	list.insert(list.length()-1,9);
	list.print();
	list.delAt(1);
	list.print();
	list.delAt(0);
	list.print();
	list.delAt(list.length()-1);
	list.print();
	return 0;
}