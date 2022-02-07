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

int find(Node *head,int x){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==x){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
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
            temp->next=newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    int x;
    Node *head = takeInput();
    print(head);
    cout<<endl<<"Enter the Number to be searched : ";
    cin>>x;
    int index=find(head,x);
    cout<<index;
    
}