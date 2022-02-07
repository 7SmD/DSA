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

Node *swap(Node *head, int i, int j)
{
    Node *c1 = head;
    Node *c2 = head;

    Node *p1 = NULL;
    Node *p2 = NULL;

    Node *pre = NULL;
    Node *temp = head;
    int x = 0;
    while (temp != 0)
    {
        if (x == i)
        {
            c1 = temp;
            p1 = pre;
        }
        else if (x == j)
        {
            c2 = temp;
            p2 = pre;
        }
        pre = temp;
        temp = temp->next;
        x++;
    }
    if (p1 != NULL)
    {
        p1->next = c2;
    }
    else
    {
        head = c2;
    }
    if (p2 != NULL)
    {
        p2->next = c1;
    }
    else
    {
        head = c2;
    }
    Node *TEMP = c2->next;
    c2->next = c1->next;
    c1->next = TEMP;
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
    cin >> i >> j;
    cout << endl;
    Node *s = swap(head, i, j);

    print(s);
}