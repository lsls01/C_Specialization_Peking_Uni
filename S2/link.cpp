#include <iostream>
using namespace std;

struct student
{
    int id;
    student *next;
};

student *create();

int main()
{
    student *pointer = create();
    while(pointer -> next != NULL)
    {
        cout << pointer -> id << endl;
        pointer = pointer -> next;
    }
    return 0;
}

student *create()
{
    student *head, *temp;
    int num, n = 0;
    head = new student;
    temp = head;
    cin >> num;

    while(num != -1)
    {
        n++;
        temp -> id = num;
        temp -> next = new student;
        temp = temp -> next;
        cin >> num;
    }

    if(n == 0)
        head = NULL;
    else
        temp -> next = NULL;

    return head;
}

linker *dele(student *head; int n)
{
    student *temp, *follow;
    temp = head;
    if(head == NULL)
        return(head);
    if(head -> num == n)
    {
        head = head -> next;
        delete temp;
        return(head);
    }
    while(temp != NULL && temp -> num != n)
    {
        follow = temp;
        temp = temp -> next;
    }
    if(temp == NULL)
        cout << "not found";
    else
    {
        follow -> next = temp -> next;
        delete temp;
    }
    return(head);
}
