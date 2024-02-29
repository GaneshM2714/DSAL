#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    bool lbit, rbit;

public:
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        lbit = 0;
        rbit = 0;
    }
    friend class TBST;
};

class TBST
{
    Node *root;
    void displayTree(Node *root, int spaces)
    {
        if (root->lbit || root->rbit)
        {
            return;
        }

        spaces += 5;

        displayTree(root->left, spaces);

        cout << endl;
        for (int i = 5; i < spaces; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;

        displayTree(root->right, spaces);
    }

public:
    Node *create()
    {
        root = NULL;
        return root;
    }
    void insert(Node *&root, int val)
{
    Node *curr = root;
    Node *prev = nullptr;  // Track the parent of the current node

    while (curr != nullptr)
    {
        prev = curr;
        if (val == curr->data)
        {
            // Node with the same value already exists, handle accordingly
            return;
        }
        else if (val < curr->data)
        {
            if (!curr->lbit)
            {
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (!curr->rbit)
            {
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
    }

    Node *node = new Node(val);
    if (prev == nullptr)
    {
        // The tree is empty, set the new node as the root
        root = node;
    }
    else if (val < prev->data)
    {
        node->left = prev->left;
        node->right = prev;
        prev->left = node;
        prev->lbit = 1;
    }
    else
    {
        node->right = prev->right;
        node->left = prev;
        prev->right = node;
        prev->rbit = 1;
    }
}

    void display(Node *root)
    {
        cout << "Binary Tree:" << endl;
        displayTree(root, 0);
    }
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    Node *root=NULL;
    TBST t;

    int ch;
    int val;
    while (true)
    {
        cout << "Enter a choice: " << endl;
        cout << "1. Create TBST" << endl;
        cout << "2. Insert a node" << endl;
        cout << "3. Count the number of nodes in the longest path" << endl;
        cout << "4. Find the minimum and maximum data value" << endl;
        cout << "5. Swap pointers at every node" << endl;
        cout << "6. Search for an element" << endl;
        cout << "7. Exit" << endl;
        cout << "8.Display Tree" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Created!" << endl;
            root = t.create();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            t.insert(root, val);
            break;
        case 8:
        {
            cout << "Displaying Binary Tree: " << endl;
            t.display(root);
            break;
        }
        case 10:
            exit(0);
            break;
        default:
            cout << "Inavlid" << endl;
            break;
        }
    }
}
