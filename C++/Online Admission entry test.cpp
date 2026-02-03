
	/****************************Project NAME*****************************************
	**********ONLINE ENTRY TEST AND ADMISSION MANAGMENT SYSTEM************************
	**********MEHRAN UNIVERSITY OF ENGINEERING AND TECHNOLIGY*************************
	*****************SOFTWARE ENGINEERING (SECTIION-01)*******************************
	****************************ROLL NO:20SW041***************************************
	*****************************MUHAMMAD USMAN***************************************/




#include<iostream>
#include<conio.h>//This library is  for get function
#include<iomanip>//This liabrary is for setW function
using namespace std;

class  Test{//class name as Test 
	public://I make data member as public because this is test system so both university 
	//And user have access that's why these are All public
	string Name;//This store name of candidate
	string Cnic_no;//This store Cnic number i take string beacause Cnic number is long
	string Father_name;//This store Father's name
	string surname;//This Store Surname of Candidate
	string District;//This Store District name 
	string technology;//This store technology Choosen by CAndidate when He/She will pass the test
	char  password[6];//This is Array Of char having Size 6 it stores Password
		
		void Set_ID(string n, string Nic, string Fname,string Sname, string Dis)
		//This is Member function which SEt the Data of Candidate
		{
			Name=n;
			Cnic_no=Nic;
			Father_name=Fname;
			surname=Sname;
			District=Dis;
			
			cout<<"Enter Your Name: ";
			getline(cin,Name);//I Use getline Fucntion because input of user is in string 
			cout<<"Enter Your Cnic Card no: ";
			getline(cin,Cnic_no);
			cout<<"Enter Your Father's Name: ";
			getline(cin,Father_name);
			cout<<"Enter your Surname: ";
			getline(cin,surname);
			cout<<"Enter Your District Name: ";
			getline(cin,District);
			
			}
			void getCnic()//This member function  shows the Cnic number because When programe provides username 
			//and password to candidate so Cnic nummebr will be its Username
			{
				
				cout<<Cnic_no;
			}
			
			void get_ID()//This is Member function which set the password for Candidate to login in test portal
			{	int Size=Cnic_no.length();//This lenght Function Will tells the Size of Cnic number and then Store in size variable 
			//Password will be 1st 2 letter of your name And last $ digit Of Your Cnic number 
				password[0]=Name[0];//At 0 index of Password it STores 1st letter of Name
				password[1]=Name[1];//At 1 index of Password it STores 2nd letter of Name
				password[2]=Cnic_no[Size-4];//At 2 index of Password it STores 4th last digit of Cnic numebr 
				password[3]=Cnic_no[Size-3];//At 3 index of Password it STores 3rd last digit of Cnic numebr 
				password[4]=Cnic_no[Size-2];//At 4 index of Password it STores 2nd last digit of Cnic numebr 
				password[5]=Cnic_no[Size-1];//At 5 index of Password it STores  last digit of Cnic numebr 
				
				cout<<"Your username is: "<<Cnic_no;//it Shows the user name 
				cout<<"\nYour Password is: "<<password;//it shows password for loging 
			}
			void getpassword()//This function /shows the value of password 
			{
				cout<<password[6];
			}
			void Display()//This is display function Which shows the Addmission letter Of Candidate After ADmission
			{	cout<<"\t\t\t\t\t\t\t Mehran University Of Engineering & Technology, Jamshoro"
					<<"\n\t\t\t\t\t\tAdmission Session (2020-2021)"
					<<"\n\t\t\t\t\t\t  Jamshoro-Sindh, Pakistan"
					<<"\n\t\t\t\t\t  (Telephone 022-2771704 Fax022-2109030)"
					<<"\n\t\t\t\t\t\t www.admission.muet.edu.pk"<<endl;
					cout<<endl<<endl<<endl<<endl;
					cout<<"Name in full: "<<setw(10)<<Name<<endl
						<<"Father's Name: "<<Father_name<<endl
						<<"Surname: "<<setw(12)<<surname<<endl
						<<"Cnic Number: "<<setw(15)<<Cnic_no<<endl
						<<"District: "<<setw(9)<<District<<endl
						<<endl<<endl;
						
					cout<<"Congratulations!"<<endl
						<<"You have been provisionaly selected for admission BACHLOR OF ENGINEERING PROGRAM"
						<<" in FIRST YEAR CLASS for academic session\n(2020-21)under Regular Scheme "
						<<"in the dicipline and on the terms and conditions as mentioned below: "<<endl;
					cout<<endl<<endl;
					cout<<"DICIPLINE AWARDED \t\t\t\t\t\t  "<<technology<<endl
						<<"PLACE OF STUDY \t\t\t\t\t\t\t Jamshoro"<<endl
						<<"ROLL NUMBER \t\t\t\t\t\t\t 20"<<technology<<"01"<<endl
						<<"GUARDIAN'S NAME \t\t\t\t\t\t"<<Father_name<<endl<<endl
						<<"My furthur and final choices are as under :"<<endl
						<<"NFC (No Further choice)"<<endl
						<<"\t\t\t\t\t\t\t\t\t Signature of Candidate";    
		}
};

