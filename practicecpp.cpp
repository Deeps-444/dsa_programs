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
};

//function to create list
void list :: create()
{
	int i, n, x;
	cout<<"\nEnter the size of SLL: \n";
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

//menu in main
int main()
{
	int choice, p=1;
	list l;
	while(p==1){
		cout<<"\nEnter your choice: \n 1)Create list \n 2)display list";
		cin>>choice;
		switch(choice)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();
		}
		cout<<"Enter 1 to continue: ";
		cin>>p;
	}
	return 0;
}
