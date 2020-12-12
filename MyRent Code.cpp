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
#include <chrono> // REQUIERD FOR TIME
#include <ctime>  //REQUIERD FOR TIME
#include <cctype> //requiered of isdigit()
#include <stdlib.h>

using namespace std;

struct landlord
{
	long id = 0000;
	string firstName;
	string lastName;
	string password;
	string email_address;
	string phoneNumber;
	string address;
};
struct renter
{
	long id = 0000;
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
bool idAlreadyExists(string id);
void AddAsset(string curr_id);
void UpdateAsset(string curr_id);
void renterUpgrade(string curr_id);
void search_resullt(int day1, int month1, int year1, int day2, int month2, int year2, string country, string city, string address, int totaldays, string curr_id);
void SearchAsset(string curr_id);
void advanced_search(string curr_id, int totaldays, int day1, int month1, int year1, int day2, int month2, int year2);
bool priceRange(string pernight, int totaldays, int range3, int range4);
bool dateCheck(int day1, int month1, int year1, int day2, int month2, int year2, string country, string city, string address);
void sort(string curr_id, int searchKind);
void ORDERS_DB_UPDATE(string order_landlord_id, int day1, int month1, int year1, int day2, int month2, int year2, string order_address, string order_guest_number1, string order_room_number, int order_payment_sum1, string order_landlord_name, string order_landlord_mail, string order_landlord_phone1, string curr_id, string order_rank);
void order_Summary();
int validDate(int day, int month, int year);
void orderHistory(string curr_id);
void Reports(string curr_id);
void PAYMENT();
int* bubbleSort(int arr[], int n);
void upgradeAccountToLandlord(string curr_id);//מיותר ??
int order_number = 0;

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

	int choose;//var that save user choose
	cin >> choose;

