#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *swap(Node *ptr1, Node *ptr2)
{
    Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

Node *bubble_sort_LinkedList_itr(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int i = 0;
    while (i < count)
    {
        temp = head;

        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
        }
        i++;
    }
    return head;
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cin >> data;
    }

    return head;
}

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    int i, j;
    Node *head = takeInput();
    print(head);
    cout << endl;

    Node *s = bubble_sort_LinkedList_itr(head);

    print(s);
}