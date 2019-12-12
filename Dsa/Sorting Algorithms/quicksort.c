// Quick sort
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partition(int arr[],int low,int size){

  int x=arr[size];
  int i=low-1;
  int j;
  for(j=low;j<=size-1;j++){
    if(arr[j]<x){
      i++;
      //swap(arr[i],arr[j]);
       int tmp=arr[j];
       arr[j]=arr[i];
       arr[i]=tmp;
     }
  }
   //swap(arr[i+1],arr[size]);
       int tmp=arr[i+1];
       arr[i+1]=arr[size];
       arr[size]=tmp;
  return (i+1);
}


void quicksort(int arr[],int low,int size){

  if(low<size){
    int j=partition(arr,low,size);

    quicksort(arr,low,j-1);
    quicksort(arr,j+1,size);
   }

}


void main(){
  int arr[20];
  printf("Enter size of array");
  int size;
  scanf("%d",&size);
  printf("Enter array to sort using QuickSort Algorithm");
  int i;
  for(i=0;i<size;i++)
  scanf("%d",&arr[i]);

  quicksort(arr,0,size-1);
  printf("Sorted Array is : ");

  for(i=0;i<size;i++)
  printf("%d \t",arr[i]);

}
