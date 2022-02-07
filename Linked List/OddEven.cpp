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

Node *oddEven(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *oddT = NULL;
    Node *oddH = NULL;
    Node *evenT = NULL;
    Node *evenH = NULL;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = current;
                evenT = current;
            }
            else
            {
                evenT->next = current;
                evenT = current;
            }
        }
        else
        {
            if (oddH == NULL)
            {
                oddH = current;
                oddT = current;
            }
            else
            {
                oddT->next = current;
                oddT = current;
            }
        }
        current = current->next;
    }
    if (oddH == NULL)
    {
        return evenH;
    }
    else
    {
        if (evenH != NULL)
        {
            oddT->next = evenH;
            evenT->next = NULL;
            return oddH;
        }
        else
        {
            return oddH;
        }
    }
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
    cout << endl;
    Node *oe = oddEven(head);

    print(oe);
}