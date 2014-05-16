//BiangHoo May 2014
//the realization of queue by using dynamic array
#include<iostream>
using namespace std;
template<class T>//模板
class Queue{
	private:
		T* q;
		int front;
		int rear;
		int maxSize;
	public:
		Queue(int maxSize){
			q=new T[maxSize];
			this->maxSize=maxSize;
			front=rear=0;
		}
		~Queue(){
			delete[] q;
		}
		int Size(){
			return (rear-front);
		}
		bool isEmpty(){
			return front==rear;
		}
		bool push(const T &item){
			if(rear>=maxSize){
				cout<<"dynamic array"<<item<<endl;
				maxSize=(rear-front)*2;//using dynamic array to extend the volume of queue
				T* tmp= new T[maxSize];
				int j=0;
				for(int i=front;i<rear;i++){
					tmp[j++]=q[i];
				}
				delete q;
				q=tmp;
				rear=rear-front;
				front=0;
			}
			q[rear++]=item;
			return true;
			
		}
		bool pop( T& item){//pop element from the front of the queue
			if(isEmpty()){
				cout<<"the Queue is empty!"<<endl;
				return false;
			}else{
				item=q[front];
				q[front++]=NULL;
				return true;
			}
		}
		void print(){
			for(int i=front;i<rear;i++){
				cout<<q[i]<<" ";
			}
			cout<<endl;
		}
		int capacity(){
			return maxSize;
		}
};
int main(){
	Queue<int> q(3);
	q.push(10);
	q.push(12);
	cout<<"size:"<<q.capacity()<<endl;
	q.print();
	q.push(3);
	q.push(5);
	cout<<"size:"<<q.capacity()<<endl;
	q.print();
	int t;
	q.pop(t);
	q.print();
	return 0;
}