#pragma once
# include "variables.h"
#include <iomanip>


///////////////////////////////////////writing functions in files//////////////////////////////

// write in the car file 
void car_write()
{
	f_car.open("car.txt", ios::out);
	for (int ctr = 0; ctr < car_index; ctr++)
	{
		f_car << arr_car[ctr].type << "#" << arr_car[ctr].L_P_N << "#" << arr_car[ctr].cost.c_hour << "#"
			<< arr_car[ctr].cost.c_day << "#" << arr_car[ctr].cost.c_week << "#" << arr_car[ctr].statue << "#"
			<< arr_car[ctr].cr_branch << "#" << arr_car[ctr].cust_id << "#" << arr_car[ctr].dat.rc_day << "#" << arr_car[ctr].dat.rc_month << "#"
			<< arr_car[ctr].dat.rc_year << "#" << arr_car[ctr].dat.rtn_day << "#" << arr_car[ctr].dat.rtn_month << "#"
			<< arr_car[ctr].dat.rtn_year << "#"  << arr_car[ctr].dat.num_hours << "#"
			<< arr_car[ctr].rtn_branch << "\n";
	}
	f_car.close();
}

// write in the customer file
void cust_write()
{
	f_cust.open("customer.txt", ios::out);
	for (int ctr = 0; ctr < cust_idx; ctr++)
	{
		f_cust << arr_cust[ctr].f_name << "#" << arr_cust[ctr].l_name << "#" << arr_cust[ctr].id << "#"
			<< arr_cust[ctr].age << "#" << arr_cust[ctr].cr_number << "#" << arr_cust[ctr].ph_number << "#"
			<< arr_cust[ctr].us_name << "#" << arr_cust[ctr].pass << "\n";
	}
	f_cust.close();
}

// write in the rental file 
void rtl_write()
{
	f_rentals.open("rentals.txt", ios::out);
	for (int ctr = 0; ctr < rtl_idx; ctr++)
	{
		f_rentals << arr_rtl[ctr].cust_index << "#" << arr_rtl[ctr].car_LPN << "#" << arr_rtl[ctr].car_type << "#" <<  arr_rtl[ctr].statue << "#"
			<< arr_rtl[ctr].dat.rc_day << "#" << arr_rtl[ctr].dat.rc_month << "#" << arr_rtl[ctr].dat.rc_year << "#"
			<< arr_rtl[ctr].dat.rtn_day << "#" << arr_rtl[ctr].dat.rtn_month << "#" << arr_rtl[ctr].dat.rtn_year << "#"
			<< arr_rtl[ctr].dat.num_hours << "#" << arr_rtl[ctr].rental_cost << "\n";

	}
	f_rentals.close();
}

// write in the index file 
void idx_write()
{
	index.open("index.txt", ios::out);
	index << car_index;
	index << "\n";
	index << cust_idx;
	index << "\n";
	index << rtl_idx;
	index.close();
}

//______________________________________________________________________________________//

/////////////////////////////////////////reading functions from files///////////////////////////////////

//read the index file 
void idx_read()
{
	index.open("index.txt", ios::in);
	index >> car_index;
	index >> cust_idx;
	index >> rtl_idx;
	index.close();
}

//read from car file
void car_read()
{
	f_car.open("car.txt", ios::in);
	for (int ctr = 0; ctr < car_index; ctr++)
	{

		getline(f_car, arr_car[ctr].type, '#');
		getline(f_car, arr_car[ctr].L_P_N, '#');

		getline(f_car, sti, '#');  arr_car[ctr].cost.c_hour = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].cost.c_day = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].cost.c_week = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].statue = stoi(sti);

		getline(f_car, arr_car[ctr].cr_branch, '#');
		getline(f_car, arr_car[ctr].cust_id, '#');


		getline(f_car, sti, '#');  arr_car[ctr].dat.rc_day = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.rc_month = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.rc_year = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.rtn_day = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.rtn_month = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.rtn_year = stoi(sti);
		getline(f_car, sti, '#');  arr_car[ctr].dat.num_hours = stoi(sti);

		getline(f_car, arr_car[ctr].rtn_branch);

	}
	f_car.close();
}

//read from customer file 
void cust_read()
{
	f_cust.open("customer.txt", ios::in);
	for (int ctr = 0; ctr < cust_idx; ctr++)
	{
		getline(f_cust, arr_cust[ctr].f_name, '#');
		getline(f_cust, arr_cust[ctr].l_name, '#');
		getline(f_cust, arr_cust[ctr].id, '#');

		getline(f_cust, sti, '#');   arr_cust[ctr].age = stoi(sti);

		getline(f_cust, arr_cust[ctr].cr_number, '#');
		getline(f_cust, arr_cust[ctr].ph_number, '#');
		getline(f_cust, arr_cust[ctr].us_name, '#');
		getline(f_cust, arr_cust[ctr].pass);

	}
	f_cust.close();
}

