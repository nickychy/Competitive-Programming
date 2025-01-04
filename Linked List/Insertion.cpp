#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
    Node(int x, Node *next1)
    {
        data = x;
        next = next1;
    }
};
Node *convertToLL(vector<int> arr);
void print(Node *head);

//------------INSERTION-------------

//-------INSERT AT FRONT---------
Node *insertHead(Node *head, int x)
{
    Node *temp = new Node(x, head);
    head = temp;
    return head;
}

//-------INSERT AT END--------
Node *insertAtEnd(Node *head, int x)
{
    if (head == NULL)
        return new Node(x);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(x);
    temp->next = newNode;
    return head;
}

//-----------INSERT BY POSITION---------
Node *insertAtKPos(Node *head, int k, int x)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(x);
        else
            return NULL;
    }
    if (k == 1)
    {
        Node *temp = new Node(x, head);
        return temp;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *nodeToBeInserted = new Node(x);
            nodeToBeInserted->next = temp->next;
            temp->next = nodeToBeInserted;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//--------INSERT BEFORE A GIVEN VALUE------
Node *insertBeforeValueK(Node *head, int k, int x)
{
    if (head == NULL)
        return NULL;
    if (head->data == k)
    {
        Node *temp = new Node(x, head);
        return temp;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            Node *newNode = new Node(x, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr{1, 2, 3, 5, 6};
    Node *head = convertToLL(arr);
    // head = insertHead(head, 11);
    // head = insertAtEnd(head, 60);
    // head = insertAtKPos(head, 3, 7);
    head = insertBeforeValueK(head, 1, 4);
    print(head);
    return 0;
}

Node *convertToLL(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}