#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;
int e,n,Q,p,q,d,m=88;

int hcf(int a,int b){
  int temp;
  while(1){
    temp = a%b;
    if(temp==0) {return b;}
    a = b;
    b = temp;
  }
}

int prime(int x){
  int flag=1,i;
  for(i=0;i<x/2;i++){
    if(x%i==0){
      flag=0;
      break;
    }
  }
  if(flag==1){
    return x;
  }
  else{
    exit(0);
  }
}

int main(){
  int p,q,n,i,e,d,z,ch,j;
  char text[10];
  int cipher[10];
  cout<<"enter two prime numbers\n";
  cin>>p>>q;
  cout<<"enter the text to be ecrypted\n";
  cin>>text;
  n = p*q;
  z = (p-1)*(q-1);

  for(i=2;i<z;i++){
    if(hcf(i,z)==1 && prime(i))  {
      e = i;
      break;
    }
  }
  cout<<"public key is "<<e<<"\t"<<z<<endl;
  for(d=2;d<z;d++){
    if((d*e)%z==1){
      break;
    }
  }
  cout<<"private key is "<<d<<"\t"<<z<<endl;
  for(i=0;i<strlen(text);i++){
    int t=1;
    ch = (int)text[i];
    for(j=0;j<e;j++){
      t = (t*ch)%n;
    }
    cipher[i] = t;
  }
  cout<<"MESSAGE ENCRYPTED\n";
  for(i=0;i<strlen(text);i++){
    cout<<cipher[i];
  }
  for(i=0;i<strlen(text);i++){
    char t;
    ch = cipher[i];
    for(j=0;j<d;j++){
      t = (t*ch)%n;
    }
    text[i] = t;
  }
  cout<<"MESSAGE DECRYPTED\n";
  for(i=0;i<strlen(text);i++){
    cout<<text[i];
  }
  text[i]='\0';
  return 0;
}
