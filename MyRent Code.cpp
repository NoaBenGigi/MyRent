#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define RED "\033[1;31m" 
#define GREEN "\033[1;32m" 
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m" 
#define PINK "\033[1;35m" 
#define MAGENTA "\033[1;36m" 
#define WHITE "\033[0m"    
#define BLOCKCOLOR "\033[1;100;30m" 

#include<iomanip>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include "string.h"
using namespace std;

struct landlord
{
	long id = 00000;
	string firstName;
	string lastName;
	string password;
	string email_address;
	string phoneNumber;
	string address;
};
struct renter
{
	long id = 00000;
	string firstName;
	string lastName;
	string password;
};
struct asset
{
	string country;
	string city;
	string address;
	string guests;
	string price;
	string avilable;
	string roomNum;
};

void welcome();
void REG();
void LOG();
void landlordMENU(string curr_id);
void Landlordchoose(int choose, string curr_id);
void Renterchoose(int choose, string curr_id);
void renterMENU(string curr_id);
void EXIT();
void EDIT_PERSONAL_DETAILS(string curr_id);
int details_validation(string id, string password);
void AddAsset(string curr_id);
void UpdateAsset(string curr_id);
//void SearchAsset(string curr_id);
//void sort(string curr_id, int totdays, int range3, int range4);

