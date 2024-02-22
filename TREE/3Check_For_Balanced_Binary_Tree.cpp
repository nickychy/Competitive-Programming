/*Check if the Given TREE is Balanced or not
//A tree is balanced if and only if the heights of its left subtree and right  subtree differ by at most one.
 */
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
/*Brute Force:
For every node find leftHeight and rightHeight and check if its difference is greater than 1 then not balanced
else traverse to next Node
If any one Node gives a false,return false*/
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int left = isBalanced(root->left);
    int right = isBalanced(root->right);
    if (abs(left - right) > 1)
        return false;
    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);
    if (!left || !right)
        return false;
    return true;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    root->left->right->left->right = new Node(70);
    cout << isBalanced(root);
    return 0;
}