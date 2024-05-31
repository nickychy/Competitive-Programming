/*
Binary Search Tree is a node-based binary tree data structure
left subtree of a node contains only nodes with keys lesser than node's key.
right subtree of a node contains only nodes with keys greater than the node's key.
 he left and right subtree each must also be a binary search tree. There must be no duplicate nodes.
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

//---------------------INSERTION IN BST-----------------------
Node *insertBST(Node *root, int x)
{
    if (!root)
    {
        Node *root = new Node(x);
        return root;
    }
    else if (root->data > x)
    {
        root->left = insertBST(root->left, x);
    }
    else
    {
        root->right = insertBST(root->right, x);
    }
    return root;
}
//-----------------------------Iterative Insertion in BST
Node *insertIntoBST(Node *root, int val)
{
    if (!root)
    {
        return new Node(val);
    }
    Node *curr = root;
    while (curr)
    {
        if (curr->data > val)
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
    }
    return root;
}
//------------------SEARCH IN BST---------------------------
Node *
searchBST(Node *root, int val)
{
    if (!root)
        return NULL;
    int curr = root->data;
    if (curr == val)
    {
        return root;
    }
    else if (curr > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

void inorderBST(Node *root)
{
    if (!root)
        return;
    inorderBST(root->left);
    cout << root->data << " ";
    inorderBST(root->right);
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
        root = insertBST(root, k);
    }
    inorderBST(root);
    insertIntoBST(root, 100);
    cout << endl;
    inorderBST(root);
    return 0;
}