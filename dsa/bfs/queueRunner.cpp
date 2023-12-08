//bfs
#include<stdio.h>
#include"queue.h"
int arr[][5]={
	//0,1,2,3,4
	{0,1,1,1,0},
	{1,0,1,0,0},
	{1,1,0,0,1},
	{1,0,0,0,0},
	{0,0,1,0,0}
};
int visited[10]={-1},i=0;
int vertex=0;
int see[10]={0};
void dfs(){
	add(vertex);
	printf("%d ",vertex);
	while(!isEmpty()){
		int node = peek(); //remove
        see[vertex] = 1; //mark visited
        for (int j = 0; j < 5; j++)
        {
            if(arr[node][j] ==1 && see[j] == 0){
                printf("%d ", j); //add to the bfs
                see[j] = 1;
                add(j); //add neighbors
            	
			}
        }
        vertex=peek();
        del();
	}
}

int main(){
	dfs();
}
