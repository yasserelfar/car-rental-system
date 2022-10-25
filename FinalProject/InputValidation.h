#pragma once
#include <iostream>
#include <fstream>
#include <iomanip> // contain setw() function for design
#include <string>
#include <algorithm>  // contain ( all_of ) function
#include <cctype>    // contain functions which determining if the characters entered are numbers or letters or whitespace....

using namespace std;


void getCarType(string &st)
{
	const int num_of_CarType = 5;                // number of avaliabe different car types ------> "note if you modify this constant you should add new type in the (car_types) file"
	string carTypeArray[num_of_CarType];         // array of strings to store these types
	fstream carType;                             // the file of car types ----> "note we can only modify in this file by hand"
	carType.open("car_types.txt", ios::in);
	for (int i = 0; i < num_of_CarType; i++)
	{
		getline(carType, carTypeArray[i]);
		cout << "TO add a new car from type--> " << left << setw(30) << carTypeArray[i] << "Enter number " << i + 1 << "\n";
	}
	carType.close();
	cout << endl;  // for design only.
	string choise;
	cout << "Enter your choice:  ";
	do
	{
		getline(cin, choise);
		if (all_of(choise.begin(), choise.end(), [](char ch) {return (isdigit(ch)); }) // check if each character in the choice string is number or only
			&& choise.size() == 1 // check if the size of choice string equal 1 or not 
			&& choise[0] != '0'   // to verify that the input is only between 1 --> 9
			)
		{
			int a = stoi(choise); // here we convert the string choise to integar
			st = carTypeArray[a - 1];  //we make the type of the car in our car_arrays equal carTypeArray[our integar - 1]
			break;
		}
		else
		{
			cout << "\aPlease Enter valid choice between \"1\" and \"9\" \n";
			cout << "\"Hint\"---> If you leave spaces please don't leave it\n";
		}
	} while (true);
}

void getCarL_P_N(string &st)
{
	cout << "Enter car license plate number (3 or 4 digits only) -->the first digit not 0\n";
	do
	{
		getline(cin, st);
		if (all_of(st.begin(), st.end(), [](char ch) {return (isdigit(ch)); }) // check if each character in the st string is number or only
			&& st.size() >= 3 && st.size() <= 4  // check if the size of st string equal 3 , 4 or not 
			&& st[0] != '0'   // to verify that the input is only between 1 --> 9
			)
		{
			break;
		}
		else {
			cout << "\aPlease Enter valid car license plate number (3 or 4 digits only) -->the first digit not 0 \n";
			cout << "\"Hint\"---> If you leave spaces please don't leave it\n";
		}
	} while (true);
}