//simple and fast
#include<stdio.h>
//simple (done)
//fast
void fast(int arr[][3],int trans[][3],int t);
//void big(int arr[][3],int t);

void display(int arr[10][3],int t){
	printf("\n");
	for(int i=0;i<=t;i++){
		for(int j=0;j<3;j++){
			printf("%d	",arr[i][j]);
		}
		printf("\n");
	}
	
	
}


void bubbleSort(int arr[10][3],int t){
	int flag=1,n=t+1;
	while(flag){
		flag=0;
		
		for(int i=1;i<n;i++){
			if(arr[i][0]>arr[i+1][0] && (i+1)!=n){
				int temp=arr[i][0];
				arr[i][0]=arr[i+1][0];
				arr[i+1][0]=temp;
				
			 	temp=arr[i][1];
				arr[i][1]=arr[i+1][1];
				arr[i+1][1]=temp;
				
				temp=arr[i][2];
				arr[i][2]=arr[i+1][2];
				arr[i+1][2]=temp;
				flag=1;
			}
		}
	}
	
	
}


void simple(int arr[][3],int trans[][3],int t){
	trans[0][1]=arr[0][0];
	trans[0][0]=arr[0][1];
	trans[0][2]=arr[0][2];
	
	//switch the first and last
	
	for(int i=1;i<=t;i++){
		trans[i][0]=arr[i][1];
		trans[i][1]=arr[i][0];
		trans[i][2]=arr[i][2];
	}
	printf("========just swap===========");
	display(trans,6);
	//now value swap
	bubbleSort(trans,t);
	printf("========sort==========");
	display(trans,t);
	
}

int main(){
	int arr[][3]={
		{5,6,6},	
		{0,2,9},
		{1,1,8},
		{2,0,4},
		{2,3,2},
		{3,4,5},
		{4,2,2}
	};
	//1 1 2 1 0 1
	//1 2 3 5 6 6
//	printf("=========original==========\n");
//	display(arr,6);
	int trans[10][3];
//	simple(arr,trans,6);
	fast(arr,trans,6);


}

int big(int arr[][3],int t){
	int n=t+1;
	int max=0;
	for(int i=1;i<n;i++){
		if(max<arr[i][1])
			max=arr[i][1];
	}
	return max;
}

void fast(int arr[][3],int trans[][3],int t){
	trans[0][1]=arr[0][0];
	trans[0][0]=arr[0][1];
	trans[0][2]=arr[0][2];
	

	//how many times came
	//start of it
	int limit=big(arr,6)+1,n=t+1;
	int freq[limit]={0},start[limit]={0};
	//n coz it iterates

	for(int i=1;i<n;i++){
		freq[arr[i][1]]+=1;
	}
	//limit for freq
	for(int i=0;i<limit;i++)
		printf("%d	",freq[i]);
	
	printf("\n===================\n");
	start[0]=freq[0];
	for(int i=1;i<limit;i++){
	
			start[i]=start[i-1]+freq[i-1];
		
	}
	
	for(int i=0;i<limit;i++)
		printf("%d	",start[i]);
	
	int rows=1;
	for(int i=1;i<=t;i++){

		int tempCheck=arr[i][1];	
		trans[start[tempCheck]][0]=arr[i][1];
		trans[start[tempCheck]][1]=arr[i][0];
		trans[start[tempCheck]][2]=arr[i][2];
		//printf("%d	%d	%d	\n",trans[start[tempCheck]][0],trans[start[tempCheck]][1],trans[start[tempCheck]][2]);
		start[tempCheck]+=1;
	}
	printf("\n===========\n");
	display(trans,6);
	
	
}