//read from the rentals file
void rtl_read()
{
	f_rentals.open("rentals.txt", ios::in);
	for (int ctr = 0; ctr < rtl_idx; ctr++)
	{
		getline(f_rentals, sti, '#'); arr_rtl[ctr].cust_index = stoi(sti);

		getline(f_rentals, arr_rtl[ctr].car_LPN, '#');
		getline(f_rentals, arr_rtl[ctr].car_type, '#');

		getline(f_rentals, sti, '#'); arr_rtl[ctr].statue = stoi(sti);

		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rc_day = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rc_month = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rc_year = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rtn_day = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rtn_month = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.rtn_year = stoi(sti);
		getline(f_rentals, sti, '#'); arr_rtl[ctr].dat.num_hours = stoi(sti);
		getline(f_rentals, sti); arr_rtl[ctr].rental_cost = stoi(sti);

	}
	f_rentals.close();
}

// read from admins file 
void admin_read()
{
	f_admin.open("admin.txt", ios::in);
	for (int ctr = 0; ctr < adm_size; ctr++) //  adm_size is the numder of admins
	{
		getline(f_admin, arr_admin[ctr].usr_name, '#');
		getline(f_admin, arr_admin[ctr].password);

	}
	f_admin.close();
}

//___________________________________________________________________________________________________//

////////////////////////////////////////////adding function/////////////////////////////////////////////

//add new car
void add_car()
{
	string choice;
	do
	{
		cout << "******************************************\n";
		cout << "\nEnter type of the car                      :    ";
		cin >> arr_car[car_index].type; 
		cout << "\nEnter the licence plat number              :    "; 
		cin >> arr_car[car_index].L_P_N;
		cout << "\nEnter the cost off hiring  for an hour     :    ";
		cin >> arr_car[car_index].cost.c_hour;
		cout << "\nEnter the cost of hiring for a day         :    ";
		cin >> arr_car[car_index].cost.c_day;
		cout << "\nEnter the cost of hiring for a week        :    ";
		cin >> arr_car[car_index].cost.c_week;
		cout << "\nIs the car frree or not?\n" 
		     << "(1 --> avalible /0 --> not avalible)       :    ";
		cin >> arr_car[car_index].statue;
		if (arr_car[car_index].statue == 0) // this the car isn't free to rental (which mean that some one hire it)
		{
			cout << "\nEnter the customer id who hired th car     :    ";
			cin >> arr_car[car_index].cust_id;
			
			cout << "\nEnter the start day of hiring              :    ";
			cin >> arr_car[car_index].dat.rc_day;
			cout << "\nEnter the start month of hiring            :    ";
			cin >> arr_car[car_index].dat.rc_month;
			cout << "\nEnter the start year of the hiring         :    ";
			cin >> arr_car[car_index].dat.rc_year;
			cout << "\nEnter the end day of hiring                :    ";
			cin >> arr_car[car_index].dat.rtn_day;
			cout << "\nEnter the end month of hiring              :    ";
			cin >> arr_car[car_index].dat.rtn_month;
			cout << "\nEnter the end year of the hiring           :    ";
			cin >> arr_car[car_index].dat.rtn_year;
			// now we will consider if he rent the car for only 1 day
			if (arr_car[car_index].dat.rc_day == arr_car[car_index].dat.rtn_day
				&& arr_car[car_index].dat.rc_month == arr_car[car_index].dat.rtn_month
				&& arr_car[car_index].dat.rc_year == arr_car[car_index].dat.rtn_year)
			{
				cout << "\nEnter the number of rental hours           :    ";
				cin >> arr_car[car_index].dat.num_hours;
			}
			
			cout << "\nEnter the return branch of  the car        :    ";
			cin >> arr_car[car_index].rtn_branch;

		}
		else
		{
			cout << "\nEnter the cuurent branch                   :    ";
			cin >> arr_car[car_index].cr_branch;

		}

		car_index++;
		cout << "\nDo you want to add new car ? (y/n)         :    ";
		cin >> choice;
	} while (choice == "y" || choice == "Y");
}