	while (choose != 1 && choose != 2)
	{
		cout << "Wrong input inserted , please try again" << endl;
		cout << MAGENTA << "please choose if you want to register or to log in : " << endl << "1.REGISTER" << endl << "2.LOG-IN" << endl;
		cin >> choose;
	}
	system("CLS");
	if (choose == 1)		//register
		REG();
	if (choose == 2)		//log-in
		LOG();

}
void REG()
{//This func allowed the user to register the system 
	int choose;	//var that save the user choise
	cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
	cin >> choose;
	while ((choose != 1) && (choose != 2))
	{
		cout << "Wrong input inserted , please try again" << endl;
		cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
		cin >> choose;
	}
	string curr_id;			//var that will save the current id
	if (choose == 1)		//Register as a Landlord
	{
		landlord lUser;
		cout << "Hi ,to Register as a landlord you have to fill all fields" << endl;
		cout << "Enter your ID: " << endl;
		cin >> curr_id;
		while (idAlreadyExists(curr_id))
		{
			cout << "ID number already exists in database, please enter another id number: " << endl;
			cin >> curr_id;
		}
		lUser.id = stoi(curr_id);
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
		cin >> curr_id;
		while (idAlreadyExists(curr_id))
		{
			cout << "ID number already exists in database, please enter another id number: " << endl;
			cin >> curr_id;
		}
		rUser.id = stoi(curr_id);
		cout << "Enter your first name: " << endl;
		cin >> rUser.firstName;
		cout << "Enter your last name: " << endl;
		cin >> rUser.lastName;
		cout << "Enter your password: " << endl;
		cin >> rUser.password;

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
	ifstream DBusersf;			//name decleartion
	string word;
	vector <string> words;
	int validDetails;
	while (1)			//while the log-in faild
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
					cout << RED << "Which field are you want to change ? " << endl << "1.firstname" << endl << "2.lastname" << endl << "3.password" << endl << "4.email" << endl << "5.phone" << endl << "6.address" << endl << "7.Save & Next" << WHITE << endl;
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
	if (choose == 2)
	{
		landlordMENU(curr_id);
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
		renterMENU(curr_id);
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
		renterUpgrade(curr_id);
		landlordMENU(curr_id);
	}
}
void Renterchoose(int choose, string curr_id)
{//This func directed the user according to his choise
	if (choose == 1)
	{
		SearchAsset(curr_id);
	}
	if (choose == 2)
	{
		orderHistory(curr_id);
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
		Reports(curr_id);
}
void EXIT()
{//This func will end the activity in the system
	system("CLS");

	




	cout <<YELLOW<<endl<<endl<<endl<< " THANK YOU FOR USING THE SYSTEM :)" << YELLOW<<endl;
	exit(1);
}
int details_validation(string id, string password)
{//This func after log-in check the correctness of the details
	string line;
	ifstream DBusersf;
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
bool idAlreadyExists(string id)
{
	string line;
	ifstream DBusersf;
	string word;
	vector <string> words;
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
		if (id == words[1])
		{
			DBusersf.close();
			return true;
		}
		words.clear();
	}
	DBusersf.close();
	return false;
}
void AddAsset(string curr_id)
{//This func allow the landlord to add new asset
	cout<< YELLOW << "Hi dear landlord please add your new asset details: " << WHITE << endl;
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
		L.avilable << '\n';
	ASSETda.close();
}
void UpdateAsset(string curr_id)
{//This func allow the landlord update his assets
	string address1;
	cout <<YELLOW<< "Hello landlord,Enter the address of the asset you want to update: " <<WHITE<< endl;
	cin >> address1;

	int choose;
	string line;
	string word;
	vector <string> words;
	ofstream Temp2;//name decleartion
	ifstream ASSETda;//name decleartion
	bool flag = false;//var that save if landlord made a change in his assets
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
		if (words[3] == address1 && words[0] == curr_id)
		{
			flag = true;
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
					cin >> TempA.roomNum;
					words[6] = TempA.roomNum;
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
	if (!flag)
	{
		cout << "Wrong address!" << endl;
	}
	ASSET.close();
	Temp3.close();
	remove("C:/database/temp1.txt");
}
void renterUpgrade(string curr_id)
{
	cout <<YELLOW<< "Hello Renter to upgrade for landlord please select the fill " <<WHITE<< endl;
	string line;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	ofstream Temp;
	string address, email, phone;
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

		if (curr_id == words[1])
		{
			Temp.open("C:/database/temp2.txt", ios::app);
			cout << "Your have to fill those fields to become a ranter : " << endl;

			cout << "Enter your email: " << endl;
			cin >> email;

			cout << "Enter your phone number (only numbers): " << endl;
			cin >> phone;

			cout << "Enter your Address: " << WHITE << endl;
			cin >> address;

			words[0] = "Landlord";
			words[4] = words[4] + "," + email + "," + phone + "," + address;

			for (int i = 0; i < 5; i++)
			{
				if (i < 4)
					Temp << words[i] << ",";
				if (i == 4)
					Temp << words[i] << endl;
			}
			Temp.close();
		}
		else
		{
			Temp.open("C:/database/temp2.txt", ios::app);
			Temp << line << endl;
			Temp.close();
		}
		words.clear();
	}
	Temp.close();
	string convert;
	ofstream BDusersf;//name decleartion
	BDusersf.open("C:/database/DBusers.txt", ios::trunc);
	ifstream Temp2;
	Temp2.open("C:/database/temp2.txt");
	while (Temp2 >> convert)
	{
		BDusersf << convert << endl;
	}
	DBusersf.close();
	Temp2.close();
	remove("C:/database/temp2.txt");
}
void SearchAsset(string curr_id)
{//Basic search
	int day1, day2, month1, month2, year1, year2;
	string country, city, address;int  totaldays;
	cout <<YELLOW<< "-------BASIC SEARCH------  " <<WHITE<< endl;
	cout << "Hello Renter please search by your preference:  " << endl;
	cout << "The dates you are plan to stay are from : " << endl;
	cout << "from day: " << endl;
	cin >> day1;
	cout << "MONTH: " << endl;
	cin >> month1;
	cout << "YEAR:" << endl;
	cin >> year1;
	cout << "until: " << endl;
	cin >> day2;
	cout << "MONTH: " << endl;
	cin >> month2;
	cout << "YEAR:" << endl;
	cin >> year2;
	cout << "Total days: " << endl;
	cin >> totaldays;
	cout << "The country you looking for : " << endl;
	cin >> country;
	cout << "The city you looking for: " << endl;
	cin >> city;
	cout << "the address you looking for : " << endl;
	cin >> address;
	search_resullt(day1, month1, year1, day2, month2, year2, country, city, address, totaldays, curr_id);
}
void search_resullt(int day1, int month1, int year1, int day2, int month2, int year2, string country, string city, string address, int totaldays, string curr_id)
{
	string line;
	string word;
	vector <string> words;
	ifstream ASSETda;
	ifstream DBusersf;
	ofstream temp;//name decleartion
	temp.open("C:/database/searchR.txt", ios::app);
	int res = 1;	//var that save number result
	int choose;
	int tablechoose = 0;
	int counter = 1;
	ASSETda.open("C:/database/ASSETda.txt");
	while (ASSETda >> line)
	{//search resullt - Basic
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (words[1] == country && words[2] == city && dateCheck(day1, month1, year1, day2, month2, year2, country, city, words[3]) && words[7] == "yes")
		{
			cout << "RESULT number:" << YELLOW << res << WHITE << "|Location : " << words[1] << "," << words[2] << "," << words[3] << "| Guests Num: " << words[4] << "|price per night :" << words[5] << "| Room Num :" << words[6] << "|asset rating " << endl;
			temp << line << '\n';
			res++;
		}
		words.clear();
	}
	if (res == 1)
	{
		cout << "No results! " << endl;
		return;
	}
	ASSETda.close();
	temp.close();
	ifstream tempOrder;
	cout << "Continue to advanced search ?   " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No, go to sort" << endl;
	cout << "3.Make an order" << endl;
	long id_ln;
	string lanldlord_id;
	cin >> choose;
	string land_name, land_phone, land_email;
	if (choose == 1)
	{
		advanced_search(curr_id, totaldays, day1, month1, year1, day2, month2, year2);
	}
	if (choose == 2)
	{
		sort(curr_id, 1);
		res = 1;
		counter = 1;
		ifstream Regular;
		Regular.open("C:/database/searchR.txt");
		while (Regular >> line)
		{//search resullt - Basic
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (words[1] == country && words[2] == city && dateCheck(day1, month1, year1, day2, month2, year2, country, city, words[3]) && words[7] == "yes")
			{
				cout << "RESULT number:" <<YELLOW<< res << WHITE<<"|Location : " << words[1] << "," << words[2] << "," << words[3] << "| Guests Num: " << words[4] << "|price per night :" << words[5] << "| Room Num :" << words[6] << "|asset rating " << endl;
				res++;
			}
			words.clear();
		}
		Regular.close();
		Regular.open("C:/database/searchR.txt");
		cout << "Please enter your option from Result table is : " << endl;
		cin >> tablechoose;
		while (Regular >> line)
		{
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (counter == tablechoose)
			{
				break;
			}
			counter++;
			words.clear();
		}
		string guests = words[4];
		string rooms = words[6];
		int total;
		total = stoi(words[5]) * totaldays;
		string address1 = words[1] + "." + words[2] + "." + words[3];

		id_ln = stoi(words[0]);
		lanldlord_id = words[0];
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
			if (words[1] == lanldlord_id)
			{
				land_name = words[2];
				land_phone = words[6];
				land_email = words[5];
			}
			words.clear();
		}
		DBusersf.close();
		Regular.close();
		remove("C:/database/searchR.txt"); // remove basic search  
		PAYMENT();
		ORDERS_DB_UPDATE(lanldlord_id, day1, month1, year1, day2, month2, year2, address1, guests, rooms, total, land_name, land_email, land_phone, curr_id, "***");
		order_Summary();

	}
	if (choose == 3)
	{
		tempOrder.open("C:/database/searchR.txt");
		cout << "Please enter your option from Result table is : " << endl;
		cin >> tablechoose;
		while (tempOrder >> line)
		{
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (counter == tablechoose)
			{
				break;
			}
			counter++;
			words.clear();
		}
		string guests = words[4];
		string rooms = words[6];
		int total;
		total = stoi(words[5]) * totaldays;
		string address1 = words[1] + "." + words[2] + "." + words[3];

		id_ln = stoi(words[0]);
		lanldlord_id = words[0];
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
			if (words[1] == lanldlord_id)
			{
				land_name = words[2];
				land_phone = words[6];
				land_email = words[5];
			}
			words.clear();
		}
		DBusersf.close();
		tempOrder.close();
		remove("C:/database/searchR.txt"); // remove basic search 
		PAYMENT();
		ORDERS_DB_UPDATE(lanldlord_id, day1, month1, year1, day2, month2, year2, address1, guests, rooms, total, land_name, land_email, land_phone, curr_id, "***");
		order_Summary();
	}
}
void advanced_search(string curr_id, int totaldays, int day1, int month1, int year1, int day2, int month2, int year2)
{
	string line, word;
	string numOfguests = "0";
	string numOfrooms = "0";
	string land_name, land_email, land_phone;
	int range1 = 0, range2 = 0;
	vector <string> words;
	cout << YELLOW << "-------ADVANCE SEARCH------  " << WHITE << endl;
	cout << "Enter number of guests: " << endl;
	cin >> numOfguests;
	cout << "Enter a price range: " << endl;
	cout << "From: " << endl;
	cin >> range1;
	cout << "To: " << endl;
	cin >> range2;
	cout << "Enter number of rooms: " << endl;
	cin >> numOfrooms;
	int res = 1;
	int  tablechoose;
	ifstream searchBasic;
	int counter = 1;
	searchBasic.open("C:/database/searchR.txt");
	ofstream temp;//name decleartion
	ifstream DBusersf;
	temp.open("C:/database/searchR_ADV.txt", ios::app);
	while (searchBasic >> line)
	{//search resullt - advanced
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (numOfguests == words[4] && numOfrooms == words[6] && priceRange(words[5], totaldays, range1, range2))
		{
			cout << "RESULT number:" << YELLOW << res << WHITE << "|Location : " << words[1] << "," << words[2] << "," << words[3] << "| Room Num :" << words[6] << "|price per night :" << words[5] << "|asset rating " << endl;
			temp << line << '\n';
			res++;
		}
		words.clear();
	}
	searchBasic.close();
	temp.close();
	if (res == 1)
	{
		cout << "No results! " << endl;
		return;
	}
	int choose;
	cout << "Continue to sort ?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No,Make an order" << endl;
	cout << "3. Exit from Search and go back to menu" << endl;
	cin >> choose;
	if (choose == 1)
	{
		sort(curr_id, 2);
		res = 1;
		counter = 1;
		ifstream Advance;
		Advance.open("C:/database/searchR_ADV.txt");
		while (Advance >> line)
		{//search resullt - advanced
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (numOfguests == words[4] && numOfrooms == words[6] && priceRange(words[5], totaldays, range1, range2))
			{
				cout << "RESULT number:" << YELLOW << res << WHITE << "|Location : " << words[1] << "," << words[2] << "," << words[3] << "| Room Num :" << words[6] << "|price per night :" << words[5] << "|asset rating " << endl;

				res++;
			}
			words.clear();
		}
		Advance.close();
		Advance.open("C:/database/searchR_ADV.txt");
		cout << "Please enter your option from Result table is : " << endl;
		cin >> tablechoose;
		while (Advance >> line)
		{
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (counter == tablechoose)
			{
				break;
			}
			counter++;
			words.clear();
		}
		string address1 = words[1] + "." + words[2] + "." + words[3];
		int total;
		total = totaldays * stoi(words[5]);
		long id_ln = stoi(words[0]);
		string lanldlord_id = words[0];
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
			if (words[1] == lanldlord_id)
			{
				land_name = words[2];
				land_phone = words[6];
				land_email = words[5];
			}
			words.clear();
		}
		DBusersf.close();
		Advance.close();
		remove("C:/database/searchR.txt"); // remove basic search 
		remove("C:/database/searchR_ADV.txt"); // remove basic search 
		PAYMENT();
		ORDERS_DB_UPDATE(lanldlord_id, day1, month1, year1, day2, month2, year2, address1, numOfguests, numOfrooms, total, land_name, land_email, land_phone, curr_id, "***");
		order_Summary();


	}
	if (choose == 2)
	{
		searchBasic.open("C:/database/searchR.txt");
		cout << "Please enter your option from Result table is : " << endl;
		cin >> tablechoose;
		while (searchBasic >> line)
		{
			istringstream iss(line);
			if (line != "")
			{
				while (getline(iss, word, ','))
				{
					words.push_back(word);
				}
			}
			if (counter == tablechoose)
			{
				break;
			}
			counter++;
			words.clear();
		}
		string address1 = words[1] + "." + words[2] + "." + words[3];
		int total;
		total = totaldays * stoi(words[5]);
		long id_ln = stoi(words[0]);
		string lanldlord_id = words[0];
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
			if (words[1] == lanldlord_id)
			{
				land_name = words[2];
				land_phone = words[6];
				land_email = words[5];
			}
			words.clear();
		}
		DBusersf.close();
		searchBasic.close();
		temp.close();
		remove("C:/database/searchR.txt"); // remove basic search 
		remove("C:/database/searchR_ADV.txt"); // remove basic search 
		PAYMENT();
		ORDERS_DB_UPDATE(lanldlord_id, day1, month1, year1, day2, month2, year2, address1, numOfguests, numOfrooms, total, land_name, land_email, land_phone, curr_id, "***");
		order_Summary();
	}
	if (choose == 3)
	{
		remove("C:/database/searchR.txt");
		remove("C:/database/searchR_ADV.txt");
		renterMENU(curr_id);
	}

}
void sort(string curr_id, int searchKind)
{
	vector <string> words;
	vector <int> words1;
	vector <string> words2;
	string line, line1, word, word1;

	int choose, counter = 0;
	cout << "Please choose how do you want to sort(from low to high) : " << endl << "1.number of rooms" << endl << "2.availability" << endl << "3.price per night" << endl << "4.rating" << endl << "5.save&make the order" << endl;
	cin >> choose;

	ifstream Regular;
	Regular.open("C:/database/searchR.txt");

	
		if (choose == 1)
		{
			if (searchKind == 1)
			{
				cout << "here";
				while (Regular >> line)
				{
					istringstream iss(line);
					if (line != "")
					{
						counter++;
						while (getline(iss, word, ','))
						{
							words.push_back(word);
						}
					}
					words1.push_back(stoi(words[6]));
					words.clear();

				}
				Regular.close();

				int* tamp = new int[counter];
				for (int i = 0; i < counter;i++)
				{
					tamp[i] = words1[i];
				}

				int* tamp1 = bubbleSort(tamp, counter);

				for (int i = 0; i < counter;i++)
				{
					tamp[i] = tamp1[i];
				}

				int counter1 = 0;
				ofstream Temp;
				for (int i = 0; i < counter; i++)
				{
					Regular.open("C:/database/searchR.txt");
					while (Regular >> line)
					{

						istringstream iss(line);
						if (line != "")
						{

							while (getline(iss, word, ','))
							{
								words.push_back(word);
							}
						}

						if (tamp[counter1] == stoi(words[6]))
						{

							counter1++;
							Temp.open("C:/database/temp.txt", ios::app);
							Temp << line << endl;
							Temp.close();


						}
						words.clear();
					}
					Regular.close();
				}
				words1.clear();



				string convert;
				ofstream Regular;//name decleartion
				Regular.open("C:/database/searchR.txt", ios::trunc);
				ifstream Temp1;
				Temp1.open("C:/database/temp.txt");
				while (Temp1 >> convert)
				{
					Regular << convert << endl;
				}
				Regular.close();
				Temp1.close();
				remove("C:/database/temp.txt");

			}
			if (searchKind == 2)
			{


				//no sort needed because it is advance and he select the number of rooms



			}


		}
		if (choose == 2)
		{
			if (searchKind == 1)
			{

				cout << YELLOW << "ALL avilable asstes:" << WHITE<< endl;
			}
			if (searchKind == 2)
			{
				cout << YELLOW << "ALL avilable asstes:" << WHITE << endl;
			}
		}
		if (choose == 3)
		{
			if (searchKind == 1)
			{
				cout << "here";
				while (Regular >> line)
				{
					istringstream iss(line);
					if (line != "")
					{
						counter++;
						while (getline(iss, word, ','))
						{
							words.push_back(word);
						}
					}
					words1.push_back(stoi(words[5]));
					words.clear();

				}
				Regular.close();

				int* tamp = new int[counter];
				for (int i = 0; i < counter;i++)
				{
					tamp[i] = words1[i];
				}

				int* tamp1 = bubbleSort(tamp, counter);

				for (int i = 0; i < counter;i++)
				{
					tamp[i] = tamp1[i];
				}

				int counter1 = 0;
				ofstream Temp;
				for (int i = 0; i < counter; i++)
				{
					Regular.open("C:/database/searchR.txt");
					while (Regular >> line)
					{

						istringstream iss(line);
						if (line != "")
						{

							while (getline(iss, word, ','))
							{
								words.push_back(word);
							}
						}

						if (tamp[counter1] == stoi(words[5]))
						{

							counter1++;
							Temp.open("C:/database/temp.txt", ios::app);
							Temp << line << endl;
							Temp.close();


						}
						words.clear();
					}
					Regular.close();
				}
				words1.clear();



				string convert;
				ofstream Regular;//name decleartion
				Regular.open("C:/database/searchR.txt", ios::trunc);
				ifstream Temp1;
				Temp1.open("C:/database/temp.txt");
				while (Temp1 >> convert)
				{
					Regular << convert << endl;
				}
				Regular.close();
				Temp1.close();
				remove("C:/database/temp.txt");

			}
			if (searchKind == 2)
			{
				ifstream Advance;
				Advance.open("C:/database/searchR_ADV.txt");

				while (Advance >> line)
				{
					istringstream iss(line);
					if (line != "")
					{
						counter++;
						while (getline(iss, word, ','))
						{
							words.push_back(word);
						}
					}
					words1.push_back(stoi(words[5]));
					words.clear();

				}
				Advance.close();

				int* tamp = new int[counter];
				for (int i = 0; i < counter;i++)
				{
					tamp[i] = words1[i];
				}

				int* tamp1 = bubbleSort(tamp, counter);

				for (int i = 0; i < counter;i++)
				{
					tamp[i] = tamp1[i];
				}

				int counter1 = 0;
				ofstream Temp;
				for (int i = 0; i < counter; i++)
				{
					Advance.open("C:/database/searchR_ADV.txt");
					while (Advance >> line)
					{

						istringstream iss(line);
						if (line != "")
						{

							while (getline(iss, word, ','))
							{
								words.push_back(word);
							}
						}

						if (tamp[counter1] == stoi(words[5]))
						{

							counter1++;
							Temp.open("C:/database/temp.txt", ios::app);
							Temp << line << endl;
							Temp.close();


						}
						words.clear();
					}
					Advance.close();
				}
				words1.clear();



				string convert;
				ofstream Advance1;//name decleartion
				Advance1.open("C:/database/searchR_ADV.txt", ios::trunc);
				ifstream Temp1;
				Temp1.open("C:/database/temp.txt");
				while (Temp1 >> convert)
				{
					Advance1 << convert << endl;
				}
				Advance1.close();
				Temp1.close();
				remove("C:/database/temp.txt");



			}


		}
		
		







}
int* bubbleSort(int arr[], int n)
{
	int i, j, temp, pass = 0;



	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		pass++;
	}
	return arr;
}
bool dateCheck(int day1, int month1, int year1, int day2, int month2, int year2, string country, string city, string address)
{
	string line;
	string word;
	vector <string> words;
	ifstream ORDERS_DB;
	bool flag1 = false, flag2 = false;
	int linescount = 0;
	int entryDate;
	int startDate;
	int endDate;
	int Dday1, Dmonth1, Dyear1;
	int Dday2, Dmonth2, Dyear2;
	string alladdress = country + "." + city + "." + address;
	ORDERS_DB.open("C:/database/ORDERS_DB.txt");
	while (ORDERS_DB >> line)
	{
		linescount++;
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (words[8] == alladdress)
		{
			Dday1 = stoi(words[2]);
			Dmonth1 = stoi(words[3]);
			Dyear1 = stoi(words[4]);
			Dday2 = stoi(words[5]);
			Dmonth2 = stoi(words[6]);
			Dyear2 = stoi(words[7]);

			entryDate = (year1 * 10000) + (month1 * 100) + day1;
			startDate = (Dyear1 * 10000) + (Dmonth1 * 100) + Dday1;
			endDate = (Dyear2 * 10000) + (Dmonth2 * 100) + Dday2;
			if (entryDate >= startDate && entryDate <= endDate) {

				return false;
			}

			entryDate = (year2 * 10000) + (month2 * 100) + day2;
			startDate = (Dyear1 * 10000) + (Dmonth1 * 100) + Dday1;
			endDate = (Dyear2 * 10000) + (Dmonth2 * 100) + Dday2;
			if (entryDate >= startDate && entryDate <= endDate) {

				return false;
			}
			//if (flag1 == false && flag2 == 2)
			//{
			//	return false;
			//}
		}
		words.clear();
	}
	if (linescount == 0)
	{
		ORDERS_DB.close();
		return true;
	}

	ORDERS_DB.close();
	return true;
}
bool priceRange(string pernight, int totaldays, int range3, int range4)
{
	int pricepernight;
	pricepernight = stoi(pernight);
	if (pricepernight >= range3 && pricepernight <= range4)
	{
		return 1;
	}
	return 0;
}
void ORDERS_DB_UPDATE(string order_landlord_id, int day1, int month1, int year1, int day2, int month2, int year2, string order_address, string order_guest_number1, string order_room_number, int order_payment_sum1, string order_landlord_name, string order_landlord_mail, string order_landlord_phone1, string curr_id1, string order_rank)
{
	long curr_id = stoi(order_landlord_id);
	order_number++;
	ofstream ORDERS_DB;
	ORDERS_DB.open("C:/database/ORDERS_DB.txt", ios::app);
	ORDERS_DB << order_number << ',' <<
		curr_id << ',' <<
		day1 << ',' <<
		month1 << ',' <<
		year1 << ',' <<
		day2 << ',' <<
		month2 << ',' <<
		year2 << ',' <<
		order_address << ',' <<
		order_guest_number1 << ',' <<
		order_room_number << "," <<
		order_payment_sum1 << ',' <<
		order_landlord_name << ',' <<
		order_landlord_mail << ',' <<
		order_landlord_phone1 << ',' <<
		curr_id1 << ',' <<
		order_rank << '\n';
	ORDERS_DB.close();
}
void orderHistory(string curr_id)
{
	int totalpayment = 0;
	int orderscount = 0;
	long id = stoi(curr_id);
	string line;
	string word;
	vector <string> words;
	ifstream ORDERda;
	ORDERda.open("C:/database/ORDERS_DB.txt");
	while (ORDERda >> line)
	{
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (id == stoi(words[15]))
		{
			cout <<GREEN<< "RENTER ID N.: " << id <<WHITE<< "  YOUR ORDER HISTORY IS :" << endl;
			cout << "order number : " << words[0] << endl;
			cout << "address is  : " << words[8] << endl;
			cout << "date order is  : " << words[2] << "," << words[3] << "," << words[4] << endl;
			cout << "total price : " << words[11] << endl;
			totalpayment += stoi(words[11]);
			orderscount++;
		}
		words.clear();
	}
	cout << " your total payment are : " << totalpayment << endl;
	cout << " you made : " << orderscount << " orders " << endl;
}
void Reports(string curr_id)
{
	long id = stoi(curr_id);
	int totalpayment = 0;
	int orderscount = 0;
	string line, line1;
	string word, word1;
	vector <string> words;
	vector <string> words1;
	ifstream ORDERda;
	ifstream DBusers;
	ORDERda.open("C:/database/ORDERS_DB.txt");
	DBusers.open("C:/database/DBusers.txt");
	while (ORDERda >> line)
	{
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (id == stoi(words[1]))
		{
			while (DBusers >> line1)
			{
				istringstream iss(line1);
				if (line1 != "")
				{
					while (getline(iss, word1, ','))
					{
						words1.push_back(word1);
					}
				}
				if (stoi(words1[1]) == stoi(words[15]))
				{
					break;
				}

				words1.clear();

			}
			cout <<GREEN<< "Landlord ID N. " <<WHITE<< id << "  YOUR REPORTS ARE :" << endl;
			cout << "order number : " << words[0] << endl;
			cout << "address is  : " << words[8] << endl;
			cout << "date order is  : " << words[2] << "," << words[3] << "," << words[4] << endl;
			cout << "name of cosumer is : " << words1[2] << endl;
			cout << " total price : " << words[10] << endl;
			totalpayment += stoi(words[11]);
			orderscount++;
		}
		words.clear();
	}

	ORDERda.close();
	//DBusers.close();
	cout << "your total profit from orders : " << totalpayment << endl;
	cout << "you have " << orderscount << " total orders" << endl;

}
void order_Summary()
{
	//TIME FUNCTIONS
	auto start = chrono::system_clock::now();
	auto end = chrono::system_clock::now();
	int counter = 0, counter1 = 0;
	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);
	//TIME FUNCTIONS END
	ifstream ORDERS_DB;
	string line;
	string word;
	string lastline;
	vector <string> words;
	ORDERS_DB.open("C:/database/ORDERS_DB.txt");
	while (ORDERS_DB >> line)
	{
		counter++;
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
	}
	ORDERS_DB.close();
	ORDERS_DB.open("C:/database/ORDERS_DB.txt");
	while (ORDERS_DB >> line)
	{
		counter1++;
		istringstream iss(line);
		if (line != "")
		{
			while (getline(iss, word, ','))
			{
				words.push_back(word);
			}
		}
		if (counter == counter1)
			break;
		words.clear();
	}
	int rank = 0;
	cout <<YELLOW<< " -V- CONFIRMED ORDER " <<WHITE<< endl;
	cout << "Deal number is : " << order_number << endl;
	cout << "Order Date : " << ctime(&end_time) << endl;
	cout << "Check-in date : " << words[2] << "." << words[3] << "." << words[4] << endl;
	cout << "Check-out date : " << words[5] << "." << words[6] << "." << words[7] << endl;
	cout << "Asset Addres is : " << words[8] << endl;
	cout << " Number of guests is : " << words[9] << endl;
	cout << "____CHARGES____:" << endl;
	cout << "Total paid : " << words[11] << endl;
	cout << "Contact landlord:" << endl;
	cout << "Landlord's name: " << words[12] << endl;
	cout << "Landlord's mail: " << words[13] << endl;
	cout << "Landlord's phone: " << words[14] << endl;
	cout << "Please insert your rate (1-5) for the asset :" << endl;
	//cin << rank; //SHOULD BE FIXED 

}
void PAYMENT()
{
	cout <<MAGENTA<< "-----PAYMENT----" <<WHITE <<endl;
	string card_ownername;
	cout << "What is the cardowner's FIRST name ?" << endl;
	cin >> card_ownername;
	bool has_only_digits = true;

	while (has_only_digits == 0)
	{
		cout << "wrong input, please try again" << endl;
		cout << "What is the cardowner's first name ?" << endl;
		cin >> card_ownername;
		for (int n = 0; n < card_ownername.length(); n++)
		{
			if (isdigit(card_ownername[n]))
			{
				has_only_digits = false;
				break;
			}
			else
				has_only_digits = true;
		}
	}
	string cardtype;
	cout << "what is your card type ?  choose the correct :" << endl;
	cout << "1.Visa" << endl << "2.MasterCard" << endl << "3.American Express" << endl;
	cin >> cardtype;
	while (cardtype != "1" && cardtype != "2" && cardtype != "3")
	{
		cout << "Wrong choose inserted pleasetry again" << endl;
		cout << "what is your card type ?  choose the correct :" << endl;
		cout << "1.Visa" << endl << "2.MasterCard" << endl << "3.American Express" << endl;
		cin >> cardtype;
	}

	string cardnumber;

	switch (stoi(cardtype)) {
	case 1: cout << "as for your Visa card number please insert your card number(16 digits requiered):" << endl;
		cin >> cardnumber;
		break;       // and exits the switch
	case 2: cout << "as for your MasterCard  number please insert your card (16 digits requiered):" << endl;
		cin >> cardnumber;
		break;

	case 3: cout << "as for your American Express card number please insert your card number (16 digits requiered):" << endl;
		cin >> cardnumber;
		break;
	}
	while (cardnumber.length() < 16)
	{
		cout << "wrong card number inserted , 16 digits requiered";
		switch (stoi(cardtype)) {
		case 1: cout << "as for your Visa card number please insert your card number(16 digits requiered):" << endl;
			cin >> cardnumber;
			break;       // and exits the switch
		case 2: cout << "as for your MasterCard  number please insert your card number(16 digits requiered):" << endl;
			cin >> cardnumber;
			break;
		case 3: cout << "as for your American Express card number please insert your card number(16 digits requiered):" << endl;
			cin >> cardnumber;
			break;
		}
		cin >> cardnumber;
	}
	int month;
	int year;
	cout << "Please insert the expiration date MONTH :" << endl;
	cin >> month;
	while (month < 1 || month> 12)
	{
		cout << "wrong month inserted please try again:" << endl;
		cout << "Please insert the expiration date MONTH :" << endl;
		cin >> month;
	}
	cout << "Please insert the expiration date YEAR :" << endl;
	cin >> year;
	while (year < 2020)
	{
		cout << "your card had expired , please fix your choise" << endl;
		cin >> year;
	}
	cout << endl << "________PAYMENT SUMMARY________ " << endl
		<< "Card owner is: " << card_ownername << endl
		<< "Card type is: " << cardtype << endl;
	return;
}

