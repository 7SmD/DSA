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

int mid(Node *head, int len)
{
    int count=0;
    int mp=(len-1)/2;
    for(int i=0;i<mp;i++)
    {
        
        count++;
    }
    return count;
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


    int midpoint = mid(head,  len);
    cout<<endl<<"Mid-Point index : "<<midpoint;
}