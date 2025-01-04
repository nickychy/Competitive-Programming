#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int x, Node *next1)
    {
        data = x;
        next = next1;
    }
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

//-----------DELETION----------

//---------DELETE HEAD OF LL-----
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

//---------DELETE TAIL OF LL
Node *deleteTail(Node *head)
{

    // contain 0 or 1 element
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    // Get hold of second last element
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

//--------DELETE BY POSITION K
Node *deleteByPosition(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    if (k == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *prev = NULL;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *convertToLL(vector<int> arr)
{
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
Node *deleteByValue(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    Node *prev = NULL;
    if (head->data == k)
    {
        head = head->next;
        delete (temp);
        return head;
    }
    while (temp)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
        prev = temp;
        temp = temp->next;
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
    cout << endl;
}
int main()
{
    vector<int> arr{2, 3, 4, 5, 6};
    Node *head = convertToLL(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);

    // head = deleteByPosition(head, 5);
    head = deleteByValue(head, 7);
    print(head);
    return 0;
}