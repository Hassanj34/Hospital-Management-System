#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

//Menu
void MainMenu();

//Structure for Accounts
struct Account
{
	string UserID;
	string UserPass;
}
Users;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Pharmacy
class Pharmacy
{
	public:
	void PharmacyMenu();
	void PharmacyMenu(int,float);
	void PharmacyMedicine();
	void PharmacyReciept(int,float);
	void PharmacyMedicineFiling();
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Medicine 
class Medicine
{
    char ID[20];
    char Name[20];
    float Price;
    int Quantity;
    public:
    Medicine()
    {
        strcpy(ID," ");
        strcpy(Name," ");
        Price=0.0;
        Quantity=0;
    }
    void SetMedicineData(char a[], char b[], float c, int e)
    {
        strcpy(ID,a);
        strcpy(Name,b);
        Price=c;
        Quantity=e;
    }
    void setMedicineQuantity(int q)
    {
    	Quantity=q;
	}
    char * getMedicineName()
    {
    	return Name;
	}
	char * getMedicineID()
    {
    	return ID;
	}
	float getMedicinePrice()
	{
		return Price;
	}
	int getMedicineQuantity()
	{
		return Quantity;
	}
    void ShowMedicineData();
    void StoreMedicineData();
    void ViewMedicineData();
    float SearchMedicines(char *t);
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Appointment
class Appointment
{
	int Min;
	int Hour;
	int Day;
	int Month;
	int Year;
	char Slot;
	char Availability[20];
	public:
	Appointment()
	{
		strcpy(Availability,"Available");
	}
	Appointment(int hour, int min, int day, int month, int year, char slot)
	{
		strcpy(Availability,"Available");
		Hour=hour;
		Min=min;
		Day=day;
		Month=month;
		Year=year;
		Slot=slot;
	}
	void SetAll(int hour, int min, int day, int month, int year, char slot, char availability[])
	{
		strcpy(Availability,availability);
		Hour=hour;
		Min=min;
		Day=day;
		Month=month;
		Year=year;
		Slot=slot;
	}
	void setAvailability(char a[])
	{
		strcpy(Availability,a);
	}
	Display()
	{
		cout<<" - "<<Slot<<" | "<<"  "<<Hour<<"  | "<<Min<<"   | "<<Day<<"  / "<<Month<<"  / "<<Year<<" | "<<Availability<<endl;
	}
	char getSlot()
	{
		return Slot;
	}
	char* getAvailability()
	{
		return Availability;
	}
	void IncrementDate()
	{
		Day+=7;
		if(Day>30)
		{
			Day=Day-30;
			Month++;
			if(Month>12)
			{
				Month=Month-12;
				Year++;
			}
		}
	}
	//Prototypes for Appointment Functions
	void AppointmentUpdate(char,string);
	void AppointmentAddSlot(string);
	void AppointmentRemoveSlot(string);
	void AppointmentUpdateSlot(string,int);
	void AppointmentUpdateAvailability(string);
};


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of User
class User
{
	//Data Members
    protected:
    char FirstName[30];
    char LastName[30];
    char HomeAddress[50];
    char BloodGroup[10];
    char Gender[10];
    double Age;
    char PhoneNumber[30];
    public:
    //Getters
    char* getFirstName()
    {
        return FirstName;
    }
    char* getLastName()
    {
        return LastName;
    }
    char* getAddress()
    {
        return HomeAddress;
    }
    char* getBloodGroup()
    {
        return BloodGroup;
    }
    char* getGender()
    {
    	return Gender;
	}
    double getAge()
    {
        return Age;
    }
    char* getPhoneNumber()
    {
        return PhoneNumber;
    }
    //Setters
    void setFirstName(char First[])
    {
        strcpy(FirstName,First);
    }
    void setLastName(char Last[])
    {
        strcpy(LastName,Last);
    }
    void setAddress(char Address[])
    {
        strcpy(HomeAddress,Address);
    }
    void setBloodGroup(char Group[])
    {
        strcpy(BloodGroup,Group);
    }
    void setGender(char FM[])
    {
    	strcpy(Gender,FM);
	}
    void setAge(double Old)
    {
        Age=Old;
    }
    void setPhoneNumber(char Phone[])
    {
        strcpy(PhoneNumber,Phone);
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Patient
class Patient : protected User
{
	int MR;
    string PatientID;
    string PatientPass;
    public:
    //Getters
    int getMR()
    {
    	return MR;
	}
    string getPatientID()
    {
        return PatientID;
    }
    string getPatientPass()
    {
        return PatientPass;
    }
    //Setters
    void setMR(int MedNum)
    {
    	MR=MedNum;
	}
    void setPatientID(string P_ID)
    {
    	PatientID=P_ID; 
	}
	void setPatientPass(string P_Pass)
	{
		PatientPass=P_Pass;
	}
    //Constructors
    Patient()
    {
    	
	}
	Patient(int MedNum, char First[], char Last[], char MF[], char Address[], char Group[], double Ages, char Phone[], string P_ID, string P_Pass)
	{
		MR=MedNum;
		strcpy(FirstName,First);
		strcpy(LastName,Last);
		strcpy(HomeAddress,Address);
		strcpy(Gender,MF);
		strcpy(BloodGroup,Group);
		Age=Ages;
		strcpy(PhoneNumber,Phone);
		PatientID=P_ID;
		PatientPass=P_Pass;
	}
	//Prototypes for Patient Functions
	void PatientFile();
	void ShowPatientData();
	void ViewPatientData();
	void PatientModule();
	void PatientSignup();
	void PatientLogin();
	void PatientMenu();
	void PatientAppointment();
	void ViewPatientData(int);
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Doctor
class Doctor : protected User
{
	int DR;
	string DoctorID;
    string DoctorPass;
    char fname[30],lname[30],Speciality[30];
    public:
    //Getters
    char * getDRFirstName()
    {
    	return fname;
	}
	char * getDRLastName()
	{
		return lname;
	}
	char * getDRSpeciality()
	{
		return Speciality;
	}
    string getDoctorID()
    {
        return DoctorID;
    }
    string getDoctorPass()
    {
        return DoctorPass;
    }
    int getDoctorDR()
    {
    	return DR;
	}
    //Setters
    void setDRFirstName()
    {
    	strcpy(fname,getFirstName());
	}
	void setDRLastName()
	{
		strcpy(lname,getLastName());
	}
	void setDoctorSpeciality(char s[])
	{
		strcpy(Speciality,s);
	}
    void setDoctorID(string D_ID)
    {
    	DoctorID=D_ID;
	}
	void setDoctorPass(string D_Pass)
	{
		DoctorPass=D_Pass;
	}
	void setDoctorDR(int dr)
	{
		DR=dr;
	}
    //Constructors
    Doctor()
    {
    	
	}
	Doctor(int Ref, char First[], char Last[], char spec[] , char MF[], char Address[], char Group[], double Ages, char Phone[])
	{
		DR=Ref;
		strcpy(FirstName,First);
		strcpy(LastName,Last);
		strcpy(Speciality,spec);
		strcpy(HomeAddress,Address);
		strcpy(Gender,MF);
		strcpy(BloodGroup,Group);
		Age=Ages;
		strcpy(PhoneNumber,Phone);
	}
	//Prototypes for Doctor Functions
	void DoctorModule();
	void DoctorMenu(int);
	void DoctorAppointment(int);
	void DoctorViewRecords(int);
	void DoctorShowData();
	void DoctorFile();
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Class of Admin
class Admin : protected User
{
	public:
	//Prototypes for Admin Functions
	void AdminMenu();
	void AdminPatientView();
	void AdminDoctorView();
	void AdminAddDoctor();
	void AdminRemoveDoctor();
	void AdminUpdateDoctor();
	void AdminViewPharmacy();
	void AdminAddMedicine();
	void AdminRemoveMedicine();
	void AdminUpdateMedicine();
	void AdminRefillPharmacy();
	void AdminRenewPharmacy();
};

//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                 Appointment Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Appointment::AppointmentUpdate(char slot, string filename)
{
	fstream file;
	file.open(filename.c_str(),ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	while(file)
	{
		file.read((char*)this,sizeof(*this));
		if(slot==Slot)
		{
			strcpy(Availability,"Booked");
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			break;
		}
	}
}

void Appointment::AppointmentAddSlot(string filename)
{
	int Hour;
	int Min;
	int Day;
	int Month;
	int Year;
	char Slot;
	houragain:
	try
	{
		cout<<"Set Hour: ";
		cin>>Hour;
		if(Hour<1 || Hour>12)
		{
			throw(Hour);
		}
	}
	catch(int hour)
	{
		cout<<"Hour can only be 1-12. Please enter again: \n";
		goto houragain;
	}
	minutesagain:
	try
	{
		cout<<"Set Minutes: ";
		cin>>Min;
		if(Min<1 || Min>60)
		{
			throw(Min);
		}
	}
	catch(int min)
	{
		cout<<"Minutes can only be 1-60. Please enter again: \n";
		goto minutesagain;
	}
	dayagain:
	try
	{
		cout<<"Set day: ";
		cin>>Day;
		if(Day<1 || Day>30)
		{
			throw(Day);
		}
	}
	catch(int day)
	{
		cout<<"Day can only be 1-30. Please enter again: \n";
		goto dayagain;
	}
	monthagain:
	try
	{
		cout<<"Set month: ";
		cin>>Month;
		if(Month<1 || Month>12)
		{
			throw(Month);
		}
	}
	catch(int month)
	{
		cout<<"Month can only be 1-12. Please enter again: \n";
		goto monthagain;
	}
	cout<<"Set year: ";
	cin>>Year;
	slotagain:
	try
	{
		cout<<"Set slot: ";
		cin>>Slot;
		if(Slot<'A' || Slot>'Z')
		{
			throw(Slot);
		}
	}
	catch(char slot)
	{
		cout<<"Slot can only be captial letters. Please enter again: \n";
		goto slotagain;
	}
	Appointment obj(Hour,Min,Day,Month,Year,Slot);
	ofstream file;
	file.open(filename.c_str(), ios::out | ios::app);
	if(!file.is_open())
	{
		cout<<"Appointment file could not be found!\n";
	}
	else
	{
		file.write((char*)&obj,sizeof(obj));
	}
	file.close();
}

void Appointment::AppointmentRemoveSlot(string filename)
{
	int flag=0;
	char slot;
	slotagain:
	try
	{
		cout<<"Enter the slot you want to remove: ";
		cin>>slot;
		if(slot<'A' || slot>'Z')
		{
			throw(slot);
		}
	}
	catch(char slot)
	{
		cout<<"Slot can only be captial letters. Please enter again: \n";
		goto slotagain;
	}
	ifstream file;
	file.open(filename.c_str(), ios::in);
	ofstream test;
	test.open("Test.dat", ios::app);
	while(file)
	{
		while(!file.eof())
		{
			if(file.read((char*)this,sizeof(*this)))
			{
				if(slot==getSlot())
				{
					cout<<"Deleted slot is: \n";
					Display();
					flag=1;
				}
				else
				{
					test.write((char*)this,sizeof(*this));
				}
			}
			else
			{
				break;
			}
		}
	}
	file.close();
	test.close();
	remove(filename.c_str());
	rename("Test.dat",filename.c_str());
	if(flag==1)
	{
		cout<<"Slot was successfully removed.\n";
	}
	else
	{
		cout<<"Slot not found!\n";
	}
}

void Appointment::AppointmentUpdateSlot(string filename, int dr)
{
	slotagain:
	int Hour;
	int Min;
	int Day,flag=0;
	int Month;
	int Year;
	char Slot;
	char Availability[20];
	ifstream fp;
	fp.open(filename.c_str(), ios::in);
	while(fp)
	{
		while(!fp.eof())
		{
			if(fp.read((char*)this,sizeof(*this)))
			{
				if(strcmp(getAvailability(),"Booked")==0)
				{
					flag=1;
				}
				else
				{
					flag=0;
				}
			}
			else
			{
				break;
			}
			if(flag==0)
			{
				cout<<"You have slots that are marked Available. Please make sure all appointments are viable for updation.\n";
				system("PAUSE");
				system("cls");
				Doctor doc;
				doc.DoctorMenu(dr);
			}
		}
	}
	fp.close();
	fstream file;
	file.open(filename.c_str(), ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	while(file)
	{
		while(!file.eof())
		{
			if(file.read((char*)this,sizeof(*this)))
			{
				IncrementDate();
				setAvailability("Available");
				file.seekp(file.tellp()-sizeof(*this));
				file.write((char*)this,sizeof(*this));
				flag=1;	
			}
			else
			{
				break;
			}
		}
	}
	file.close();
	if(flag==1)
	{
		cout<<"Slots updated successfully!\nYour appointments have been set to Available and scheduled for next week.\n";
	}
}

void Appointment::AppointmentUpdateAvailability(string filename)
{
	char slot;
	int flag=0;
	slotagain:
	try
	{
		cout<<"Enter the slot you want to update: ";
		cin>>slot;
		if(slot<'A' || slot>'Z')
		{
			throw(slot);
		}
	}
	catch(char slot)
	{
		cout<<"Slot can only be captial letters. Please enter again: \n";
		goto slotagain;
	}
	fstream file;
	file.open(filename.c_str(), ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	while(file)
	{
		while(!file.eof())
		{
			if(file.read((char*)this,sizeof(*this)))
			{
				if((strcmp(getAvailability(),"Booked")==0 || strcmp(getAvailability(),"Unavailable")==0)  && slot==getSlot())
				{
					strcpy(Availability,"Available");
					file.seekp(file.tellp()-sizeof(*this));
					file.write((char*)this,sizeof(*this));
					cout<<"Availability updated to Available\n";
					flag=1;
					break;
				}
				else if(strcmp(getAvailability(),"Available")==0 && (slot==getSlot()))
				{
					char choice;
					cout<<"Do you want to set the availability to Unavailable?\nEnter Y to update and N to to leave it as it is: ";
					cin>>choice;
					if(choice=='Y' || choice=='y')
					{
						strcpy(Availability,"Unavailable");
						cout<<"Availability updated to Unavailable\n";
					}
					else
					{
						flag=1;
						break;
					}
					file.seekp(file.tellp()-sizeof(*this));
					file.write((char*)this,sizeof(*this));
					flag=1;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	if(flag!=1)
	{
		cout<<"No such slot exists\n";
	}
	file.close();
}

//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                 Medicine Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Medicine::ShowMedicineData()
{ 
    cout<<"     "<<ID<<"          \t\t"<<Name<<"           \t$"<<Price<<"         \t\t"<<Quantity<<"                    "<<"\t"<<endl; 
}

void Medicine::StoreMedicineData()
{
    if(ID==" ")
    {
        cout<<"Incorrect data";
    }
    else
    {
        ofstream fout;
        fout.open("Medicine.dat",ios::app);
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
}

void Medicine::ViewMedicineData()
{
    fstream fin;
    string output;
    fin.open("Medicine.dat",ios::in);
    if(!fin)
    {
        cout<<"There are currently no medicines present in the pharmacy!\n";
    }
    else
    {
        while(fin)
        {
        	if(fin.read((char*)this,sizeof(*this)))
            ShowMedicineData();
            else
            break;
        }
        fin.close();
    }
}
    
float Medicine::SearchMedicines(char *t)
{
	float flag=0;
	float temp;
	ifstream search;
	search.open("Medicine.dat",ios::in);
	if(!search)
	{
		cout<<"File not found.\n";
    	return 0;
	}
	else
	{
		while(!search.eof())
		{
			search.read((char*)this,sizeof(*this));
			if(strcmp(t,Name)==0 && Quantity>0)
			{
				flag=1;
				temp=Price;
				search.close();
				return temp;
			}
			else if(strcmp(t,Name)==0 && Quantity==0)
			{
				cout<<"This medicine is currently out of stock in the pharmacy, please come back again another time.\n";
			}
		}
		if(flag==0)
		{
			cout<<"Record not found!\n";
			search.close();
			return 2;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                 Pharmacy Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Pharmacy::PharmacyMedicineFiling()
{
	int i;
	remove ("Medicine.dat");
    Medicine M[20];
    Medicine M1;
    char ID[100][100]={"0001","0002","0003","0004","0005","0006","0007","0008","0009","0010","0011","0012","0013","0014","0015","0016","0017","0018","0019","0020","0021","0022","0023","0024","0025"};
    char Names[100][100]={"Panadol","Tylenol","Leflox","Insulin","Somogel","Levitra","Valium","Dafflon","Amoxicil","Hydrillin","Rigix","Calpol","Britanyl","Montekulast","Telfast","Ciproxin","Lysovit","Singulair","Xanax","Advil","Dispirin","Vitamin A","Vitamin B12","Vitamin C","Vitamin D"};
    double Cost[]={2.49,4.99,9.99,3.49,4.99,2.99,14.99,4.99,7.49,13.49,12.99,9.99,10.49,4.99,2.99,14.99,4.99,7.49,2.49,4.99,9.99,3.49,6.99,4.49,19.99};
	for (i=0;i<19;i++)
	{
		M[i].SetMedicineData(ID[i],Names[i],Cost[i],100);
		M[i].StoreMedicineData();
	}
	for(i=20;i<25;i++)
	{
		M[i].SetMedicineData(ID[i],Names[i],Cost[i],100);
		M[i].StoreMedicineData();
	}
}

void Pharmacy::PharmacyMenu()
{
	//PharmacyMedicineFiling();
	int chc=999;
	do
	{
		cout<<"\t\t\t---PHARMACY STORE---\n";
		cout<<"____________________________________________________________\n";
		cout<<"\n -> Press 1 to visit the Pharmacy Store.\n";
		cout<<"____________________________________________________________\n";
		cout<<"\n-> ";
		cin>>chc;
		if(chc==1)
		{
			system("CLS");
			PharmacyMedicine();
		}
		else
		{
			cout<<"Incorrect option.\n";
		}
	}
	while(chc!=1);
}

void Pharmacy::PharmacyMenu(int med,float bill)
{
	int chc;
	cout<<"\n\t\t\t---PHARMACY STORE---\n";
	cout<<"\n________________________________________________\n";
	cout<<"-> Press 1 to print your reciept for your current order.\n";
	cout<<"-> Press 2 to replace your old order with a new one.";
	cout<<"\n________________________________________________";
	do
	{
		cout<<"\n-> ";
		cin>>chc;
		if(chc==1)
		{
			PharmacyReciept(med,bill);
		}
		else if(chc==2)
		{
			remove("Billing.txt");
			//PharmacyMedicineFiling();
			PharmacyMedicine();
		}
		else
		{
			cout<<"Incorrect option, try again.\n";
		}
	}
	while(chc!=1|chc!=2);
}

void Pharmacy::PharmacyMedicine()
{
	remove("Billing.txt");
	int i,meds;
	char select[25];
	string Name="Billing.txt";
	fstream med;
	med.open("Billing.txt",ios::out|ios::app);
	med<<"| \tDrugs\t|\tPrice\t|\tQuantity\t|\n";
	med.close();
	float total=0,bill=0,quantity,filler,flag;
	cout<<"_______________________________________________________________________________________________________________\n\n";
	cout<<"\n\t\t\t\t\t--- MEDICINE COUNTER ---\n\n";
	cout<<"_______________________________________________________________________________________________________________\n\n";
	cout<<"\n   SERIAL NO.'S\t\t     AVAILABLE DRUGS\t\tPRICE\t\t\tQUANTITY\t\n\n";
	Medicine M1;
	M1.ViewMedicineData();
	cout<<"-----------------------------------------------\n";
	cout<<"Enter how many medicines would you like to purchase: ";
	cin>>meds;
	for(i=0;i<meds;i++)
	{
		searchagain:
		cout<<"Please enter the name of the medicine: ";
		cin>>select;
		flag=M1.SearchMedicines(select);
		if(flag==0)
		{
			cout<<"There was an error in finding the file.\n";
			break;
		}
		else if(flag==2)
		{
			cout<<"This medicine does not exist, or is not available within the pharmacy as of now.\n";
			cout<<"Please try again.\n";
			goto searchagain;
		}
		else if(flag!=1)
		{
			cout<<"This medicine is currently available.\n";
			repeat:
			cout<<"Please enter the quantity of this medicine: ";
			cin>>quantity;
			if(quantity>10)
			{
				cout<<"Sorry, we cannot allow you to take more than 10 of each Medicine. Please choose a lesser amount.\n";
				goto repeat;
			}
			total=quantity*flag;
			bill=total+bill;
			med.open("Billing.txt",ios::out|ios::app);
			med<<"| \t"<<select<<"\t|\t$"<<flag<<"\t|\t"<<quantity<<"\t\t|"<<endl;
			med.close();
			fstream file;
			file.open("Medicine.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.seekg(0);
			Medicine M;
			while(file)
			{
				file.read((char*)&M,sizeof(M));
				if(strcmp(select,M.getMedicineName())==0)
				{	
					filler=M.getMedicineQuantity()-quantity;
					//quantity=M.getMedicineQuantity()-quantity;
					M.SetMedicineData(M.getMedicineID(),M.getMedicineName(),M.getMedicinePrice(),filler);
					file.seekp(file.tellp()-sizeof(M));
					file.write((char*)&M,sizeof(M));
					file.close();
					break;
				}
			}
		}
	}
	system("PAUSE");
	system("cls");
	PharmacyMenu(meds,bill);
}

void Pharmacy::PharmacyReciept(int medicine,float bill)
{
	int i;
	int order;
	srand(time(NULL));
	order=(rand() % 900000)+100000;
	string Output,Name;
	fstream file;
	Name="Billing.txt";
	file.open("Billing.txt",ios::in);
	cout<<"\t\t\t---RECIEPT---\n";
	cout<<"Order Number: "<<order<<endl;
	cout<<"\n________________________________________________________________\n";
	while(getline(file,Output))
	{
		cout<<Output<<endl;
	}
	cout<<"__________________________________________________________________\n";
	cout<<"\nTotal : $"<<bill;
	cout<<"\n________________________________________________";
	cout<<"\nThank you for coming to our pharmacy!\n";
	Patient P;
	system("PAUSE");
	system("cls");
	P.PatientMenu();
}



//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                 Patient Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Patient::PatientModule()
{
	int choice=999;
	do
	{
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout<<"\n\t\t   PATIENT MENU\n";
    	cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		cout<<"1. Sign-Up\n";
		cout<<"2. Login\n";
		cout<<"3. Return to Main Menu\n";
		cout<<"0. Exit Program\n";
		cout<<"\n-> ";
		cin>>choice;
		if(choice==1)
		{
			PatientSignup();
		}
		else if(choice==2)
		{
			PatientLogin();
		}
		else if(choice==3)
		{
			system("cls");
			MainMenu();
		}
		else if(choice==0)
		{
			cout<<"Thank you for visiting our hospital!\n";
			exit(1);
		}
		else
		{
			cout<<"Incorrect option, try again.\n";
		}
	}
	while(choice!=0);
}

void Patient::PatientSignup()
{
	int MR;
	srand(time(NULL));
	MR=(rand() % 9000)+1000;
	char First[30],Last[30],Gender[10],Address[50],BloodGroup[10],Number[30];
	string ID,temp,Password1,Password2;
	double Age;
	system("CLS");
	cout<<"\n---Account Creation Form---\n\n";
	usernameagain:
	cout<<"Set your Username: ";
	cin>>ID;
	ifstream file;
	temp=ID;
	temp+=".txt";
	file.open(temp.c_str(), ios::in);
	if(file.is_open())
	{
		cout<<"Username is already taken. Please enter a different username: \n";
		goto usernameagain;
	}
	else
	{
		
	}
	repeated:
	cout<<"Set your password: ";
	cin>>Password1;
	cout<<"Confirm your password: ";
	cin>>Password2;
	if(Password1!=Password2)
	{
		cout<<"\nYour passwords did not match, please try again.";
		goto repeated;
	}
	//Account is created before the data is filled
	system("CLS");
	cout<<"\n---General Data Form---\n\n";
	cout<<"Your Medical Reference (MR) Number is: "<<MR<<endl;
	cout<<"It is important that you memorize this number and keep it with you at all times!\n\n";
	firstnameagain:
	try
	{
		cout<<"Enter your first name: ";
		cin>>First;
		for(int i=0;i<strlen(First);i++)
		{
			if((First[i]>='a' && First[i]<='z') || (First[i]>='A' && First[i]<='Z') || (First[i]==' '))
			{
				
			}
			else
			{
				throw(First[i]);
			}
		}
	}
	catch(char first)
	{
		cout<<"First name can only contain alphabets. Please enter again: \n";
		goto firstnameagain;
	}
	lastnameagain:
	try
	{
		cout<<"Enter your last name: ";
		cin>>Last;
		for(int i=0;i<strlen(Last);i++)
		{
			if((Last[i]>='a' && Last[i]<='z') || (Last[i]>='A' && Last[i]<='Z') || (Last[i]==' '))
			{
				
			}
			else
			{
				throw(Last[i]);
			}
		}
	}
	catch(char last)
	{
		cout<<"Last name can only contain alphabets. Please enter again: \n";
		goto lastnameagain;
	}
	genderagain:
	try
	{
		cout<<"Enter your gender: ";
		cin>>Gender;
		if(strcmp(Gender,"Male")==0 || strcmp(Gender,"male")==0 || strcmp(Gender,"Female")==0 || strcmp(Gender,"female")==0 || strcmp(Gender,"M")==0 || strcmp(Gender,"F")==0 || strcmp(Gender,"m")==0 || strcmp(Gender,"f")==0)
		{
			
		}
		else
		{
			throw(Gender);
		}
	}
	catch(char * gender)
	{
		cout<<"Gender can only be Male/Female. Please enter again: \n";
		goto genderagain;
	}
	cout<<"Enter your age: ";
	cin>>Age;
	againss:
	try
	{
		cout<<"Enter your mobile number: ";
		cin>>Number;
		for(int i=0;i<strlen(Number);i++)
		{
			if(Number[i]>='0' && Number[i]<='9')
			{
				
			}
			else
			{
				throw(Last[i]);
			}
		}
	}
	catch(char)
	{
		cout<<"A number cannot have alphabets or special characters!\n";
		goto againss;
	}
	 
	cout<<"Enter your address: ";
	cin>>Address;
	bloodgroupagain:
	try
	{
		cout<<"Enter your blood group: ";
		cin>>BloodGroup;
		if(strcmp(BloodGroup,"A+")==0 || strcmp(BloodGroup,"a+")==0 || strcmp(BloodGroup,"A-")==0 || strcmp(BloodGroup,"a-")==0 || strcmp(BloodGroup,"B+")==0 || strcmp(BloodGroup,"b+")==0 || strcmp(BloodGroup,"B-")==0 || strcmp(BloodGroup,"b-")==0 || strcmp(BloodGroup,"AB+")==0 || strcmp(BloodGroup,"ab+")==0 || strcmp(BloodGroup,"AB-")==0 || strcmp(BloodGroup,"ab-")==0 || strcmp(BloodGroup,"O+")==0 || strcmp(BloodGroup,"o+")==0 || strcmp(BloodGroup,"O-")==0 || strcmp(BloodGroup,"o-")==0)
		{
			
		}
		else
		{
			throw(BloodGroup);
		}
	}
	catch(char * bloodgroup)
	{
		cout<<"Blood group can only be A,B,AB,O in +/-. Please enter again: \n";
		goto bloodgroupagain;
	}
	Patient P(MR,First,Last,Gender,Address,BloodGroup,Age,Number,ID,Password1);
	P.PatientFile();
	cout<<"\nAccount created succesfully!"<<endl;
	system("cls");
	PatientModule();
}

void Patient::PatientFile()
{
	//Binary File Creation of Patient Data
	ofstream file;
	file.open("Patients.dat",ios::app);
	file.write((char*)this,sizeof(*this));
	file.close();
	//Normal File Creation of Patient Username and Password
	string Username;
	Users.UserID=PatientID;
	Users.UserPass=PatientPass;
	Username=Users.UserID;
	Username+=".txt";
	file.open(Username.c_str());
	file<<Users.UserID<<endl;
	file<<Users.UserPass<<endl;
	file.close();
}

void Patient::PatientLogin()
{
	againmenu:
	again:
	enteragain:
	string Name,Username,Password;
	char ch,back;
	cout<<"Do you want to go back to Patient Menu?\nEnter Y to go back and enter N to continue: ";
	cin>>back;
	if(back=='Y' || back=='y')
	{
		system("cls");
		PatientModule();
	}
	else if(back=='N' || back=='n')
	{
		
	}
	else
	{
		cout<<"Invalid choice. Please enter again: \n";
		goto enteragain;
	}
	cout<<"Enter your username: ";
	cin.ignore();
	cin>>Username;
	cout<<"Enter your password: ";
	ch = _getch();
    while(ch != 13)
	{
    	Password.push_back(ch);
    	cout<<'*';
    	ch=_getch();
    }
	Name=Username;
	Name+=".txt";
	ifstream read(Name.c_str());
	getline(read, Users.UserID);
	getline(read, Users.UserPass);
	if(!read.is_open())
	{
		cout<<"No such user is present in database\n";
		goto againmenu;
	}
	if(Username==Users.UserID && Password==Users.UserPass)
	{
		system("CLS");
		cout<<"\nAccess granted!\n";
		PatientMenu();
	}
	else
	{
		cout<<"\nInvalid ID or password"<<endl;
		goto again;
	}
}

void Patient::PatientMenu()
{
	int mrnum;
	int choice;
	cout<<"\n____________________________________________________________\n";
    cout<<"\t\t\tPatient Menu\n";
    cout<<"____________________________________________________________\n";
	cout<<"\n1. Display your Patient Profile";
	cout<<"\n2. Book an Appointment";
	cout<<"\n3. Go to the Pharmacy";
	cout<<"\n4. Return to Main Menu";
	cout<<"\n0. Exit Program";
	cout<<"\n____________________________________________________________\n";
	do
	{
		cout<<"\n-> ";
		cin>>choice;
		if(choice==1)
		{
			ifstream fin;
			cout<<"Enter your MR No.: ";
			cin>>mrnum;
			system("cls");
            ViewPatientData(mrnum);
            system("PAUSE");
            system("cls");
            PatientMenu();
		}
		else if(choice==2)
		{
			PatientAppointment();
			system("PAUSE");
            system("cls");
            PatientMenu();
		}
		else if(choice==3)
		{
			Pharmacy P;
			system("cls");
			P.PharmacyMenu();
			system("PAUSE");
            system("cls");
            PatientMenu();
		}
		else if(choice==4)
		{
			system("cls");
			MainMenu();
		}
		else if(choice==0)
		{
			cout<<"Thank you for visiting our hospital!\n";
			exit(1);
		}
	}
	while(choice!=0);
}

void Patient::ShowPatientData()
{
	cout<<"\n\t\t--- Patient No. "<<MR<<" ---"<<endl<<endl;
    cout<<"First Name  : "<<FirstName<<endl;
    cout<<"Last Name   : "<<LastName<<endl;
    cout<<"Gender      : "<<Gender<<endl;
    cout<<"Age         : "<<Age<<endl;
    cout<<"Home Address: "<<HomeAddress<<endl;
    cout<<"Phone Number: "<<PhoneNumber<<endl;
    cout<<"Blood Group : "<<BloodGroup<<endl;
}

void Patient::ViewPatientData(int mednum)
{
	cout<<"\n____________________________________________________________\n";
    cout<<"\t\t\tPatient File\n";
    cout<<"____________________________________________________________\n";
	int flag=0;
    ifstream search;
    search.open("Patients.dat",ios::in);
    if(!search)
    {
    	cout<<"File not found.";
	}
	else
	{
		while(!search.eof())
		{
			search.read((char*)this,sizeof(*this));
			if(MR==mednum)
			{
				flag=1;
				ShowPatientData();
				search.close();
				break;
			}
		}
		if(flag==0)
		{
			cout<<"Record not found!";
		}
		search.close();
	}
}

void Patient::PatientAppointment()
{
	int id;
	stringstream ss; 
	Doctor doc;
	system("CLS");
	cout<<"\n\t\t\t----- Appointment Booking -----\n";
	ifstream doctor;
	doctor.open("Doctors.dat", ios::binary | ios::in);
	cout << "\nDoctor's currently available: \n\n";
	cout<<"       ID         |           Name            |     Speciality\n";
	while(doctor)
	{
		while(!doctor.eof())
		{
			if(doctor.read((char*)&doc,sizeof(doc)))
			{
				cout <<"->   "<<doc.getDoctorDR()<<"                 "<<doc.getDRFirstName()<<" "<<doc.getDRLastName()<<"               "<<doc.getDRSpeciality()<<endl;
			}
			else
			{
				break;
			}
		}
	}
	doctor.close();
	cout << "Enter the doctor ID to display appointment schedule: \n";
	cin >> id; 
  	ss<<id;  
  	string s;
  	ss>>s;
	string filename="Appointment";
	filename+=s;
	filename+=".dat";
	ifstream file3;
	file3.open(filename.c_str(), ios::in);
	int flag=0;
	char slot;
	Appointment obj;
    cout<<"\n\n\t\t\t Timings of Booking\n";
	cout<<"Slot | HOUR | MIN | DD / MM / YYYY | Status"<<endl;
	cout<<"___________________________________________"<<endl;
	while(file3)
	{
		if(file3.read((char*)&obj,sizeof(obj)))
		{
			obj.Display();
		}
		else
		{
			break;
		}
	}
	file3.close();
	slotagain:
	Appointment Example;
	ifstream file2;
	file2.open(filename.c_str(), ios::in);
	enteragain:
	try
	{
		cout<<"Choose a slot for your booking: ";
		cin>>slot;
		if(slot<'A' || slot>'Z')
		{
			throw(slot);
		}
	}
	catch(char slot)
	{
		cout<<"Slot can only be captial letters. Please enter again: \n";
		goto enteragain;
	}
	if(slot=='Q'||slot=='q')
	{
		cout<<"Your booking has been cancelled.\n";
		system("PAUSE");
		system("cls");
		PatientMenu();
	}
	while(!file2.eof())
	{
		if(file2.read((char*)&Example,sizeof(Example)))
		{
			if(slot==Example.getSlot() && strcmp("Available",Example.getAvailability())==0)
			{
				flag=1;
				Example.AppointmentUpdate(slot,filename);
				break;
			}
			else if(slot==Example.getSlot() && strcmp("Booked",Example.getAvailability())==0)
			{
				flag=2;
				break;
			}
			else
			{			
				flag=0;
			}
		}
		else
		{
			break;
		}
	}
	file2.close();
	if(flag==0)
	{
		cout<<"That slot does not exist!";
		goto slotagain;
	}
	else if(flag==2)
	{
		cout<<"That slot is currently unavailable, please choose another slot.";
		cout<<"\nAlternatively, press 'Q' to exit\n";
		goto slotagain;
	}
	else if(flag==1)
	{
		cout<<"That slot is currently available, your booking has been made!\n";
		system("PAUSE");
		system("cls");
		PatientMenu();
	}
}

//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                   Doctor Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Doctor::DoctorModule()
{
	int dr=99,flag=0;
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout<<"\n\t\t\tDOCTOR MENU\n";
    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	cout<<"Enter your Doctor Reference Number to login: ";
	cin>>dr;
	ifstream file;
	file.open("Doctors.dat", ios::in);
	if(!file.is_open())
	{
		cout<<"Doctors file not found!\n";
	}
	else
	{
		while(!file.eof())
		{
			if(file.read((char*)this,sizeof(*this)))
			{
				if(dr==getDoctorDR())
				{
					flag=1;
					DoctorMenu(dr);
				}
				else
				{
					flag=0;
				}
			}
			else
			{
				break;
			}
		}
	}
	file.close();
	if(flag==0)
	{
		cout<<"Access denied.\n\n";
		system("PAUSE");
		system("cls");
		DoctorModule();
	}
}

void Doctor::DoctorMenu(int dr)
{
	int choice=999;
	do
	{
		system("CLS");
		cout<<"\nAccess granted!\n";
		cout<<"\n____________________________________________________________\n";
    	cout<<"\t\t\tDoctor Menu\n";
    	cout<<"____________________________________________________________\n";
    	cout<<"\n1. Display your Doctor Profile.";
		cout<<"\n2. Check your current scheduled appointments.";
		cout<<"\n3. Check patient records.";
		cout<<"\n4. Logout.";
		cout<<"\n5. Go to Main Menu.";
		cout<<"\n0. Exit Program.";
		cout<<"\n___________________________________________________________\n";
		cout<<"\n-> ";
		cin>>choice;
		if(choice==1)
		{
			DoctorShowData();
			system("PAUSE");
			system("cls");
		}
		else if(choice==2)
		{
			DoctorAppointment(dr);
			system("PAUSE");
			system("cls");
		}	
		else if(choice==3)
		{
			DoctorViewRecords(dr);
//			system("PAUSE");
//			system("cls");
		}
		else if(choice==4)
		{
			system("cls");
			DoctorModule();
		}
		else if(choice==5)
		{
			system("cls");
			MainMenu();
		}
		else if(choice==0)
		{
			cout<<"\nThank you for visiting our hospital!\n";
			exit(1);
		}
		else
		{
			cout<<"Incorrect choice! Try again.\n";
		}
	}
	while(choice!=0);
}

void Doctor::DoctorViewRecords(int dr)
{
	ifstream file;
	Patient P;
	file.open("Patients.dat");
	if(!file)
	{
		cout<<"No patient data has been stored as of yet!\n";
	}
	else
	{
		system("CLS");
		cout<<"\n____________________________________________________________\n";
    	cout<<"\t\t\tPatient File\n";
    	cout<<"____________________________________________________________\n";
		while(file)
		{
			if(file.read((char*)&P,sizeof(P)))
			{
				P.ShowPatientData();
				system("PAUSE");
				system("cls");
				DoctorMenu(dr);
			}
			else
			{
				break;
			}
		}
	}
}

void Doctor::DoctorShowData()
{
	system("CLS");
	cout<<"\n____________________________________________________________\n";
    cout<<"\t\t\tDoctor Profile\n";
    cout<<"____________________________________________________________\n";
	cout<<"\n\t\t   --- Doctor. ID "<<DR<<" ---"<<endl<<endl;
	cout<<"First Name  : "<<FirstName<<endl;
	cout<<"Last Name   : "<<LastName<<endl;
	cout<<"Gender      : "<<Gender<<endl;
	cout<<"Age         : "<<Age<<endl;
	cout<<"Speciality  : "<<Speciality<<endl;
	cout<<"Home Address: "<<HomeAddress<<endl;
	cout<<"Phone Number: "<<PhoneNumber<<endl;
	cout<<"Blood Group : "<<BloodGroup<<endl;
}

void Doctor::DoctorFile()
{
	ofstream file;
	file.open("Doctors.dat", ios::out | ios::app);
	file.write((char*)this,sizeof(*this));
	file.close();
}

void Doctor::DoctorAppointment(int dr)
{
	stringstream ss;
  	ss<<dr;  
  	string s;
  	ss>>s;
	string filename="Appointment";
	filename+=s;
	filename+=".dat";
	ifstream file;
	file.open(filename.c_str(), ios::in);
	Appointment obj;
	system("CLS");
	cout<<"\n\t\t Timings of Booking\n";
	cout<<"Slot | HOUR | MIN | DD / MM / YYYY | Status"<<endl;
	cout<<"___________________________________________\n"<<endl;
	while(file)
	{
		if(file.read((char*)&obj,sizeof(obj)))
		{
			obj.Display();
		}
		else
		{
			break;
		}
	}
	file.close();
	int choice=999;
	while(choice!=0)
	{
		cout<<"\n\t   --- Appointment Menu ---\n\n";
		cout<<"1. Add an appointment slot\n";
		cout<<"2. Remove an appointment slot\n";
		cout<<"3. Update an appointment slot\n";
		cout<<"4. Update availability of a slot\n";
		cout<<"5. Return to Doctor Menu\n";
		cout<<"6. Return to Main Menu\n";
		cout<<"0. Exit Program\n";
		cout<<"\nEnter your choice: \n";
		cout<<"-> ";
		cin>>choice;
		if(choice==1)
		{
			Appointment a;
			a.AppointmentAddSlot(filename);
			system("PAUSE");
			system("cls");
		}
		else if(choice==2)
		{
			Appointment a;
			a.AppointmentRemoveSlot(filename);
			system("PAUSE");
			system("cls");
		}
		else if(choice==3)
		{
			Appointment a;
			a.AppointmentUpdateSlot(filename,dr);
			system("PAUSE");
			system("cls");
		}
		else if(choice==4)
		{
			Appointment a;
			a.AppointmentUpdateAvailability(filename);
			system("PAUSE");
			system("cls"); 
		}
		else if(choice==5)
		{
			system("cls");
			DoctorMenu(dr);
		}
		else if(choice==6)
		{
			system("cls");
			MainMenu();
		}
		else if(choice==0)
		{
			cout<<"Thank you for visiting out hospital. Goodbye!\n";
			exit(1);
		}
		else
		{
			cout<<"Invalid option! Enter again: \n";
		}
	}
}

//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                 Admin Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

void Admin::AdminMenu()
{
	int choice=999;
	do
	{
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout<<"\n\t\t\tADMIN MENU\n";
    	cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		cout<<" 1. Check Patient Records\n";
		cout<<" 2. Check Doctor Records\n";
		cout<<" 3. Add a new Doctor\n";
		cout<<" 4. Remove a current Doctor\n";
		cout<<" 5. Update a Doctor's Data\n";
		cout<<" 6. Check Pharmacy Stock\n";
		cout<<" 7. Add a new Medicine to the Pharmacy\n";
		cout<<" 8. Remove a Medicine from the Pharmacy\n";
		cout<<" 9. Update a Medicine's Data\n";
		cout<<"10. Refill entire Pharmacy Stock\n";
		cout<<"11. Return to Main Menu\n";
		cout<<" 0. Exit Program\n";
		cout<<"\n-> ";
		cin>>choice;
		if(choice==1)
		{
			AdminPatientView();
		}
		else if(choice==2)
		{
			AdminDoctorView();
		}
		else if(choice==3)
		{
			AdminAddDoctor();
			system("PAUSE");
			system("cls");
		}
		else if(choice==4)
		{
			AdminRemoveDoctor();
			system("PAUSE");
			system("cls");
		}
		else if(choice==5)
		{
			AdminUpdateDoctor();
		}
		else if(choice==6)
		{
			AdminViewPharmacy();
			system("PAUSE");
			system("cls");
		}
		else if(choice==7)
		{
			AdminAddMedicine();
			system("PAUSE");
			system("cls");
		}
		else if(choice==8)
		{
			AdminRemoveMedicine();
			system("PAUSE");
			system("cls");
		}
		else if(choice==9)
		{
			AdminUpdateMedicine();
			system("PAUSE");
			system("cls");
		}
		else if(choice==10)
		{
			AdminRefillPharmacy();
			system("PAUSE");
			system("cls");
		}
		else if(choice==11)
		{
			system("cls");
			MainMenu();
		}
		else if(choice==0)
		{
			cout<<"Thank you for visiting our hospital. Goodbye!\n";
			exit(1);
		}
		else
		{
			cout<<"Incorrect option! Try again.";
		}
	}
	while(choice!=0);
}

void Admin::AdminPatientView()
{
	ifstream file;
	Patient P;
	file.open("Patients.dat");
	if(!file.is_open())
	{
		cout<<"No patient data has been stored as of yet!\n";
	}
	else
	{
		system("CLS");
		cout<<"\n____________________________________________________________\n";
    	cout<<"\t\t\tPatient File\n";
    	cout<<"____________________________________________________________\n";
		while(!file.eof())
		{	
			if(file.read((char*)&P,sizeof(P)))
			{
				P.ShowPatientData();
				cout<<"\n";
			}
			else
			{
				break;
			}
		}
		system("PAUSE");
		system("cls");
		AdminMenu();
	}
}

void Admin::AdminDoctorView()
{
	ifstream file;
	file.open("Doctors.dat");
	Doctor D;
	if(!file.is_open())
	{
		cout<<"Doctor file not found\n";
	}
	else
	{
		system("CLS");
		cout<<"\n____________________________________________________________\n";
    	cout<<"\t\t\tDoctor File\n";
    	cout<<"____________________________________________________________\n";
		while(!file.eof())
		{
			if(file.read((char*)&D,sizeof(D)))
			{
				D.DoctorShowData();
				cout<<"\n";
			}
			else
			{
				break;
			}
		}
		system("PAUSE");
		system("cls");
		AdminMenu();
	}
}

void Admin::AdminAddDoctor()
{
	double Age;
	int DR;
	srand(time(NULL));
	DR=(rand() % 9000)+1000;
	char First[30],Last[30],Gender[10],Address[50],BloodGroup[10],Speciality[30],Number[30];
	cout<<"The DR number is "<<DR<<endl;
	firstnameagain:
	try
	{
		cout<<"Enter your first name: ";
		cin>>First;
		for(int i=0;i<strlen(First);i++)
		{
			if((First[i]>='a' && First[i]<='z') || (First[i]>='A' && First[i]<='Z') || (First[i]==' '))
			{
				
			}
			else
			{
				throw(First[i]);
			}
		}
	}
	catch(char first)
	{
		cout<<"First name can only contain alphabets. Please enter again: \n";
		goto firstnameagain;
	}
	lastnameagain:
	try
	{
		cout<<"Enter your last name: ";
		cin>>Last;
		for(int i=0;i<strlen(Last);i++)
		{
			if((Last[i]>='a' && Last[i]<='z') || (Last[i]>='A' && Last[i]<='Z') || (Last[i]==' '))
			{
				
			}
			else
			{
				throw(Last[i]);
			}
		}
	}
	catch(char last)
	{
		cout<<"Last name can only contain alphabets. Please enter again: \n";
		goto lastnameagain;
	}
	genderagain:
	try
	{
		cout<<"Enter your gender: ";
		cin>>Gender;
		if(strcmp(Gender,"Male")==0 || strcmp(Gender,"male")==0 || strcmp(Gender,"Female")==0 || strcmp(Gender,"female")==0 || strcmp(Gender,"M")==0 || strcmp(Gender,"F")==0 || strcmp(Gender,"m")==0 || strcmp(Gender,"f")==0)
		{
			
		}
		else
		{
			throw(Gender);
		}
	}
	catch(char * gender)
	{
		cout<<"Gender can only be Male\Female. Please enter again: \n";
		goto genderagain;
	}
	cout<<"Enter age: ";
	cin>>Age;
	specagain:
	try
	{
		cout<<"Enter speciality: ";
		cin>>Speciality;
		if(strcmp(Speciality,"Neurologist")==0 || strcmp(Speciality,"Orthopedic")==0 || strcmp(Speciality,"General Surgeon")==0 || strcmp(Speciality,"Dentist")==0 || strcmp(Speciality,"Gynecologist")==0 || strcmp(Speciality,"Psychiatrist")==0 || strcmp(Speciality,"Cardiologist")==0 || strcmp(Speciality,"Dermatologist")==0 || strcmp(Speciality,"Endocrinologist")==0 || strcmp(Speciality,"Radiologist")==0)
		{
			
		}
		else
		{
			throw(Speciality);
		}
	}
	catch(char * speciality)
	{
		cout<<"Speciality can be from: \n-Neurologist\n-Orthopedic\n-General Surgeon\n-Dentist\n-Gynecologist\n-Phsyciatrist\n-Cardiologist\n-Dermatologist\n-Endocrinologist\n-Radiologist\nEnter again: \n";
		goto specagain;
	}
	cout<<"Enter mobile number: ";
	cin>>Number; 
	cout<<"Enter address: ";
	cin>>Address;
	bloodgroupagain:
	try
	{
		cout<<"Enter your blood group: ";
		cin>>BloodGroup;
		if(strcmp(BloodGroup,"A+")==0 || strcmp(BloodGroup,"a+")==0 || strcmp(BloodGroup,"A-")==0 || strcmp(BloodGroup,"a-")==0 || strcmp(BloodGroup,"B+")==0 || strcmp(BloodGroup,"b+")==0 || strcmp(BloodGroup,"B-")==0 || strcmp(BloodGroup,"b-")==0 || strcmp(BloodGroup,"AB+")==0 || strcmp(BloodGroup,"ab+")==0 || strcmp(BloodGroup,"AB-")==0 || strcmp(BloodGroup,"ab-")==0 || strcmp(BloodGroup,"O+")==0 || strcmp(BloodGroup,"o+")==0 || strcmp(BloodGroup,"O-")==0 || strcmp(BloodGroup,"o-")==0)
		{
			
		}
		else
		{
			throw(BloodGroup);
		}
	}
	catch(char * bloodgroup)
	{
		cout<<"Blood group can only be A,B,AB,O in +/-. Please enter again: \n";
		goto bloodgroupagain;
	}
	Doctor D(DR,First,Last,Speciality,Gender,Address,BloodGroup,Age,Number);
	D.setDRFirstName();
	D.setDRLastName();
	D.DoctorFile();
	stringstream ss;  
  	ss<<DR;  
  	string s;
  	ss>>s;
	string filename="Appointment";
	filename+=s;
	filename+=".dat";
	ofstream file;
	file.open(filename.c_str(), ios::out);
	Appointment A(2,0,1,6,2020,'A');
	Appointment B(2,30,1,6,2020,'B');
	Appointment C(3,45,1,6,2020,'C');
	file.write((char*)&A,sizeof(A));
	file.write((char*)&B,sizeof(B));
	file.write((char*)&C,sizeof(C));
	file.close();
}

void Admin::AdminRemoveDoctor()
{
	int flag=0;
    ifstream file;
    file.open("Doctors.dat", ios::binary | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::binary | ios::app);
    Doctor obj;
    int dr;
    cout<<"Enter Doctor Reference Number to delete doctor record: ";
    cin>>dr;
    if(!file.is_open())
	{
        cout << "File not found!" << endl;
    }
    else
	{
    	while(!file.eof())
		{
            file.read((char*)&obj,sizeof(obj));
            if(file)
			{
                if(dr==obj.getDoctorDR())
				{
                    cout << "Deleted record is: " << endl;
                    obj.DoctorShowData();
                    flag=1;
                }
                else
				{
                    temp.write((char*)&obj,sizeof(obj));
                }
            }
        }
    }
    file.close();
    temp.close();
    remove("Doctors.dat");
    rename("temp.dat","Doctors.dat");
    if(flag==1)
	{
        cout << "Doctor successfully deleted!" << endl;
    }
    else
	{
        cout << "Doctor not found!" << endl;
    }
    stringstream ss;  
  	ss<<dr;  
  	string s;
  	ss>>s;
	string filename="Appointment";
	filename+=s;
	filename+=".dat";
	remove(filename.c_str());
}

void Admin::AdminUpdateDoctor()
{
	double Age;
	int DR;
	char First[30],Last[30],Gender[10],Address[50],BloodGroup[10],Speciality[30],Number[30];
	int pos,flag=0;
    fstream file;
    Doctor obj;
    file.open("Doctors.dat", ios::binary | ios::in | ios::out);
    int dr;
    cout<<"Enter Doctor Reference Number to update doctor record: ";
    cin>>dr;
    while(!file.eof())
	{
        pos=file.tellg();
        file.read((char*)&obj,sizeof(obj));
        if(file)
		{
            if(dr==obj.getDoctorDR())
			{
                cout<<"\n   --- New Data Entry ---\n" << endl;
				firstnameagain:
				try
				{
					cout<<"Enter your first name: ";
					cin>>First;
					for(int i=0;i<strlen(First);i++)
					{
						if((First[i]>='a' && First[i]<='z') || (First[i]>='A' && First[i]<='Z') || (First[i]==' '))
						{
					
						}
						else
						{
							throw(First[i]);
						}
					}
				}
				catch(char first)
				{
					cout<<"First name can only contain alphabets. Please enter again: \n";
					goto firstnameagain;
				}
				lastnameagain:
				try
				{
					cout<<"Enter your last name: ";
					cin>>Last;
					for(int i=0;i<strlen(Last);i++)
					{
						if((Last[i]>='a' && Last[i]<='z') || (Last[i]>='A' && Last[i]<='Z') || (Last[i]==' '))
						{
							
						}
						else
						{
							throw(Last[i]);
						}
					}
				}
				catch(char last)
				{
					cout<<"Last name can only contain alphabets. Please enter again: \n";
					goto lastnameagain;
				}
				genderagain:
				try
				{
					cout<<"Enter your gender: ";
					cin>>Gender;
					if(strcmp(Gender,"Male")==0 || strcmp(Gender,"male")==0 || strcmp(Gender,"Female")==0 || strcmp(Gender,"female")==0 || strcmp(Gender,"M")==0 || strcmp(Gender,"F")==0 || strcmp(Gender,"m")==0 || strcmp(Gender,"f")==0)
					{
						
					}
					else
					{
						throw(Gender);
					}
				}
				catch(char * gender)
				{
					cout<<"Gender can only be Male\Female. Please enter again: \n";
					goto genderagain;
				}
				cout<<"Enter age: ";
				cin>>Age;
				specagain:
				try
				{
					cout<<"Enter speciality: ";
					cin>>Speciality;
					if(strcmp(Speciality,"Neurologist")==0 || strcmp(Speciality,"Orthopedic")==0 || strcmp(Speciality,"General Surgeon")==0 || strcmp(Speciality,"Dentist")==0 || strcmp(Speciality,"Gynecologist")==0 || strcmp(Speciality,"Psychiatrist")==0 || strcmp(Speciality,"Cardiologist")==0 || strcmp(Speciality,"Dermatologist")==0 || strcmp(Speciality,"Endocrinologist")==0 || strcmp(Speciality,"Radiologist")==0)
					{
						
					}
					else
					{
						throw(Speciality);
					}
				}
				catch(char * speciality)
				{
					cout<<"Speciality can be from: \n-Neurologist\n-Orthopedic\n-General Surgeon\n-Dentist\n-Gynecologist\n-Phsyciatrist\n-Cardiologist\n-Dermatologist\n-Endocrinologist\n-Radiologist\nEnter again: \n";
					goto specagain;
				}
				cout<<"Enter mobile number: ";
				cin>>Number; 
				cout<<"Enter address: ";
				cin>>Address;
				bloodgroupagain:
				try
				{
					cout<<"Enter your blood group: ";
					cin>>BloodGroup;
					if(strcmp(BloodGroup,"A+")==0 || strcmp(BloodGroup,"a+")==0 || strcmp(BloodGroup,"A-")==0 || strcmp(BloodGroup,"a-")==0 || strcmp(BloodGroup,"B+")==0 || strcmp(BloodGroup,"b+")==0 || strcmp(BloodGroup,"B-")==0 || strcmp(BloodGroup,"b-")==0 || strcmp(BloodGroup,"AB+")==0 || strcmp(BloodGroup,"ab+")==0 || strcmp(BloodGroup,"AB-")==0 || strcmp(BloodGroup,"ab-")==0 || strcmp(BloodGroup,"O+")==0 || strcmp(BloodGroup,"o+")==0 || strcmp(BloodGroup,"O-")==0 || strcmp(BloodGroup,"o-")==0)
					{
						
					}
					else
					{
						throw(BloodGroup);
					}
				}
				catch(char * bloodgroup)
				{
					cout<<"Blood group can only be A,B,AB,O in +/-. Please enter again: \n";
					goto bloodgroupagain;
				}
				DR=dr;
				Doctor D(DR,First,Last,Speciality,Gender,Address,BloodGroup,Age,Number);
                file.seekp(pos);
                file.write((char*)&D,sizeof(D));
                flag=1;
                break;
            }
        }
    }
	file.close();
    if(flag==1)
	{
        cout << "Doctor successfully updated!" << endl;
    }
    else
	{
        cout << "Doctor not found" << endl;
    }
    system("PAUSE");
	system("cls");
	AdminMenu();
}

void Admin::AdminViewPharmacy()
{
	system("CLS");
	cout<<"_______________________________________________________________________________________________________________\n\n";
	cout<<"\n\t\t\t\t\t--- MEDICINE COUNTER ---\n\n";
	cout<<"_______________________________________________________________________________________________________________\n\n";
	cout<<"\n   SERIAL NO.'S\t\t     AVAILABLE DRUGS\t\tPRICE\t\t\tQUANTITY\t\n\n";
	Medicine M1;
	M1.ViewMedicineData();
}

void Admin::AdminAddMedicine()
{
	char ID[20];
    char Name[20];
    float Price;
    int Quantity=100;
    cout<<"Enter medicine ID: ";
    cin>>ID;
    nameagain:
	try
	{
		cout<<"Enter medicine name: ";
		cin>>Name;
		for(int i=0;i<strlen(Name);i++)
		{
			if((Name[i]>='a' && Name[i]<='z') || (Name[i]>='A' && Name[i]<='Z') || (Name[i]==' '))
			{
					
			}
			else
			{
				throw(Name[i]);
			}
		}
	}
	catch(char name)
	{
		cout<<"Medicine name can only contain alphabets. Please enter again: \n";
		goto nameagain;
	}
    cout<<"Enter medicine price: ";
    cin>>Price;
    Medicine M;
    M.SetMedicineData(ID,Name,Price,Quantity);
    M.StoreMedicineData();
}

void Admin::AdminRemoveMedicine()
{
	int flag=0;
    ifstream file;
    file.open("Medicine.dat", ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app);
    Medicine obj;
    char id[30];
    cout<<"Enter medicine ID to delete medicine: ";
    cin>>id;
    if(!file.is_open())
	{
        cout<<"File not found!\n";
        temp.seekp(0);
    }
    else
	{
    	while(!file.eof())
		{
            if(file.read((char*)&obj,sizeof(obj)))
            {
            	if(strcmp(id,obj.getMedicineID())==0)
				{
					cout<<"Deleted medicine is: \n";
                	obj.ShowMedicineData();
                	flag=1;    
            	}
            	else
				{
                	temp.write((char*)&obj,sizeof(obj));
            	}
			}
        }
    }
    file.close();
    temp.close();
    if(flag==1)
	{
		remove("Medicine.dat");
    	rename("temp.dat","Medicine.dat");
        cout<<"Medicine successfully deleted!\n";
    }
    else
	{
        cout<<"Medicine not found!\n";
    }
}

void Admin::AdminUpdateMedicine()
{
    Medicine obj;
    int flag=0;
    char id[30];
    cout<<"Enter medicine ID to update medicine: ";
    cin>>id;
    ofstream file2;
    file2.open("temporary.dat", ios::out);
    ifstream file;
    file.open("Medicine.dat", ios::in);
    while(file)
	{
        if(file.read((char*)&obj,sizeof(obj)))
        {
        	if(!strcmp(id,obj.getMedicineID()))
			{
				char Name[20],ID[20],Prescription;
    			float Price;
    			int size,Quantity=100;
				cout<<"Enter new data: /n";
            	cout<<"Enter medicine ID: ";
    			cin>>ID;
    			nameagain:
				try
				{
					cout<<"Enter medicine name: ";
					cin>>Name;
					for(int i=0;i<strlen(Name);i++)
					{
						if((Name[i]>='a' && Name[i]<='z') || (Name[i]>='A' && Name[i]<='Z') || (Name[i]==' '))
						{
					
						}
						else
						{
							throw(Name[i]);
						}
					}
				}
				catch(char name)
				{
					cout<<"Medicine name can only contain alphabets. Please enter again: \n";
					goto nameagain;
				}
   				cout<<"Enter medicine price: ";
    			cin>>Price;
    			cout<<"Select if medicine needs prescription to buy: (Y/N)";
    			cin>>Prescription;
    			Medicine M;
				M.SetMedicineData(ID,Name,Price,Quantity);
            	file2.write((char*)&M,sizeof(M));
            	flag=1;	
        	}
        	else
        	{
        		file2.write((char*)&obj,sizeof(obj));
			}
		}
		else
		{
			break;
		}
    }
	file.close();
	file2.close();
	remove("Medicine.dat");
	rename("temporary.dat","Medicine.dat");
    if(flag==1)
	{
        cout<<"Medicine successfully updated!\n";
    }
    else
	{
        cout<<"Medicine not found\n";
    }
}

void Admin::AdminRefillPharmacy()
{
	Medicine M;
	ofstream file2;
	file2.open("temp.dat", ios::out);
	fstream file;
	file.open("Medicine.dat", ios::in | ios::out);
	file.seekg(0);
	if(!file.is_open())
	{
		cout <<"Medicine file not found!\n";
	}
	else
	{
		while(!file.eof())
		{
			if(file.read((char*)&M,sizeof(M)))
			{
				M.setMedicineQuantity(100);
            	file2.write((char*)&M,sizeof(M));
			}
			else
			{
				break;
			}
		}
	}
	file.close();
	file2.close();
	remove("Medicine.dat");
	rename("temp.dat","Medicine.dat");
	cout<<"Pharmacy stock refilled!\n";
}

//______________________________________________________________________________________________________________________________________________________________________________________//
//                                                                                  Main Menu Functions
//______________________________________________________________________________________________________________________________________________________________________________________//

//Main Menu of Program
void MainMenu()
{
	Pharmacy P;
	P.PharmacyMedicineFiling();
	char identify;
    int i;
    static int count=0;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout<<"\t\t\t\t\t\t                                           		                                  \n";
    cout<<"\t\t\t\t\t\t                                           		                                  \n";
    cout<<"\t\t\t\t\t\t                                            		                                  \n";
    cout<<"\t\t\t\t\t\t                                           		                                  \n";
    cout<<"\t\t\t\t\t\t                                           		                                  \n";
    cout<<"\t\t\t\t\t\t                                           		                                  \n";
    cout<<"\t\t\t\t\t\t\t\t\t                                  WELCOME TO                                           \n";
    cout<<"\t\t\t\t\t\t\t                                                                                       \n";
    cout<<"\t\t\t\t\t\t\t                                      The Benevolent Companion Hospital                                  \n";
    cout<<"\t\t\t\t\t\t                                                                                       \n";
    cout<<"\t\t\t\t\t\t                                                                                       \n";
    cout<<"\t\t\t\t\t\t                                                                                       \n";
    cout<<"\t\t\t\t\t\t                                                                                       \n";
    cout<<"\t\t\t\t\t\t                                                                                      \n";
    cout<<"\t\t\t\t\t\t                                                                                       \n";
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
//    cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
//    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout<<"\nPlease enter which interface you'd like to use:- ";
	cout<<"\n- Press P to display Patient Interface\n- Press D to display Doctor Interface\n- Press A to display Admin Interface\n- Press E to exit menu\n";
	//cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	cout<<"\n->";
	cin>>identify;
	if (count>0)
	{
		repeat:
		cout<<"\nPlease enter which interface you'd like to use :- ";
		cout<<"\n~ Enter P for Patient Interface\n~ Enter D for Doctor Interface\n~ Enter A for Admin Interface\n~ Enter E to Exit\n->";
    	cin>>identify;
    }
	
    if (identify=='P' || identify=='p')
    {
    	system("cls");
    	cout<<"\nPatient Interface has been enabled.";
    	Patient P;
    	P.PatientModule();
	}
	else if (identify=='D' || identify=='d')
	{
		system("cls");
		cout<<"\nDoctor Interface has been enabled.";
		Doctor D;
		D.DoctorModule();
	}
	else if (identify=='A' || identify=='a')
	{
		system("cls");
		cout<<"\nAdmin Interface has been enabled.";
		Admin A;
		A.AdminMenu();
	}
	else if (identify=='E' || identify=='e')
	{
		cout<<"\nYou have exited the program successfully.";
		exit(1);
	}
	else
	{
		cout<<"\nYour option is invalid, please try again.";
		goto repeat;
	}
}
