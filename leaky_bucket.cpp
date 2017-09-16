#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#define max 10

using namespace std;

int main(){
  int pts[max],buffer[max],i,n;
  int input,size,orate;
  cout<<"enter the size of the bucket\n";
  cin>>size;
  cout<<"enter the number of packets to be generated\n";
  cin>>n;
  cout<<"enter the output rate of bucket\n";
  cin>>orate;
  cout<<"the packets generated are\n";
  for(i=0;i<n;i++){
    pts[i] = rand()%50;
  }
  for(i=0;i<n;i++){
    cout<<pts[i]<<"\t";
  }cout<<endl;
  for(i=0;i<n;i++){
    input = pts[i];
    if(input > orate){
      cout<<pts[i]<<" is invalid\n";
    }
    else{
      cout<<pts[i]<<" is valid\n";
    }
  }
  return 0;
}
