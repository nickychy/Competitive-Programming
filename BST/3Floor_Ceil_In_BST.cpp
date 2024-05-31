#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
Node *insertInBST(Node *root, int x)
{
    if (!root)
    {
        return new Node(x);
    }
    Node *curr = root;
    while (curr)
    {
        if (curr->data > x)
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(x);
                break;
            }
        }
        if (curr->data < x)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(x);
                break;
            }
        }
    }
    return root;
}
int floorInBST(Node *root, int key)
{
    if (!root)
        return -1;
    int res;
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root->data;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            res = root->data;
            root = root->right;
        }
    }
    return res;
}
int findCeil(Node *root, int x)
{
    // Write your code here.
    if (!root)
        return -1;
    int res = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            return root->data;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            res = root->data;
            root = root->left;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    Node *root = new Node(10);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        root = insertInBST(root, k);
    }
    cout << floorInBST(root, 12);
    cout << endl
         << findCeil(root, 12);
    return 0;
}