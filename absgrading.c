#include<stdio.h>
#include<stdlib.h>
void main(){
  int per;
  char val;
  printf("ENTER THE STUDENTS PERCENTAGE\n");
  scanf("%d",&per);
  if(per>=90 && per<=100){
    val='A';
  }
  else if(per<90 && per>=80){
    val='B';
  }
  else if(per<80 && per>=70){
    val='C';
  }
  else if(per<70 && per>=60){
    val='D';
  }
  else if(per<60 && per>=50){
    val='E';
  }
  else{
    printf("INVALID PERCENTAGE\n");
  }
  switch(val){
    case 'A':printf("OUTSTANDING\n");
    break;
    case 'B':printf("VERY GOOD\n");
    break;
    case 'C':printf("GOOD\n");
    break;
    case 'D':printf("FAIR\n");
    break;
    case 'E':printf("SHOULD IMPROVE\n");
    break;
  }
}
