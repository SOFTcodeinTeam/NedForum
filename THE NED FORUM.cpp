#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<cstring>
#include<fstream>
#include<ctime>
#include<time.h>
#include<Windows.h>
using namespace std;

class User                                                 //Base class
{
protected:
	string User_Name, First_Name, Last_Name, Date_of_Birth, Gender, User_Id, Department; // Attributes
	char Password[20];
public:
	User()                                                 //Default constructor
	{ }
	//Get set methods
	string Get_Name()                
	{
		return First_Name + " " + Last_Name;
	}
	void Set_First_Name (string n)
	{
		First_Name = n;
	}
	string Get_First_Name()
	{
		return First_Name;
	}
	void Set_Name(string n, string l)
	{
		First_Name = n;
		Last_Name = l;
		User_Name = n + " " + l;
	}
	string Get_DOB()
	{
		return Date_of_Birth;
	}
	void Set_DOB(string n)
	{
		Date_of_Birth = n;
	}
	string Get_Gender()
	{
		return Gender;
	}
	void Set_Gender(string n)
	{
		Gender = n;
	}
	string Get_UserID()
	{
		return User_Id;
	}
	void Set_UserID(string n)
	{
		User_Id = n;
	}
	char* Get_Password()
	{
		return Password;
	}
	void Set_Password(char n[])
	{
		int i = 0;
		while (n[i] != '\0')
		{
			Password[i] = n[i];
			i++;
		}
		Password[i] = '\0';
	}
	string Get_Department()
	{
		return Department;
	}
	void Set_Department(string n)
	{
		Department = n;
	}
	virtual void input()                                       //input method
	{
		ofstream outfile;
		outfile.open("Passwords.txt", ios :: app);    //password file for matching passwords
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout << endl << "First Name : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> First_Name;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Last Name : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Last_Name;
		User_Name = First_Name + " " + Last_Name;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Date of Birth : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Date_of_Birth;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Gender : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Gender;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "User Id : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> User_Id;
		outfile << User_Id << " ";
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Password : ";
		char ch;
		SetConsoleTextAttribute(hConsole, 241);
		while ((ch = _getch()) != '\r')                            // for hiding password characters
	    {
		   outfile.put(ch);
		   cout << "*";
	    }
		outfile << endl;
		outfile.close();
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\nDepartment (press '.' to terminate): ";
		SetConsoleTextAttribute(hConsole, 241);
		getline(cin, Department,'.');
		outfile.open( "Searching.txt" , ios :: app );              // Searching file, to search someone by his/her name 
		outfile << User_Id << " " << First_Name << endl;
		outfile.close();
	}
	virtual void display() = 0;                                    // pure virtual method
	bool Password_Match()                                          // password match method
	{
		ifstream infile;
		infile.open("Passwords.txt");
		string user_id, password;
		while (!infile.eof())
		{
			infile >> user_id >> password;
			if(user_id == User_Id && password == Password)
			{
				infile.close();
				return true;
			}
		}
		infile.close();
		return false;
	}
};

class Student : public User                                       // student class
{
	string  Year, Extra_Curriculum_Activities;
public:
	Student()                                                           // Default constructor
	{ }
	// Get set methods
	string Get_Year()
	{
		return Year;
	}
	void Set_Year(string n)
	{
		Year = n;
	}
	string Get_Activities()
	{
		return Extra_Curriculum_Activities;
	}
	void input()                                                     // Input method of student class
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		ofstream outfile;
		User :: input();
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Year : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Year;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Extra Curriculum Activities (press '.' to terminate) : ";
		SetConsoleTextAttribute(hConsole, 241);
		getline(cin, Extra_Curriculum_Activities, '.');
		outfile.open(User_Id,ios::app);                              // Writing to file
		outfile << "\nUser Name : " << User_Name;
		outfile << "\nDate of Birth : " << Date_of_Birth;
		outfile << "\nGender : " << Gender;
		outfile << "\nUser ID : " << User_Id;
		outfile << "\nDepartment : " << Department;
		outfile << "\nAcademic Year : " << Year;
		outfile << "\nExtra Curriculum Activities : " << Extra_Curriculum_Activities;
		outfile << "\n\nPosts\n" ;
		outfile.close();
	}
	void display()                                               // Display method of student class
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 241);
		string item;
		ifstream infile;
		infile.open(User_Id);
		for (int i = 0; i < 10 ; i++)
		{
			getline(infile, item);
			cout << item << endl;
		}
	}
};

