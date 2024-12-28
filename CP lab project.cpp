#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
int current_guest = 0;
fstream current_record,history, current_record_new,meal;
int customer_booked = 0;
const int  rooms = 108;
const int  floors = 8;
const int rooms_per_floor=14;
const int penthouse_floors = 2;
const int penthouse_rooms = 12;
string room_data[floors - 2][rooms_per_floor];
struct room {
	int floor;
	bool booking;	
}arr_room[rooms],penthouse_arr[penthouse_floors][penthouse_rooms];
struct customer {
	int customer_id = rand() % 10000;
	string customer_name;
	int time_duration;
	/*bool park;
	int num_park;*/
}arr_customer[rooms];
//string funct(int i,int j)
//{
//	string *prt_one = &room_data[i][j];
//	*prt_one = "Booked";
//	cout << "Booking completed successfully!\n";
//	return prt_one;
//}
void check_room_availability()
{
	for (int i = 0;i < floors - 2;i++) {
		cout << "Floor " << i + 1 << ": ";
		for (int j = 0;j < rooms_per_floor;j++) {
			cout << room_data[i][j] << setw(10);
		}
		cout << endl;
	}
}
void room_book()
{
	int j = 0, i = 0;
	cout << "Available rooms are:\n";
	for (int i = 0;i < floors-2;i++) {
		cout << "Floor:"<<i+1<<" ";
		for (int j = 0;j < rooms_per_floor;j++) {
			room_data[i][j] = to_string(j + 1);
			cout << room_data[i][j]<<" ";
		}
		cout << endl;
	}
cout << endl;
	for (int i = 0;i <=current_guest;i++)
	{
		if (i == current_guest)
		{
			int floor;
			cout << "Enter floor from 1 to 6:";
			cin >> floor;
			cout << "Enter your room :\n";
			int select_room;
			cin >> select_room;
			if (floor > 6 || (select_room > 14 || select_room < 1)) {
				cout << "Wrong floor!\n";
			}
			else {
				arr_room[i].booking = true;
				for (int i = 0;i < 6;i++)
				{
					for (int j = 0;j < 14;j++) {
						if (i + 1 == floor && j + 1 == select_room)
						{
							if (room_data[i][j] == "Booked")
							{
								cout << "Already booked!\n";
							}
							else if (room_data[floor - 1][select_room - 1] == "Booked") {
								cout << "Room is already booked!\n";
							}
							else {
								/*funct( i, j);*/
								room_data[i][j] = "Booked";
								cout << "Booking completed successfully!\n";
								customer_booked++;
							}
						}
					}
				}			
			}
		}
	}
}
string line,arr_line[3];
void classic_book()
{
	for (int i = 0;i < 3;i++)
	{
	for (int i = 0;i < current_guest + 1;i++) {
		if (i == current_guest) {
			cout << "Enter customer_id:" << current_guest+1<<": "<< arr_customer[current_guest].customer_id<<endl;
			cout << "Enter customer_name" << current_guest+1<<":";
			cin >> arr_customer[current_guest].customer_name;
			cout << "Enter days for stay :";
			cin >> arr_customer[current_guest].time_duration;
			if (arr_customer[current_guest].time_duration < 1)  cout << "Sorry!Your stay should be >=1";
			else {
				current_record.open("current_record.txt", ios::app);
				if (current_record.is_open()) {
					current_record << arr_customer[i].customer_id << " " << arr_customer[i].customer_name << "\n";
					cout << "Record saved successfully!";
				}
			}
		}
		current_record.close();
	}
	current_guest++;
	room_book();
}
void penthouse()
{
	cout << "Enter floors from(1-" << penthouse_floors << "): ";
	int floor;
	cin >> floor;
	cout << "Enter room from(1-" << penthouse_floors << "): ";
	int room;
	cin >> room;
	for (int i = 0;i < penthouse_floors;i++) 
	{
		for (int j = 0;j < penthouse_rooms;j++)
		{
			penthouse_arr[i][j].floor;
		}
	}
}
void bookings()
{
	cout << "1. Penthouse:\n";
	cout << "2. Classic:\n";
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
		penthouse();
	case 2:
		classic_book();
	}	
}
void room_delivery()
{
	cout << "Enter your floor:";
	int floor;
	cin >> floor;
	cout << "Enter your room:";
	int room;
	cin >> room;
	cout << "Your order has been placed\n";
}
const int max_members = 7;
//void dining_table()
//{
//	cout << "Enter your members:";
//	int members;
//	cin>> members;
//	if (members <= max_members)
//	{
//		for(int i=2;i<=7;i++)
//	}
//}
//void buffet()
//{
//
//}
void item(int price)
{
	cout << "Enter quantity:";
	int quantity;
	cin >> quantity;
	cout << "Total amount:" << price * quantity;
}
void meal()
{
	int price=0;
	cout << "***Menu***\n";
	cout << "1. Burger"<<setw(5)<<"$100"<<endl;
	cout << "2. Pasta\n" << setw(5) << "$200" << endl;
	cout << "3. Chicken\n" << setw(5) << "$300" << endl;
	cout << "4. Mutton\n" << setw(5) << "$400" << endl;
	cout << "5. Noodles\n" << setw(5) << "$100" << endl;
	cout << "6. Platter\n" << setw(5) << "$500" << endl;
	cout << "7. Tea\n" << setw(5) << "$50" << endl;
	cout << "8. Snacks\n" << setw(5) << "$100" << endl;
	cout << "9. Desserts\n" << setw(5) << "$300" << endl;
	cout << "10. Drinks\n" << setw(5) << "$100" << endl;
	int select;
	string food;
	cout << "Selection:";
	cin >> select;
	switch (select)
	{ 
	case 1:
		food = burger;
		price = 100;
		break;
	case 2:
		food = pasta;
		price = 200;
		break;
	case 3:
		food = chicken;
		price = 300;
		break;
	case 4: 
		price = 400;
		break;
	case 5:
		price = 100;
		break;
	case 6:
		price = 500;
		break;
	case 7:
		price = 50;
		break;
	case 8:
		price = 100;
		break;
	case 9:
		price = 300;
		break;
	case 10:
		price = 100;
		break;
	default:
		break;
	}
	item(price);
}
void history_funct(customer c)
{
	history.open("history.txt", ios::app);
	if (history.is_open()) {
		history << c.customer_id << " " << c.customer_name << "\n";
	}
	else {
		cout << "File not opened!\n";
	}
	history.close();
}
void meal_options()
{
	cout << "1. Room delivery    $500\n";
	cout << "2. Dining table     $250\n"; 
	cout << "3. Buffet           $200\n";
	cout << " 4. Take away       $180\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		room_delivery();
	//case 2:
	//	/*dining_table();*/
	//case 3:
	}
	meal();
}
void delete_record(customer c)
{
	current_record_new.open("current_record_new.txt", ios::app);
	if (current_record_new.is_open()) {
		current_record_new << c.customer_id<<" "<<c.customer_name;
	}
	else cout << "Error file not opened!";
	current_record_new.close();
}
int z = 0;
void check_out()
{
	cout << "Enter customer ID for check out:";
	int input_ID;
	cin >> input_ID;
	string line;
	customer c;
	current_record.open("current_record.txt", ios::in);
	if (current_record.is_open()) {
		while (getline(current_record, line)) {
			stringstream ss(line);
			ss >> c.customer_id; 
			ss >> c.customer_name; 
			if (c.customer_id == input_ID) {
				history_funct(c);
				delete_record(c);
			}
			else cout << "ID not found";
		}
	}
	else cout << "Error file not opened!";
	current_record.close();
	const char* current_record = "current_record.txt";
	const char* current_record_new = "current_record_new.txt";
	remove("current_record.txt");
	rename("current_record.txt", "current_record_new.txt");
}
void bill(int customer_id, int stay_duration, float room_rate, float meal_charge, float service_fee)
{
	float total = (stay_duration * room_rate) + meal_charge + service_fee;
	cout << "Customer ID:" << customer_id << endl;
	cout << "Stay duration:" << stay_duration << endl;
	cout << "Room rate per room:" << room_rate << endl;
	cout << "Total meal charge:" << meal_charge << endl;
	cout << "Additional service fee:" << service_fee<< endl;
	cout << "--------------\n";
	cout << "Total Bill :"<<total<<endl;
}
void guest()
{
	string cont;
	do {
		cout << "---Menu---\n";
		cout << "1. Check Room Availability\n";
		cout << "2. Book a Room\n";
		cout << "3. Manage Guest Details\n";
		cout << "4. Meal\n";
		cout << "5. Check in a guest\n";
		cout << "6. Check out a Guest\n";
		cout << "7. Generate Bill for Stay\n";
		cout << "8. View/Edit Reservations\n";
		cout << "9. Manage Special Requests\n";
		cout << "10. Log Out\n";
		cout << "Enter your services:";
		int services;
		cin >> services;
		switch (services)
		{
		case 1:
			check_room_availability();
			break;
		case 2:
			bookings();
			break;
		/*case 3:*/

		case 4:
			meal_options();
			break;
		case 6:
			check_out();
			break;
		case 7:
			bill(customer_id, stay_duration, room_rate, meal_charge, service_fee);
		}
		cout << "Press any key to continue :";
		cin >> cont;
	} while (cont!=" ");
}
int main()
{
	srand(time(0));
	cout << "1. Staff \n";
	cout << "2. Guest \n";
	int choices;
	cout << "Enter choice:";
	cin >> choices;
	switch (choices)
	{
	case 1:
		cout << "none";
	case 2:
		guest();
	}

}

