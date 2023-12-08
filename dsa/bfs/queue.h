#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;


node *front=NULL;
node *rear=NULL;

void add(int data){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(front==NULL && rear==NULL){
		front=rear=temp;
		rear->next=front;
	}else{
		rear->next=temp;
		temp->next=front;
		rear=temp;
	}
}

void display(){
	if(front==NULL && rear==NULL)
		return;
	printf("%d\n",front->data);
	node* temp=front->next;
	while(temp!=front){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

void del(){
	if(front!=rear){
		node* temp=front;
		front=front->next;
		rear->next=front;
		free(temp);
	}else{
		if(front==rear){
			node* temp=front;
			front=rear=NULL;
			free(temp);
		}
	}
}

bool isEmpty(){
	if(front==NULL && rear==NULL)
		return true;
	return false;
	
}

int peek(){
	if(front!=NULL)
		return front->data;
}
