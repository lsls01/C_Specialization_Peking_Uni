#include <iostream>
using namespace std;

int main()
{
    return 0;
}

Node *Create(int N)
{
    int n = 1;
    Node *node = new Node;
    node -> num = n;
    
    Node *head = node;
    Node *tail = head;

    while(n++ < N)
    {
        node = new Node;
        node -> num = n;
        tail -> next = node;
        node -> ahead = tail;
        tail = tail -> next;
    }

    tail -> next = head;
    head -> ahead = tail;
    return head;
}

Node *Search(Node *head, int P)
{
    while(head -> num != P)
        head = head -> next;
    return head;
}

Node *Release(Node *head, int M)
{
    int count = 1;
    Node *temp = head;
    while(count < M)
    {
        temp = temp -> next;
        count++;
    }

    temp -> ahead -> next = temp -> next;
    temp -> next -> ahead = temp -> ahead;
    cout << temp -> num << ",";
    head = temp -> next;
    delete temp;
    return head;
}