class Teaching_Staff : public User                              // Teacher class
{
	string Status, Course;
public:
	Teaching_Staff()                                            // Default constructor
	{ }
	// Get set methods
	string Get_Status()
	{
		return Status;
	}
	string Get_Course()
	{
		return Course;
	}
	void Set_Status(string n)
	{
		Status = n;
	}
	void Set_Course(string n)
	{
		Course = n;
	}
	void input()                                                // Input method of Teaching_Staff class
	{
		ofstream outfile;
		User :: input();
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Status (press '.' to terminate): ";
		SetConsoleTextAttribute(hConsole, 241);
		getline(cin, Status,'.');
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Course (press '.' to terminate): ";
		SetConsoleTextAttribute(hConsole, 241);
		getline(cin, Course,'.');
		outfile.open(User_Id , ios::app );                        // Writing to file
		outfile << "\nName : " << User_Name;
		outfile << "\nDate of Birth : " << Date_of_Birth;
		outfile << "\nGender : " << Gender;
		outfile << "\nUser ID : " << User_Id;
		outfile << "\nDepartment : " << Department;
		outfile << "\nStatus(e.g Chair_person, Lecturer, Professor) : " << Status;
		outfile << "\nCourse : " << Course;
		outfile << "\n\nPosts\n" ;
		outfile.close();
	}
	void display()                                             // Display method of Teaching_Staff class
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 241);
		string item;
		ifstream infile;
		infile.open(User_Id);
		for (int i = 0; i < 11; i++)
		{
			getline(infile, item);
			cout << item << endl;
		}
		infile.close();
	}
};

class Post                                                    // post class
{
	string Text_Post;
public:
	Post()                                                    // Default constructor
	{ }
	void Write_post()                                         // Write Post method
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout<<"\nWrite post(Use '$' to terminate):\n";
		SetConsoleTextAttribute(hConsole, 241);
		getline(cin, Text_Post, '$');
	}
	string Get_post()                                         // Get post method
	{
		return Text_Post;
	}
};

