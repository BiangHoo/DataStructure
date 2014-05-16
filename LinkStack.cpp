//BiangHoo May 2014
//a realization of stack  by using linklist
#include<iostream>
using namespace std;
template<class T>
struct Node{
	T data;
	struct Node<T>* pPre;
};
template<class T>
class LinkStack{
	private:
		Node<T>* top;
		Node<T>* bottom;
	public:
		LinkStack(){
			Node<T>* p=new Node<T>;
			p->data=NULL;
			p->pPre=NULL;
			bottom=p;
			top=bottom;
		}
		~LinkStack(){
			Node<T>*p1;
			Node<T>*p2;
			p1=top;
			while(p1!=NULL){
				p2=p1;
				p1=p1->pPre;
				delete p2;
			}
		}
		bool push(const T& item){
			Node<T>* p=new Node<T>;
			p->data=item;
			p->pPre=top;
			top=p;
			return true;		
		}
		bool pop(T& item){
			if(!isEmpty()){
				Node<T>* p=top;
				item=p->data;
				top=p->pPre;
				delete p;
				return true;
			}
			return false;
		}
		bool isEmpty(){
			return NULL==bottom;
		}
		void print(){
			Node<T>*p1;
			p1=top;
			while(p1!=bottom){
				cout<<p1->data<<" ";
				p1=p1->pPre;
			}
			cout<<endl;
		}
};
int main(){
	LinkStack<int> ls;
	ls.push(10);
	ls.print();
	ls.push(21);
	ls.print();
	ls.push(30);
	ls.print();
	ls.push(26);
	ls.print();
	int t;
	ls.pop(t);
	ls.print();
	ls.pop(t);
	ls.print();
	ls.pop(t);
	ls.print();
	return 0;
}