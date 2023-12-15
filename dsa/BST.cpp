#include<stdio.h>
#include<malloc.h>

typedef struct node{
	
	int data;
	struct node *left,*right;
	
}node;

node* add(node* root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}else{
		if(root->data > data)
			root->left=add(root->left,data);
		else
			root->right=add(root->right,data);
	}
}

void inorder(node* root){
	if(root==NULL)
		return;
	
	inorder(root->left);
	printf("%d	",root->data);
	inorder(root->right);
}
//
//node* replacer(node* root,int flag){
//	if(root->left!=NULL){
//		node* temp=root->left;
//		while(temp->right!=NULL)
//			temp=root->right;
//		flag=0;
//		return temp;
//	}else{
//	//	root=root->right;
//		flag=1;
//		return root->right;
//	}
//}
//
//node* del(node* root,int data){
//	if(root==NULL)
//		return NULL;
//	node* temp=root;
//	node* see=NULL;
//	
//	if(temp->data==data){
//		if(temp->left==NULL && temp->right==NULL){
//			free(temp);
//			return NULL;
//		}else{
//			int	flag=0;
//			see=replacer(temp,flag);
//			temp->data=see->data;
//			if(flag==1)
//				temp->left=del(temp->left,see->data);
//			else
//				temp->right=del(temp->right,see->data);
//		}
//	}else{
//		if(data >temp->data)
//			temp->right=del(temp->right,data);
//		else
//			temp->left=del(temp->left,data);
//	}
//	
//	return temp;
//	
//	
//	
//}

void mirror(node* root){
	if(root==NULL)
		return;
	
	mirror(root->left);
	mirror(root->right);
	
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
}

int height(node* root){
	if(root==NULL)
		return 0;
		
	int left=height(root->left);
	int right=height(root->right);
	
	if(left> right)
		return left+1;
	else
		return right+1;
}

node* replacer(node* root,int flag){
	if(root->left!=NULL){
		node* temp=root->left;
		while(temp->right!=NULL)
			temp=temp->right;
		flag=0;
		return temp;
	}else{
		flag=1;
		return root->right;
	}
}

node* del(node* root,int key){
	node* temp=root;
	node* see=NULL;
	if(temp->data==key){
		if(temp->left==NULL && temp->right==NULL){
			free(temp);
			return NULL;
		}else{
			int flag=-1;
			see=replacer(temp,flag);
			temp->data=see->data;
			if(flag==1)
				temp->left=del(temp->left,see->data);
			else
				temp->right=del(temp->right,see->data);
		}
	}else{
		if(key > temp->data)
			temp->right=del(temp->right,key);
		else
			temp->left=del(temp->left,key);
	}
	
	return temp;
}


int main(){
	node *root=NULL;
	root=add(root,12);
	root=add(root,11);
	root=add(root,13);
	root=add(root,14);

	root=add(root,15);

	inorder(root);
	
	printf("\n\n");
	printf("%d\n",height(root)-1);
	
	inorder(root);
}
