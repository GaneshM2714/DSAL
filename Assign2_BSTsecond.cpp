#include <iostream>
#include <bits/stdc++.h>
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
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
    Node *root;
    int min = INT_MAX;

public:
    Node *create()
    {
        root = nullptr;
        return root;
    }

    Node *insertNode(Node *node, int val)
    {
        if (node == NULL)
        {
            Node *insert = new Node(val);
            node = insert;
            return node;
        }
        if (val < node->data)
        {
            node->left = insertNode(node->left, val);
        }
        else
        {
            node->right = insertNode(node->right, val);
        }
        return node;
    }

    int nodesinlongetspath(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int lheight = nodesinlongetspath(node->left);
        int rheight = nodesinlongetspath(node->right);
        if (lheight > rheight)
        {
            return lheight + 1;
        }
        return rheight + 1;
    }

    int give_min(Node *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node->data;
    }

    int give_max(Node *node)
    {
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node->data;
    }

    void swappointers(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        swap(node->left, node->right);
        swappointers(node->left);
        swappointers(node->right);
    }

    bool searchelement(Node *node, int val)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == val)
        {
            return true;
        }
        if (node->data > val)
        {
            return searchelement(node->left, val);
        }
        return searchelement(node->right, val);
    }
};

int main()
{
    BST b;
    Node *root;
    int choice;
    do
    {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Create BST" << endl;
        cout << "2. Insert a node" << endl;
        cout << "3. Count the number of nodes in the longest path" << endl;
        cout << "4. Find the minimum and maximum data value" << endl;
        cout << "5. Swap pointers at every node" << endl;
        cout << "6. Search for an element" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            root = b.create();
            cout << "BST created successfully." << endl;
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            root = b.insertNode(root, value);
            break;
        }
        case 3:
        {
            cout << "Number of nodes in the longest path: " << b.nodesinlongetspath(root) << endl;
            break;
        }
        case 4:
        {
            cout << "Minimum value: " << b.give_min(root) << endl;
            cout << "Maximum value: " << b.give_max(root) << endl;
            break;
        }
        case 5:
        {
            b.swappointers(root);
            cout << "Pointers swapped at every node." << endl;
            break;
        }
        case 6:
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            if (b.searchelement(root, value))
            {
                cout << "Element found in the tree." << endl;
            }
            else
            {
                cout << "Element not found in the tree." << endl;
            }
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            exit(0);
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);

    return 0;
}