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
void markParent(Node *root, unordered_map<Node *, Node *> &mp)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
    }
}
Node *findTarget(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    return findTarget(root->left, target);
    return findTarget(root->right, target);
}
vector<int> print_Node_At_K_Distance(Node *root, unordered_map<Node *, Node *> mp, Node *target, int k)
{
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    int curr_dist = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr_dist++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (mp[temp] && !visited[mp[temp]])
            {
                q.push(mp[temp]);
                visited[mp[temp]] = true;
            }
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->data);
        q.pop();
    }
    return result;
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    unordered_map<Node *, Node *> mp;
    markParent(root, mp);
    int x, k;
    cout << "Enter the target data " << endl;
    cin >> x;
    Node *target = findTarget(root, x);
    cout << target->data << endl;
    cout << "Enter the distance " << endl;
    cin >> k;
    vector<int> ans;
    ans = print_Node_At_K_Distance(root, mp, target, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}