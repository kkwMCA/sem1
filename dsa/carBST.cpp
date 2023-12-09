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

node* search(node* temp,int key){
	node* root=temp;
	while(root->left!=NULL || root->right!=NULL){
		if(root->left->data==key || root->right->data){
			if(root->left->data==key){
			
				return root;//left
			}else{
			
				return root;//right
			}
		}else{
			
			if(root->left->data > key){
					root=root->left;
			}else{
					root=root->right;
			}
			
		}
	}
	root=NULL;
	return root;
	
}
//
//void del(node* root,int key){
//	
//	node* temp=root;
//	//root clause dalna hai
//	if(search(temp,key)==1){
//		node* delRoot=temp->left;
//		if(delRoot->left==NULL && delRoot->right==NULL){
//			temp->left=NULL;
//			free(delRoot);
//		}else{
//			if(delRoot->left==NULL){
//				temp->left=delRoot->right;
//			}else if(delRoot->right==NULL){
//				temp->left=delRoot->left;
//			}else if(delRoot->left!=NULL && delRoot->right!=NULL){
//				temp->left=delRoot->right;
//				temp->left->left=delRoot->left;
//			}
//		}
//		
//	}else if(search(temp,key)==2){
//		node* delRoot=temp->right;
//		if(delRoot->left==NULL && delRoot->right==NULL){
//			temp->right=NULL;
//			free(delRoot);
//		}else{
//			if(delRoot->left==NULL){
//				temp->right=delRoot->left;
//			}else if(delRoot->right==NULL){
//				temp->right=delRoot->right;
//			}else if(delRoot->left!=NULL && delRoot->right!=NULL){
//				temp->right=delRoot->left;
//				temp->right->right=delRoot->right;
//			}
//		}
//		
//	}
//	
//}
void del(node* root,int key);
int main(){
	node* root=NULL;
	root=create(root,12);
	root=create(root,13);
	root=create(root,11);
	root=create(root,10);
	inorder(root);
	
	node *temp=search(root,10);

	printf("\n%d<-temp\n",temp->data);
	printf("found");
	
	
	inorder(root);
}

void del(node* root,int key){
	if(root==NULL)
		return;
	if(key > root->data){
		root->right=del(root->right,key);
	}else{
		root->right=del(root->right,key);
	}
	if(root->left==NULL){
		node* temp=root->right;
		free(root);
	}else{
		if(root->right==NULL){
			node* temp=root->left;
			free(root);
		}
	}	
	
	if(root->left!=NULL && root->right!=NULL){
		node* temp=root->left;
		node* r=root->right;
		free(root);
		
		
	}

}

