#include<stdio.h>

void merge(int arr[],int beg,int mid,int end){
	int leftSize=mid-beg+1; //coz arr start from 0
	int rightSize=end-mid;
	int leftarr[leftSize],rightarr[rightSize];
	
	//copy data
	/*12 31 25 8 | 32 17 40 42
		if beg is 4 that is 32 the start putting value 
		from i=0 then beg+i i.e is 4+0 that is 32
		the i++ so 32 17 40 42 copied!
	*/
	for(int i=0;i<leftSize;i++)
		leftarr[i]=arr[beg+i];
	for(int i=0;i<rightSize;i++)
		rightarr[i]=arr[mid+i+1];
	//mid+j+1 coz mid is one behind
	
	//traverse the array
	int i=0,j=0,k=beg;
	
	while(i<leftSize && j<rightSize){
		if(leftarr[i]<=rightarr[j]){
			arr[k]=leftarr[i];
			i++;
		}else{
			arr[k]=rightarr[j];
			j++;
		}
		k++;
	}
	//agar koi array khatam hai to jo baccha hai usska dalo
	while(i<leftSize){
		arr[k]=leftarr[i];
		i++;
		k++;
	}
	
	while(i<rightSize){
		arr[k]=rightarr[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int beg,int end){
	printf("\nhello\n");
	if(beg<end)
	{
		int mid=(beg+end)/2;
		mergeSort(arr,beg,mid);
		mergeSort(arr,mid+1,end);
		printf("\nin\n");
		merge(arr,beg,mid,end);
	}

		
}

int main(){
	
	int arr[]={4,6,3,7,1,9};
	mergeSort(arr,0,5);
	printf("\n========\n");
	for(int i=0;i<6;i++)
		printf("%d	",arr[i]);
}
