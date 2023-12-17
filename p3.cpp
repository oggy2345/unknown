/*
Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
*/

#include<iostream>
#include<string.h>
using namespace std;
class publication
{
	string title;
	float price;
public:
		void getdata()
		{

			cout<<"\n Enter the title: ";
			cin.ignore();
			getline(cin,title);
			cout<<"\n Enter the price: ";
			//cin.ignore();
			cin>>price;
		}
		void display()
		{
			cout<<"\n Title: "<<title;
			cout<<"\n Price: "<<price;
		}
};
class book:public publication
{
	int page_count;
public:
	void getdata()
	{
		try
		{
			publication::getdata();
			cout<<"\n Enter the no. of pages in book: ";
			cin.ignore();
			cin>>page_count;
			if(page_count<=0)
				throw page_count;
		}
		catch(...)
		{
			cout<<"\n Invalid page count!!! Try Again... \n";
			page_count=0;
		}
	}
	void display()
	{
		publication::display();
		cout<<"\n No. of pages: "<<page_count;
	}

};
class tape:public publication
{
	float play_time;
public:		
	void getdata()
	{
		try
		{
			publication::getdata();
			cout<<"\n Enter the playing time for tape: ";
			cin>>play_time;
			if(play_time<=0)
				throw play_time;
		}
		catch(...)
		{
  			cout<<"\n Invalid play time!!! Try Again... \n";
			play_time=0;
		}
	}
	void display()
	{
		publication::display();
		cout<<"\n play_time: "<<play_time;
	}
};

int main()
{
	book b[10];
	tape t[10];
	int ch, bcount=0, tcount=0;
	do
	{
		cout<<"\n---------- Publication Details ----------";
		cout<<"\n 1. Add book details ";
		cout<<"\n 2. Add tape details ";
		cout<<"\n 3. Display book details ";
		cout<<"\n 4. Display tape details ";
		cout<<"\n 5. Exit";
		cout<<"\n Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b[bcount].getdata();
				bcount++;
				break;
			case 2:
				t[tcount].getdata();
				tcount++;
				break;
			case 3:
				for(int i=0;i<bcount;i++)
				{
					b[i].display();
				}
				break;
			case 4:
				for(int i=0;i<tcount;i++)
				{
					t[i].display();
				}
				break;
			case 5:
				exit(0);
		}
	}while(ch!=5);

	return 0;
}
