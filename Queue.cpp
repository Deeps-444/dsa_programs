//queue
#include<iostream>
using namespace std;

const int MAX = 25;
class node{
	public:
		int data;
		node* next;
		node(int x){
			data = x;
			next = NULL;
		}
};

class queue{
	node *front, *rear;
	public:
		int count;
		queue(){
			front = NULL;
			rear = NULL;
			count = 0;
		}
		//methods
		void enqueue(int v);
		void dequeue();
		bool isFull(){
			return count == MAX;
		}
		bool isEmpty(){
			return front == NULL;
		}
		void display(); 
};

void queue::enqueue(int v){
	node* newnode = new node(v);
	node* temp;
	if(isFull()){
		cout << "Queue Overflow!";
		return;
	}
	if(isEmpty()){
		front = newnode;
		rear = newnode;
		temp = newnode;
	}else{
		temp->next = newnode;
		rear = newnode;
		temp = temp->next;
	}
	count++;
	cout << v << "added to the queue." << endl;	
}

void queue::dequeue(){
	if(isEmpty()){
		cout << "Queue Underflow!";
		return;
	}
	cout << front->data << "Removed from the queue" << endl;
	node* temp = front;
	front = front->next;
	delete(temp);
	count--; 
}

int main()
{
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	return 0;
}
