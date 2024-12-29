#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
int current_guest = 0;
fstream current_record,history, current_record_new,meal,database, room_file;;
int customer_booked = 0;
int price_per_room = 10000;
const int  rooms = 108;
const int  floors = 8;
const int rooms_per_floor=14;
const int penthouse_floors = 2;
const int penthouse_rooms = 12;
const int max_guests = 100;
const float room_rate  = 50000.2;
const float service_fee = 800.1;
string room_data[floors - 2][rooms_per_floor];
struct room {
	int floor;
	int room;
	bool booking;	
}arr_room[floors][rooms_per_floor],penthouse_arr[penthouse_floors][penthouse_rooms];
struct customer {
	int customer_id;
	string customer_name;
	int time_duration;
	float meal_charges;
	room Room;
}guests[max_guests],arr_customer[rooms];
//string funct(int i,int j)
//{
//	string *prt_one = &room_data[i][j];
//	*prt_one = "Booked";
//	cout << "Booking completed successfully!\n";
//	return prt_one;
//}
void initializerooms()
{
	cout << "Available rooms are:\n";
	for (int i = 0;i < floors - 2;i++) {
		for (int j = 0;j < rooms_per_floor;j++) {
			arr_room[i][j].floor = i + 1;
			arr_room[i][j].room = j + 1;
			arr_room[i][j].booking = false;
		}
	}
}
void check_room_availability()
{
	cout << "Available rooms are:\n";
	for (int i = 0;i < floors - 2;i++) {
		cout << "Floor:" << i + 1 << " ";
		for (int j = 0;j < rooms_per_floor;j++) {
			if (arr_room[i][j].booking == true) arr_room[i][j].room = 0;
			cout << arr_room[i][j].room<<" ";
		}
		cout << endl;
	}
}
void room_book()
{
		for (int i = 0;i <= current_guest;i++)
		{
			customer* guest = &guests[i];
			cout << "Your customer ID is : ";
			guest->customer_id = rand()% 10000 + 1;
			cout << guest->customer_id;
			cout << "Enter name: ";
			cin>> guest->customer_name;
			cout << "Enter days for stay:";
			cin >> guest->time_duration;
			guest->meal_charges = 0;
				int floor_input, room_input;
				cout << "Enter floor from 1 to 6:";
				cin >> floor_input;
				cout << "Enter your room :\n";
				cin >> room_input;
				if (floor_input > floors || room_input > rooms_per_floor || room_input < 1) {
					cout << "Wrong floor!\n";
				}
				if (arr_room[floor_input - 1][room_input - 1].booking == true) {
					cout << "Room already booked.\n";
				}
				else {
					arr_room[floor_input - 1][room_input - 1].booking = true;
					guest->Room.floor= floor_input;
					guest->Room.room = room_input;
					guest->Room.booking = true;
					cout << "Room booked successfully.\n";
				}
				room_file.open("room_file.txt", ios::app);
				if (room_file.is_open()) {
					room_file << guest->customer_id << " " << guest->customer_name << " "<< guest->time_duration<<" "<< guest->meal_charges<<" "<< guest->Room.floor << " " << guest->Room.room << endl;
				}

				/*else {
					arr_room.booking = true;
					for (int i = 0;i < 6;i++)
					{
						for (int j = 0;j < 14;j++) {
							if (i + 1 == arr_room.floor && j + 1 == arr_room.room)
							{
								if (room_data[i][j] == "Booked")
								{
									cout << "Already booked!\n";
								}
								else if (room_data[arr_room.floor - 1][arr_room.room - 1] == "Booked") {
									cout << "Room is already booked!\n";
								}
								else {
									room_data[i][j] = "Booked";
									cout << "Booking completed successfully!\n";
									customer_booked++;
								}
							}
						}
					}
					for (int i = 0;i < floors - 2;i++) {
						cout << "Floor " << i + 1 << ": ";
						for (int j = 0;j < rooms_per_floor;j++) {
							cout << room_data[i][j] << setw(10);
						}
						cout << endl;
					}
				}*/
			
		}
}
string line,arr_line[3];
void manage_guest_details()
{
	if (current_guest >= max_guests) {
		cout << "Maximum guest capacity reached.\n";
	}
	else {
		customer* guest = &guests[current_guest];
		guest->customer_id = rand() % 10000 + 1;
		cout << "Enter customer name:";
		cin.ignore();
		getline(cin, guest->customer_name);
		cout << "Enter days for stay:";
		cin >> guest->time_duration;
		guest->meal_charges = 0;
		cout << "Guest details saved successfully!\n";
		current_guest++;
	}
}
void checkIN_guest()
{
	bool Isbook = false;
	int input_Id;
	cout << "Enter guest ID: ";
	cin >> input_Id;
	for (int i = 0; i < current_guest; i++) {
		if (guests[i].customer_id == input_Id) {
			cout << "Check-in successful for guest " << guests[i].customer_name << ".\n";
			Isbook = true;
		}
	}
	if(Isbook=false)  cout << "Guest not found.\n";	
}
//void classic_book()
//{
//			    for (int i = 0;i < 3;i++)
//				{
//					for (int i = 0;i < current_guest + 1;i++) {
//						if (i == current_guest) {
//							cout << "Your customer_id is:" << current_guest + 1 << ": " << arr_customer[current_guest].customer_id << endl;
//							cout << "Enter customer_name" << current_guest + 1 << ":";
//							cin >> arr_customer[current_guest].customer_name;
//							cout << "Enter days for stay :";
//							cin >> arr_customer[current_guest].time_duration;
//							if (arr_customer[current_guest].time_duration < 1)  cout << "Sorry!Your stay should be atleast 1 day";
//							else {
//								current_record.open("current_record.txt", ios::app);
//								if (current_record.is_open()) {
//									current_record << arr_customer[i].customer_id << " " << arr_customer[i].customer_name << "\n";
//									cout << "Record saved successfully!";
//								}
//							}
//						}
//						current_record.close();
//					}
//					room_book();
//					/*database.open("database.txt", ios::app);
//					if (database.is_open()) {
//						database << arr_customer[current_guest].customer_id << " stayed at " << arr_room.floor << " in " << arr_room.room << price_per_room << endl;
//						cout << "Record saved successfully!\n";
//					}
//					else cout << "File not opened!\n";
//					d/*atabase.close();*/
//				}
//}
//void penthouse()
//{
//	cout << "Enter floors from(1-" << penthouse_floors << "): ";
//	int floor;
//	cin >> floor;
//	cout << "Enter room from(1-" << penthouse_floors << "): ";
//	int room;
//	cin >> room;
//	for (int i = 0;i < penthouse_floors;i++) 
//	{
//		for (int j = 0;j < penthouse_rooms;j++)
//		{
//			penthouse_arr[i][j].floor;
//		}
//	}
//}
//void bookings()
//{
//	cout << "1. Penthouse:\n";
//	cout << "2. Classic:\n";
//	int ch;
//	cin >> ch;
//	switch (ch)
//	{
//	case 1:
//		penthouse();
//	case 2:
//		classic_book();
//	}	
//}
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
void item(string food,float price)
{
	int i = 0;
	customer meal_arr[max_guests];
	cout << "Enter customer_ID:";
	float total;
	int inp_ID;
	cin >> inp_ID;
	for (int i = 0;i < current_guest;i++) {
		string line;
		if (guests[i].customer_id == inp_ID)
		{
			cout << "Enter quantity:";
			int quantity;
			cin >> quantity;
			total = price * quantity;
			guests[i].meal_charges = total;
			cout << "Order placed successfully!\n";
			/*room_file.open("room_file.txt", ios::in);
			if (room_file.is_open()) {
				while (getline(room_file, line)) {
					stringstream ss(line);
					ss >> meal_arr[i].customer_id;
			
				}
			}*/
		}
	}
}
void meal_func()
{
    float price=0;
	cout << "***Menu***\n";
	cout << "1. Burger"<<setw(5)<<"$100.2"<<endl;
	cout << "2. Pasta" << setw(5) << "$200.7" << endl;
	cout << "3. Chicken" << setw(5) << "$300.9" << endl;
	cout << "4. Mutton" << setw(5) << "$400.0" << endl;
	cout << "5. Noodles" << setw(5) << "$100.9" << endl;
	cout << "6. Platter" << setw(5) << "$500.1" << endl;
	cout << "7. Tea" << setw(5) << "$50.2" << endl;
	cout << "8. Snacks" << setw(5) << "$100.0" << endl;
	cout << "9. Desserts" << setw(5) << "$300.8" << endl;
	cout << "10. Drinks" << setw(5) << "$100.5" << endl;
	int select;
	string food;
	cout << "Selection:";
	cin >> select;
	switch (select)
	{ 
	case 1:
		food = "burger";
		price = 100.2;
		break;
	case 2:
		food = "pasta";
		price = 200.7;
		break;
	case 3:
		food = "chicken";
		price = 300.9;
		break;
	case 4: 
		price = 400.0;
		break;
	case 5:
		price = 100.9;
		break;
	case 6:
		price = 500.1;
		break;
	case 7:
		price = 50.2;
		break;
	case 8:
		price = 100.0;
		break;
	case 9:
		price = 300.8;
		break;
	case 10:
		price = 100.5;
		break;
	default:
		break;
	}
	item(food,price);
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
	meal_func();
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
	for (int i = 0;i < current_guest;i++) {
		if (guests[i].customer_id == input_ID) {
			guests[i].time_duration=0;
			guests[i].meal_charges = 0;
			cout << "Check-out successful for guest " << guests[i].customer_name << ".\n";
			guests[i].customer_name.clear();
		}
	}
	/*string line;
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
	rename("current_record.txt", "current_record_new.txt");*/
}
void bill()
{
	/*customer read_data[max_guests];
	string line;
	cout << "Enter customer_id:";
	int inp_id;
	cin>> inp_id;
	room_file.open("room_file.txt",ios::in);
	int i = 0;
		if (room_file.is_open())
		{
			while (getline(room_file, line)) {
				stringstream ss(line);
				ss >> read_data[i].customer_id;
				ss >> read_data[i].customer_name;
				ss >> read_data[i].time_duration;
				ss >> read_data[i].meal_charges;
				ss >> read_data[i].Room.floor;
				ss >> read_data[i].Room.room;
				i++;
			}
		}
		room_file.close();
		for (int j = 0;i < i-1;j++)
		{
			cout << read_data[j].customer_id << read_data[j].customer_name << read_data[j].time_duration;
			if (read_data[i].customer_id == inp_id) {
				cout << "Customer ID:" << read_data[j].customer_id << endl;
				cout << "Stay duration:" << read_data[j].time_duration << endl;
				cout << "Room rate per room:" << room_rate << endl;
				cout << "Total meal charge:" << read_data[j].meal_charges << endl;
				cout << "Additional service fee:" << service_fee << endl;
				cout << "--------------\n";
				float total = read_data[j].time_duration * room_rate + read_data[j].meal_charges + service_fee;
				cout << "Total Bill :" << total << endl;
			}
		}*/

	int customerID;
	cout << "Enter customer ID: ";
	cin >> customerID;

	fstream room_file("room_file.txt", ios::in);
	if (room_file.is_open()) {
		string line;
		bool customerFound = false;
		while (getline(room_file, line)) {
			stringstream ss(line);
			customer Customer;
			ss >> Customer.customer_id>> Customer.customer_name >> Customer.time_duration >> Customer.meal_charges >> Customer.Room.floor >> Customer.Room.room;
			if (Customer.customer_id == customerID) {
				float totalBill = Customer.time_duration * room_rate + Customer.meal_charges +service_fee;
				cout << "--- Bill ---\n";
				cout << "Customer ID: " << Customer.customer_id << "\n";
				cout << "Name: " << Customer.customer_name << "\n";
				cout << "Stay Duration: " << Customer.time_duration << "\n";
				cout << "Room Charges: " << Customer.time_duration * room_rate << "\n";
				cout << "Meal Charges: " << Customer.meal_charges << "\n";
				cout << "Service Fee: " << service_fee << "\n";
				cout << "Total Bill: " << totalBill << "\n";
				customerFound = true;
				break;
			}
		}
		room_file.close();

		if (!customerFound) {
			cout << "Customer not found.\n";
		}
	}
	else {
		cerr << "Error reading customer file.\n";
	}
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
			room_book();
			break;
		case 3:
			manage_guest_details();
			break;
		case 4:
			meal_options();
			break;
		case 5:
			checkIN_guest();
			break;
		case 6:
			check_out();
			break;
		case 7:
			bill();
			break;
		}
		cout << "Press any key to continue :";
		cin >> cont;
	} while (cont!="e");
}
int main()
{
	initializerooms();
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
