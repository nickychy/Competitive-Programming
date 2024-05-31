#include <bits/stdc++.h>
using namespace std;
struct Node
{

    int data;
    Node *next;
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

// Traversal
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of L.L
int length(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Search an element in L.L
bool search(Node *head, int x)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *curr = new Node(arr[i]);
        temp->next = curr;
        temp = temp->next;
    }

    printList(head);
    cout << length(head) << endl;
    cout << search(head, 5);
    return 0;
}