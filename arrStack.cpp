//BiangHoo May 2014
//a realization of stack  by using dynamic array
#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		int capacity;
		T* stack;
		int top;
		int bottom;
	public:
		Stack(int cap){
			this->capacity=cap;
			stack=new T[cap];
			top=bottom=0;
		}
		bool push(const T& item){
			if(top>=capacity){
				capacity=capacity*2;
				T* tmp=new T[capacity];
				int j=0;
				for(int i=0;i<capacity;i++){
					tmp[j++]=stack[i];
				}
				delete stack;
				stack=tmp;
			}
			stack[top++]=item;
		}
		bool pop(T& item){
			if(!isEmpty()){
				T tmp=stack[top--];
				item=tmp;
			}
			return false;
		}
		bool isEmpty(){
			return top==bottom;
		}
		void print(){
			cout<<"bottom: ";
			for(int i=bottom;i<top;i++){
				cout<<stack[i]<<" ";
			}
			cout<<endl;
		}
		int getCapa(){
			return capacity;
		}
};
int main(){
	Stack<int> s(3);
	s.push(1);
	s.print();
	cout<<"size:"<<s.getCapa()<<endl;
	s.push(20);
	s.print();
	cout<<"size:"<<s.getCapa()<<endl;
	s.push(15);
	s.print();
	cout<<s.getCapa()<<endl;
	s.push(17);
	s.print();
	cout<<s.getCapa()<<endl;
	int t;
	s.pop(t);
	s.print();
	cout<<s.getCapa()<<endl;
	s.pop(t);
	s.print();
	cout<<s.getCapa()<<endl;
	return 0;
}