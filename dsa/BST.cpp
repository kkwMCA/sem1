//"Write a program to create binary tree. Find height of the tree and print leaf
//nodes. Find mirror image, print original and mirror image using level-wise printing"
/*
height
leaf
mirror
*/
#include<stdio.h>
#include<malloc.h>
typedef struct node{
	struct node *left;
	int data;
	struct node	*right;
}node;


node* create(node* root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}else{
		if(root->data > data)
			root->left=create(root->left,data);
		else
			root->right=create(root->right,data);
	}
}

void inorder(node* root){
	if(root==NULL)
		return;
	
	inorder(root->left);
	printf("%d	",root->data);
	inorder(root->right);
}

void leaf(node* root){
	if(root->left==NULL && root->right==NULL){
		printf("%d\n",root->data);
		return;
	}
	if(root->left)
		leaf(root->left);
	if(root->right)
	leaf(root->right);
		
}

node* temp;
void mirror(node* root){
	if(root==NULL)
		return;
	
	mirror(root->left);
	mirror(root->right);

	temp=root->left;
	root->left=root->right;
	root->right=temp;
}

int height(node* root){
	if(root==NULL){
		//last tak jayenga
		//aur jab returm hote jayenga tab increment
		return 0;
	}else{
		int left=height(root->left);
		int right=height(root->right);
		
		if(left > right)
			return(left+1);
		else
			return(right+1);
	}
	
}


int main(){
	node* root=NULL;
	root=create(root,12);
	root=create(root,13);
	root=create(root,11);
	root=create(root,10);
	inorder(root);
	
	node* tempRoot=NULL;
	printf("\n=========\n");
	leaf(root);
	printf("\n=========\n");
	mirror(root);
	inorder(root);
	printf("\n=========\n");
	int i=height(root);
	printf("%d ",i-1);
}
