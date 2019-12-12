//dfs traversal of graph using adjacency matrix
// the index represents the node.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[10];
int top=-1;

void push(int ele){
    stack[++top]=ele;
}

int pop(){
    return stack[top--];
}

void dfs(int graph[10][10],int n)
{
    int i,j;
    int visited[10];
    for(i=0;i<n;i++)
        visited[i]=0;

    i=0;
    push(i);
    while(top!=-1){
        i=pop();

        if(!visited[i]){
            visited[i] = 1;
            printf("%d \n",i);

            for(j=0;j<n;j++){
                if(!visited[j] && (graph[i][j] == 1 || graph[j][i] == 1))
                    push(j);
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

    dfs(graph,n);
}
