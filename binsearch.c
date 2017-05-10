#include<stdio.h>
#include<stdlib.h>

void main(){
  int low,mid,high,a[10];
  int i,n,key;
  printf("enter the number of elements\n");
  scanf("%d",&n);
  printf("enter the elements\n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter the key\n");
  scanf("%d",&key);
  low=0;
  high=n-1;
  mid=(low+high)/2;

  while(low<=high){
    if(a[mid]<key){
      low=mid+1;
    }
    else if(a[mid]==key){
      printf("element found at location %d\n",mid+1);
      break;
    }
    else{
      high=mid-1;
    }
    mid=(low+high)/2;
  }
  if(low>high){
    printf("element not found\n");
    exit(0);
  }
}