//add new customer
void add_customer()
{
	string choice;
	do
	{
		cout << "*********************************************************\n";
		cout << "\nEnter the first name            :     ";
		cin >> arr_cust[cust_idx].f_name;
		cout << "\nEnter the last  name            :     ";
		cin >> arr_cust[cust_idx].l_name;
		cout << "\nEnter  national id              :     ";
		cin >> arr_cust[cust_idx].id;
		cout << "\nEnter the age                   :     ";
		cin >> arr_cust[cust_idx].age;
		cout << "\nEnter the credit card nuumber   :     ";
		cin >> arr_cust[cust_idx].cr_number;
		cout << "\nEnter the phone number          :     ";
		cin >> arr_cust[cust_idx].ph_number;
		cout << "\nEnter the customer user name    :     ";
		cin >> arr_cust[cust_idx].us_name;
		cout << "\nEnter the password              :     ";
		cin >> arr_cust[cust_idx].pass;
		cout << "\n\nThe customer is successfuly added \n";
		cout << "\nDo you want to add new one? (y/n)     ";
		cin >> choice;
		cust_idx++;
	} while (choice == "y" || choice == "Y");
}

//___________________________________________________________________________________________//

////////////////////////////////////////delete car//////////////////////////////////
void delet() {
	string ch;   //choice
	do
	{
		if (car_index = 0)
		{
			cout << "Ther is no car to delete\n";
			break;
		}
		string lp; // licence plate number
		bool found = false;
		cout << "Enter licence plate number\n";
		cin >> lp;
		for (size_t i = 0; i < car_index; i++)
		{
			if (lp == arr_car[i].L_P_N) {
				for (size_t j = i; j < car_index - 1; j++)
				{
					arr_car[j] = arr_car[j + 1];
					cout << "Sucessfully deleted \n";
					found = true;
					break;
				}
				
			}
		}
		if (!found)
			cout << "Not found\n";
		car_index--;
		cout << "Do you want to delete another one? (y/n)\n";
		cin >> ch;
	} while (ch == "y" || ch == "Y");
}

//___________________________________________________________________________________________//

////////////////////////////////////////////////display car/////////////////////////////

