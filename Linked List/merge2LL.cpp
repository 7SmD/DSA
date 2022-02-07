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

Node* findMid(Node *head) { 
	if(head == NULL) { 
		return head; 
	} 
	Node *slow = head, *fast = head; 
	while(fast -> next != NULL && fast -> next -> next != NULL) { 
		slow = slow -> next; 
		fast = fast -> next -> next; 
	} 
	return slow; 
}
Node *merge(Node *head1, Node *head2)
{
    Node *fh = NULL, *ft = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (fh == NULL)
            {
                fh = head1;
                ft = head1;
            }
            else
            {
                ft->next = head1;
                ft = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if (fh == NULL)
            {
                fh = head2;
                ft = head2;
            }
            else
            {
                ft->next = head2;
                ft = head2;
            }
            head2 = head2->next;
        }
    }
    if (head1 != NULL)
        ft->next = head1;
    if (head2 != NULL)
        ft->next = head2;
    return fh;
}
Node* mergeSort(Node *head) { 
	if(head == NULL || head -> next == NULL) { 
		return head; 
	}
	Node *mid = findMid(head); 
	Node *half1 = head; 
	Node *half2 = mid -> next; 
	mid -> next = NULL; 
	half1 = mergeSort(half1); 
	half2 = mergeSort(half2); 
	Node *finalHead = merge(half1, half2); 
	return finalHead; 
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
    cout<<endl;
    Node* fhead=mergeSort(head);
    print(fhead);
    
}