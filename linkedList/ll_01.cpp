#include <iostream>
using namespace std;

// linked list
class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }

    public void insertAtTail(Node *&tail, Node *&head, int data)
    {
        // create node
        Node newNode = new Node(data);
        // assert : true => np ; false => run time error dega
        assert(tail->next == NULL);
        tail->next = newNode;
    }

    public void print_ll(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "\t";
        }
        cout << endl;
    }
};

int main()
{
    Node *head = NULL, *tail = NULL;
    
}