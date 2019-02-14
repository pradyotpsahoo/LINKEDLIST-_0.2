#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*next;
	node*prev;
	node(){
		next = NULL;
		prev = NULL;	
	}
};

class ll{
	public:
	node* head;
	node* tail;
	ll(){
		head = NULL;
		tail = NULL;
	}
	void insert(int value){
		node * temp =new node;
		temp->data=value;
		if(head==NULL){
			head=temp;
			tail=temp;
			temp->next=head;
		}
		
		else{
			tail->next=temp;
			tail=temp;
			temp->next=head;
		}
	}
	void display(){
		node* current=head;
		while(current->next!=head){
			cout<<current->data<<"--";
			current=current->next;	
		}
		cout<<current->data;
		cout<<endl;
	}
	void insertat(int pos,int value){
		node*temp=new node;
		node* current=head;
		temp->data=value;
		int i=1;
		if(pos!=1){
			while(i<pos-1){
				i++;
				current=current->next;
			}
			temp->next=current->next;
			current->next=temp;
			tail->next=head;
		}
		else{
			temp->next=head;
			head=temp;
			tail->next=head;
		}
	}
	void del(){
		node* temp=tail;
		node*current=head;
		while(current->next!=tail){
			current=current->next;
		}
		current->next=head;
		tail=current;
		delete temp;
	}
	void deleteat(int pos){
		node*current=head;
		int i=1;
		if(pos!=1){
		while(i<pos-1){
			i++;
			current=current->next;
		}
		node*current2;
		current2=current->next;
		current->next=current2->next;
	    tail->next=head;
		delete current2;
	}
	else{
		  head=current->next;
		  tail->next=head;
		delete current;
	}
	}
	void revll(){
		node * temp=head;
		rev2(head);
		temp->next=head;
	}
	void rev2(node*current){
		if(current==NULL){
		return;	
		} 
		else if(current->next==head){
			head=current;
			return;
		}
		else{
			rev2(current->next);
			current->next->next=current;
		}
	}
};
int main(){
	ll l1;
	for(int i=1;i<11;i++){
		l1.insert(i);
	}
	l1.display();
	l1.del();
	l1.display();
	l1.insertat(1,56);
	l1.display();
	l1.insert(78);
	l1.display();
	l1.del();
	l1.display();
	l1.deleteat(3);
	l1.display();
	l1.insertat(1,67);
	l1.display();
	l1.deleteat(1);
	l1.display();
	cout<<"rev"<<endl;
	l1.revll();
	l1.display();
	return 0;
}