void dis() {
	bool found;
	string lp; // licence plate number
	char choice;
	int x = 0;
	do
	{
		if (car_index == 0)
		{
			cout << "There is no cars to display\n";
				break;
		}
		else {
			cout << "If you want to view spacific car press    1\n";
			cout << "If you want to view available cars press  2\n";
			cout << "If you want to view rented cars press     3\n";
			cout << "If you want to view all cars press        4\n";
			cin >> x;
			if (x == 1) {
				found = false;
				cout << "Enter licence plate number\n";
				cin >> lp;
				for (size_t i = 0; i < car_index; i++)
				{
					if (lp == arr_car[i].L_P_N)
					{
						found = true;
						cout << left << setw(10) << "#Type" << setw(15) << "#Hour Cost" << setw(15) << "#Day Cost" << setw(15) << "#Week Cost" << setw(15) << "#State" << setw(20) << "Return Branch" << setw(10) << "#L.P.N" << setw(15) << "Customer ID" << setw(20) << "#current Branch" << setw(20) << "#Rented from" << "#To " << endl;
						cout << left << setw(10) << arr_car[i].type <<
							setw(15) << arr_car[i].cost.c_hour
							<< setw(15) << arr_car[i].cost.c_day
							<< setw(15) << arr_car[i].cost.c_week;
						if (arr_car[i].statue == 0)
						{
							cout << left << setw(15) << "Not avilable" << setw(20) << arr_car[i].rtn_branch <<
								setw(10) << arr_car[i].L_P_N <<
								setw(15) << arr_car[i].cust_id << setw(20) << "---------------" << setw(2) << arr_car[i].dat.rc_day << "/" << setw(2) << arr_car[i].dat.rc_month << "/" << setw(14) << arr_car[i].dat.rc_year
								<< setw(2) << arr_car[i].dat.rtn_day << "/" << setw(2) << arr_car[i].dat.rtn_month << "/" << arr_car[i].dat.rtn_year << endl;
						}
						else
						{

							cout << left << setw(15) << "Avilable" << setw(20) << "--------" << setw(10) << arr_car[i].L_P_N << setw(15) << "-------" <<
								setw(20) << arr_car[i].cr_branch << setw(20) << "-----------" << "----------" << endl;
						}
						break;
					}
				}
				if (!found) cout << "Not Found\n";
			}
			else if (x == 2)
			{
				found = false;
				for (size_t i = 0; i < car_index; i++)
				{
					if (arr_car[i].statue == 1) {
						if (!found) {  // to show this only one time
							cout << "********************************** AVAILABLE CARS *******************************\n";
						}
						cout << left << setw(10) << "#Type" << setw(15) << "#Hour Cost" << setw(15) << "#Day cost" << setw(15) << "#Week Cost" << setw(20) << "#Current Branch" << setw(10) << "#L.P.N" << endl;
						found = true;
						cout << left << setw(10) << arr_car[i].type << setw(15)
							<< arr_car[i].cost.c_hour << setw(15)
							<< arr_car[i].cost.c_day << setw(15)
							<< arr_car[i].cost.c_week << setw(20)
							<< arr_car[i].cr_branch <<
							setw(10) << arr_car[i].L_P_N << endl;
					}

				}
				if (!found) cout << "There is no available cars\n";
			}
			else if (x == 3)
			{
				found = false;
				for (int i = 0; i < car_index; i++)
				{
					if (arr_car[i].statue == 0) {
						if (!found) {  // to show this only one time
							cout << "********************************** RENTED CARS *******************************\n";
						}
						cout << left << setw(10) << "Type" << setw(15) << "#Hour Cost" << setw(15) << "#Day Cost" << setw(15) << "#Week Cost" << setw(20) << "#Return Branch" << setw(10) << "#L.P.N" << setw(15) << "#Customer ID" << setw(20) << "#Rented from" << "#To " << endl;
						found = true;
						cout << left << setw(10) << arr_car[i].type <<
							setw(15) << arr_car[i].cost.c_hour <<
							setw(15) << arr_car[i].cost.c_day <<
							setw(15) << arr_car[i].cost.c_week <<
							setw(20) << arr_car[i].rtn_branch <<
							setw(10) << arr_car[i].L_P_N <<
							setw(15) << arr_car[i].cust_id << setw(2) << arr_car[i].dat.rc_day << "/" << setw(2) << arr_car[i].dat.rc_month << "/" << setw(14) << arr_car[i].dat.rc_year
							<< setw(2) << arr_car[i].dat.rtn_day << "/" << setw(2) << arr_car[i].dat.rtn_month << "/" << arr_car[i].dat.rtn_year << endl;

					}
				}
				if (!found) cout << "Ther is no rented cars\n";
			}
			else if (x == 4)
			{
				found = false;
				cout << "************************************ ALL CARS *********************************\n";

				cout << left << setw(10) << "#Type" << setw(15) << "#Hour" << setw(15) << "#Day Cost" << setw(15) << "#Week Cost" << setw(15) << "#State" << setw(20) << "#Return Branch" << setw(10) << "#L.P.N" << setw(15) << "#Customer ID" << setw(20) << "#crunt branch" << setw(20) << "#Rented from" << "#To " << endl;
				for (size_t i = 0; i < car_index; i++)
				{


					cout << left << setw(10) << arr_car[i].type <<
						setw(15) << arr_car[i].cost.c_hour
						<< setw(15) << arr_car[i].cost.c_day
						<< setw(15) << arr_car[i].cost.c_week;
					if (arr_car[i].statue == 0)
					{
						cout << left << setw(15) << "Not avilable" << setw(20) << arr_car[i].rtn_branch <<
							setw(10) << arr_car[i].L_P_N <<
							setw(15) << arr_car[i].cust_id << setw(20) << "---------------" << setw(2) << arr_car[i].dat.rc_day << "/" << setw(2) << arr_car[i].dat.rc_month << "/" << setw(14) << arr_car[i].dat.rc_year
							<< setw(2) << arr_car[i].dat.rtn_day << "/" << setw(2) << arr_car[i].dat.rtn_month << "/" << arr_car[i].dat.rtn_year << endl;
					}
					else
					{
						cout << left << setw(15) << "Avilable" << setw(20) << "--------" << setw(10) << arr_car[i].L_P_N << setw(15) << "-------" <<
							setw(20) << arr_car[i].cr_branch << setw(20) << "-----------" << "----------" << endl;
					}

				}
			}


		}
		cout << "Do you want to Display more (y/n)";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

//___________________________________________________________________________________________//

///////////////////////////////////admin choise///////////////////////////////////
void admin_c()
{
	do {
		int num;
		cout << "****************** WELCOME To Admin Department*******************\n";
		cout << "If you want to add new car,           Enter    1     :\n";
		cout << "If you want to add new customer,      Enter    2     :\n";
		cout << "If you want to Delete car,            Enter    3     :\n";
		cout << "If you want to Disply,                Enter    4     :\n";
		cout << "If you want to Log out,               Enter    5     :\n";
		cin >> num;

		if (num == 1)
			add_car();
		else if (num == 2)
			add_customer();
		else if (num == 3)
			delet();
		else if (num == 4)
			dis();
		else if (num == 5)
		{
			cout << "Thank You\n";
			break;
		}
		else cout << "Invalid choice\n";
	} while (true);
}
//___________________________________________________________________________________________//