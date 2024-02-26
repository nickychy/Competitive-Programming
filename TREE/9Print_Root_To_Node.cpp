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

// PRINT Root to specific Node Path
bool printPath(Node *root, vector<int> &ans, int x)
{
    if (!root)
        return false;
    ans.push_back(root->data);
    if (root->data == x)
        return true;
    if (printPath(root->left, ans, x) || printPath(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}

// PRINT ALL PATHS FROM ROOT TO NODE CODE
void printAllPath(Node *root, vector<string> &ans, string prev)
{
    if (!root)
        return;
    prev += to_string(root->data) + " ";
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(prev);
        return;
    }
    printPath(root->left, ans, prev);
    printPath(root->right, ans, prev);
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

    int x;
    cout << "Enter Node Value" << endl;
    cin >> x;
    vector<int> arr;
    if (printPath(root, arr, x))
    {
        for (auto x : arr)
        {
            cout << x << " -> ";
        }
    }
    else
    {
        cout << "No Such Value In the Given Tree" << endl;
    }
    vector<string> ans;
    printAllPath(root, ans, "");

    return 0;
}