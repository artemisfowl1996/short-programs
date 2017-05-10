#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#define len 50

using namespace std;

class student{
public:char buf[len],name[10],usn[10],age[3];
void pack();
void unpack();
void add();
void display();
void search();
void modify();
};

void student::pack(){
  strcpy(buf,name);
  strcat(buf,"|");
  strcat(buf,usn);
  strcat(buf,"|");
  strcat(buf,age);
  for(int i=strlen(buf);i<len;i++)
  {
    strcat(buf,"*");
  }
}

void student::unpack(){
  strcpy(name,strtok(buf,"|"));
  strcpy(usn,strtok(NULL,"|"));
  strcpy(age,strtok(NULL,"*"));
}

void student::add(){
  ofstream fout;
  fout.open("2.txt",ios::out|ios::app);
  cout<<"ENTER STUDENT DETAILS:"<<endl;
  cout<<"ENTER NAME\n";
  cin>>name;
  cout<<"ENTER USN\n";
  cin>>usn;
  cout<<"ENTER AGE\n";
  cin>>age;
  pack();
  fout<<buf<<endl;
  fout.close();
  cout<<"record added\n";
}

void student::display(){
  ifstream fin;
  fin.open("2.txt",ios::in);
  cout<<"details are\n";
  while(!fin.eof())
  {
    fin>>buf;
    if(fin.fail())break;
    unpack();
    cout<<"NAME\t"<<name<<endl<<"USN\t"<<usn<<endl<<"AGE\t"<<age<<endl;
  }
  fin.close();
}

void student::search(){
  fstream fin;
  fin.open("2.txt",ios::in);
  char key[10];
  int i=1;
  cout<<"enter the key to be searched"<<endl;
  cin>>key;
  while(!fin.eof())
  {
    fin>>buf;
    if(fin.fail())break;
    unpack();
    if(strcmp(key,usn)==0){
      i=0;
    cout<<"STUDENT DETAILS ARE:"<<endl;
    cout<<"NAME\t"<<name<<endl<<"USN\t"<<usn<<endl<<"AGE\t"<<age<<endl;
    return;
  }
}
  if(i==1)
  {
    cout<<"RECORD NOT FOUND\n";
  }
}

void student::modify(){
  char key[10];
  int f=1;
  fstream fin;
  fin.open("2.txt",ios::in|ios::out);
  cout<<"enter the key"<<endl;
  cin>>key;
  while(!fin.eof())
  {
    fin>>buf;
    if(fin.fail())break;
    unpack();
    if(strcmp(key,usn)==0)
    {
      f=0;
      cout<<"CURRENT DETAILS ARE:\n";
      cout<<"NAME\t"<<name<<endl<<"USN\t"<<usn<<endl<<"AGE\t"<<age<<endl;
      cout<<"ENTER NAME\n";
      cin>>name;
      cout<<"ENTER USN\n";
      cin>>usn;
      cout<<"ENTER AGE\n";
      cin>>age;
      pack();
      fin.seekp((int)fin.tellg()-len,ios::beg);
      fin<<buf;
      fin.close();
      return;
    }
  }
  if(f==1)
  {
    cout<<"RECORD NOT FOUND"<<endl;
  }
}

int main()
{
  student s;
  int i;
  while(1){
  cout<<"ENTER YOUR CHOICE"<<endl;
  cout<<"1.ADD\n2.DISPLAY\n3.SEARCH\n4.MODIFY\n5.EXIT"<<endl;
  cin>>i;
  switch (i) {
    case 1:s.add();
    break;
    case 2:s.display();
    break;
    case 3:s.search();
    break;
    case 4:s.modify();
    break;
    case 5:exit(0);
  }
}
  return 0;
}
