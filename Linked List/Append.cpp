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

Node *append(Node *head, int x, int len)
{
    if (len <= x)
    {
        return head;
    }
    else
    {
        Node *temp1 = head;
        Node *temp2 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = head;

        for (int i = 0; i < len - x - 1; i++)
        {
            temp2 = temp2->next;
        }
        head = temp2->next;
        temp2->next = NULL;
    }
    return head;
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
         << "Lenght of LL : " << len;

    int x;
    cout << endl
         << "Enter no of digit from the last to append : ";
    cin >> x;

    head = append(head, x, len);
    print(head);
}