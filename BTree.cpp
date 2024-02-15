#include <iostream>
#include <queue>
using namespace std;
class treenode
{
    int data;
    treenode *lchild;
    treenode *rchild;

public:
    treenode()
    {
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
    friend class tree;
};
class tree
{
    treenode *root;

    // maketree() function is made private since the root should not be accessible in the main
    treenode *maketree();

public:
    tree()
    {
        root = NULL;
    }
    treenode *createBT()
    {
        root = maketree();
        return root;
    }
    void traversal(treenode* root);
    void preorder(treenode *root);
    void inorder(treenode *root);
    void postorder(treenode *root);
    void displayLevelWise(treenode *root);
    treenode *invert(treenode *root);
};
treenode *tree::maketree()
{
    treenode *temp = new treenode;
    cout << "Enter data: ";
    cin >> temp->data;
    cout << "Does this node have right child(y/n)?";
    char ch;
    cin >> ch;
    if (ch == 'y')
        temp->rchild = maketree();
    cout << "Does this node have left child(y/n)?";
    cin >> ch;
    if (ch == 'y')
        temp->lchild = maketree();
    return temp;
}

void tree::preorder(treenode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void tree::inorder(treenode *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

void tree::postorder(treenode *root)
{
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " ";
}
void tree::traversal(treenode *root)
{
    /*
        * Preorder = root left right
        * Inorder = left root right
        * Postorder = left right root
        */
    cout<<"Preorder: ";
    preorder(root);
    cout<<"\n\nInorder: ";
    inorder(root);
    cout<<"\n\nPostorder: ";
    postorder(root);

}
treenode *tree::invert(treenode *root)
{
    cout << "Inversion has began" << endl;
    treenode *temp;
    temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    if (root->lchild != NULL)
        invert(root->lchild);
    if (root->rchild != NULL)
        invert(root->rchild);
    return root;
    cout << "\nInversion done!!!\n"<< endl;
}
void tree::displayLevelWise(treenode *root)
{
    queue<treenode *> que1;
    queue<treenode *> que2;
    que1.push(root);
    while (!que1.empty() || !que2.empty())
    {
        while (!que1.empty())
        {
            root = que1.front();
            cout << root->data << " ";
            que1.pop();
            if (root->lchild)
                que2.push(root->lchild);
            if (root->rchild)
                que2.push(root->rchild);
        }
        cout << endl;
        while (!que2.empty())
        {
            root = que2.front();
            cout << root->data << " ";
            que2.pop();
            if (root->lchild)
                que1.push(root->lchild);
            if (root->rchild)
                que1.push(root->rchild);
        }
        cout << endl;
    }
}
int main()
{
    int choice;
    cout<<"Enter choice: ";
    cin>>choice;
    cout<<"======================MENU============================="<<endl;

    tree tbj;
    treenode *toor = tbj.createBT();
    tbj.displayLevelWise(toor);
    tbj.traversal(toor);
    tbj.invert(toor);
    tbj.displayLevelWise(toor);
    tbj.traversal(toor);
    return 0;
}
