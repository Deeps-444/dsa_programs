#include<iostream>
using namespace std;
const int MAX = 10;
class graphnode{
    public:
    int vertex;
    graphnode* next;
    graphnode(int x){
        vertex = x;
        next = NULL;
    }
};

class graph{
    protected:
    graphnode* list[5];
    int no_nodes;
    public:
    graph(int n){
        no_nodes = n;
        for(int i=0; i<no_nodes; i++){
            list[i] = NULL;
        }
    }
    graphnode* temp = NULL;
    //methods
    void create();
    void display();
    void delete_edge(int v1, int v2);
    void delete_node(int v);
    void DFS();
    void BFS();
};

void graph::create(){
    int ans;
    for(int i=0; i<no_nodes; i++){
        for(int j=0; j<no_nodes; j++){
            cout << "Is there an edge between " << i+1 <<" and " << j+1 <<endl
                 << "Enter 1 for yes and 0 for no.";
            cin >> ans;
            if(ans == 1){
                graphnode *newnode = new graphnode(j+1);
                if(list[i] == NULL){
                    list[i] = newnode;
                    temp = newnode;
                }else{
                    temp->next =newnode;
                    temp = temp->next;
                }
            }
        }
    }
}

void graph::display(){
    for(int i=0; i<no_nodes; i++){
        cout << "Vertex" << i+1 << ": " ;
        temp = list[i];
        while(temp != NULL){
            cout << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void graph::delete_edge(int v1, int v2){
    temp = list[v1-1];
    graphnode* prev = NULL;
    while(temp!=NULL && temp->vertex != v2){
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        if(prev==NULL){
            list[v1-1] = temp->next;
        }else{
            prev->next = temp->next;
        }
        delete(temp);
    }
}

void graph::delete_node(int v){
    for(int i=0; i<no_nodes; i++){
        cout << "v" << list[i]->vertex << " ";
        delete_edge(i+1, v);
    }
    temp = list[v-1];
    graphnode* prev;
    while(temp!=NULL){
        prev = temp;
        temp = temp->next;
        delete(prev);
    }
    list[v-1] = NULL;
}
//stack----------------------------------------------------------------------------------------
class stack_node{
    public:
    int data;
    stack_node* down;
    stack_node(int x) {
        data = x;
        down = NULL;
    }
};

class stack{
    public:
    stack_node* top;
    int count;
    stack(){
        top = NULL;
        count = 0;
    }
    //methods
    bool isStackEmpty(){
        return top == NULL;
    }
    bool isStackFull(){
        return count == MAX;
    }
    void push(int x);
    void pop();
};

void stack::push(int x){
    stack_node* newnode = new stack_node(x);
    if(isStackFull()){
        cout << "Stack Overflow!" << endl;
        return;
    }
    if(isStackEmpty()){
        top = newnode;
    }else{
        newnode->down = top;
        top = newnode;
    }
    count++;
}

void stack::pop(){
    stack_node* temp = top;
    top = top->down;
    delete(temp);
    count--;
}

void graph::DFS(){
    int visited[no_nodes] = {0};
    int start = 1;
    stack s;
    visited[start-1] = 1;
    cout << "DFS: " << start << ", ";
    s.push(start);
    while(!s.isStackEmpty()){
        int top_vertex = s.top->data;
        s.pop();
        temp = list[top_vertex-1];
        while(temp!=NULL){
            if(!visited[temp->vertex-1]){
                cout << temp->vertex << ", ";
                visited[temp->vertex-1] = 1;
                s.push(temp->vertex);
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

//Queue-------------------------------------------------------------------------------
class Qnode{
    public:
    int Qdata;
    Qnode* next ;
    Qnode(int x){
        Qdata = x;
        next = NULL;
    }
};

class queue{
    public: 
    Qnode *front, *rear;
    int count;
    queue(){
        front = rear = NULL;
        count = 0;
    }
    //methods
    bool isQempty(){
        return front == NULL;
    }
    bool isQfull(){
        return count == MAX;
    }
    void enqueue(int x);
    void dequeue();
};

void queue::enqueue(int x){
    Qnode* newnode = new Qnode(x);
    if(isQfull()){
        cout << "Queue Overflow!";
        return;
    }
    if(isQempty()){
        front = rear = newnode;
    }else{
        rear->next = newnode;
        rear = rear->next;
    }
    count++;
}

void queue::dequeue(){
    if(isQempty()){
        cout << "Queue Underflow!";
        return;
    }
    Qnode* temp = front;
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    delete(temp);
    count--;
}

void graph::BFS(){
    int visited[no_nodes] = {0};
    queue q;
    int start = 1;
    visited[start-1] = 1;
    q.enqueue(start);
    cout << "BFS: ";
    while(!q.isQempty()){
        int curr = q.front->Qdata;
        cout << curr << " ";
        q.dequeue();
        temp = list[curr-1];
        while(temp!=NULL){
            if(!visited[temp->vertex-1]){
                visited[temp->vertex-1] = 1;
                q.enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    int choice, p, n;
    cout << "Enter the number of nodes required in the graph: ";
    cin >> n;
    graph g(n);
    do{
        cout << "Enter your choice: " << endl
             << "1) Create graph" << endl
             << "2) display graph" << endl
             << "3) Delete an edge" << endl
             << "4) Delete a node" << endl
             << "5) Depth First Search" << endl
             << "6) Breadth First Search" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                g.create(); break;
            }
            case 2:{
                g.display(); break;
            }
            case 3:{
                int v1, v2;
                cout << "enter starting vertex and ending vertex of the edge to delete: ";
                cin >> v1 >> v2;
                g.delete_edge(v1, v2);
                break;
            }
            case 4:{
                int v;
                cout << "Enter the node to delete: ";
                cin >> v;
                g.delete_node(v);
                break;
            }
            case 5:{
                g.DFS();
                break;
            }
            case 6:{
                g.BFS();
                break;
            }
            default:{
                cout << "No such option exists!" << endl; break;
            }
        }
        cout <<"To continue enter 1. ";
        cin >> p;
    }while(p==1);
    return 0;
}