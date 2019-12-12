//bfs traversal of graph using adjacency matrix
// the index represents the node.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int queue[10];
int f=-1,r=-1;

void insert(int ele){
    queue[++r]=ele;
}

int removeEle(){
    return queue[++f];
}

void bfs(int graph[10][10],int n){

    int i,j;
    int visited[10];
    for(i=0;i<n;i++)
        visited[i]=0;

    i=0;
    visited[i]=1;
    insert(i);
    while(f!=10){
        i=removeEle();
        for(j=0;j<n;j++){
            if(!visited[j] && (graph[i][j] == 1 || graph[j][i] == 1))
              {
                visited[j]=1;
                insert(j);
              }
        }
    }

}

void main(){

    int graph[10][10];
    int i,j,n;
    puts("Enter no of elements \n");
    scanf("%d",&n);

    puts("Enter adjacency matrix for the graph \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    puts("Matrix u entered is \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
              printf("%d \t",graph[i][j]);
        }
        printf("\n");
    }

    bfs(graph,n);
}
