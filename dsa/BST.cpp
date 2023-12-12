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
	int data;
	struct node *right,*left;
}node;

node* create(node* root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}else{
		if(root->data > data){
			root->left=create(root->left,data);
		}else{
			root->right=create(root->right,data);
		}
	}	
}

void inorder(node *root){
	if(root==NULL)
		return;
	
	inorder(root->left);
	printf("%d	",root->data);
	inorder(root->right);
}

node* replacer(node* root){
	if(root->left!=NULL){
		node* temp=root->left;
		while(temp->right!=NULL)
			temp=temp->right;
		return temp;
	}else{
		return root->right;
	}
}

node* search(node* root,int key){
	node* temp=root;
	while(1){
		if(temp==NULL)
			return temp;
		else{
			if(temp->data==key){
				return temp;
			}else{
				if(temp->data > key){
					temp=temp->left;
				}else{
					temp=temp->right;
				}
			}
		}
	}
}

void leaf(node* root){
	if(root==NULL)
		return;
	leaf(root->left);
	if(root->left==NULL && root->right==NULL)
		printf("\n%d",root->data);
	leaf(root->right);
	
}

node* del(node* root,int key){
	node* iPre;
	node* temp=root;
    if (root == NULL){
        return NULL;
    }
    if (temp->left==NULL&&temp->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (key < temp->data){
        temp-> left = del(temp->left,key);
    }
    else if (key > temp->data){
        temp-> right = del(temp->right,key);
    }
    //deletion strategy when the node is found
    else{
        iPre = replacer(temp);
        temp->data = iPre->data;
        temp->left = del(temp->left, iPre->data);
    }
    return temp;
}

int height(node* root){
	if(root==NULL)
		return 0;
	else{
		int left=height(root->left);
		int right=height(root->right);
		if(left > right){
			return left+1;
		}else
			return right+1;
	}
}


void mirror(node* root){
	if(root==NULL)
		return;
		
	mirror(root->left);
	mirror(root->right);
	
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
}

int main(){
	node* root=NULL;
	root=create(root,12);
	root=create(root,11);
	root=create(root,13);
	root=create(root,10);
	root=create(root,9);
//	inorder(root);
//	node* temp=search(root,9);
//	if(temp!=NULL)
//		printf("\n%d",temp->data);
//	else
//		printf("\nnot found");
//		
//	del(root,12);
	inorder(root);
	leaf(root);
	int h=height(root)-1;
	printf("\nheight:%d",h);

	mirror(root);
	inorder(root);
}
