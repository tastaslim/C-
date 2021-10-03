#include "CommonTemplate.h"
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> waiting;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        int leftChildData;
        cout << "Enter left child data of node " << front->data << ":";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            waiting.push(leftChild);
        }
        int rightChildData;
        cout << "Enter right child data of node " << front->data << ":";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            waiting.push(rightChild);
        }
    }
    return root;
}

void topView(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> k = q.front();
        BinaryTreeNode<int> *front = k.first;
        int temp = k.second;
        q.pop();
        if (mp.find(temp) == mp.end())
        {
            mp[temp] = front->data;
        }
        if (front->left)
        {
            q.push(make_pair(front->left, k.second - 1));
        }

        if (front->right)
        {
            q.push(make_pair(front->right, k.second + 1));
        }
    }
    for (auto &it : mp)
    {
        cout << it.second << " ";
    }
}

// Using recursion

// Prints but in random order. Answer would be absolutely correct if order does not matter

/*unordered_map<int, BinaryTreeNode<int> *> mp;
void topView(BinaryTreeNode<int> *root, int level)
{
    if (!root)
        return;
    mp[level] = root;
    topView(root->left, level - 1);
    topView(root->right, level + 1);
}

void topView(BinaryTreeNode<int> *root)
{
    topView(root, 0);
    for (auto &itr : mp)
    {
        cout << itr.second->data << " ";
    }
    cout << endl;
}
*/

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    topView(root);
}