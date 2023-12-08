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

int vertex=0;//for the see[]
int see[10]={0};//visited
void dfs(){
	add(vertex);//put 0 first
	printf("%d ",vertex);//print it
	while(!isEmpty()){
		int node = peek(); //put to get adj
        see[vertex] = 1; //mark visited
        for (int j = 0; j < 5; j++)
        {
            if(arr[node][j] ==1 && see[j] == 0){
                printf("%d ", j); //add to the bfs
                see[j] = 1;
                add(j); //add neighbors
            	
			}
        }
        vertex=peek();//now put the adj in the vertex to visit
        del(); //del first
	}
}

int main(){
	dfs();
}
