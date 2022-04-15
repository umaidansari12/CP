void topView(struct Node *root)
{
    //Your code here
    if (root == NULL)
        return;
    queue<pair<struct Node*, int>>q;
    int hd = 0;
    q.push(make_pair(root, hd));
    map<int, int> m;
    while (!q.empty())
    {
        struct Node* t = q.front().first;
        hd = q.front().second;
        q.pop();
        if (m.find(hd) == m.end())
        {
            m[hd] = t->data;
        }
        if (t->left)
            q.push(make_pair(t->left, hd - 1));
        if (t->right)
            q.push(make_pair(t->right, hd + 1));
    }
    auto i = m.begin();
    while (i != m.end())
    {
        cout << i->second << " ";
        i++;
    }
    //cout<<endl;
}


