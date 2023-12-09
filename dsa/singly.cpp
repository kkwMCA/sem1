//singly
#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}node;

node* head=NULL;
node* end=NULL;
void create(int data){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->next=NULL;
		head->next=newnode;
		end=newnode;
	}else{
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=data;
		newnode->next=NULL;
		end->next=newnode;
		end=end->next;
	}
	
}

void display(){
	node* temp=head->next;
	
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}



bool search(int data){
	node* temp=head->next;
	while(temp!=NULL){
		if(temp->data==data)
			return true;
		temp=temp->next;
	}
	return false;
}

void del(int key){
	if(search(key)){
		node* temp=head;
		node* tnode;
		while(1){
			if(temp->next->data==key){
					tnode=temp->next;
					temp->next=tnode->next;
					tnode->next=NULL;
					free(tnode);
					return;
			}
			temp=temp->next;
		}	
	}else{
		printf("\n not found\n");
	}
	
}

void rev(){
	node* prev;
	node* curr;
	node* ahead;
	
	prev=head->next;
	curr=prev->next;
	prev->next=NULL;
	if(curr->next==NULL){
		curr->next=prev;
		head->next=curr;
	}else{
		// 3 5 6
		 //  p c a
		ahead=curr->next;
		while(ahead!=NULL){
			curr->next=prev;
			prev=curr;
			curr=ahead;
			ahead=ahead->next;			
		}
		curr->next=prev;
		head->next=curr;
		//1 >2 > 3 > 4
		//1 < 2  3 > 4
		//1 < 2
	}
}


int main(){

	create(3);
	create(5);
	create(6);
	display();
	printf("\n");
	rev();
	display();
}
