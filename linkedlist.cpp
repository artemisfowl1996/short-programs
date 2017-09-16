#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
typedef struct Node{
  int data;
  Node *next;
}node;

int print_data(node *n){
    cout<<"the data in the node is "<<n->data;
}
int insert_node(){
  node *n;
  n = (node*)malloc(sizeof(node));
  cout<<"insert data\n";
  cin>>n->data;
}
int main(){
  node *head=NULL,*first=NULL,*last=NULL;
  head = (node*)malloc(sizeof(node));
  first = (node*)malloc(sizeof(node));
  last = (node*)malloc(sizeof(node));
  return 0;
}
