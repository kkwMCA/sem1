/*
Write a menu driven program which will maintain a list of car models,
their price, name of the manufacture, engine capacity etc. as a doubly
linked list. The menu should make provisions for inserting information
pertaining to new car models, delete obsolete models, update data such as
price besides answering queries such as listing all car models within a
price range specified by the client and listing all details given a car model
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node{
	int price;
	char manu[10];
	int capacity;
	struct node* next;
	struct node* prev;
}node;

node* head=NULL;
node* end=NULL;
void insert(int price,char manu[],int capacity){
	node* newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->manu,manu);
	newnode->price=price;
	newnode->capacity=capacity;
		
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->next=newnode;
		
		end=newnode;
	}else{
		end->next=newnode;
		newnode->prev=end;
		end=end->next;
	}
}

void display(){
	node* temp=head->next;
	while(temp!=NULL){
		printf("%d	",temp->price);
		temp=temp->next;
	}
}

node* search(char manu[]){
	node* temp=NULL;
	if(head==NULL)
		return temp;
	temp=head->next;	
	while(temp!=NULL){
		if(strcmp(temp->manu,manu)==0){
			printf("\nfound\n");
			return temp;
		}else{
			temp=temp->next;
		}
		
	}
	return temp;
}

void update(char manu[],int price){
	node* temp=search(manu);
	if(temp!=NULL)
		temp->price=price;
	else
		printf("\ncar not found\n");
	
}

void del(char manu[]){
	node* temp=search(manu);
	if(temp!=NULL){
		node* prevTemp=temp->prev;
		prevTemp->next=temp->next;
		temp->next->prev=prevTemp;
		temp->next=NULL;
		temp->prev=NULL;
		free(temp);
		display();
	}else
		printf("\ncar not found\n");
}

void range(int lower,int upper){
	int flag=0;
	if(head==NULL){
		printf("\n head is null\n");
		return;
	}
	node* temp=head->next;
	printf("\n");
	while(temp!=NULL){
		if(temp->price>=lower && temp->price<=upper){
			flag=1;
			printf("%s	",temp->manu);
		}
		temp=temp->next;
	}
	if(flag==0)
		printf("\n no carin this price range\n");
}


int main(){
	node* head=NULL;
	insert(34,"sumedh",90);
	insert(30,"dev",80);
	insert(56,"pratik",76);
	
	display();
	range(30,35);
}