class SNS                                                     // SNS class
{
	string Designation;
	User *U;
	Post P;
public:
	SNS()                                                     // Default constructor
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\nDesignation(e.g Teacher, Student) : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Designation;
		if (Designation == "Teacher")
			U = new Teaching_Staff;
		else if (Designation == "Student")
			U = new Student;
	}
	string Get_Designation()                                  // Get method
	{
		return Designation;
	}
	void Create_Account()                                     // Method to create account
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\n \t\t SIGNUP FOR THE NED FORUM !!! \n";
		cout << "\nDesignation(e.g Teacher, Student) : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> Designation;
		if (Designation == "Teacher")
			U = new Teaching_Staff;
		else if (Designation == "Student")
			U = new Student;
		U -> input();
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\nYour account has been created. ";
	}
	void Login()                                             // Method to login to your account
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\n\t\t   LOGIN INTO THE NED FORUM !!!! \n";
		string n, month;
		int min, hr, day, year;
		string first_name, last_name, id;
		char password[20], ch;
		int no;
		int count = 0;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\nName : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> first_name >> last_name;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "User ID : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> id;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "Password : ";
		SetConsoleTextAttribute(hConsole, 241);
		while ((ch = _getch()) != '\r')
		{
			cout << "*";
			password[count++] = ch;
		}
		password[count] = '\0';
		U -> Set_First_Name(first_name);
		U -> Set_Name(first_name, last_name);
		U -> Set_UserID(id);
		U -> Set_Password(password);
		if(U -> Password_Match())                                  // checking if user has logged in
		{
			mylabel:
			system("CLS");
			SetConsoleTextAttribute(hConsole, 240);
			cout<<"\n\t\t***THE NED FORUM***"<<endl;
			SetConsoleTextAttribute(hConsole, 241);
			for(int i=0;i<80;i++)
			{
				cout<<"_";
			}
			cout<<endl<<endl;
			cout<<"    *** ";
			SetConsoleTextAttribute(hConsole, 240);
			cout << U->Get_Name();
			SetConsoleTextAttribute(hConsole, 241);
			cout <<" ***"<<endl<<endl;    // User's name will be displayed
			U -> display();
			Display_Posts();
			while(1)
			{
				SetConsoleTextAttribute(hConsole, 240);
                cout<<"\n\t\t***MAIN MENU***"<<endl<<endl;
				SetConsoleTextAttribute(hConsole, 241);
				cout<<"   1. Write Posts."<<endl;
				cout<<"   2. Virtual Chat room."<<endl;
				cout<<"   3. Search."<<endl;
				cout<<"   4. Logout."<<endl;
				SetConsoleTextAttribute(hConsole, 240);
			    cin >> no;
		        if(no == 1)                                     // When user wants to write posts
		        {
					system("CLS");
					SetConsoleTextAttribute(hConsole, 240);
		            cout<<"\n\t\t***THE NED FORUM***"<<endl;
					SetConsoleTextAttribute(hConsole, 241);
	 	            for(int i=0;i<80;i++)
		            {
			           cout<<"_";
		            }
				    ofstream outfile;
					Get_Current_Date(month, day, year);
				    Get_Current_Time(n, hr, min);
		            P.Write_post();
			        outfile.open(U -> Get_UserID(), ios :: app);
					outfile << U->Get_Name();
					outfile << endl;
				    outfile << month << " " << day << ", " << year << " at " << hr << ":" << min << " " << n << endl;
			        outfile << P.Get_post() << endl << endl;
					SetConsoleTextAttribute(hConsole, 240);
			        cout << "\nSaved";
			        outfile.close();
				    goto mylabel;
		        }
			    if(no == 2)                                      // When user want to go to virtual chat room
			    {
				   virtual_chat();
				   goto mylabel;
			    }
			    if(no == 3)                                      // When user want to Search someone
			    {
				   Search();
				   goto mylabel;
			    }
                if (no == 4)                                     // When user wants to logout
			    {
				   Logout();
			       break;
			    }
		    }
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 240);
			cout << "\nInvalid User Id / Password.\n";
		}
	}
	void Logout()                                               // logout method
	{
		system("CLS");
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Press any key to continue .... ";
	}
	void Display_Posts()                                        // To display posts
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 240);
		ifstream infile;
		string buffer;
		int len;
		int count = 0;
		infile.open(U->Get_UserID());
		while(!infile.eof())
	    {
		    infile >> buffer;
		    len = buffer.length();
		    if (buffer == "Posts")
		    {
				count += len + 8;
			    infile.seekg(count, ios :: beg);
				label:
			    getline(infile, buffer);
			    cout << buffer << endl;
				if(infile.eof())
				{ 
					break; 
				} 
				else
				{
					goto label;
				}
			 }
		        else
				{
			        count += len + 1;
			    }
	        }
	        infile.close();
	}
	int virtual_chat()                                        // Virtual chat method
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("CLS");
		SetConsoleTextAttribute(hConsole, 240);
		cout<<"\n\t\t***THE NED FORUM***"<<endl;
		SetConsoleTextAttribute(hConsole, 241);
		for(int i=0;i<80;i++)
		{
			cout<<"_";
		}
		SetConsoleTextAttribute(hConsole, 240);
		cout<<"\n\t\t***VIRTUAL CHAT ROOM***"<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cout<<"Enter 'exit' to exit chat room"<<endl;
		SetConsoleTextAttribute(hConsole, 241);
		for(int i=0;i<80;i++)
		{
			cout<<"_";
		}
		SetConsoleTextAttribute(hConsole, 240);
		string message;
		ifstream infile;
		infile.open("Chat.txt");
		cout << endl;
		if(infile.is_open())
		{
		    while(!infile.eof())
		    {
			    getline(infile, message);
			    cout << message <<endl;
		    }
		}
		infile.close();
		while(1)
		{
			SetConsoleTextAttribute(hConsole, 240);
		     cout << "\nEnter message (press $ to terminate) :\n\n";
			 SetConsoleTextAttribute(hConsole, 241);
		     getline(cin, message, '$');
			 if(message=="\nexit")
	            return 0;
		     ofstream outfile;
		     outfile.open("Chat.txt", ios :: app);                                  // Chat file that saves message of the person with his/her name
		     outfile << endl<< U -> Get_First_Name() << " : " << message << endl;
		     outfile.close();
		}
	}
	void Search()                                                 // Search method
	{
		HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		string n, month;
		int min, hr, day, year;
		string first_name, last_name, user_name, user_id;
		int found = 0;
		SetConsoleTextAttribute(hConsole, 240);
		cout << "\nName : ";
		SetConsoleTextAttribute(hConsole, 241);
		cin >> first_name >> last_name;
		ifstream in;
		in.open("Searching.txt");
		while(!in.eof())
		{
			in >> user_id >> user_name;
			if(user_name == first_name)
			{
				found = 1;
				break;
			}
		}
		in.close();
		if(found == 1)
		{
			string n;
			search_label:
		    in.open(user_id);
			if(in.is_open())
			{
			   system("CLS");
			   SetConsoleTextAttribute(hConsole, 240);
			   cout<<"\n\t\t***THE NED FORUM***"<<endl;
			   SetConsoleTextAttribute(hConsole, 241);
		       for(int i=0;i<80;i++)
		       {
			      cout<<"_";
		       }
			   cout<<endl<<endl;
			   SetConsoleTextAttribute(hConsole, 241);
			   cout<<"    *** ";
			   SetConsoleTextAttribute(hConsole, 240);
			   cout <<first_name << " " <<last_name;
			   SetConsoleTextAttribute(hConsole, 241);
			   cout <<" ***"<<endl<<endl;
		       while(!in.eof())
		       {
			     getline(in, n);
			     cout << n << endl;
		       }
		       in.close();
			}
		    while(1)
		    {
				SetConsoleTextAttribute(hConsole, 240);
		        cout << "\n Press 1 to write post\n Press 2 to go back to homepage :";
				SetConsoleTextAttribute(hConsole, 241);
		        cin >> n;
		        if (n=="1")
		        {
				   system("CLS");
				   SetConsoleTextAttribute(hConsole, 240);
		           cout<<"\n\t\t***THE NED FORUM***"<<endl;
				   SetConsoleTextAttribute(hConsole, 241);
	 	           for(int i=0;i<80;i++)
		           {
			          cout<<"_";
		           }
				   ofstream outfile;
				   Get_Current_Date(month, day, year);
				   Get_Current_Time(n, hr, min);
		           P.Write_post();
			       outfile.open(user_id, ios :: app);
				   outfile << endl << U->Get_Name() <<" : " << first_name << " " << last_name;
				   outfile << endl;
				   outfile << month << " " << day << ", " << year << " at " << hr << ":" << min << " " << n << endl;
			       outfile << P.Get_post() <<endl <<endl;
				   SetConsoleTextAttribute(hConsole, 240);
			       cout << "\nSaved";
			       outfile.close();
				   _getch();
				   goto search_label;
				}
		        else
			       break;
		    }

		}
		else
		{
			system("CLS");
			SetConsoleTextAttribute(hConsole, 240);
			cout << "\nSorry, we didn't find any people matching this search.";
			_getch();
		}
	}
	void Get_Current_Time(string &n, int &hr, int &min)                     // Get current time method
    {
	    time_t now;
	    struct tm *current;
	    now = time(0);                                                     // for current time
	    current = localtime(&now);
	    if (current->tm_hour == 13) 
	    {
			hr = 1;
		    n = "PM";
	    }
	    else if (current->tm_hour == 14)
	    {
			hr = 2;
		    n = "PM";
	    }
	    else if (current->tm_hour == 15)
	    {
			hr = 3;
		    n = "PM";
	    }
	    else if (current->tm_hour == 16)
	    {
			hr = 4;
		    n = "PM";
	    }
	    else if (current->tm_hour == 17)
	    {
			hr = 5;
		    n = "PM";
	    }
	    else if (current->tm_hour == 18)
	    {
			hr = 6;
		    n = "PM";
	    }
	    else if (current->tm_hour == 19)
	    {
		    hr = 7;
		    n = "PM";
	    }
	    else if (current->tm_hour == 20)
	    {
			hr = 8;
		    n = "PM";
	    }
	    else if (current->tm_hour == 21)
	    {
		    hr = 9;
		    n = "PM";
	    }
	    else if (current->tm_hour == 22)
	    {
			hr = 10;
		    n = "PM";
	    }
	    else if (current->tm_hour == 23)
	    {
			hr = 11;
		    n = "PM";
	    }
	    else if (current->tm_hour == 24)
	    {
			hr = 12;
	    	n = "AM";
	    }
	    else 
	    {
		    hr = current->tm_hour;
		    n = "AM";
	    }
		min = current->tm_min;
	}
	void Get_Current_Date(string &mon, int &day, int& year)              // Get current date method
    {
	    time_t t = time(0);
	    struct tm*now = localtime(&t);
	    if((now->tm_mon + 1) == 1)
			mon = "January";
	    else if((now->tm_mon + 1) == 2)
		    mon = "February";
	    else if((now->tm_mon + 1) == 3)
		    mon = "March";
	    else if((now->tm_mon + 1) == 4)
		    mon = "April";
	    else if((now->tm_mon + 1) == 5)
		    mon = "May";
	    else if((now->tm_mon + 1) == 6)
		    mon = "June";
	    else if((now->tm_mon + 1) == 7)
		    mon = "July";
	    else if((now->tm_mon + 1) == 8)
		    mon = "August";
	    else if((now->tm_mon + 1) == 9)
		    mon = "September";
	    else if((now->tm_mon + 1) == 10)
		    mon = "October";
	    else if((now->tm_mon + 1) == 11)
		    mon = "November";
	    else if((now->tm_mon + 1) == 12)
		    mon = "December";
		day = now->tm_mday;
		year = now->tm_year + 1900;
	}
};

