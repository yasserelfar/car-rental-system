#include"Functions.h"
int main()
{
	
	// reading data from files 
	idx_read();
	car_read();
	cust_read();
	rtl_read();
	admin_read();
	///////////////////////////

	string choice;
	do
	{
		bool found;
		do
		{
			string use, pass;
			cout << "Enter user name :   ";
			cin >> use;
			cout << "Enter password  :   ";
			cin >> pass;
			found = false;
			for (size_t i = 0; i < adm_size; i++)
			{

				if (use == arr_admin[i].usr_name && pass == arr_admin[i].password)
				{
					found = true;
					break;;
				}
			}
			if (found)
			{
				admin_c();
				break;
			}

			for (size_t i = 0; i < cust_idx; i++)
			{
				if (use == arr_cust[i].us_name && pass == arr_cust[i].pass)
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				cout << "Wait for customer functions\n";
				break;
			}
			else
			{
				cout << "The user name or password is incorrect\n";
			}
		} while (!found);  // he will continue untill he 
		cout << "Do you want to Exit from the program ? (y/n)   :   ";
		cin >> choice;
	} while (choice == "n" || choice == "N");


	//writing data in files
	car_write();
	cust_write();
	rtl_write();
	idx_write();
	///////////////////////
	
	return 0;
}