int main()
{
	welcome();
	return 0;
}
void welcome()
{
	cout << RED << "  HH   HH" << WHITE << "  H       H " << "" << "       " << WHITE << PINK << "  H H H    " << WHITE << " H H H H H " << YELLOW << " H       H " << WHITE << " H H H H H" << endl;
	cout << RED << "  H H H H" << WHITE << "    H   H   " << "" << "       " << WHITE << PINK << "  H   H    " << WHITE << " H         " << YELLOW << " H H     H " << WHITE << "     H    " << endl;
	cout << RED << "  H  H  H" << WHITE << "      H     " << BLOCKCOLOR << "=======" << WHITE << PINK << "  H H H H  " << WHITE << " H H H H H " << YELLOW << " H   H   H " << WHITE << "     H    " << endl;
	cout << RED << "  H     H" << WHITE << "      H     " << "" << "       " << WHITE << PINK << "  H      H " << WHITE << " H         " << YELLOW << " H     H H " << WHITE << "     H    " << endl;
	cout << RED << "  H     H" << WHITE << "      H     " << "" << "       " << WHITE << PINK << "  H      H " << WHITE << " H H H H H " << YELLOW << " H       H " << WHITE << "     H    " << endl;
	cout << BLOCKCOLOR << "                                                                           " << WHITE << endl;
	cout << endl << "My-Rent system offers rental online marketplace for lodging, primarily homestays, or tourism experiences ." << endl;
	cout << MAGENTA << "please choose if you want to register or to log in : " << endl << "1.REGISTER" << endl << "2.LOG-IN" << endl;

	int choose;
	cin >> choose;

	while (choose != 1 && choose != 2)
	{
		cout << "Wrong input inserted , please try again" << endl;
		cout << MAGENTA << "please choose if you want to register or to log in : " << endl << "1.REGISTER" << endl << "2.LOG-IN" << endl;
		cin >> choose;
	}
	if (choose == 1)
		REG();
	if (choose == 2)
		LOG();
}
void REG()
{//This func allowed the user to register to system 
	int choose;	//var that save the user choise
	cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
	cin >> choose;
	while ((choose != 1) && (choose != 2))
	{
		cout << "Wrong input inserted , please try again" << endl;
		cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
		cin >> choose;
	}

	string curr_id; //var that will save the current id

	if (choose == 1)		//Register as a Landlord
	{
		landlord lUser;
		cout << "Hi ,to Register as a landlord you have to fill all fields" << endl;
		cout << "Enter your ID: " << endl;
		cin >> lUser.id;
		cout << "Enter your first name: " << endl;
		cin >> lUser.firstName;
		cout << "Enter your last name: " << endl;
		cin >> lUser.lastName;
		cout << "Enter your password: " << endl;
		cin >> lUser.password;
		cout << "Enter your email: " << endl;
		cin >> lUser.email_address;
		cout << "Enter your phone number (only numbers): " << endl;
		cin >> lUser.phoneNumber;
		cout << "Enter your Address: " << endl;
		cin >> lUser.address;
		curr_id = lUser.id;

		ofstream BDusersf;//name decleartion
		BDusersf.open("C:/database/DBusers.txt", ios::app); 	//opening the file
		BDusersf << "Landlord" << ',' <<		//save the new landlord in DBusers
			lUser.id << ',' <<
			lUser.firstName << ',' <<
			lUser.lastName << ',' <<
			lUser.password << ',' <<
			lUser.email_address << ',' <<
			lUser.phoneNumber << ',' <<
			lUser.address << '\n';
		BDusersf.close();
	}
	if (choose == 2)	//Register as a Renter
	{
		renter rUser;
		cout << "Hi ,to Register as a Renter you have to fill all fields" << endl;
		cout << "Enter your ID: " << endl;
		cin >> rUser.id;
		cout << "Enter your first name: " << endl;
		cin >> rUser.firstName;
		cout << "Enter your last name: " << endl;
		cin >> rUser.lastName;
		cout << "Enter your password: " << endl;
		cin >> rUser.password;
		curr_id = rUser.id;

		ofstream BDusersf;//name decleartion
		BDusersf.open("C:/database/DBusers.txt", ios::app); // opening the file
		BDusersf << "Renter" << ',' <<		//save the new renter in DBusers
			rUser.id << ',' <<
			rUser.firstName << ',' <<
			rUser.lastName << ',' <<
			rUser.password << '\n';
		BDusersf.close();
	}
	if (choose == 1)		//go to landlordMENU
		landlordMENU(curr_id);
	if (choose == 2)		//go to renterMENU
		renterMENU(curr_id);
}
void LOG()
{//This func allowed the user to login the system
	string id;
	string password;
	string line;
	string curr_type, curr_password;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	string curr_id;
	int validDetails;
	while (1)
	{
		cout << "Enter your id: ";
		cin >> id;
		cout << "Enter your password: ";
		cin >> password;
		validDetails = details_validation(id, password);
		switch (validDetails)	//you've been directed to the suitable menu
		{
		case 1:
			renterMENU(id);
			break;
		case 2:
			landlordMENU(id);
			break;
		default:
			cout << "One or more of the details is incorrect, try again!" << endl;
		}
	}
}
void EDIT_PERSONAL_DETAILS(string curr_id)
{//This func allowed to change personal details
	string line;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	int counter = 0;
	ofstream Temp;//name decleartion
	int choose;

	DBusersf.open("C:/database/DBusers.txt");

	while (DBusersf >> line)
	{
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (words[1].compare(curr_id) == 0)
		{
			Temp.open("C:/database/temp.txt", ios::app);
			if (words[0].compare("Landlord") == 0)
			{
				cout << RED << "Which field are you want to change ? " << endl << "1.firstname" << endl << "2.lastname" << endl << "3.password" << endl << "4.email" << endl << "5.phone" << endl << "6.address" << endl << "7.Save & Next" << WHITE << endl;
				cin >> choose;
				landlord TempL;
				while (choose >= 0 && choose < 8)
				{
					if (choose == 1)
					{
						cout << YELLOW << "Enter your first name: " << endl;
						cin >> TempL.firstName;
						words[2] = TempL.firstName;
					}
					if (choose == 2)
					{
						cout << "Enter your last name: " << endl;
						cin >> TempL.lastName;
						words[3] = TempL.lastName;
					}
					if (choose == 3)
					{
						cout << "Enter your password: " << endl;
						cin >> TempL.password;
						words[4] = TempL.password;
					}
					if (choose == 4)
					{
						cout << "Enter your email: " << endl;
						cin >> TempL.email_address;
						words[5] = TempL.email_address;
					}
					if (choose == 5)
					{
						cout << "Enter your phone number (only numbers): " << endl;
						cin >> TempL.phoneNumber;
						words[6] = TempL.phoneNumber;
					}
					if (choose == 6)
					{
						cout << "Enter your Address: " << WHITE << endl;
						cin >> TempL.address;
						words[7] = TempL.address;
					}
					if (choose == 7)
					{
						break;
					}
					cout << RED << "Which field are you want to change ? " << endl << "1.firstname" << endl << "2.lastname" << endl << "3.password" << endl << "4.email" << endl << "5.phone" << endl << "6.address" << endl << "7.DONE EDITING" << WHITE << endl;
					cin >> choose;
				}
				for (int i = 0; i < 8; i++)
				{
					if (i < 7)
						Temp << words[i] << ",";
					if (i == 7)
						Temp << words[i] << endl;
				}
			}
			if (words[0].compare("Renter") == 0)
			{
				renter tempR;
				cout << RED << "Which field are you want to change ? " << endl << "1.firstname" << endl << "2.lastname" << endl << "3.password" << endl << "4.Save & Next" << WHITE << endl;
				cin >> choose;
				while (choose >= 0 && choose < 7)
				{
					if (choose == 1)
					{
						cout << YELLOW << "Enter your first name: " << endl;
						cin >> tempR.firstName;
						words[2] = tempR.firstName;
					}
					if (choose == 2)
					{
						cout << "Enter your last name: " << endl;
						cin >> tempR.lastName;
						words[3] = tempR.lastName;
					}
					if (choose == 3)
					{
						cout << "Enter your password: " << WHITE << endl;
						cin >> tempR.password;
						words[4] = tempR.password;
					}
					if (choose == 4)
					{
						break;
					}
					cout << RED << "Which field are you want to change ? " << endl << "1.firstname" << endl << "2.lastname" << endl << "3.password" << endl << "4.Save & Next" << WHITE << endl;
					cin >> choose;
				}
				for (int i = 0; i < 5; i++)
				{
					if (i < 4)
						Temp << words[i] << ",";
					if (i == 4)
						Temp << words[i] << endl;
				}
			}
			Temp.close();
		}
		else
		{
			Temp.open("C:/database/temp.txt", ios::app);
			Temp << line << endl;
			Temp.close();
		}
		words.clear();
	}
	string convert;
	ofstream BDusersf;//name decleartion
	BDusersf.open("C:/database/DBusers.txt", ios::trunc);
	ifstream Temp1;
	Temp1.open("C:/database/temp.txt");
	while (Temp1 >> convert)
	{
		BDusersf << convert << endl;
	}
	DBusersf.close();
	Temp1.close();
	remove("C:/database/temp.txt");

}
void landlordMENU(string curr_id)
{//This func disply the landlord menu

	cout << GREEN << "Hello landlord please choose the what you want to do for menu " << WHITE << endl;
	int choose;
	cout << BLUE << "1.ADD NEW ASSETS " << endl << "2.UPDATE EXIST ASSETS" << endl << "3.EDIT PERSONAL DATA " << endl << "4.REPORTS" << endl << "5.Choose another option" << WHITE << endl;
	cin >> choose;
	while (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5)
	{
		cout << "Wrong input , please try again" << endl;
		cout << BLUE << "1.ADD NEW ASSETS " << endl << "2.UPDATE EXIST ASSETS" << endl << "3.EDIT PERSONAL DATA " << endl << "4.REPORTS" << endl << "5.Choose another option" << WHITE << endl;
		cin >> choose;
	}

	if (choose <= 4)
		Landlordchoose(choose, curr_id);
	cout << GREEN << "Choose anoter option : " << endl;
	cout << RED << "1.BACK " << endl << "2.MENU" << endl << "3.LOGOUT" << endl << "4.EXIT" << endl << "5.CONTINUE AS RENTER" << WHITE << endl;
	cout << "Your choose is :" << endl;
	cin >> choose;
	//if (choose == 1)
	//{
	//	back
	//}
	//if (choose == 2)
	//{

	//}
	if (choose == 3)
	{
		welcome();
	}
	if (choose == 4)
	{
		EXIT();

	}
	if (choose == 5)
	{
		renterMENU(curr_id);
	}

}
void renterMENU(string curr_id)
{//This func disply the renter menu
	cout << GREEN << "Hello renter please choose the what you want to do for menu " << WHITE << endl;
	int choose;
	cout << BLUE << "1.SEARCH AVILABLE ASSETS " << endl << "2.ORDER HISTORY" << endl << "3.EDIT PERSONAL DATA " << endl << "4.Choose another option" << WHITE << endl;
	cin >> choose;
	while (choose != 1 && choose != 2 && choose != 3 && choose != 4)
	{
		cout << "Wrong input , please try again" << endl;
		cout << BLUE << "1.SEARCH AVILABLE ASSETS " << endl << "2.ORDER HISTORY" << endl << "3.EDIT PERSONAL DATA " << endl << "4.Choose another option" << WHITE << endl;
		cin >> choose;
	}

	if (choose < 4)
		Renterchoose(choose, curr_id);

	cout << GREEN << "Choose anoter option : " << endl;
	cout << RED << "1.BACK " << endl << "2.MENU" << endl << "3.LOGOUT" << endl << "4.EXIT" << "                                 5.CONTINUE AS LANDLORD" << WHITE << endl;
	cout << "Your choose is :" << endl;
	cin >> choose;
	if (choose == 1)
	{

	}
	if (choose == 2)
	{

	}
	if (choose == 3)
	{
		welcome();
	}
	if (choose == 4)
	{
		EXIT();

	}
	if (choose == 5)
	{
		landlordMENU(curr_id);
	}
}
void Renterchoose(int choose, string curr_id)
{//This func directed the user according to his choise
	if (choose == 1)
	{
		cout << YELLOW << "1.SEARCH FOR AVILABLE ASSTEST : //////" << WHITE << endl;
	}
	if (choose == 2)
	{
		cout << YELLOW << "2.ORDER HISTORY : //////" << WHITE << endl;
	}
	if (choose == 3)
	{
		EDIT_PERSONAL_DETAILS(curr_id);
	}
}
void Landlordchoose(int choose, string curr_id)
{//This func directed the user according to his choise
	if (choose == 1)
		AddAsset(curr_id);
	if (choose == 2)
		UpdateAsset(curr_id);
	if (choose == 3)
		EDIT_PERSONAL_DETAILS(curr_id);
	if (choose == 4)
		cout << YELLOW << "3.REPORTS: //////" << WHITE << endl;
}
void EXIT()
{//This func will end the activity in the system
	cout << "goodbye" << endl;
	exit(1);
}
int details_validation(string id, string password)
{//This func after log-in check the correctness of the details
	string line;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	string curr_id, curr_password, curr_type;
	DBusersf.open("C:/database/DBusers.txt"); // opening the file
	while (DBusersf >> line)
	{
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		curr_password = words[4];
		curr_id = words[1];
		curr_type = words[0];
		if (id == curr_id && password == curr_password)
		{
			DBusersf.close();
			if (curr_type.compare("Renter") == 0)
				return 1;
			else
			{
				if (curr_type.compare("Landlord") == 0)
					return 2;
			}
		}
		words.clear();
	}
	DBusersf.close();
	return 3;
}
void AddAsset(string curr_id)
{//This func allow the landlord to add new asset
	cout << GREEN << "Hi dear landlord please add your new asset details: " << WHITE << endl;
	cout << "Your current ID is :" << curr_id << endl;

	asset L;
	cout << "Enter asset Country: " << endl;
	cin >> L.country;
	cout << "Enter asset City: " << endl;
	cin >> L.city;
	cout << "Enter asset Address: " << endl;
	cin >> L.address;
	cout << "Enter number of guests: " << endl;
	cin >> L.guests;
	cout << "Enter Price p. night: " << endl;
	cin >> L.price;
	cout << "Enter number of rooms:" << endl;
	cin >> L.roomNum;
	L.avilable = "yes";
	ofstream ASSETda;//name decleartion
	ASSETda.open("C:/database/ASSETda.txt", ios::app); // opening the file
	ASSETda << curr_id << ',' <<
		L.country << ',' <<
		L.city << ',' <<
		L.address << ',' <<
		L.guests << ',' <<
		L.price << ',' <<
		L.roomNum << ',' <<
		L.avilable <<
		'\n';
	ASSETda.close();
}
void UpdateAsset(string curr_id)
{//This func allow the landlord update his assets
	string address1;
	cout << "Hello dear landlord please select enter the Asset address you would like to change " << endl;
	cin >> address1;

	int choose;
	string line;
	string word;
	vector <string> words;
	ofstream Temp2;//name decleartion
	ifstream ASSETda;//name decleartion

	ASSETda.open("C:/database/ASSETda.txt");
	while (ASSETda >> line)
	{
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (words[3] == address1)
		{
			Temp2.open("C:/database/temp1.txt", ios::app);
			cout << "Which field are you want to change ? " << endl << "1.Country" << endl << "2.City" << endl << "3.Address" << endl << "4.Guest n." << endl << "5.Price p.night" << endl << "6.Number of rooms" << endl << "7.Avilable(yes/no)" << endl << "8.Save & Next" << endl;
			cin >> choose;
			asset TempA;
			while (choose > 0 && choose <= 8)
			{
				if (choose == 1) {
					cout << "Enter asset Country: " << endl;
					cin >> TempA.country;
					words[1] = TempA.country;
				}
				if (choose == 2) {
					cout << "Enter asset City: " << endl;
					cin >> TempA.city;
					words[2] = TempA.city;
				}
				if (choose == 3) {
					cout << "Enter asset address: " << endl;
					cin >> TempA.address;
					words[3] = TempA.address;
				}
				if (choose == 4) {
					cout << "Number of guests: " << endl;
					cin >> TempA.guests;
					words[4] = TempA.guests;
				}
				if (choose == 5) {
					cout << "price per night: " << endl;
					cin >> TempA.price;
					words[5] = TempA.price;
				}
				if (choose == 6) {
					cout << "number of rooms: " << endl;
					cin >> TempA.price;
					words[6] = TempA.price;
				}
				if (choose == 7) {
					cout << "AVILABLE : " << endl << "yes/no" << endl;
					cin >> TempA.avilable;
					words[7] = TempA.avilable;
				}
				if (choose == 8)
				{
					break;
				}
				cout << "Which field are you want to change ? " << endl << "1.Country" << endl << "2.City" << endl << "3.Address" << endl << "4.Guest n." << endl << "5.Price p.night" << endl << "6.Avilable(yes/no)" << endl << "7.Number of rooms." << endl << "8.Save & Next" << endl;
				cin >> choose;
			}
			for (int i = 0; i < 8; i++)
			{
				if (i < 7)
					Temp2 << words[i] << ",";
				if (i == 7)
					Temp2 << words[i] << endl;
			}
			Temp2.close();
		}
		else
		{
			Temp2.open("C:/database/temp1.txt", ios::app);
			Temp2 << line << endl;
			Temp2.close();
		}
		ASSETda.close();
		words.clear();
	}
	string convert;
	ofstream ASSET;//name decleartion
	ASSET.open("C:/database/ASSETda.txt", ios::trunc); // opening the file

	ifstream Temp3;
	Temp3.open("C:/database/temp1.txt");
	while (Temp3 >> convert)
	{
		ASSET << convert;
	}

	ASSET.close();
	Temp3.close();
	remove("C:/database/temp1.txt");
}
/*
void SearchAsset(string curr_id)
{
	string range1, range2;
	string kind;
	string adult, children,guests;
	string country, city, address;
	string notes;
	int range3, range4;
	int choose;
	int totdays;

	cout << "Hello Renter please search by your preference:  " << endl;
	cout << "The dates you are plan to stay are from : " << endl;
	cin >> range1;
	cout << "to : " << endl;
	cin >> range2;
	cout << "TOTAL DAYS : " << endl;
	cin >> totdays;

	cout << "Select you type : 1.unit " << endl << "2.two rooms" << endl << "3.three rooms" << endl << "4.four rooms" << endl;
	cin >> choose;
	if (choose == 1)
		kind = "unit";
	if (choose == 2)
		kind = "two rooms";
	if (choose == 3)
		kind = "three rooms";
	if (choose == 4)
		kind = "four rooms";

	cout << "Number of total guests are : " << endl;
	cin >> guests;
	cout << "number of ADULTS : " << endl;
	cin >> adult;
	cout << "number of CHILDREN : " << endl;
	cin >> children;

	cout << "The countery you looking for : " << endl;
	cin >> country;
	cout << "The city you looking for: " << endl;
	cin >> city;
	cout << "the address you looking for : " << endl;
	cin >> address;

	cout << "Your price p.night range " << endl;
	cout << "FROM : " << endl;
	cin >> range3;
	cout << "TO : " << endl;
	cin >> range4;

	sort(curr_id, totdays, range3, range4);

}

void sort(string curr_id, int totdays, int range3, int range4)
{
	string line;
	string word;
	vector <string> words;
	ifstream ASSETda;//name decleartion

	string country;
	string city;
	string address;
	string zip;
	string kind;
	string about;
	string attraction;
	string guests;
	string price;
	string avilable;

	cout << "ALL AVILABLE SEARCH RESULT :" << endl;
	cout << "  COUNTRY   |   CITY   |   ADDRESS  |   GUESTS   |   PRICE   |  AVILABLE(Y\N)   " << endl;
	cout <<"----------------------------------------------------------"<<endl;
	ASSETda.open("C:/USERSDATA/ASSETda.txt");
	while (ASSETda >> line)
	{

		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (words[10] == "yes")
		{

			cout << words[1] << "     " << words[2] << "     " << words[3] << "     " << words[8] << "     " << words[9] << "     " << words[10] << endl;

		}
		words.clear();
	}

}*/