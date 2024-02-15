//============================================================================
// Name        : LL_29.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next=NULL;
	}
};
Node* insertatHead(Node* head,int data){
	if (head==NULL){
	head=new Node(data);
	return head;
	}
	Node* newnode=new Node(data);
	newnode->next=head;
	head=newnode;
	return head;

}

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

Node* insertatk(Node* head,int data,int pos){


	if (pos==1){
		head=insertatHead(head,data);
		return head;
	}
	Node* temp=head;
		int cnt=1;
		Node* newnode=new Node(data);
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}
	newnode->next=temp->next;
	temp->next=newnode;

	return head;
}

void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n----------------------------------------"<<endl;
}

Node* deleteHead(Node* head){
	if (head==NULL){
		return NULL;
	}
	Node* temp=head;
	head=head->next;
	delete temp;
	return head;
}

Node* deleteTail(Node* head){
	if (head==NULL){
		return NULL;
	}
	Node* temp=head;
	while (temp->next->next!=NULL){
		temp=temp->next;
	}
	Node* todelete=temp->next;
	temp->next=NULL;
	delete todelete;
	return head;
}

Node* deleteatk(Node* head,int pos){
	Node* temp=head;
	int cnt=1;
	if (pos==1){
		head=deleteHead(head);
		return head;
	}
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}
	Node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
	return head;
}

Node* deletebyVal(Node* head,int val){
	Node* temp=head;
	int cnt=1;
	while (temp!=NULL && temp->data!=val){
		temp=temp->next;
		cnt++;
	}
	head=deleteatk(head,cnt);
	return head;
}

void search(Node* head,int val){
	Node* temp=head;
	int cnt=1;
	while (temp!=NULL){
		if (temp->data==val){
			break;
		}
		temp=temp->next;
		cnt++;
	}
	if (temp==NULL){
		cout<<val<<" is not present in the list."<<endl;
		return;
	}
	cout<<val<<" is present at "<<cnt<<" position in the list."<<endl;
}


int main() {

//	Node* n1=new Node(2);
//	n1=insertatHead(n1,1);
//	n1=insertatHead(n1,10);n1=insertatHead(n1,11);
//	print (n1);
//	n1=insertatTail(n1,19);
//	n1=insertatTail(n1,38);
//	n1=insertatTail(n1,25);
//	n1=insertatTail(n1,16);
//	n1=insertatTail(n1,69);
//	n1=insertatk(n1,16,3);
//	print(n1);
//	n1=deleteHead(n1);
//	n1=deleteTail(n1);
//	n1=deleteatk(n1,2);
//	n1=deletebyVal(n1,38);
//	print(n1);
//	search(n1,38);
//	search(n1,19);





	Node* n2=NULL;
	int ch,d,p,k;
	while(true){
		cout<<"Choose an Option:\n1.Insert At Head\n2.Insert At Tail\n3.Insert At kth position\n4.Print LL\n5.Delete Head\n6.Delete Tail\n7.Delete at k\n8.Delete by Value\n9.Exit";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter Data:";
			cin>>d;
			n2=insertatHead(n2,d);
			break;
		case 2:
			cout<<"Enter Data:";
			cin>>d;
			n2=insertatTail(n2,d);
			break;
		case 3:
			cout<<"Enter Data:";
			cin>>d;
			cout<<"Enter Position: ";
			cin>>p;
			n2=insertatk(n2,d,p);
			break;
		case 4:
			cout<<"The Current Linked List is ";
			print(n2);
			break;
		case 5:
			cout<<"Deleted Successfully from head";
			n2=deleteHead(n2);
			break;
		case 6:
			cout<<"Deleted Successfully from Tail";
			n2=deleteTail(n2);
			break;
		case 7:
			cout<<"Enter Position of Node to Delete :";
			cin>>k;
			n2=deleteatk(n2,k);
			cout<<"Deleted Node at "<<k<<" successfully."<<endl;
			break;
		case 8:
			cout<<"Enter a Value to delete:";
			cin>>k;
			n2=deletebyVal(n2,k);
			break;
		case 9:
			exit(0);
		}
	}

	return 0;
}
