#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;

// Function Declarations
void main_menu();
void login_customer();
void login_reception();
void login_admin();
void menu_customer();
void menu_receptionist();
void menu_admin();
void load_user_data(const string &filename, int *id, string *name, string *password, int &count);
bool validate_login(int *id, string *password, int count, int &user_index);
void book_room();
void view_booking_details();
void check_room_availability();
void manage_bookings();
void view_system_logs();
void manage_users();
void manage_staff();
void view_food_menu();
void return_to_main_menu();

// Room and booking structure
struct Room {
    int room_id;
    string room_type;
    bool is_available;
};

struct Booking {
    size_t booking_id;
    string customer_name;
    int room_id;
    string check_in_date;
    string check_out_date;
};

// User management structure
struct User {
    int user_id;
    string name;
    string password;
};

struct Staff {
    int staff_id;
    string name;
    string position;
};

// Global variables for rooms and bookings
vector<Room> rooms = {{101, "Single", true}, {102, "Double", true}, {103, "Suite", true}};
vector<Booking> bookings;
vector<User> users = {{1, "Alice", "password1"}, {2, "Bob", "password2"}};  // Example users
vector<Staff> staff = {{1, "John", "Receptionist"}, {2, "Sarah", "Manager"}};  // Example staff

int user_choice;

int main() {
    cout << "\nWelcome to Imperial Resort Management System" << endl;
    
    while (true) {
        main_menu();
        switch (user_choice) {
            case 1: login_customer(); break;
            case 2: login_reception(); break;
            case 3: login_admin(); break;
            case 4: cout << "\nExiting... Thank you for using our system!\n"; return 0;
            default: cout << "Invalid Choice! Try Again...\n"; break;
        }
    }
}

// Main menu for user selection
void main_menu() {
    cout << "\nLogin as:" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Receptionist" << endl;
    cout << "3. Administrator" << endl;
    cout << "4. Exit" << endl;
    cout << "\nChoice: ";
    cin >> user_choice;
}

// Load user data from a file
void load_user_data(const string &filename, int *id, string *name, string *password, int &count) {
    ifstream file(filename);
    string line;
    count = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        char delimiter;
        string temp_name;

        ss >> id[count];
        ss >> delimiter;                  // Skip the comma after ID
        getline(ss, temp_name, ',');      // Read the name before the comma
        name[count] = temp_name;
        getline(ss, password[count]);    // Read the password directly
        count++;
    }
    file.close();
}

// Validate user login
bool validate_login(int *id, string *password, int count, int &user_index) {
    int entered_id;
    string entered_password;

    // Validate ID
    while (true) {
        cout << "Enter ID: ";
        cin >> entered_id;

        for (int i = 0; i < count; i++) {
            if (entered_id == id[i]) {
                user_index = i;
                break;
            }
        }

        if (user_index != -1) break;
        cout << "ID not found! Try again!" << endl;
    }

    // Validate Password
    while (true) {
        cout << "Password: ";
        cin >> entered_password;

        if (entered_password == password[user_index]) {
            return true;
        } else {
            cout << "Incorrect password! Try again!" << endl;
        }
    }
}

// Customer login and menu
void login_customer() {
    int id[100], user_index = -1, count = 0;
    string name[100], password[100];

    load_user_data("customer.txt", id, name, password, count);
    if (validate_login(id, password, count, user_index)) {
        cout << "\nLogin successful!" << endl;
        cout << "\nWelcome, " << name[user_index] << "!" << endl;
        menu_customer();
    }
}

