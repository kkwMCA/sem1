#include<stdio.h>
int arr[4][5] =  
    {  
        {0 , 0 , 6 , 0 , 9 },  
        {0 , 0 , 4 , 6 , 0 },  
        {0 , 0 , 0 , 0 , 0 },  
        {0 , 1 , 2 , 0 , 0 }  
};

void toSpares(int sp[][3],int n,int m,int t){
	int temp1=1;
	sp[0][0]=n;
	sp[0][1]=m;
	sp[0][2]=t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0){
				sp[temp1][0]=i;
				sp[temp1][1]=j;
				sp[temp1][2]=arr[i][j];
				temp1++;
			}
		}
	}
	
}

void displaySpares(int sp[][3],int t){
	
	for(int i=0;i<=t;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",sp[i][j]);
		}
		printf("\n");
	}
}


//===simple trans start==========
void bubble(int trans[][3],int t){
	int temp,n=t+1;
	bool b=true;
	while(b){
	
		b=false;
		for(int i=1;i<n;i++){
			if(trans[i][0]>trans[i+1][0] && i+1!=n){
				b=true;
				//printf("hello\n");
				temp=trans[i][0];
				trans[i][0]=trans[i+1][0];
				trans[i+1][0]=temp;
			
				temp=trans[i][1];
				trans[i][1]=trans[i+1][1];
				trans[i+1][1]=temp;
				
				temp=trans[i][2];
				trans[i][2]=trans[i+1][2];
				trans[i+1][2]=temp;
			}else{
				if(trans[i][0]==trans[i+1][0] && i+1!=n){
					if(trans[i][1]>trans[i+1][1]){
						b=true;
				//printf("hello\n");
						temp=trans[i][0];
						trans[i][0]=trans[i+1][0];
						trans[i+1][0]=temp;
					
						temp=trans[i][1];
						trans[i][1]=trans[i+1][1];
						trans[i+1][1]=temp;
						
						temp=trans[i][2];
						trans[i][2]=trans[i+1][2];
						trans[i+1][2]=temp;		
					}	
				}
			}
		}
	}
}



void simpleTrans(int sp[][3],int trans[][3],int t){
	trans[0][0]=sp[0][0];
	trans[0][1]=sp[0][1];
	trans[0][2]=sp[0][2];
	for(int i=1;i<=t;i++){
		trans[i][0]=sp[i][1];
		trans[i][1]=sp[i][0];
		trans[i][2]=sp[i][2];
	}
	bubble(trans,t);	
}
//===simple trans end==========

void fastTrans(int sp[][3],int trans[][3],int t){
	
	int freq[sp[0][1]]={0},pos[sp[0][1]]={0};
	for(int i=1;i<=sp[0][1];i++){
		freq[sp[i][1]]+=1;
	}
	int n=sp[0][1];
	int start=0;
	for(int i=0;i<n;i++){
		if(freq[i]!=0){
			start=i;
			break;
		}
	}
	printf("\nstart:%d\n",start);
	
	printf("\n====freq=====\n");
	for(int i=0;i<n;i++)
		printf("%d ",freq[i]);
	printf("\n");
	
	pos[start]=1;
	for(int i=start+1;i<n;i++){
		pos[i]=pos[i-1]+freq[i-1];	
	}
	printf("\n====start=====\n");
	for(int i=0;i<n;i++)
			printf("%d ",pos[i]);
	trans[0][0]=sp[0][1];
	trans[0][1]=sp[0][0];
	trans[0][2]=sp[0][2];
	int temp;
	for(int i=1;i<t;i++){
		temp=sp[i][1];
		trans[pos[temp]][0]=temp;
		trans[pos[temp]][1]=sp[i][0];
		trans[pos[temp]][2]=sp[i][2];
		pos[temp]+=1;
	}
//	trans[1][0]=
//-1 1 3 1 1 0	
}

int main(){
	int sp[10][3];
	int trans[10][3];
	printf("\n==============\n");
	toSpares(sp,4,5,6);
	displaySpares(sp,6);
	printf("\n==============\n");
//	simpleTrans(sp,trans,6);
	printf("\n==============\n");
//	displaySpares(trans,6);
	fastTrans(sp,trans,6);
	printf("\n");
	displaySpares(trans,6);
	
}  

