#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#define len 50
using namespace std;
class student
{
	char name[20],usn[20],marks[20],buf[len];
	public:void add();
	void pack();
	void unpack();
	void search();
	void display();
};

void student::pack()
{
	strcpy(buf,name);
	strcat(buf,"|");
	strcat(buf,usn);
	strcat(buf,"|");
	strcat(buf,marks);
	for(int i=strlen(buf);i<len-1;i++)
	{
		strcat(buf,"*");
	}
}

void student::unpack()
{
	strcpy(name,strtok(buf,"|"));
	strcpy(usn,strtok(NULL,"|"));
	strcpy(marks,strtok(NULL,"*"));
}

void student::add()
{
	cout<<"enter the student name"<<endl;
	cin>>name;
	cout<<"enter the student USN"<<endl;
	cin>>usn;
	cout<<"enter the student marks"<<endl;
	cin>>marks;
	pack();
	fstream fout("student1.txt",ios::out|ios::app);
	fout<<buf<<endl;
	fout.close();

	cout<<"record added"<<endl;
}

void student::display()
{
	fstream fin;
	fin.open("student1.txt",ios::in);
	cout<<"student details are"<<endl;
	while(!fin.eof())
	{
		fin>>buf;
		if(fin.fail())
		break;
		unpack();
		cout<<"name:"<<"\t"<<name<<"\n"<<"usn:"<<"\t"<<usn<<"\n"<<"marks:"<<"\t"<<marks<<"\n";
	}
	fin.close();
}

void student::search()
{
	int rrn;
	cout<<"enter the rrn"<<endl;
	cin>>rrn;
	fstream fin;
	fin.open("student1.txt",ios::in);
	int offset=rrn*len;
	fin.seekg(offset,ios::beg);
	fin>>buf;
	if(fin.fail())
	{
		cout<<"record not found\n";
		exit(0);
	}
	else
	{
		unpack();
		cout<<"name:"<<"\t"<<name<<"\n"<<"usn:"<<"\t"<<usn<<"\n"<<"marks:"<<"\t"<<marks<<"\n";
		fin.close();
	}
}

int main()
{
	student s;
	int choice;
	while(1){
	cout<<"enter your choice\n";
	cout<<"1:ADD\n2:DISPLAY\n3:SEARCH\n4:EXIT"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:s.add();
			break;
		case 2:s.display();
			break;
		case 3:s.search();
			break;
		case 4:exit(0);
	}
	}
}
