#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    bool lthread, rthread;

public:
    friend class TBST;
};

class TBST
{
    Node *root = new Node;

public:
    Node *create()
    {
        root = NULL;
        return root;
    }
    void insert(Node *&root, int val)
    {
        Node *curr = root;
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            prev = curr;
            if (val == curr->data)
            {
                return;
            }
            else if (val < curr->data)
            {
                if (curr->lthread == false)
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
                if (curr->rthread == false)
                {
                    curr = curr->right;
                }
                else
                {
                    break;
                }
            }
        }

        Node *node = new Node;
        node->data = val;
        node->lthread = true;
        node->rthread = true;
        if (prev == nullptr)
        {
            // The tree is empty, set the new node as the root
            root = node;
            node->left = NULL;
            node->right = NULL;
        }
        else if (val < prev->data)
        {
            node->left = prev->left;
            node->right = prev;
            prev->left = node;
            prev->lthread = false;
        }
        else
        {
            node->right = prev->right;
            node->left = prev;
            prev->right = node;
            prev->rthread = false;
        }
    }

    Node *inorderSuccessor(Node *ptr)
    {

        if (ptr->rthread == true)
            return ptr->right;
        ptr = ptr->right;

        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            cout << "Tree is empty" << endl;

        Node *ptr = root;
        while (ptr->lthread == false)
            ptr = ptr->left;

        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = inorderSuccessor(ptr);
        }
    }

    void preorder(Node *root)
    {
        if (root == NULL)
        {
            cout << "tree is empty \n";
        }
        else
        {
            while (root != NULL)
            {
                cout << root->data << " ";
                if (root->lthread == false)
                {
                    root = root->left;
                }
                else if (root->rthread == false)
                {
                    root = root->right;
                }
                else
                {
                    while (root != NULL && root->rthread == true)
                    {
                        root = inorderSuccessor(root);
                    }
                    if (root != NULL)
                    {
                        root = root->right;
                    }
                }
            }
        }
    }

    void deletenode(Node *root, int val)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return;
        }
        while (root != NULL)
        {
            if (root->data == val)
            {
                break;
            }
            else if (root->data > val)
            {
                if (root->lthread == false)
                {
                    root = root->left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (root->rthread==false){
                    root=root->right;
                }
                else{
                    break;
                }
            }
        }
        if (root->rthread && root->lthread)
        {   

            delete root;
            return;
        }
        else if ((root->lthread && !(root->rthread)) || (!(root->lthread) && root->rthread))
        {
            deleteonechild(root);
            return;
        }
        else
        {
            deletetwochildren(root);
            return;
        }
    }
    void deleteonechild(Node* root){
        if (root->lthread==false){
            root->data=root->left->data;
            root->lthread=root->left->lthread;
            delete root->left;
        }
        else{
            root->data=root->right->data;
            root->rthread=root->right->rthread;
            delete root->right;
        }
    }
    void deletetwochildren(Node* root){
        Node* ptr=inorderSuccessor(root);
        root->data=ptr->data;
        root->rthread=ptr->rthread;
    }
};

int main()
{
    Node *root = NULL;
    TBST t;

    int ch;
    int val;
    while (true)
    {
        cout << "Enter a choice: " << endl;
        cout << "1. Create TBST" << endl;
        cout << "2. Insert a node" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Delete a node" << endl;
        cout << "6. Exit" << endl;
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
        case 3:
            cout << "Inorder Traversal: " << endl;
            t.inorder(root);
            break;
        case 4:
            cout << "Preorder Traversal: " << endl;
            t.preorder(root);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Inavlid" << endl;
            break;
        }
    }
}
