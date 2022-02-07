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

Node *skipMdelN(Node *head, int M, int N)
{
    if (!head || N == 0)
    {
        return head;
    }
    else if (M == 0)
    {
        return NULL;
    }

    Node *current = head;

    while (current != NULL)
    {
        for (int i = 0; i < M - 1 && current; i++)
        {
            current = current->next;
        }

        Node *temp = NULL;
        if (current)
        {
            temp = current->next;
        }

        for (int i = 0; i < N && temp; i++)
        {
            temp = temp->next;
        }

        if (current)
        {
            current->next = temp;
            current = current->next;
        }
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
    int M, N;
    Node *head = takeInput();
    print(head);
    cout << endl;
    cin >> M >> N;
    cout << endl;
    Node *oe = skipMdelN(head, M, N);

    print(oe);
}