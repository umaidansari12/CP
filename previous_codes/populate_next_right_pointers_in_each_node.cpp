/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//this method works only for perfect/complete binary tree

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* t = q.front();
            q.pop();
            if (t->left && t->right)
            {
                t->left->next = t->right;
                if (t->next)
                    t->right->next = t->next->left;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return root;
    }
};

//this method is extended level order traversal of binary tree and works on both
//complete as well as non complete binary tree

void connect(node* p)
{
    // Set the nextRight for root
    p->nextRight = NULL;

    // Set the next right for rest of the nodes
    // (other than root)
    connectRecur(p);
}

/* Set next right of all descendents of p.
Assumption: p is a compete binary tree */
void connectRecur(node* p)
{
    // Base case
    if (!p)
        return;

    // Set the nextRight pointer for p's left child
    if (p->left)
        p->left->nextRight = p->right;

    // Set the nextRight pointer
    // for p's right child p->nextRight
    // will be NULL if p is the right
    // most child at its level
    if (p->right)
        p->right->nextRight = (p->nextRight) ? p->nextRight->left : NULL;

    // Set nextRight for other
    // nodes in pre order fashion
    connectRecur(p->left);
    connectRecur(p->right);
}

void connect(Node *p)
{
    // Your Code Here
    queue<Node*> q;
    q.push(p);
    while (!q.empty())
    {
        int n = q.size();
        Node* temp = NULL;
        for (int i = 0; i < n; i++)
        {
            Node* prev = temp;
            temp = q.front();
            q.pop();
            if (i > 0)
                prev->nextRight = temp;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        temp->nextRight = NULL;
        /*while(n--)
        {
            Node* curr= q.front();
            q.pop();
            if(q.empty())
            curr->nextRight=NULL;
            else
            curr->nextRight=q.front();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }*/
    }
}