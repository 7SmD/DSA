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

Node *reverse(Node *head2)
{
    Node *p = head2, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head2 = q;
    return q;
}

int length(Node *head)
{

    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool palindrome(Node *head)
{
    int x = length(head) / 2;
    Node *temp = head;

    for (int i = 1; i < x; i++)
    {
        temp = temp->next;
    }
    Node *head2 = temp->next;
    temp->next = NULL;

    head2 = reverse(head2);

    while (head && head2)
    {
        if (head->data != head2->data)
        {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
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
    int len = length(head);
    cout << endl
         << "Lenght of LL : " << len << endl;

    int p = palindrome(head);
    if (p == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}