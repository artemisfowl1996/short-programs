#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#define len 50
#include<stdio.h>

using namespace std;

class student{
  char name[10],usn[10],age[3],buf[len];
public:void pack();
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
  strcat(buf,"#");
}

void student::unpack(){
  strcpy(name,strtok(buf,"|"));
  strcpy(usn,strtok(NULL,"|"));
  strcpy(age,strtok(NULL,"#"));
}

void student::add(){
  cout<<"ENTER THE STUDENT DETAILS\n";
  cout<<"NAME\n";
  cin>>name;
  cout<<"USN\n";
  cin>>usn;
  cout<<"AGE\n";
  cin>>age;
  pack();
  ofstream fout;
  fout.open("3.txt",ios::out|ios::app);
  fout<<buf;
  fout.close();
  cout<<"RECORD ADDED\n";
}

void student::display(){
  fstream fin;
  fin.open("3.txt",ios::in);
  while(!fin.eof())
  {
    fin.getline(buf,100,'#');
    if(fin.fail())break;
    unpack();
    cout<<"NAME\t"<<name<<"\n"<<"USN\t"<<usn<<"\n"<<"AGE\t"<<age<<endl;
  }
  fin.close();
}

void student::search(){
  char key[10];
  int i=1;
  cout<<"enter the usn"<<endl;
  cin>>key;
  fstream fin;
  fin.open("3.txt",ios::in);
  while(!fin.eof())
  {
    fin.getline(buf,100,'#');
    if(fin.fail())break;
    unpack();
    if(strcmp(key,usn)==0)
    {
      cout<<"RECORD FOUND"<<endl;
      i=0;
      cout<<"NAME\t"<<name<<"\n"<<"USN\t"<<usn<<"\n"<<"AGE\t"<<age<<endl;
    }
  }
  if(i==1)
  {
    cout<<"RECORD NOT FOUND"<<endl;
  }
}

void student::modify(){
  char key[10];
  cout<<"enter the key"<<endl;
  cin>>key;
  fstream fin,fout;
  fin.open("3.txt",ios::in);
  fout.open("a.txt",ios::out|ios::app);
  while(!fin.eof())
  {
    fin.getline(buf,100,'#');
    if(fin.fail())break;
    unpack();
    if(strcmp(key,usn)==0)
    {
      cout<<"CURRENT DETAILS ARE:"<<endl;
      cout<<"NAME\n"<<name<<"\n"<<"USN\t"<<usn<<"\n"<<"AGE\t"<<age<<endl;
      cout<<"ENTER NEW DETAILS"<<endl;
      cout<<"NAME\n";
      cin>>name;
      cout<<"USN\n";
      cin>>usn;
      cout<<"AGE\n";
      cin>>age;}
      pack();
      fout<<buf;
  }
  fin.close();
  fout.close();
  remove("3.txt");
  rename("a.txt","3.txt");
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
