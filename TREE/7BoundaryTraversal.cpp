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
bool isLeaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}
void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *temp = root->left;
    while (temp)
    {
        if (!isLeaf(temp))
            ans.push_back(temp->data);
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
}
void addLeaves(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, ans);
    if (root->right)
        addLeaves(root->right, ans);
}
void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *temp = root->right;
    stack<int> st;
    while (temp)
    {
        if (!isLeaf(temp))
            st.push(temp->data);
        if (temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> boundaryTraversal(Node *root, vector<int> &ans)
{

    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
}

/*T.C O(H) + O(H) + O(N) */
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    vector<int> ans;
    boundaryTraversal(root, ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}