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
int Size_Of_BT(Node *root)
{
    if (root == NULL)
        return 0;
    int left = Size_Of_BT(root->left);
    int right = Size_Of_BT(root->right);
    return left + right + 1;
}
/*T.C O(N)
S.C O(H)*/
int Max_in_BT(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    int left = Max_in_BT(root->left);
    int right = Max_in_BT(root->right);
    int maxi = max(left, right);
    return max(maxi, root->data);
}

int main()
{
    Node *root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    root->left->right->left->right = new Node(70);
    cout << Size_Of_BT(root);
    cout << endl;
    cout << Max_in_BT(root);
    return 0;
}