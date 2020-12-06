#define  _CRT_SECURE_NO_WARNINGS
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

void welcome();
void REG();
void LOG();
void landlordMENU(string curr_id);
void Landlordchoose(int choose, string curr_id);
void Renterchoose(int choose, string curr_id);
void renterMENU(string curr_id);
void EXIT();
void EDIT_PERSONAL_DETAILS(string curr_id);


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
	
	while((choose!=1)||(choose!=2))
	{
		cout<<"Wrong input inserted , please try again";
		cout << MAGENTA << "please choose if you want to register or to log in : " << endl << "1.REGISTER" << endl << "2.LOG-IN" << endl;
		cin>>choose;
	}

	if (choose == 1)
		REG();
	if (choose == 2)
		LOG();
}
void REG()
{
	int choose;
	cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
	cin >> choose;
	while((choose!=1)||(choose!=2))
	{
		cout<<"Wrong input inserted , please try again";
		cout << GREEN << "please choose if you want to to Register as a : " << WHITE << endl << "1.LANDLORD" << endl << "2.RENTER" << endl;
		cin>>choose;
	}
	
	string curr_id;
	if (choose == 1)
	{//REGISTER AS LANDLORD
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
		BDusersf.open("C:/USERSDATA/newC.txt", ios::app); // opening the file
		BDusersf << "Landlord" << ',' <<
			lUser.id << ',' <<
			lUser.firstName << ',' <<
			lUser.lastName << ',' <<
			lUser.password << ',' <<
			lUser.email_address << ',' <<
			lUser.phoneNumber << ',' <<
			lUser.address << '\n';
		BDusersf.close();
	}
	if (choose == 2)
	{//REGISTER AS RENTER
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
		BDusersf.open("C:/USERSDATA/newC.txt", ios::app); // opening the file
		BDusersf << "Renter" << ',' <<
			rUser.id << ',' <<
			rUser.firstName << ',' <<
			rUser.lastName << ',' <<
			rUser.password << '\n';
		BDusersf.close();
	}
	if (choose == 1)
		landlordMENU(curr_id);
	if (choose == 2)
		renterMENU(curr_id);
}
void LOG()
{
	string id;
	string password;
	string line;
	string curr_type, curr_password;
	int i = 0;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	string curr_id;
	while (1)
	{
		DBusersf.open("C:/USERSDATA/newC.txt"); // opening the file
		cout << "Enter your id: ";
		cin >> id;
		cout << "Enter your password: ";
		cin >> password;
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
			curr_type = words[0];
			curr_password = words[4];
			curr_id = words[1];
			if (id == curr_id && password == curr_password)
			{
				cout << "USER EXIST , YOU WILL DIRECTED TO RIGHT MENU " << endl;
				if (curr_type == "Renter")
				{
					curr_id = id;
					
					DBusersf.close();
					renterMENU(curr_id);
				}
				if (curr_type == "Landlord")
				{
					curr_id = id;
					DBusersf.close();
					landlordMENU(curr_id);
				}
			}
			words.clear();
		}
		cout << "USER DOES NOT EXIST, TRY AGAIN" << endl;
		DBusersf.close();
	}
}
void EDIT_PERSONAL_DETAILS(string curr_id)
{
	
	
	string line;
	ifstream DBusersf;//name decleartion
	string word;
	vector <string> words;
	DBusersf.open("C:/USERSDATA/newC.txt");
	size_t pos;
	size_t len;
	
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
		
		if (words[1] == curr_id)
		{

			while (getline(DBusersf, line))
			{
				len= curr_id.length();
				pos = line.find(curr_id);
				if (pos != string::npos)
				{

					line.replace(pos, len, "ada");
				}
			}
			/*if (words[0] == "Landlord")
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
				DBusersf.close();
			}*/



		}
		words.clear();
	}


}
	

void landlordMENU(string curr_id)
{
	
	cout << GREEN << "Hello landlord please choose the what you want to do for menu " << WHITE << endl;
	int choose;
	cout << BLUE << "1.ADD NEW ASSETS " << endl << "2.UPDATE EXIST ASSETS" << endl << "3.EDIT PERSONAL DATA " << endl << "4.REPORTS" << endl << "5.Choose another option" << WHITE << endl;
	cin >> choose;
	while((choose!=1)||(choose!=2)||(choose!=3)||(choose!=4)||(choose!=5))
	{
		cout<<"Wrong input , please try again"<<endl;
		cout << BLUE << "1.ADD NEW ASSETS " << endl << "2.UPDATE EXIST ASSETS" << endl << "3.EDIT PERSONAL DATA " << endl << "4.REPORTS" << endl << "5.Choose another option" << WHITE << endl;
		cin>>choose;
	}
	
	if (choose <= 4)
		Landlordchoose(choose, curr_id);
	cout << GREEN << "Choose anoter option : " << endl;
	cout << RED << "1.BACK " << endl << "2.MENU" << endl << "3.LOGOUT" << endl << "4.EXIT" <<endl<< "5.CONTINUE AS RENTER" << WHITE << endl;
	cout << "Your choose is :" << endl;
	cin >> choose;
	//if (choose == 1)
	//{

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
{
	cout << GREEN << "Hello renter please choose the what you want to do for menu " << WHITE << endl;
	int choose;
	cout << BLUE << "1.SEARCH AVILABLE ASSETS " << endl << "2.ORDER HISTORY" << endl << "3.EDIT PERSONAL DATA " << endl << "4.Choose another option" << WHITE << endl;
	cin >> choose;
	while((choose!=1)||(choose!=2)||(choose!=3)||(choose!=4)||(choose!=5))
	{
		cout<<"Wrong input , please try again"<<endl;
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
{
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
{
	if (choose == 1)
	{
		cout << YELLOW << "ADD NEW ASSETS : //////" << WHITE << endl;
	}
	if (choose == 2)
	{
		cout << YELLOW << "UPDATE EXIST ASSETS : //////" << WHITE << endl;
	}
	if (choose == 3)
	{
		EDIT_PERSONAL_DETAILS(curr_id);
	}
	if (choose == 4)
	{
		cout << YELLOW << "3.REPORTS: //////" << WHITE << endl;
	}
}
void EXIT()
{
	cout << "goodbye" << endl;
	exit(1);
}
