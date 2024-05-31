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
Node *findSucsessor(Node *root)
{
    root = root->right;
    while (root->left != NULL && root != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deletionInBST(Node *root, int x)
{
    if (!root)
        return root;
    if (root->data > x)
    {
        root->left = deletionInBST(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = deletionInBST(root->right, x);
    }
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = findSucsessor(root);
            root->data = succ->data;
            root->right = deletionInBST(root->right, succ->data);
        }
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    vector<Node *> v;
    int n;
    cin >> n;
    Node *root = new Node(10);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        root = insertInBST(root, k);
    }
    inorder(root);
    root = deletionInBST(root, 10);
    cout << endl;
    inorder(root);
    return 0;
}