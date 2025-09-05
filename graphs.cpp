#include<iostream>
using namespace std;

const int MAX = 20;
const int INF = 999999;  // Representing "infinity" for Prim's Algorithm

// graph node ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
class node{
	public:
		int vertex;
		node* next;
		node(int n){
			vertex = n;
			next = NULL;
		}	
};

// graph--------------------------------------------
class graph{
	protected:
		node *list[20];
	    int n;
	public:
		graph(int x){
			n = x;
			for(int i=0; i<n; i++){
				list[i] = NULL;
			}
		}
		void create();
		void display();
		void delete_edge(int, int);
		void delete_node(int);
		void DFS();
		void BFS();
		void primsMST();  // Function for Prim's Algorithm
};

void graph::create(){
	int i, j, ans;
	node* temp;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout << "Is there an edge from vertex " << i+1 << " to " << j+1;
			cin >> ans;
			if(ans != 0){
				node* newnode = new node(j+1);  
				if(list[i] == NULL){
					list[i] = temp = newnode;
				}else{
					temp->next = newnode;
					temp = newnode;
				}
			}
		}
	}
}

void graph::display(){
	int i;
	node* temp;
	for(i=0; i<n; i++){
		cout <<"Vertex " << i+1 << ": ";
		temp = list[i];
		while(temp != NULL){
			cout << "V" << temp->vertex << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
}

void graph::delete_edge(int v1, int v2){
	node* temp;
    temp = list[v1-1];
    node* prev = NULL;
    while(temp != NULL && temp->vertex != v2){
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        if(prev == NULL){
            list[v1-1] = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp; 
    }
}

void graph::delete_node(int v){
	node* temp;
    for(int i = 0; i < n; i++){
        delete_edge(i+1, v);  
    }
    temp = list[v-1];
    while(temp != NULL){
        node* q = temp;
        temp = temp->next;
        delete q;
    }
    list[v-1] = NULL;
}

// Stack structure for DFS
class stack_node{
	public:
	   int data; 
	   stack_node* down;
	   stack_node(int x){
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
		void push(int v);
		void pop();
		bool isStackEmpty(){
			return top == NULL;
		}
		bool isStackFull(){
			return count == MAX;
		}
};

void stack::push(int v){
	stack_node* newnode = new stack_node(v);
	if(isStackFull()){
		cout << "stack overflow!";
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
	if(isStackEmpty()){
		cout << "stack underflow!";
		return;
	}
	stack_node* temp = top;
	top = top->down;
	delete(temp);
	count--;
}

// DFS implementation
void graph::DFS(){
	int visited[MAX] = {0};
	stack s;
	int start = 1;
	visited[start-1] = 1;
	cout << "DFS: " << start << " ";
	s.push(start);
	while(!s.isStackEmpty()){
		int v = s.top->data;
		bool checkAdj = false;
	    node* temp = list[v-1];
	    while(temp != NULL){
	    	if(!visited[temp->vertex-1]){
	    		cout << temp->vertex << " ";
	    		visited[temp->vertex-1] = 1;
	    		s.push(temp->vertex);
				checkAdj = true;
				break;
			}
			temp = temp->next;
		}
		if(!checkAdj){
			s.pop();
		}
	}
}

// Queue structure for BFS
class q_node{
	public:
		int data;
		q_node* next;
		q_node(int x){
			data = x;
			next = NULL;
		}
};

class queue{
	public:
		q_node *front, *rear;
	    int count;
		queue(){
			front = NULL;
			rear = NULL;
			count = 0;
		}
		bool isQFull(){
			return count == MAX;
		}
		bool isQEmpty(){
			return front == NULL;
		}
		void enqueue(int v);
		void dequeue();		
};

void queue::enqueue(int v){
	q_node* newnode = new q_node(v);
	q_node* temp;
	if(isQFull()){
		cout << "Queue Overflow!";
		return;
	}
	if(isQEmpty()){
		front = newnode;
		rear = newnode; 
	}else{
		rear->next = newnode;
		rear = newnode;
	}
	count++;
}

void queue::dequeue(){
	if(isQEmpty()){
		cout << "Queue Underflow!";
		return;
	}
	q_node* temp = front;
    if(front == rear){
        front = rear = NULL;
    } else {
        front = front->next;
    }
    delete temp;
    count--;
}

// BFS implementation
void graph::BFS(){
	int visited[MAX] = {0};
	queue q;
	int start = 1;
	
	visited[start-1] = 1;
	q.enqueue(start);
	cout <<"BFS: " ;
	
	while(!q.isQEmpty()){
		int curr = q.front->data;
		cout << curr << " ";
		q.dequeue();
		node* temp = list[curr-1];
	    while(temp != NULL){
		    if(!visited[temp->vertex-1]){
			    visited[temp->vertex-1] = 1;
			    q.enqueue(temp->vertex);
		    }
	        temp = temp->next;
	    }
	}
	cout << endl;
}

// Prim's Algorithm for Minimum Spanning Tree
void graph::primsMST() {
    int adjMatrix[MAX][MAX] = {0};
    
    // Step 1: Create an adjacency matrix from the adjacency list
    for(int i=0; i<n; i++){
        node* temp = list[i];
        while(temp != NULL){
            int v = temp->vertex;
            int weight;
            cout << "Enter the weight of the edge between vertex " << i+1 << " and vertex " << v << ": ";
            cin >> weight;
            adjMatrix[i][v-1] = weight;
            adjMatrix[v-1][i] = weight;  // Undirected graph, so mirror the value
            temp = temp->next;
        }
    }

    int parent[MAX];  // Array to store constructed MST
    int key[MAX];     // Key values used to pick minimum weight edge
    bool mstSet[MAX]; // To represent set of vertices included in MST

    // Initialize all keys as "infinity" and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include first vertex in MST.
    key[0] = 0;      // Make key 0 so that this vertex is picked first
    parent[0] = -1;  // First node is always root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int min = INF, u;

        for (int v = 0; v < n; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], u = v;

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v])
                parent[v] = u, key[v] = adjMatrix[u][v];
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] + 1 << " - " << i + 1 << "\t" << adjMatrix[i][parent[i]] << " \n";
}

int main()
{
	int vertices;
	cout << "Enter number of vertices of graph: ";
	cin >> vertices;
	graph g(vertices);
	int choice, p;
	do{
		cout<<"Enter choice: " <<endl
		    << "1) Create Graph"<< endl
			<< "2) Display graph" << endl
			<< "3) Delete edge" << endl
			<< "4) delete node" << endl
			<< "5) Show Depth First Search" << endl
			<< "6) Show Breadth First Search" << endl
			<< "7) Apply Prim's Algorithm for MST" << endl;
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
				cout << "Enter starting and ending vertex of edge to delete: ";
				cin >> v1 >> v2;
				g.delete_edge(v1, v2); break;
			}
			case 4:{
				int v;
				cout << "Enter the vertex to delete: ";
				cin >> v;
				g.delete_node(v); break;
			}
			case 5:{
				g.DFS();
				break;
			}
			case 6:{
				g.BFS();
				break;
			}
			case 7:{
				g.primsMST();
				break;
			}
		}
		cout << "\nTo continue, enter 1. " ;
		cin >> p;
	}while(p==1);
	return 0;
}

