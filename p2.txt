#include<iostream> 	//header file used for input and output
#include<string>	//header file for string class
using namespace std;	//refer cin and cout
class student		//DEFINITION OF STUDENT CLASS
{
	string name,clas,dob,bld,addr,lic; 
	int *rollno,div,mob;
public:
	friend class teacher;		//FRIEND CLASS
	student()			//DEFAULT CONSTRUCTOR
	{
		rollno=new int;		//NEW IS DYNAMIC MEMORY ALLOCATION OPERATOR
		name,clas,dob,bld,addr,lic="";
		*rollno,div,mob=0;
	}
	student(student &obj)        //COPY CONSTRUCTOR
	{
		this->name=obj.name;	//this is a pointer points to the object which invokes it
      		this->addr=obj.addr;	//this-> can be written as name
      		this->clas=obj.clas;
      		this->div=obj.div;
      		this->rollno=obj.rollno;
      		this->mob=obj.mob;
      		this->bld=obj.bld;
      		this->dob=obj.dob;
		this->lic=obj.lic;
	}
	~student()			 //DESTRUCTOR
	{
		delete rollno;
	}
	inline static void display_header()		//STATIC FUNCTION AND INLINE FUNCTION
	{
		cout<<"\n ----------------- Student information system-------------------";
		cout<<"\n NAME \t ROLL NO  DIV \t CLASS \t DOB \t MOB \t BLD GRP \t ADDRESS \t LIC NO";
	}
	void getdata()			//TO CREATE DATABASE
	{
		cout<<"\nROLL NUMBER : ";
		cin>>*rollno;
		cout<<"\nNAME : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\nADDRESS : ";
		getline(cin,addr);
		cout<<"\nDATE OF BIRTH : ";
		getline(cin,dob);
		cout<<"\nClass : ";
		getline(cin,clas);
		cout<<"\nDIVISION: ";
		//cin.ignore();
		cin>>div;
		cout<<"\nBLOOD GROUP : ";
		cin.ignore();
		getline(cin,bld);
		cout<<"\nLICEINCE NUMBER : ";
		getline(cin,lic);
		cout<<"\nPHONE NUMBER : ";
		cin.ignore();
		cin>>mob;
	}
	void display()		//TO CREATE DATABASE
	{
		
	cout<<"\n"<<name<<"\t"<<*rollno<<"\t"<<div<<"\t"<<clas<<"\t"<<dob<<"\t"<<mob<<"\t"<<bld<<"\t"<<addr<<"\t"<<lic;
	}
};
class teacher
{
	public:    	
		void display_t(student &obj1, int d)   
		{
			try
			{
				if(obj1.div==d) 	//CHECK DIV
				{	student::display_header();
					obj1.display();
				}
				else
					throw(obj1.div);
			}
			catch(int x)  
			{
				cout<<"\nstudent & teacher division can not matched\n";
			}	
		}	
};
int main()
{
	 student s[10];
	 teacher t;
	 int ch,n;
	 do
	 {
	 cout<<"\n \n--------------------- Student information system ----------------------";
	 cout<<"\n -------------------- Menu------------------------";
	 cout<<"\n 1. Add student record";
	 cout<<"\n 2. Display student record";
	 cout<<"\n 3. Copy Constructor";
	 cout<<"\n 4. Division wise information";
	 cout<<"\n 5. Exit";
	 cout<<"\n Enter choice: ";
	 cin>>ch;
	 switch(ch)
	 {
	 	case 1:
	 		cout<<"\n Enter no of students: ";
			cin>>n;
			for(int i=0; i<n; i++)
			{
				cout<<"\nEnter details for student "<<i+1<<endl;
				s[i].getdata(); 
			}
	 		break;
	 	case 2:
	 		student::display_header();		//CALLING INLINE STATIC FUNCTION
		   	for(int i=0;i<n;i++)
		   	{
		   		s[i].display();
			   	
	       		}
		   	break;
		case 3:
			{
			cout<<"\n Copy Constructor";
			student s1;
			s1.getdata();
			student s2(s1);
			s2.display();
			}
			break;
		case 4:
			int div;
			cout<<"\n Enter division";
			cin>>div;
			for(int i=0;i<n;i++)
			{
				t.display_t(s[i],div);  
			}
			break;
		case 5:
		 	exit(0);     
		}
		}while(ch!=5);
	return 0;
}