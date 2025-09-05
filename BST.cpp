//binary search tree
#include<iostream>
#include<stdlib.h>
using namespace std;
const int max = 25;
class node{
	int data;
	node *right, *left;
	public:
		node(int n){
			data = n;
			left = NULL;
			right = NULL;
		}
		friend class bst;
};

class bst{
	node *root, *temp;
	public:
		bst(){
			root = NULL;
		} 
	//functions
	void create();
	void display();
	void inorder(node* curr);
	void preorder(node* curr);
	void postorder(node* curr);
	void insert_node(); 
	void search_node();
	void min_value();
	void max_value();
	void delete_node();
};

void bst::create() 
{
	int x, choice;
	do{
		cout << "enter data: ";
		cin >> x;
		node* newnode = new node(x);
		
		if(root == NULL){
			root = newnode;
		}
		else{
			temp = root;
			while(1){
				if(temp->data > x){
					if(temp->left == NULL){
						temp->left = newnode;break;
					}
					else{
						temp = temp->left;
				    }
				}
				else{
					if(temp->right == NULL){
						temp->right = newnode; break;
					}
					else{
						temp = temp->right;
				    }	
				}
			}
		}
		cout << "Any more nodes? ";
		cout << "Enter 1 to continue adding.";
		cin >> choice;
	}while(choice == 1);
}

// display
void bst::display(){
	cout << "\nInorder: \t";
	inorder(root);
	cout << "\nPreorder: \t";
	preorder(root);
	cout << "\nPostorder: \t";
	postorder(root);
}
//inorder
void bst::inorder(node* curr) 
{
	if(curr == NULL){
		return;
	}
	//LDR
	inorder(curr->left);
	cout << curr->data << ", ";
	inorder(curr->right);
}
//preorder
void bst::preorder(node* curr) 
{
	if(curr == NULL){
		return;
	}
	//DLR
	cout << curr->data << ", ";
	inorder(curr->left);
	inorder(curr->right);
}
//postorder
void bst::postorder(node* curr) 
{
	if(curr == NULL){
		return;
	}
	//LRD
	inorder(curr->left);
	inorder(curr->right);
	cout << curr->data << ", ";
}

//inserting a node
void bst::insert_node()
{
	int x; 
	cout << "Enter data to insert: ";
	cin >> x;
	node *newnode = new node(x);
	temp = root;
	while(1){
		if(root == NULL){
			root = newnode;
		}
		else{
			if(temp->data > newnode->data){
				if(temp->left == NULL){
					temp->left =  newnode; break;
				}else{
					temp = temp->left;
				}
			}else{
				if(temp->right == NULL){
					temp->right = newnode; break;
				}else{
					temp = temp->right;
				}
			}
			
		}
	}
}

//searching a node
void bst::search_node() 
{
	int x;
	cout << "Enter the value you want to search: ";
    cin >> x;
	temp = root;
	while(temp != NULL && temp->data != x){
		if(x<temp->data){
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}
	cout << "The key is present in the tree? ";
	if(temp==NULL){
		cout << "no";
	}else{
		cout << "yes";
	}
}

//finding minimum value
void bst::min_value() 
{
	int min;
	temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	min = temp->data;
	cout << "The minimum value is: " << min << endl;
}

//finding max value
void bst::max_value()
{
	int max;
	temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	max = temp->data;
	cout << "The maximum value is: " << max << endl;
}

void bst::delete_node()
{
	int x;
	node  *parent, *r, *son, *father;
	cout << "Enter the node to delete: ";
	cin >> x;
	node* temp = root;
	while(temp!=NULL && temp->data!=x){
		if(x<temp->data){
			parent = temp;
			temp = temp->left;
		}else{
			parent = temp;
			temp = temp->right;
		}
	}
	if(temp==NULL){
		cout << "node not found";
		return;
	}
	if(temp->right == NULL){
		r = temp->left;
	}
	else if(temp->left == NULL){
		r = temp->right;
	}else{
		father = temp;
		r = temp->right;
		son = r->left;
		while(son!=NULL){
			father = r;
			r = son;
			son = r->left;
		}
		if(father!=temp){
			father->left = r->right;
			r->right = temp->right;
		}
		r->left = temp->left;
	}
	
	if(parent==NULL){
		root = r;
	}else{
		if(temp == parent->left){
			parent->left = r;
		}else{
			parent->right = r;
		}
	}
	delete(temp);
	return ;
}

int main()
{
	bst t;
	int choice, p;
	do{
		cout<<"Enter choice: " <<endl
		    << "1) Create Binary Search Tree"<< endl
			<< "2) Display Binary Search Tree" << endl
			<< "3) Insert a node" << endl
			<< "4) Search a node" << endl
			<< "5) Find minimum value" << endl
			<< "6) Find maximum value" << endl
			<< "7) Delete a node" << endl;
		cin >> choice;
		switch(choice){
			case 1:{
				t.create(); break;
			}
			case 2:{
				t.display(); break;
			}
			case 3:{
				t.insert_node(); break;
			}
			case 4:{
				t.search_node(); break;
			}
			case 5:{
				t.min_value();
				break;
			}
			case 6:{
				t.max_value();
				break;
			}
			case 7:{
				t.delete_node();
				break;
			}
		}
		cout << "\nTo continue, enter 1. " ;
		cin >> p;
	}while(p==1);
	return 0;
}
