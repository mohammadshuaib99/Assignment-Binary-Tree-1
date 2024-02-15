#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int minVal(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minVal(root->left), minVal(root->right)));
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    Node *g = new Node(70);
    Node *h = new Node(80);
    Node *i = new Node(90);

    // Building the tree structure
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->left = h;
    d->right = i;

    display(a);

    cout << endl;
    cout << "Minimum value in the tree: " << minVal(a) << endl;

    return 0;
}