void Display(char ch){//THis is User defined  function which will use in desining it will take 
//one char argument as input
	for(int i=0; i<=110; i++)
	cout<<ch;
}

int main()//main function starts
{
	system("title ONLINE ENTRY TEST AND ADMISSION MANAGMENT SYSTEM ");//This sets the title of project 
	system("color f0");//THis will  set color of console 
	cout<<"\t\t\t WELCOME TO MEHRAN UNIVERSITY OF  ENGINEERING & TECHNOLOGY JAMSHORO !"<<endl<<endl;
	Display('_');
	cout<<"\nOnline Entry Test System And Admission Managment System! "<<endl<<endl;
	cout<<"\t\t\tEnter your Data"<<endl;
	string name,nicno,fname,sname,district;
	string username;
	string Password;
	string choice;
	Test t1;//t1 is object of class Test
	t1.Set_ID(name,nicno,fname,sname,district);//Call of Set_Id fuction to get input from user 
	t1.get_ID();//Call of get function Which PRovides  username and password to the user 
	int count=0;  //This is count variable of  type integer which will count test score
	char ch;
	float matric,inter,cpn;//These variables of type float which takes matric ,Ineter and set CPN Off candidate
	do{//I Use do while  loop because if user provides wrong username or passaword the it will show again for put correct information
	
	cout<<"\n\nUsername: ";cin>>username;
	cout<<"\nPassword: ";cin>>Password;
	system("cls");//This will clear the screen after Getting login to test Portal
	if(username==t1.Cnic_no && Password==t1.password )//This is if _else  Condition That if username and password correct then login to TEst portal 
	{
		cout<<"You have been successfully login to our test portal: "<<endl;
	}
	else {
		cout<<"Your username or Password is incorrect plz try again :"<<endl;
		
	}
	
}while(username!=t1.Cnic_no && Password!=t1.password);//DO while loop Ends

				//These ALL are  of test Ex:Instruction and Questions 
	cout<<"\n\n\t\t\tInstruction for test :"<<endl;
	cout<<"1):Please write only one option which is more suitable according to uh:"<<endl<<endl;
	cout<<"2):When you complete your please don't forget to submit :"<<endl;
	cout<<"3):60% is Your Test Score :"<<endl;
	cout<<"4):30% is Your Intermediate Percentage :"<<endl;
	cout<<"5):10% is Your Matricullation Percentage :"<<endl;
	cout<<"____________________________________________________________________________________________"<<endl;
	cout<<"Total Marks:20\t\t\t\t\t\t\t\t Passing Marks: 8"<<endl;
	cout<<"____________________________________________________________________________________________"<<endl;
	Display('*');//call of Display function which modifi Design
	cout<<"\n\t\t\t\t\tENGLISH "<<endl;
	Display('*');
	cout<<endl;
	cout<<"Qno:#1  Doer of action is known as :\n a)Subject\t\t\t b)verb  \n c)Adjective\t\t\t d)N.O.T"<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();//get function which get one character only
	system("cls");
	cout<<endl<<endl;
	if(ch=='a'||ch=='A')
	{
		++count;
	}
	
	cout<<"Qno:#2 I _______ cricket.\n a)play\t\t\t b)plays  \n c)Am Playing\t\t d)Both a and c"<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='a'||ch=='A'){
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#3  He is ______ Gentle man.\n a)An\t\t\t b)A  \n c)Both a and b\t\t d)N.O.T"<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B'){
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#4 We _______ won the Match.\n a)has\t\t\t b)Had  \n c)have\t\t\t d)Both b and c "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='d'||ch=='D')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#5  Good  is _________:\n a)Noun\t\t\t b)Adjective  \n c)Pronoun\t\t d)Verb "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B'){
		++count;
	}
	cout<<endl<<endl;
	Display('*');
	cout<<"\n\t\t\t\tPHYSICS"<<endl;
	Display('*');
	cout<<endl;
	
	cout<<"Qno:#6  _____ is unit of current.\n a)m/sec\t\t\t b)Watt  \n c)Ampere\t\t\t d)N.O.T"<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='c'||ch=='C')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#7  speed is a _________ Quantity.\n a)Scalar\t\t\t b)Vector  \n c)Tensor\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='a'||ch=='A')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#8  ________ is unit of power.\n a)joule\t\t\t b)kg  \n c)Ampere\t\t\t d)Watt "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='d'||ch=='D')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#9 Value of gravity on earth. \n a)9.6 m/sec\t\t\t b)9.8 m/sec^2  \n c)9.8 m/sec\t\t\t d)Both a and c "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#10  Displacement is a ________ Quantity.\n a)Vector\t\t\t b)Scalar  \n c)Tensor\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='a'||ch=='A')
	{
		++count;
	}
	cout<<endl<<endl;
	Display('*');
	cout<<"\n\t\t\t\tCHEMISTRY "<<endl;
	Display('*');
	cout<<endl;
	cout<<"Qno:#11 _________is the formula of water. \n a)Ho2\t\t\t b)H2o2  \n c)H2o\t\t\t d)Both a and c "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='c'||ch=='C')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#12 PH of Water is _______. \n a)7.1\t\t\t b)7.4  \n c)7.0\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getch();
	system("cls");
	if(ch=='c'||ch=='C')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#13 Nacl is the formula of _____. \n a)Sodium bi chloride\t\t\t b)Sodium chloride  \n c)Sodium chromate\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#14 Atomic number of Tin. \n a)50\t\t\t b)55  \n c)60\t\t\t d)65 "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='a'||ch=='A')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#15 Atomic Mass of Nitrogen. \n a)7\t\t\t b)14  \n c)21\t\t\t d)28 "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B')
	{
		++count;
	}
	cout<<endl<<endl;
	Display('*');
	cout<<"\n\t\t\t\tGeneral Knowledge"<<endl;
	Display('*');
	cout<<endl;
	cout<<"Qno:#16 USA stands for: \n a)United Super Asia\t\t\t b)Unique stand America  \n c)United State of America\t\t d)N.O.T"<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='c'||ch=='C')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#17 Capital of Turkey. \n a)Istambul\t\t b)Newyork  \n c)Yen\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='d'||ch=='D')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#18 How many continents are there in the world \n a)4\t\t\t b)5  \n c)6\t\t\t d)7 "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='d'||ch=='D')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#19 Largest river in Asia . \n a)Mohan River\t\t\t b)Indus River \n c)Both a and b\t\t\t d)N.O.T "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='b'||ch=='B')
	{
		++count;
	}
	cout<<endl<<endl;
	cout<<"Qno:#20 _______ has Largest Population in the wolrd. \n a)Pakistan\t\t\t b)India  \n c)China\t\t\t d)USA "<<endl<<endl;
	cout<<"Answer: ";
	ch=getche();
	system("cls");
	if(ch=='c'||ch=='C')
	{
		++count;
	}
	cout<<endl<<endl;
	do{
	
	cout<<"Press S for submit the test :";
	ch=getche();
	if(ch=='s'||ch=='S')
	{
		break;
	}
	else 
	cout<<"\nWrong key please press S for submit!"<<endl;
	}while(ch!='s'||ch!='S');
	
	cout<<"\nyour score is: "<<count<<endl;
	
	if(count>=8)//Here if test score is equal to or grater then 8 then show pass otherwise fail
	{
		cout<<"Congratulations "<<t1.Name<<" You have passed the Test !"<<endl<<endl; 
		cout<<"Enter Your Matric percentage: ";
		cin>>matric;//This takes mataric percentage 
		if(matric>100){//This will only run when matric's percentage greater than 100 because as you know percentage cant be greater than 100 
			cout<<"Matric percentage should be Less or Equal to 100"<<endl;
			cout<<"Enter Your Matric percentage: ";
			cin>>matric;
			
		}
		cout<<"Enter Enter your Intermediate Percentage: ";
		cin>>inter;//This takes mataric percentage 
		if(inter>100){//This will only run when Inter's percentage greater than 100 because as you know percentage cant be greater than 100
			cout<<"Inter percentage should be Less or Equal to 100"<<endl;
			cout<<"Enter Your Inter percentage: ";
			cin>>inter;
			
		}
		float calculate=(count*0.6)+(matric*0.1)+(inter*0.3);//This Calcuates Cpn of Candidates
		
		
		cout<<"Your Cpn is: "<<calculate<<"%  Out of 52% "<<endl<<endl;
		
		Display('_');//Call of user defined function which Display Design
		cout<<"\nList Of Technologies: "<<endl;
		Display('_');
		cout<<"\n1.Software Engineering\n2.Civil Engineering\n3.Electrical Engineering\n4.Mechanical Engineering\n5.Computer system Engineering "<<endl<<endl;
		
		do {//Again do while loop for Only Correct input for selecting Techologies 
		cout<<"Write \n(SW) for Software.\n(CE) for Civil.\n(EL)for Eectrical.\n (ME) for Mechanical.\n(CS) for Computer Engineering:"<<endl<<endl;
		cout<<"Enter Your choice: ";
		cin>>t1.technology;//this take input from user to Select  Tecchnology
	}while(t1.technology !="CS"&&t1.technology!="cs"&&t1.technology!="Cs"&&t1.technology!="cS"&&t1.technology!="ME"&&t1.technology!="me"&&t1.technology!="Me"&&t1.technology!="mE"&&t1.technology!="El"&&t1.technology!="el"&&t1.technology!="El"&&t1.technology!="eL"&&t1.technology !="SW"&&t1.technology!="sw"&&t1.technology!="Sw"&&t1.technology!="sW"&&t1.technology !="CE"&&t1.technology!="ce"&&t1.technology!="Ce"&&t1.technology!="cE");
			cout<<"\n\n Press any key for Admission letter :";
			ch=getch();
			system("cls");
			system("color 30");
			cout<<endl<<endl;
			if(t1.technology =="SW"||t1.technology=="sw"||t1.technology=="Sw"||t1.technology=="sW")
			{
				Display('*');
				t1.Display(); //Call of memeber function
			}
			else if(t1.technology =="CE"||t1.technology=="ce"||t1.technology=="Ce"||t1.technology=="cE")
			{
				Display('*');	
				t1.Display(); 
			}
			else if(t1.technology=="El"||t1.technology=="el"||t1.technology=="El"||t1.technology=="eL")
			{
				Display('*');
				t1.Display(); 
			}
			else if(t1.technology=="ME"||t1.technology=="me"||t1.technology=="Me"||t1.technology=="mE")
			{	
				Display('*');
				t1.Display(); 
			}
			else if(t1.technology =="CS"||t1.technology=="cs"||t1.technology=="Cs"||t1.technology=="cS")
			{
				Display('*');
				t1.Display(); 
			}
		
		
		cout<<endl<<endl;
		cout<<"\t\t\t\t\tThankyou"<<endl;
		Display('_');
	}
	else//else When Candidate Does not pass the test the show this msg to Candidate
	{
		system("cls");//clear of sccreen
		system("color 4f");//this will sets the color of console as Red
		cout<<"\n\n\n\n\n\n\a\t\t\t\t\t\tBetter luck next time !"<<endl;	
	}
	
	getch();//getch function which hold the screen 
	return 0;
}//main Ends 