void main()                                           // main
{
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\tWELCOME TO THE NED FORUM !!!! \t\t\t        ";
	_getch();
	SNS *S1;                                          // pointer type object / memory is not allocated yet
	system("CLS");
	while(1)
	{
		cout<<"\n\t\t***THE NED FORUM***"<<endl;
		SetConsoleTextAttribute(hConsole, 241);
		for(int i=0;i<80;i++)
			{
				cout<<"_";
			}
		cout<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cout<<"\tConnect with your fellow NEDians and Faculty members!!"<<endl<<endl<<endl;
		int num;
		cout<<"   ***MENU***"<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 241);
		cout<<"  1. Signup"<<endl;
		cout<<"  2. Login"<<endl
			<<"  3. Exit"<<endl;
		cout<<" Enter the option number you want:"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>num;
		if(num==1)                                         // For signup
		{
			system("CLS");
			SetConsoleTextAttribute(hConsole, 240);
			cout<<"\n\t\t***THE NED FORUM***"<<endl;
			SetConsoleTextAttribute(hConsole, 241);
			for(int i=0;i<80;i++)
			{
				cout<<"_";
			}
			cout<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 240);
			S1=new SNS;                                   // Memory is allocated                            
			S1->Create_Account();
			_getch();
		}
		else if(num==2)                                   // For login
		{
			system("CLS");
			SetConsoleTextAttribute(hConsole, 240);
			cout<<"\n\t\t***THE NED FORUM***"<<endl;
			SetConsoleTextAttribute(hConsole, 241);
			for(int i=0;i<80;i++)
			{
				cout<<"_";
			}
			cout<<endl<<endl;
			SetConsoleTextAttribute(hConsole, 240);
			S1=new SNS;                                  // Memory is allocated
			S1->Login();
			_getch();
		}
		else if(num==3)                                   // For exiting
		{
			system("CLS");
			exit(0);
		}
		system("CLS");
	}
	delete S1;
	_getch();

}