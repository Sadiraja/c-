#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* previous;
		
		node(int val){
			data=val;
			next=NULL;
			previous=NULL;
		}
};

void insertatHead(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	if(head!=NULL){
		head->previous=n;
	}
	head=n;
}

void insertatTail(node* &head,int val){
	if(head==NULL){
		insertatHead(head,val);
		return;
	}
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->previous=temp;
	
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void deleteathead(node* &head){
	node* todelete=head;
	head=head->next;
	head->previous=NULL;
	delete todelete;
}
void deletion(node* &head,int pos){
	if(pos==1){
		deleteathead(head);
		return;
	}
	node* temp=head;
	int count=1;
	
	while(temp!=NULL&&count!=pos){
		temp=temp->next;
		count++;
	}
	temp->previous->next=temp->next;
	if(temp->next!=NULL){
		temp->next->previous=temp->previous;
	}
	delete temp;
}
int main(){
	node* head=NULL;
	
  insertatTail(head,1);
  insertatTail(head,2);
  insertatTail(head,3);
  insertatTail(head,4);
  insertatHead(head,5);
  display(head);
  deletion(head,1);
  display(head);
}
