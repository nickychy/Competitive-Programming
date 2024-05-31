#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

//-----------------Check if a tree follows Children Sum Property Or Not
bool isCSPTree(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
    }
    return (root->data == sum) &&
           isCSPTree(root->left) &&
           isCSPTree(root->right);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout << isCSPTree(root);
    return 0;
}