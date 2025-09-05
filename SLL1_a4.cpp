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
	//list constructor
	public:
		node *listptr, *temp, *q, *listptr1, *listptr2, *temp1, *temp2, *p;
		list(){
		listptr = NULL;
		temp = NULL;
		listptr1 = NULL;
		listptr2 = NULL;
		temp1 = NULL;
		temp2 = NULL;
	}
	//declaring functions
	void create();
	void display();
	void insert_start();
	void insert_end();
	void insert_inter();
	void insert_after();
	void delete_start();
	void delete_end();
	void delete_inter();
	void delete_after();
	void reverse();
	void SLL1();
	void SLL2();
	void concat();
	void SLL1_display();
	void merge();
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
	cout << "Enter data to insert at intermediate position: ";
	cin >> x;
	newnode->data = x;
	newnode->next = NULL;
	cout << "Enter the position to insert at: ";
	cin >> pos;
	temp = listptr;
	for(i=0; i<pos-2; i++){
		temp = temp->next ;

	}
	if(temp->next  != listptr && temp->next != NULL){//checking for first and last positions
		newnode->next = temp->next;
	    temp->next = newnode; 
	}
	else{
		cout << "Not an inetrmediate poition";
	}
}
//inserting after
void list :: insert_after()
{
	int x, after, i;
	//create new node
	node* newnode = new node();
	cout << "Enter data to insert at intermediate position: ";
	cin >> x;
	newnode->data = x;
	newnode->next = NULL;
	cout << "Enter the value after which given data will be inserted: ";
	cin >> after;
	//temp initialization
	temp = listptr;
	//traversal
	while(temp->data != after){
		temp = temp->next ;
	}
	newnode->next = temp->next ;
	temp->next = newnode;
}

//delete at start
void list :: delete_start()
{
	temp = listptr;
	listptr = listptr->next ;
	delete(temp);
}

//delete end
void list :: delete_end()
{
	temp = listptr; //initialize
	//traversal
	while(temp->next->next != NULL){
		temp = temp->next ;
	}
	delete(temp->next);
	temp->next = NULL;
}

//delete at intermediate position
void list :: delete_inter()
{
	int pos, i;
	cout << "Enter the postion of element to delete: ";
	cin >> pos;
	q = listptr ;
	i = 0;
	while(i< pos-2){
		q = q->next ;
		i++;
	}
	temp = q->next ;
	q->next = temp->next ;
	delete(temp);
}

//delete after
void list :: delete_after()
{
	int after;
	cout << "Enter value u want to delete after: ";
	cin >> after;
	temp = listptr;
	while(temp->data != after){
		temp = temp->next ;
	}
	q = temp->next ;
	temp->next = q->next ;
	delete(q);	
}

//reverse SLL
void list :: reverse()
{
	node *forward, *curr, *back;
	forward = listptr;
	curr = NULL;
	while(forward != NULL){
		back = curr;
		curr = forward;
		forward = forward->next ;
		curr->next = back;//back linking
	}
	listptr = curr;
}

//create 1st sll
void list :: SLL1()
{
	int i, n, x;
	cout << "1st SLL:-" << endl;
	cout<<"Enter the size of SLL: ";
	cin>> n;
	
	for (i=0; i<n; i++){
		//new node
		node* newnode = new node();
		cout << "Enter data: ";
		cin >> x;
		newnode->data = x;
		newnode->next = NULL;
		
		if (listptr1 == NULL){
			listptr1 = newnode;
			temp = listptr1;
		}
		else{
			temp->next = newnode;
			temp = temp->next;
		}
	}
}
//2nd SLL
void list :: SLL2()
{
	int i, n, x;
	cout << "2nd SLL:-" << endl;
	cout<<"Enter the size of SLL: ";
	cin>> n;
	
	for (i=0; i<n; i++){
		//new node
		node* newnode = new node();
		cout << "Enter data: ";
		cin >> x;
		newnode->data = x;
		newnode->next = NULL;
		
		if (listptr2 == NULL){
			listptr2 = newnode;
			temp = listptr2;
		}
		else{
			temp->next = newnode;
			temp = temp->next;
		}
	}
}
//conacatenate
void list :: concat()
{
	temp = listptr1;
	while(temp->next != NULL){
		temp = temp->next ;
	}  
	temp->next = listptr2;
}
void list:: SLL1_display()
{
    temp = listptr1;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data ;
}

//merge
void list :: merge()
{
	temp1 = listptr1;
	while(temp1->next != NULL){
		temp2 = listptr2;
		while(temp2->next != NULL){
			if(temp1->data == temp2->data){
				if(temp2 == listptr2){
					q = temp2;
					temp2 = temp2->next;
					listptr2 = listptr2->next;
					delete(q);
				}
				else if(temp2->next == NULL){
					q = temp2;
					temp2 = listptr2;
					delete(q);
				}
				else{
					q = temp2;
					temp2 = temp2->next ;
					p = listptr2;
					while(p->next != q){
						p = p->next;
					}
					p->next = q->next;
					delete(q);
				}
			}
			else{
				temp2 = temp2->next ;
			}
		}
		temp1 = temp1->next ;
	}
	temp1->next = listptr2;
}
//menu in main
int main()
{
	node* listptr = NULL;
	node*  listptr1 = NULL;
	node* listptr2  = NULL;
	int choice, p=1;
	list l;
	while(p==1){
		cout << "\nEnter your choice: " << endl;
		cout << "1)Create list " << endl;
		cout << "2)display list " << endl;
		cout << "3)insert at start" << endl;
		cout << "4)insert at end " << endl; 
		cout << "5)insert at intermediate position" << endl;
		cout << "6)insert after an elment" << endl;
		cout << "7)delete at start" << endl;
		cout << "8)delete at end" << endl;
		cout << "9)delete at intermediate position" << endl;
		cout << "10)delete after an element" << endl;
		cout << "11)reverse SLL" << endl;
		cout << "12)conatenate SLLs" << endl;
		cout << "13)merge SLLs" << endl;
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
				break;
			case 6:
				l.insert_after() ;
				break;
			case 7:
				l.delete_start() ;
				break;
			case 8:
				l.delete_end() ;
				break;
			case 9:
				l.delete_inter() ;
				break;
			case 10:
				l.delete_after() ;
				break;
			case 11:
				l.reverse() ;
				break;
			case 12:
				l.SLL1() ;
				l.SLL2() ;
				l.concat();
	            l.SLL1_display() ;	
				break;
			case 13:
				l.SLL1() ;
				l.SLL2() ;
				l.merge() ;
				l.SLL1_display() ;
				break;
		}
		cout << "\nEnter 1 to continue: ";
		cin >> p; 
	}
	return 0;
}