int validDate(int day, int month, int year)
{
	//int month_days;
	//bool flag = false;;
	//int checkday = 1, checkmonth = 1, checkyear = 1;// áãé÷ä ùì ú÷éðåú äúàøéê
	//int maxdays = 0; //îùúðä àùø éëéì àú îñôø äéîéí äî÷ñéîìé áàåúå çåãù
	//if (year < 2020 || year>2099)
	//	checkyear = 0;// ùðä ùâåéä
	//switch (month)
	//{
	//case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	//	if (day <= 0 || day > 31)
	//	{
	//		checkday = 0;
	//		maxdays = 31;
	//	}
	//	break;
	//case 4: case 6: case 9: case 11:
	//	if (day < 0 || day>30)
	//	{
	//		checkday = 0;
	//		maxdays = 30;
	//	}
	//	break;
	//case 2:
	//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	//		if (day <= 0 || day > 29)
	//		{
	//			checkday = 0;
	//			maxdays = 29;
	//			flag = true;
	//		}
	//		else
	//		{
	//			if (day <= 0 || day > 28)
	//			{
	//				checkday = 0;
	//				maxdays = 28;
	//			}
	//		}
	//	break;
	//default:
	//	checkmonth = 0;
	//	if (day <= 0 || day > 31)
	//	{
	//		checkday = 0;
	//		maxdays = 31;
	//	}
	//	break;
	//}// switch 
	//if (checkyear == 1 && checkmonth == 1 && checkday == 1)
	//{
	//	if (flag == true)
	//		return (day + month_days * month);
	//}
	return 1;

}
