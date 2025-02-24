#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>  
#include <ctime>    
using namespace std;

void showWelcomeMessage() {
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " *********** WELCOME TO ALPHA'S HOTEL  ***********" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl << endl;
}

void displayRoomOptions() {
    cout << endl << "    Rooms  Options     " << endl;
    cout << "|------------------------------|" << endl;
    cout << "| " << setw(10) << left << "A class" << " | " << setw(15) << right << "4000 per night" << " |" << endl;
    cout << "| " << setw(10) << left << "B class" << " | " << setw(15) << right << "3000 per night" << " |" << endl;
    cout << "| " << setw(10) << left << "C class" << " | " << setw(15) << right << "2000 per night" << " |" << endl;
    cout << "|------------------------------|" << endl;
}

void displayFoodMenu(const string food[], const int food_price[], int size) {
    cout << "Food Menu: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << " " << ":" << food[i] << "  :  " << food_price[i] << " " << endl;
    }
}

void displayDrinkMenu(const string drinks[], const int drinks_price[], int size) {
    cout << "Drink Menu: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << " " << ":" << drinks[i] << "   :  " << drinks_price[i] << " " << endl;
    }
}

void displayRoomServiceMenu() {
    cout << "|---------------------------------------------|" << endl;
    cout << "| " << setw(20) << left << "Room Cleaning" << " | " << setw(20) << right << "400 per visit" << " |" << endl;
    cout << "| " << setw(20) << left << "Laundry" << " | " << setw(20) << right << "30 Rupees per item" << " |" << endl;
    cout << "| " << setw(20) << left << "Extra Request" << " | " << setw(20) << right << "Press 1" << " | " << endl;
    cout << "|---------------------------------------------|" << endl;
}

void displayEntertainmentMenu() {
    cout << "|---------------------------------------|" << endl;
    cout << "| " << setw(15) << left << "Games" << " | " << setw(15) << right << "500 Rupees per hour" << " |" << endl;
    cout << "| " << setw(15) << left << "Swimming Pool" << " | " << setw(15) << right << "350 Rupees per hour" << " |" << endl;
    cout << "| " << setw(15) << left << "Gym" << " | " << setw(15) << right << "100 Rupees per hour" << " |" << endl;
    cout << "|---------------------------------------|" << endl;
}

void calculateAndDisplayBill(int Room_bill, int Food_bill, int Room_Service_Bill, int entertainment_bill, int parking_charges, int security_deposit, const string& name, long long int cnic, long long int phone_number, int Grand_Total) {
    cout << endl;
    cout << " *******    Your Total Bill    *******" << endl;
    cout << endl;
    cout << "|-------------------------------------" << endl;
    cout << "|-------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Name " << name << endl;
    cout << "| " << setw(25) << left << "CNIC  " << cnic << endl;
    cout << "| " << setw(25) << left << "Phone Number  " << phone_number << endl;
    cout << "| " << setw(25) << left << "Room Bill  " << Room_bill << endl;
    cout << "| " << setw(25) << left << "Food Bill  " << Food_bill << endl;
    cout << "| " << setw(25) << left << "Room service Bill  " << Room_Service_Bill << endl;
    cout << "| " << setw(25) << left << "Entertainment Bill  " << entertainment_bill << endl;
    cout << "| " << setw(25) << left << "Parking Charges  " << parking_charges << endl;
    cout << "| " << setw(25) << left << "Security charges  " << security_deposit << endl;
    cout << "| " << setw(25) << left << "Grand Total  " << Grand_Total << endl;
    cout << "|-------------------------------------" << endl;
    cout << "|-------------------------------------" << endl;
}

void storeCustomerData(long long int cnic, const string& name, long long int phone_number, int Customer_Room, int Grand_Total) {
    ofstream fout;
    fout.open("Customers_Info.txt", ios::app);
    fout << cnic << "  " << name << "  " << phone_number << " " << Customer_Room << " " << Grand_Total << endl;
    fout.close();
}

