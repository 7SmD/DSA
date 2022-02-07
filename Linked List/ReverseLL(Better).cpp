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

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseLL(head->next);

    smallAns.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_better(Node *head)
{
    return reverseLL(head).head;
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
    Node *rhead = reverseLL_better(head);

    print(rhead);
}