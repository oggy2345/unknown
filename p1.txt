/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >>to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class Complex
{
	int x;
	int y;
	
public:
	Complex()
	{
		x=y=0;
	}

    	Complex operator +(Complex);
   
	Complex operator *(Complex);
		
	friend istream & operator >> (istream &input, Complex &c)
	{
		cout<<"\nEnter real part of complex number : ";
		input>>c.x;
		cout<<"\nEnter imaginary part of complex number : ";
		input>>c.y;
	}
		
	friend ostream & operator << (ostream &output, Complex &c)
	{
		output<<c.x<<" + "<<c.y<<"i"<<endl; 
	}
};

Complex Complex :: operator + (Complex c)
{
	Complex temp;
	temp.x=x+c.x;
	temp.y=y+c.y;
	return temp;
}

Complex Complex :: operator * (Complex c)
{
	Complex temp;
	temp.x=(x*c.x)-(y*c.y);
	temp.y=(x*c.y)+(y*c.x);
	return temp;
}
int main()
{
	Complex c1,c2,c3,c4;	
	int ch;
	do
	{
			
		cout<<"\n-------------MENU-------------\n";
		cout<<"1. Default Constructor"<<endl;
		cout<<"2. Add Complex numbers "<<endl;
		cout<<"3. Display Complex number"<<endl;
		cout<<"4. Addition of Complex numbers "<<endl;
		cout<<"5. Multiplication of Complex numbers"<<endl;
		cout<<"6. Exit"<<endl;
		
		cout<<"\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nDefault constructor : ";
				cout<<c1;
				break;
			
			case 2:
				cout<<"\nEnter first number ";
				cin>>c1;
				cout<<"\nEnter second number ";
				cin>>c2;
			   break;
			case 3:
				cout<<"\n1st Complex Number : ";
				cout<<c1;
				cout<<"\n2nd Complex Number : ";
				cout<<c2;
				break;
			case 4:
				c3=c1+c2;
				cout<<"\nAddition of Complex number : ";
				cout<<c3;
				break;
			case 5:
			
				c4=c1*c2;
				cout<<"\nMultiplication of Complex number : ";
				cout<<c4;
				break;
			case 6:
				exit(0);			
		}
	}while(ch!=6);
	return 0;
}