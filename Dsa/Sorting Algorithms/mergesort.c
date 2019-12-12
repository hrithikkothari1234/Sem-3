// Merge sort
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void merge(int arr[],int t,int m,int u){
  int i=t;  //beginning of first part
  int j=m+1; //beginning of second part
  int k=0;
  int temp[j]; //temporary array of same size

    while(i<=m && j<=u){
      if(arr[i]<arr[j])
        temp[k++]=arr[i++];
      else
        temp[k++]=arr[j++];
     }

    while(i<=m)
      temp[k++]=arr[i++];

    while(j<=u)
      temp[k++]=arr[j++];

    for(i=t,j=0;i<=u;i++,j++)
      arr[i]=temp[j];         //temp->arr
 }

void mergesort(int arr[],int i,int j){
  if(i<j){
    int k=(i+j)/2;
      mergesort(arr,i,k);      //recursion of left part of array
      mergesort(arr,k+1,j);    //recursion of right part of array
      merge(arr,i,k,j);        //merge 2 sorted parts
  }
}


void main(){
  int size,i;
    puts("Enter length of array to sort using Merge Sort");
    scanf("%d",&size);
    puts("Enter data");
    int arr[size];
    for(i=0;i<size;i++)
      scanf("%d",&arr[i]);
    mergesort(arr,0,size-1);
    puts("Sorted Array is :");
      for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
}
