//practice SLL
#include<iostream>
#include<stdlib.h>

using namespace std;

//defining node class
class node 
{
	public:
		int data;
		node* next;
};

//inheriting node class to list class
class list : public node
{
	node *listptr, *temp;
	//list constructor
	public:
		list(){
		listptr = NULL;
		temp = NULL;
	}
	//declaring functions
	void create();
	void display();
	void insert_start();
	void insert_end();
	void insert_inter();
};

//function to create list
void list :: create()
{
	int i, n, x;
	cout<<"Enter the size of SLL: ";
	cin>> n;
	
	for (i=0; i<n; i++){
		//new node
		node* newnode = new node();
		cout << "Enter data: ";
		cin >> x;
		newnode->data = x;
		newnode->next = NULL;
		
		if (listptr == NULL){
			listptr = newnode;
			temp = listptr;
		}
		else{
			temp->next = newnode;
			temp = temp->next;
		}
	}
}

//function to display the list
void list :: display()
{
	temp = listptr;
	while(temp->next != NULL){
		cout << temp->data <<"->";
		temp = temp->next;
	}
	cout << temp->data ;
}

//function to insert at start
void list :: insert_start()
{
	int x;
	//create new node
	node* newnode = new node();
	cout << "Enter data to insert at start: ";
	cin >> x;
	newnode->data = x;
	newnode->next = NULL;
	//connect with listptr
	newnode->next = listptr;
	listptr = newnode;
}

//insert at end
void list :: insert_end()
{
	int x;
	//create new node
	node* newnode = new node();
	cout << "Enter data to insert at end: ";
	cin >> x;
	newnode->data = x;
	newnode->next = NULL;
	//intialize temp
	temp = listptr;
	while(temp->next != NULL){
		temp = temp->next ;
	}
	//linking
	temp->next = newnode;
}

//insert at intermediate position
void list :: insert_inter()
{
	 int x, pos, i;
	//create new node
	node* newnode = new node();
	cout << "Enter data to insert at end: ";
	cin >> x;
	newnode->data = x;
	newnode->next = NULL;
	cout << "Enter the position to insert at: ";
	cin >> pos;
	for(i=0; i<pos-1; i++){
		temp = temp->next ;
	}
	newnode->next = temp->next->next;
	temp->next = newnode; 
}

//menu in main
int main()
{
	int choice, p=1;
	list l;
	while(p==1){
		cout<<"\nEnter your choice: \n 1)Create list \n 2)display list \n 3)insert at start \n 4)insert at end \n 5)insert at intermediate position" << endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();
				break;
			case 3:
				l.insert_start();
				break;
			case 4:
				l.insert_end();
				break;
			case 5:
				l.insert_inter() ;
		}
		cout<<"\nEnter 1 to continue: ";
		cin>>p; 
	}
	return 0;
}
