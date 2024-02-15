#include<iostream>
using namespace std;

class Node
{
public:
    Node* next;
    int data;

    Node(int data)
    {
        this->data = data;
        next=NULL;
    }
//     Node* operator=(Node* root){
//     Node* temp;
//     temp=root;
//     return temp;
// }
    
};

Node* insertatTail(Node* head,int data){
	if (head==NULL){
		head=new Node(data);
		return head;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	Node* newnode=new Node(data);
	temp->next=newnode;
	return head;
}

void display(Node* root){
    Node* temp=root;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}



int main(){
    Node* head=new Node(1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);

    cout<<"The original LL: ";
    display(head);

    Node* head1=nullptr;
    head1=head;
    cout<<"The copied LL: ";
    display(head1);

    cout<<head<<endl;
    cout<<head1;

}