void handleCheckIn(int TotalRooms[3][7], string& name, long long int& cnic, long long int& phone_number, int& Grand_Total) {
    cin.ignore();
    cout << " Enter your name: ";
    getline(cin, name);

    while (true) {
        cout << " Enter your CNIC number (13 digits): ";
        cin >> cnic;
        if (to_string(cnic).length() == 13) {
            break;
        }
        cout << " Invalid CNIC. Please enter 13 digits." << endl;
    }

    while (true) {
        cout << " Enter your phone number (11 digits): ";
        cin >> phone_number;
        if (to_string(phone_number).length() == 11) {
            break;
        }
        cout << " Invalid phone number. Please enter 11 digits." << endl;
    }

    displayRoomOptions();

    char Room_choice;
    while (true) {
        cout << " Enter your choice (A, B, C): ";
        cin >> Room_choice;
        if (Room_choice == 'A' || Room_choice == 'a' || Room_choice == 'B' || Room_choice == 'b' || Room_choice == 'C' || Room_choice == 'c') {
            break;
        }
        cout << " Invalid input. Please enter A, B, or C." << endl;
    }

    int no_of_nights, no_of_rooms;
    cout << " Enter number of nights you want to stay: ";
    cin >> no_of_nights;
    cout << " How many rooms do you want (max 3): ";
    cin >> no_of_rooms;
    if (no_of_rooms > 3) {
        cout << " Sorry, we cannot give more than 3 rooms to one person." << endl;
        no_of_rooms = 3;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = rand() % 7;
    int Room_bill = 0;
    string roomclass;
    int Customer_Room = 0;

    if (Room_choice == 'A' || Room_choice == 'a') {
        Room_bill = no_of_nights * 4000;
        Customer_Room = TotalRooms[0][random_number];
        roomclass = "A";
    } else if (Room_choice == 'B' || Room_choice == 'b') {
        Room_bill = no_of_nights * 3000;
        Customer_Room = TotalRooms[1][random_number];
        roomclass = "B";
    } else if (Room_choice == 'C' || Room_choice == 'c') {
        Room_bill = no_of_nights * 2000;
        Customer_Room = TotalRooms[2][random_number];
        roomclass = "C";
    }

    Room_bill *= no_of_rooms;
    cout << " Room class: " << roomclass << "   Room bill: " << Room_bill << "    Room number: " << Customer_Room << endl;

    int Food_bill = 0;
    char menuoption;
    while (true) {
        cout << " Do you want food items (Y/N)?: ";
        cin >> menuoption;

        if (menuoption == 'Y' || menuoption == 'y') {
            const string food[3] = { "Pizza", "Burger", "Pasta" };
            const int food_price[3] = { 1500, 800, 1100 };
            displayFoodMenu(food, food_price, 3);

            int select_food_anddrinks, Quantity;
            cout << " Enter option: ";
            cin >> select_food_anddrinks;
            cout << " Enter quantity: ";
            cin >> Quantity;
            Food_bill = food_price[select_food_anddrinks - 1] * Quantity;

            const string drinks[3] = { "Water", "Coke_Cola", "Pepsi" };
            const int drinks_price[3] = { 100, 200, 190 };
            displayDrinkMenu(drinks, drinks_price, 3);

            cout << " Enter option: ";
            cin >> select_food_anddrinks;
            cout << " Enter quantity: ";
            cin >> Quantity;
            Food_bill += drinks_price[select_food_anddrinks - 1] * Quantity;
            cout << " Your order total: " << Food_bill << endl;
            break;
        } else if (menuoption == 'N' || menuoption == 'n') {
            break;
        } else {
            cout << " Invalid input! Please enter Y or N." << endl;
        }
    }

    int Room_Service_Bill = 0;
    char service;
    while (true) {
        cout << " Do you want room service (Y/N)?: ";
        cin >> service;

        if (service == 'Y' || service == 'y') {
            displayRoomServiceMenu();
            char service_choice;
            cout << " Do you want room cleaning (Y/N)?: ";
            cin >> service_choice;

            if (service_choice == 'Y' || service_choice == 'y') {
                int no_of_visits;
                cout << " Enter number of visits you want in a day: ";
                cin >> no_of_visits;
                Room_Service_Bill = no_of_visits * 400;
            }
            cout << " Do you want laundry (Y/N)?: ";
            cin >> service_choice;
            if (service_choice == 'Y' || service_choice == 'y') {
                int no_of_items;
                cout << " Enter number of items you want to wash: ";
                cin >> no_of_items;
                Room_Service_Bill += no_of_items * 30;
            }
            cout << " Do you want to add an extra request (Y/N)?: ";
            cin >> service_choice;
            if (service_choice == 'Y' || service_choice == 'y') {
                cin.ignore();
                cout << " Enter extra request: ";
                string extra_request;
                getline(cin, extra_request);
                ofstream fout1;
                fout1.open("Extra_Request.txt", ios::app);
                fout1 << extra_request << endl;
                cout << " Your request has been added." << endl;
                fout1.close();
            }

            cout << " Room service bill: " << Room_Service_Bill << endl;
            break;
        } else if (service == 'N' || service == 'n') {
            break;
        } else {
            cout << " Invalid input! Please enter Y or N." << endl;
        }
    }

    int entertainment_bill = 0;
    char ent_opt;
    while (true) {
        cout << " Do you want entertainment services (Y/N)?: ";
        cin >> ent_opt;

        if (ent_opt == 'Y' || ent_opt == 'y') {
            displayEntertainmentMenu();
            char enop;
            int no_of_hours;

            cout << " Do you want to play games (Y/N)?: ";
            cin >> enop;
            if (enop == 'Y' || enop == 'y') {
                cout << " How many hours do you want to play games?: ";
                cin >> no_of_hours;
                entertainment_bill = no_of_hours * 500;
            }
            cout << " Do you want swimming pool access (Y/N)?: ";
            cin >> enop;
            if (enop == 'Y' || enop == 'y') {
                cout << " How many hours do you want to access the pool?: ";
                cin >> no_of_hours;
                entertainment_bill += no_of_hours * 350;
            }
            cout << " Do you want to access the gym (Y/N)?: ";
            cin >> enop;
            if (enop == 'Y' || enop == 'y') {
                cout << " How many hours do you want to access the gym?: ";
                cin >> no_of_hours;
                entertainment_bill += no_of_hours * 100;
            }
            cout << " Total entertainment bill: " << entertainment_bill << endl;
            break;
        } else if (ent_opt == 'N' || ent_opt == 'n') {
            break;
        } else {
            cout << " Invalid input! Please enter Y or N." << endl;
        }
    }

    int parking_charges = 100 * no_of_nights;
    int security_deposit = 5000;
    Grand_Total = Room_bill + Food_bill + Room_Service_Bill + entertainment_bill + parking_charges + security_deposit;

    system("cls");
    calculateAndDisplayBill(Room_bill, Food_bill, Room_Service_Bill, entertainment_bill, parking_charges, security_deposit, name, cnic, phone_number, Grand_Total);

    storeCustomerData(cnic, name, phone_number, Customer_Room, Grand_Total);
}

void handleCheckOut() {
    long long int user_cnic = 0, user_phne = 0, entercnic = 0;
    string copy_name;
    int room_num, grandtotal;
    string user_name;
    bool flag1 = true;

    cout << " Enter your CNIC: ";
    cin >> entercnic;
    cout << " Did you break anything (Y/N)?: ";
    char v;
    cin >> v;
    int security_deposit = 5000;

    if (v == 'Y' || v == 'y') {
        cout << " Press 1 if you broke a mirror" << endl;
        cout << " Press 2 if you broke any cabinets or wooden items" << endl;
        cout << " Press 3 if you broke any electrical items" << endl;
        int cc;
        cin >> cc;
        if (cc == 1) {
            security_deposit -= 1000;
        } else if (cc == 2) {
            security_deposit -= 1500;
        } else if (cc == 3) {
            security_deposit -= 4500;
        } else {
            cout << " Invalid input!" << endl;
        }
    } else if (v == 'N' || v == 'n') {
        security_deposit = 5000;
    } else {
        cout << " Invalid input!" << endl;
    }

    ifstream fin;
    fin.open("Customers_Info.txt");

    while (fin >> user_cnic >> user_name >> user_phne >> room_num >> grandtotal) {
        if (user_cnic == entercnic) {
            copy_name = user_name;
            flag1 = false;
            break;
        }
    }
    fin.close();

    if (!flag1) {
        cout << " Hello, " << copy_name << "! Your security deposit refund is " << security_deposit << endl;
    } else {
        cout << " No such CNIC exists." << endl;
    }
}

int main() {
    int TotalRooms[3][7] = { {1, 2, 3, 4, 5, 6, 7}, {8, 9, 10, 11, 12, 13, 14}, {15, 16, 17, 18, 19, 20, 21} };
    bool main_loop = true;

    while (main_loop) {
        showWelcomeMessage();
        cout << " Press 1 to CHECK-IN " << endl;
        cout << " Press 2 to CHECK-OUT " << endl;

        int chek_in_out_opt;
        cin >> chek_in_out_opt;

        long long int cnic = 0, phone_number = 0;
        string name;
        int Grand_Total = 0;

        if (chek_in_out_opt == 1) {
            handleCheckIn(TotalRooms, name, cnic, phone_number, Grand_Total);
        } else if (chek_in_out_opt == 2) {
            handleCheckOut();
        } else {
            cout << "Invalid option! Please try again." << endl;
            break;
        }

        char run_again;
        while (true) {
            cout << "Do you want to run the program again? (Y/N): ";
            cin >> run_again;
            if (run_again == 'Y' || run_again == 'y') {
                system("cls");
                main_loop = true;
                break;
            } else if (run_again == 'N' || run_again == 'n') {
                system("cls");
                cout << "------------------------------------------------------" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "        Thank YOU!   " << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "------------------------------------------------------" << endl;
                main_loop = false;
                break;
            } else {
                cout << " Invalid input ! " << endl;
            }
        }
    }
    return 0;
}