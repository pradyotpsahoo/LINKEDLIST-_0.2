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
		}
		
		else{
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
	}
	void display(){
		node* current=head;
		while(current!=NULL){
			cout<<current->data<<"--";
			current=current->next;	
		}
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
			current->next->prev=temp;
			current->next=temp;
			temp->prev=current;
		}
		else{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
	}
	void del(){
		node* current=tail;
		node*current2=current->prev;
		current2->next=NULL;
		tail=current2;
		delete current;
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
		current2->next->prev=current;
		delete current2;
	}
	else{
		  head=current->next;
		delete current;
	}
	}
	void revll(){
		node * temp=head;
		rev2(head);
		temp->next=NULL;
	}
	void rev2(node*current){
		if(current==NULL){
		return;	
		} 
		else if(current->next==NULL){
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
	l1.insertat(7,78);
	l1.display();
	l1.del();
	l1.display();
	l1.deleteat(6);
	l1.display();
	l1.insertat(8,98);
	l1.display();
	cout<<"rev"<<endl;
	l1.revll();
	l1.display();
	return 0;
}