void menu_customer() {
    while (true) {
        int choice;
        cout << "\nCustomer Menu:" << endl;
        cout << "1. Book a Room" << endl;
        cout << "2. View Booking Details" << endl;
        cout << "3. View Food Menu" << endl;
        cout << "4. Logout" << endl;
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: book_room(); break;
            case 2: view_booking_details(); break;
            case 3: view_food_menu(); break;
            case 4: cout << "Logging out...\n"; return; // Logout and return to main menu
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

// Receptionist login and menu
void login_reception() {
    int id[100], user_index = -1, count = 0;
    string name[100], password[100];

    load_user_data("receptionist.txt", id, name, password, count);
    if (validate_login(id, password, count, user_index)) {
        cout << "\nLogin successful!" << endl;
        cout << "\nWelcome, " << name[user_index] << "!" << endl;
        menu_receptionist();
    }
}

void menu_receptionist() {
    while (true) {
        int choice;
        cout << "\nReceptionist Menu:" << endl;
        cout << "1. Check Room Availability" << endl;
        cout << "2. Manage Bookings" << endl;
        cout << "3. View Food Menu" << endl;
        cout << "4. Logout" << endl;
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: check_room_availability(); break;
            case 2: manage_bookings(); break;
            case 3: view_food_menu(); break;
            case 4: cout << "Logging out...\n"; return; // Logout and return to main menu
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

// Admin login and menu
void login_admin() {
    int id[100], user_index = -1, count = 0;
    string name[100], password[100];

    load_user_data("admin.txt", id, name, password, count);
    if (validate_login(id, password, count, user_index)) {
        cout << "\nLogin successful!" << endl;
        cout << "\nWelcome, " << name[user_index] << "!" << endl;
        menu_admin();
    }
}

void menu_admin() {
    while (true) {
        int choice;
        cout << "\nAdmin Menu:" << endl;
        cout << "1. View System Logs" << endl;
        cout << "2. Manage Users" << endl;
        cout << "3. Manage Staff" << endl;
        cout << "4. View Food Menu" << endl;
        cout << "5. Logout" << endl;
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: view_system_logs(); break;
            case 2: manage_users(); break;
            case 3: manage_staff(); break;
            case 4: view_food_menu(); break;
            case 5: cout << "Logging out...\n"; return; // Logout and return to main menu
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

// Function Definitions for various options
void book_room() {
    int room_id;
    cout << "\nAvailable rooms:" << endl;
    for (auto &room : rooms) {
        if (room.is_available) {
            cout << "Room " << room.room_id << " (" << room.room_type << ") is available." << endl;
        }
    }

    cout << "Enter Room ID to book: ";
    cin >> room_id;

    for (auto &room : rooms) {
        if (room.room_id == room_id && room.is_available) {
            cout << "Enter check-in date (YYYY-MM-DD): ";
            string check_in;
            cin >> check_in;
            cout << "Enter check-out date (YYYY-MM-DD): ";
            string check_out;
            cin >> check_out;

            // Use bookings.size() directly as the booking_id
            bookings.push_back({bookings.size() + 1, "Customer", room_id, check_in, check_out});
            room.is_available = false;
            cout << "Room " << room_id << " successfully booked from " << check_in << " to " << check_out << endl;
            return;
        }
    }

    cout << "Room is not available or invalid room ID.\n";
}

void view_booking_details() {
    cout << "\nBooking Details:" << endl;
    for (auto &booking : bookings) {
        cout << "Booking ID: " << booking.booking_id
             << ", Room ID: " << booking.room_id
             << ", Check-in: " << booking.check_in_date
             << ", Check-out: " << booking.check_out_date << endl;
    }
}

void check_room_availability() {
    cout << "\nRoom Availability:" << endl;
    for (auto &room : rooms) {
        cout << "Room " << room.room_id << " (" << room.room_type << "): "
             << (room.is_available ? "Available" : "Not Available") << endl;
    }
}

void manage_bookings() {
    int booking_id;
    cout << "\nEnter booking ID to cancel: ";
    cin >> booking_id;

    auto it = find_if(bookings.begin(), bookings.end(), [booking_id](const Booking& b) {
        return b.booking_id == booking_id;
    });

    if (it != bookings.end()) {
        cout << "Cancelling Booking ID: " << it->booking_id << endl;
        int room_id = it->room_id;
        it = bookings.erase(it);  // Remove the booking
        for (auto &room : rooms) {
            if (room.room_id == room_id) {
                room.is_available = true;  // Mark the room as available
                break;
            }
        }
        cout << "Booking cancelled successfully.\n";
    } else {
        cout << "Booking ID not found.\n";
    }
}

void view_system_logs() {
    cout << "\nSystem Logs:" << endl;
    cout << "1. System started successfully." << endl;
    cout << "2. User Alice logged in." << endl;
    cout << "3. Room 101 booked by customer.\n";
}

void manage_users() {
    int choice;
    cout << "\nManage Users:\n";
    cout << "1. List Users" << endl;
    cout << "2. Add User" << endl;
    cout << "3. Remove User" << endl;
    cout << "4. Back to Admin Menu" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\nList of Users:" << endl;
            for (const auto &user : users) {
                cout << "ID: " << user.user_id << ", Name: " << user.name << endl;
            }
            break;
        }
        case 2: {
            User new_user;
            cout << "Enter new user ID: ";
            cin >> new_user.user_id;
            cout << "Enter new user name: ";
            cin >> new_user.name;
            cout << "Enter password: ";
            cin >> new_user.password;
            users.push_back(new_user);
            cout << "User added successfully.\n";
            break;
        }
        case 3: {
            int user_id;
            cout << "Enter user ID to remove: ";
            cin >> user_id;
            auto it = remove_if(users.begin(), users.end(), [user_id](const User& u) {
                return u.user_id == user_id;
            });
            if (it != users.end()) {
                users.erase(it, users.end());
                cout << "User removed successfully.\n";
            } else {
                cout << "User ID not found.\n";
            }
            break;
        }
        case 4: break;  // Back to Admin Menu
        default:
            cout << "Invalid choice!\n";
    }
}

void manage_staff() {
    int choice;
    cout << "\nManage Staff:\n";
    cout << "1. List Staff" << endl;
    cout << "2. Add Staff" << endl;
    cout << "3. Remove Staff" << endl;
    cout << "4. Back to Admin Menu" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\nList of Staff Members:" << endl;
            for (const auto &staff_member : staff) {
                cout << "ID: " << staff_member.staff_id << ", Name: " << staff_member.name << ", Position: " << staff_member.position << endl;
            }
            break;
        }
        case 2: {
            Staff new_staff;
            cout << "Enter staff ID: ";
            cin >> new_staff.staff_id;
            cout << "Enter staff name: ";
            cin >> new_staff.name;
            cout << "Enter staff position: ";
            cin >> new_staff.position;
            staff.push_back(new_staff);
            cout << "Staff added successfully.\n";
            break;
        }
        case 3: {
            int staff_id;
            cout << "Enter staff ID to remove: ";
            cin >> staff_id;
            auto it = remove_if(staff.begin(), staff.end(), [staff_id](const Staff& s) {
                return s.staff_id == staff_id;
            });
            if (it != staff.end()) {
                staff.erase(it, staff.end());
                cout << "Staff removed successfully.\n";
            } else {
                cout << "Staff ID not found.\n";
            }
            break;
        }
        case 4: break;  // Back to Admin Menu
        default:
            cout << "Invalid choice!\n";
    }
}

void view_food_menu() {
    cout << "\nFood Menu:" << endl;
    cout << "1. Spaghetti - $10" << endl;
    cout << "2. Salad - $5" << endl;
    cout << "3. Burger - $8" << endl;
    cout << "4. Pizza - $12" << endl;

    int choice;
    cout << "\nEnter your choice to order food (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You have ordered Spaghetti. Total: $10\n";
            break;
        case 2:
            cout << "You have ordered Salad. Total: $5\n";
            break;
        case 3:
            cout << "You have ordered a Burger. Total: $8\n";
            break;
        case 4:
            cout << "You have ordered Pizza. Total: $12\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
    }
    
    // Ask user if they want to go back to the main menu
    char continue_choice;
    cout << "Do you want to return to the main menu? (y/n): ";
    cin >> continue_choice;
    if (continue_choice == 'y' || continue_choice == 'Y') {
        return_to_main_menu();
    } else {
        cout << "Exiting food menu.\n";
    }
}

// Function to return to the main menu
void return_to_main_menu() {
    cout << "\nReturning to the main menu...\n";
    // Assuming the main menu options need to be presented again
    main_menu();  
}

