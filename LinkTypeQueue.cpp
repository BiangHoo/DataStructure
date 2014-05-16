//BiangHoo,May 2014
#include<iostream>
using namespace std;
template <class T>
struct Node{
	Node<T>* next;
	T data;
};

template<class T>
class Queue{
	private:
	int len;
	Node<T>* front;
	Node<T>* rear;
	public:
	Queue(){
		len=0;
		Node<T>* p=new Node<T>;
		if(NULL==p){
			cout<<"fail to initialize Queue"<<endl;
		}
		p->data = NULL;
		p->next = NULL;
		front=p;
		rear=p;
	}
	~Queue(){
		Node<T>* p1;
		Node<T>* p2;
		p1=front;
		while(p1!=NULL){
			p2=p1;
			p1=p1->next;
			delete p2;
		}	
	}
	void push(const T &m){
		if(isEmpty()){
			Node<T>* p =new Node<T>;
			p->data=m;
			p->next=NULL;
			front=p;
			rear=front;
		}else{
			Node<T>* p =new Node<T>;
			p->data=m;
			p->next=NULL;
			rear->next=p;
			rear=p;
		}
		len++;
	}
	bool isEmpty(){
		return 0==len;
	}
	void pop(T &m){
		if(!isEmpty()){
		Node<T>* tmp;
		tmp=front;
		front=front->next;
		len--;
		}else{
			cout<<"the queue is empty"<<endl;
		}
	}
	void print(){
		Node<T>* tmp=front;
		while(tmp!=NULL){
			cout<<tmp->data<<" ";
			tmp=tmp->next; 
		}
		cout<<endl;
	}
};
int main(){
	Queue<int> q;
	q.push(12);
	q.print();
	q.push(11);
	q.print();
	q.push(10);
	q.print();
	int t;
	q.pop(t);
	q.print();
	q.pop(t);
	q.print();
	return 0;
}