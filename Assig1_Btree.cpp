#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;

    Node(int data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};

class Tree
{
    Node *root;
    int cnt = 0;

public:
    Tree()
    {
        root = NULL;
    }

    void create()
    {
        if (root == NULL)
        {
            root = maketree();
        }
    }

    void display()
    {
        cout << "Binary Tree:" << endl;
        displayTree(root, 0);
    }

    void displayin(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << "Inorder Traversal:" << endl;
        displayin_recursive(root);
        cout << endl;
    }

    void displaypre(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << "Preorder Traversal:" << endl;
        displaypre_recursive(root);
        cout << endl;
    }
    void displaypost(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << "Postorder Traversal:" << endl;
        displaypost_recursive(root);
        cout << endl;
    }

private:
    Node *maketree()
    {
        Node *temp = new Node(0);
        char ch;

        cout << "Enter data:";
        cin >> temp->data;

        cout << "Do you want to enter left child for " << temp->data << "? (y/n): ";
        cin >> ch;
        if (ch == 'y')
        {
            temp->lchild = maketree();
        }

        cout << "Do you want to enter right child for " << temp->data << "? (y/n): ";
        cin >> ch;
        if (ch == 'y')
        {
            temp->rchild = maketree();
        }

        return temp;
    }

    void displayTree(Node *root, int spaces)
    {
        if (root == NULL)
        {
            return;
        }

        spaces += 5;

        displayTree(root->lchild, spaces);

        cout << endl;
        for (int i = 5; i < spaces; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;

        displayTree(root->rchild, spaces);
    }

    void displaypre_recursive(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";          // Process the current node
        displaypre_recursive(root->lchild); // Recurr on the left subtree
        displaypre_recursive(root->rchild); // Recurr on the right subtree
    }
    void displayin_recursive(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        displayin_recursive(root->lchild); // Recurr on the left subtree
        cout << root->data << " ";         // Process the current node
        displayin_recursive(root->rchild); // Recurr on the right subtree
    }
    void swap(Node *t1, Node *t2)
    {
        int temp = t1->data;
        t1->data = t2->data;
        t2->data = temp;
    }

public:
    Node *getRoot()
    {
        return root;
    }
    void displaypost_recursive(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        displaypost_recursive(root->lchild); // Recurr on the left subtree
        displaypost_recursive(root->rchild); // Recurr on the right subtree
        cout << root->data << " ";           // Process the current node
    }
    int maxDepth(Node *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->lchild);
            int rDepth = maxDepth(node->rchild);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
    int countleaves(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return 1;
        }
        return countleaves(root->lchild) + countleaves(root->rchild);
    }

    int countintnodes(Node *root)
    {
        if (root != NULL)
        {
            countintnodes(root->lchild);
            if (root->rchild != NULL || root->lchild != NULL)
            {
                cnt++;
            }
            countintnodes(root->rchild);
        }
        return cnt;
    }
    void erasebt(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        delete root;
        erasebt(root->lchild);
        erasebt(root->rchild);
        
    }
    // Node* copy(Node* org,Node* cpy){
    //     if (org==NULL){
    //         return nullptr;
    //     }
    //     cpy=org;
    //     copy(org->lchild,cpy->lchild);
    //     copy(org->rchild,cpy->rchild);
    //     return cpy;
    // }
};

int main()
{
    // Tree tree,tree1;
    // tree.create();
    // tree.display();
    // tree.displaypre(tree.getRoot());
    // tree.displayin(tree.getRoot());
    // tree.displaypost(tree.getRoot());
    // int height = tree.maxDepth(tree.getRoot());
    // cout << "---------------------------------\n";
    // cout << "Height of the tree is: " << height << endl;
    // cout << "---------------------------------\n";
    // cout << "Copying one tree to another :";
    // tree1=tree;
    // cout<<"The adreesses are: "<<endl;
    // cout<<tree.getRoot()<<endl;
    // cout<<tree1.getRoot()<<endl;
    // tree1.display();
    // cout << "-----------------------------------------\n";
    // int leaf = tree.countleaves(tree.getRoot());
    // cout << "Number of leaves in Binary Tree are: " << leaf << endl;
    // cout << "-----------------------------------------\n";
    // int internalnodes = tree.countintnodes(tree.getRoot());
    // cout << "Number of internal Nodeas in the tree are: " << internalnodes-1 << endl;
    // cout << "-------------------------------------------\n";
    // cout << "Deleting Binary tree " << endl;
    // tree.erasebt(tree.getRoot());
    // cout << "Deleted successfully!!!";
    // tree.display();

    Tree b1, b2;
    int x,height=0,internalnodes=0,leaf=0;

    while (true)
    {
        cout << "\nEnter: "
             << "\n1. Make Tree "
             << "\n2. Traversal "
             << "\n3. Height "
             << "\n4. Copy "
             << "\n5. Mirror "
             << "\n6. Number of leaves, internal nodes"
             << "\n7. Display Binary Tree."
             << "\n8. Delete Binary Tree."
             << "\n9. Exit \n ENTER YOUR CHOICE: ";
        cin >> x;
        cout << endl;
        switch (x)
        {
        case 1:
            b1.create();
            break;
        case 2:
            cout << "\n\n Traversel by recursive inorder: ";
            b1.displayin(b1.getRoot());
            cout << "\n\nTraversal by recursive preorder: ";
            b1.displaypre(b1.getRoot());
            cout << "\n\nTraversal by recursive postorder: ";
            b1.displaypost(b1.getRoot());
            break;
        case 3:
            height = b1.maxDepth(b1.getRoot());
            cout << "---------------------------------\n";
            cout << "Height of the tree is: " << height << endl;
            break;
        case 4:
            cout << "---------------------------------\n";
            cout << "Copying one tree to another :";
            b2 = b1;
            cout << "The adreesses are: " << endl;
            cout << b1.getRoot() << endl;
            cout << b2.getRoot() << endl;
            cout << "The copied Binary tree is " << endl;
            b2.display();
            break;
        case 5:
            cout << "Under Construction..." << endl;
            break;

        case 6:
            cout << "-----------------------------------------\n";
            leaf = b1.countleaves(b1.getRoot());
            cout << "Number of leaves in Binary Tree are: " << leaf << endl;
            cout << "-----------------------------------------\n";
            internalnodes = b1.countintnodes(b1.getRoot());
            cout << "Number of internal Nodeas in the tree are: " << internalnodes - 1 << endl;
            cout << "-------------------------------------------\n";
            break;
        case 7:
            cout << "The Binary Tree is :" << endl;
            b1.display();
            break;

        case 8:
            cout << "Deleted all nodes in binary tree." << endl;
            b1.erasebt(b1.getRoot());
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Enter number between 1 through 9 only! \n";
        }
    }

    return 0;
}
