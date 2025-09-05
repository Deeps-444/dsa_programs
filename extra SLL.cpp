//linked list practice
#include<iostream>
using namespace std;

//node------------
class node{
    public:
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    }
};

class list{
    node *listptr, *temp;
    public:
    int count;
    list(){
        listptr = NULL;
        temp = NULL;
        count = 0;
    }
    //methods:
    void create();
    void display();
    void middleNode();
    void BubbleSort();
};

void list::create(){
    int size, x;
    cout << "Enter the size of the singly linked list: ";
    cin >> size;
    for(int i=0; i<size; i++){
        cout << "enter data: ";
        cin >> x;
        node* newnode = new node(x);
        if(listptr == NULL){
            listptr = newnode;
            temp = listptr;
            count ++;
        }else{
            temp->next = newnode;
            temp = temp->next;
            count++;
        }
    }
    cout << "Count = " << count << endl;
}

void list::display(){
    temp = listptr;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void list::middleNode(){
    int mid = count/2;
    temp = listptr;
    for(int i=0; i<mid+1; i++){
        temp = temp->next;
    }
    cout << "The middle element is: " << temp->data << endl;
}
// void swap(node *a, node *b){
//     int x = *a;
//     *a = *b;
//     *b = x;
// }
// void list::BubbleSort(){
//     node *p, *q;
//     p = listptr;
//     for(int i=0; i<count-1; i++){
//         p = p->next;
//         q = listptr;
//         for(int j=0; j<count-1-i; j++){
//             if(q->data < q->next->data){
//                 swap(q, q->next);
//             }
//         }
//     }
// }

int main(){
    list l;
    int choice, p;
    do{
        cout <<"Enter a choice: " << endl
             <<"1) Create SLL" << endl
             <<"2) Display SLL" << endl
             <<"3) Find Middle element" << endl
             <<"4) sort the list" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                l.create(); break;
            }
            case 2:{
                l.display(); break;
            }
            case 3:{
                l.middleNode(); break;
            }
            case 4:{
                l.BubbleSort();
                // cout << "Sorted SLL: ";
                // l.display(); 
                break;
            }
            default:{
                cout << "This option does not exist!"; break;
            }
        }
        cout << "\nTo continue enter 1. " << endl;
        cin >> p;
    }while(p==1);
}