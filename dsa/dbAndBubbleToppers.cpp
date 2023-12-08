//11 and 10 in one
#include<stdio.h>
#include<string.h>
int key;
void binarySearch(int roll[],int low,int high){
	
	if(low<=high){
	
		printf("\nin\n");
		int mid=low+high/2;
		if(roll[mid]==key){
			printf("\nfound\n");
			return;
		}else{
			if(key < roll[mid]){
				printf("\nif in\n");
				binarySearch(roll,low,mid-1);
			}
			else	
				binarySearch(roll,mid+1,high);		
				
		}
	}
}


void bubbleSort(float per[],char name[][10],int roll[],int n){
	int flag=1;
	float temp;
	char nameTemp[10];
	int rollTemp;
	while(flag){
		flag=0;
		for(int i=0;i<n;i++){
			if(per[i] > per[i+1] && i+1!=n){
				//per
				temp=per[i];
				per[i]=per[i+1];
				per[i+1]=temp;
				
				//roll
				rollTemp=roll[i];
				roll[i]=roll[i+1];
				roll[i+1]=rollTemp;
				
				//name
//				strcpy(nameTemp,name[i]);
//				strcpy(name[i],name[i+1]);
//				strcpy(name[i],nameTemp);
//				
				strcpy(nameTemp,name[i]);
   				strcpy(name[i],name[i+1]);
   				strcpy(name[i+1],nameTemp);
				flag=1;	
			}
		}
	}
}

void bubbleSortNumber(float per[],char name[][10],int roll[],int n){
	int flag=1;
	float temp;
	char nameTemp[10];
	int rollTemp;
	while(flag){
		flag=0;
		for(int i=0;i<n;i++){
			if(roll[i] > roll[i+1] && i+1!=n){
				//per
				temp=per[i];
				per[i]=per[i+1];
				per[i+1]=temp;
				
				//roll
				rollTemp=roll[i];
				roll[i]=roll[i+1];
				roll[i+1]=rollTemp;
				
				//name
//				strcpy(nameTemp,name[i]);
//				strcpy(name[i],name[i+1]);
//				strcpy(name[i],nameTemp);
//				
				strcpy(nameTemp,name[i]);
   				strcpy(name[i],name[i+1]);
   				strcpy(name[i+1],nameTemp);
				flag=1;	
			}
		}
	}
}

int main(){
	
	char name[][10]={"sumedh","dev","madhura","pratik","piyush","sanika"};
	int roll[]={3,61,4,33,57,22};
	float arr[]={8,9,3,5,1,7};
	for(int i=0;i<6;i++)
		printf("%d	%s	%f\n",roll[i],name[i],arr[i]);
	printf("\n++++++======+++++\n");
	bubbleSort(arr,name,roll,6);
	for(int i=0;i<6;i++)
		printf("%d	%s	%f\n",roll[i],name[i],arr[i]);
	
	printf("\n==============================\n");
	int i=6;
	for(int i=5;i>2;i--)
		printf("%d	%s	%f\n",roll[i],name[i],arr[i]);

	printf("\n======BS=======\n");
	bubbleSortNumber(arr,name,roll,6);
	key=3;
	binarySearch(roll,0,5);

}





