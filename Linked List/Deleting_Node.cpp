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

Node *deleteNode(Node *head, int i)
{
    int count = 0;

    Node *temp = head;

    if (i == 0)
    {
        head = head->next;

        return head;
    }

    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
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

    Node *head = takeInput();

    print(head);

    int i, data;
    cin >> i;

    head = deleteNode(head, i);

    print(head);
}