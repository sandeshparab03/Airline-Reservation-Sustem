#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mainMenu();

// Safe input handler to avoid infinite input loop
void safeInput(int &var) {
    while (true) {
        cin >> var;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number: ";
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
}

class Management {
public:
    Management() {
        mainMenu();
    }
};

class Details {
public:
    static string name, gender;
    int phoneNo;
    int age;
    string add;
    static int cId;

    void information() {
        cout << "\nEnter the customer ID: ";
        safeInput(cId);

        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the age: ";
        safeInput(age);

        cout << "Address: ";
        getline(cin, add);

        cout << "Gender: ";
        getline(cin, gender);

        cout << "\nYour details are saved with us.\n";
    }
};

int Details::cId;
string Details::name;
string Details::gender;

class Registration {
public:
    static int choice;
    static float charges;
    int choice1;

    void flights() {
        string flightN[] = { "Dubai", "Canada", "UK", "USA", "Australia", "Europe" };

        cout << "\nWelcome to Indian Airlines!\n";
        cout << "Available Destinations:\n";

        for (int a = 0; a < 6; a++) {
            cout << (a + 1) << ". Flight to " << flightN[a] << endl;
        }

        cout << "Enter your choice: ";
        safeInput(choice);

        if (choice < 1 || choice > 6) {
            cout << "Invalid destination. Returning to menu.\n";
            return;
        }

        cout << "\nAvailable flights to " << flightN[choice - 1] << ":\n";
        if (choice == 1) {
            cout << "1. DUB - 498\t08-01-2024 8:00AM\t10hrs\tRs.14000\n";
            cout << "2. DUB - 658\t09-01-2024 4:00AM\t12hrs\tRs.10000\n";
            cout << "3. DUB - 508\t11-01-2024 11:00AM\t11hrs\tRs.9000\n";
        } else if (choice == 2) {
            cout << "1. CA - 198\t09-01-2024 2:00PM\t20hrs\tRs.34000\n";
            cout << "2. CA - 158\t11-01-2024 6:00AM\t23hrs\tRs.29000\n";
            cout << "3. CA - 208\t14-01-2024 12:00AM\t21hrs\tRs.40000\n";
        } else if (choice == 3) {
            cout << "1. UK - 798\t12-01-2024 10:00AM\t14hrs\tRs.44000\n";
        } else if (choice == 4) {
            cout << "1. US - 567\t10-01-2024 9:00AM\t22hrs\tRs.37000\n";
            cout << "2. US - 658\t09-01-2024 6:00AM\t22hrs\tRs.39000\n";
            cout << "3. US - 508\t12-01-2024 10:00AM\t21hrs\tRs.42000\n";
        } else if (choice == 5) {
            cout << "1. AS - 298\t18-01-2024 9:00AM\t20hrs\tRs.44000\n";
            cout << "2. AS - 658\t19-01-2024 4:00AM\t22hrs\tRs.34000\n";
            cout << "3. AS - 508\t20-01-2024 12:00AM\t21hrs\tRs.42000\n";
        } else if (choice == 6) {
            cout << "1. EU - 298\t02-02-2024 2:00PM\t18hrs\tRs.36000\n";
            cout << "2. EU - 658\t03-02-2024 6:00AM\t19hrs\tRs.37000\n";
            cout << "3. EU - 508\t12-02-2024 12:00AM\t20hrs\tRs.31000\n";
        }

        cout << "\nSelect the flight you want to book: ";
        safeInput(choice1);

        // Setting charges
        if (choice == 1) {
            if (choice1 == 1) charges = 14000;
            else if (choice1 == 2) charges = 10000;
            else if (choice1 == 3) charges = 9000;
            else goto invalidFlight;
        } else if (choice == 2) {
            if (choice1 == 1) charges = 34000;
            else if (choice1 == 2) charges = 29000;
            else if (choice1 == 3) charges = 40000;
            else goto invalidFlight;
        } else if (choice == 3 && choice1 == 1) charges = 44000;
        else if (choice == 4) {
            if (choice1 == 1) charges = 37000;
            else if (choice1 == 2) charges = 39000;
            else if (choice1 == 3) charges = 42000;
            else goto invalidFlight;
        } else if (choice == 5) {
            if (choice1 == 1) charges = 44000;
            else if (choice1 == 2) charges = 34000;
            else if (choice1 == 3) charges = 42000;
            else goto invalidFlight;
        } else if (choice == 6) {
            if (choice1 == 1) charges = 36000;
            else if (choice1 == 2) charges = 37000;
            else if (choice1 == 3) charges = 31000;
            else goto invalidFlight;
        } else {
        invalidFlight:
            cout << "Invalid flight selection. Returning to main menu.\n";
            return;
        }

        cout << "Flight booked successfully!\n";
    }
};

int Registration::choice;
float Registration::charges;

class Ticket : public Registration, Details {
public:
    char arr[100];

    void Bill() {
        string destination = "";
        ofstream outf("records.txt");
        outf << "_________________Indian Airlines Ticket_________________\n";
        outf << "Customer ID:\t" << Details::cId << "\n";
        outf << "Name:\t\t" << Details::name << "\n";
        outf << "Gender:\t\t" << Details::gender << "\n";

        switch (Registration::choice) {
            case 1: destination = "Dubai"; break;
            case 2: destination = "Canada"; break;
            case 3: destination = "UK"; break;
            case 4: destination = "USA"; break;
            case 5: destination = "Australia"; break;
            case 6: destination = "Europe"; break;
            default: destination = "Unknown";
        }

        outf << "Destination:\t" << destination << "\n";
        outf << "Flight cost:\t" << Registration::charges << "\n";
        outf.close();
    }

    void dispBill() {
        ifstream ifs("records.txt");
        if (!ifs) {
            cout << "Error reading file.\n";
            return;
        }

        while (ifs.getline(arr, 100)) {
            cout << arr << endl;
        }

        ifs.close();
    }
};

void mainMenu() {
    int lchoice;
    Details d;
    Registration r;
    Ticket t;

    while (true) {
        cout << "\n=============== Indian Airlines ===============\n";
        cout << "1. Add Customer Details\n";
        cout << "2. Flight Registration\n";
        cout << "3. Ticket and Charges\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        safeInput(lchoice);

        switch (lchoice) {
            case 1:
                d.information();
                break;
            case 2:
                r.flights();
                break;
            case 3:
                t.Bill();
                cout << "Ticket generated.\n";
                cout << "Display ticket? (1 = Yes): ";
                safeInput(lchoice);
                if (lchoice == 1) {
                    t.dispBill();
                }
                break;
            case 4:
                cout << "Thank you for using Indian Airlines!\n";
                return;
            default:
                cout << "Invalid choice! Try again.\n";
        }

        cout << "\nPress Enter to return to main menu...";
        cin.get();
    }
}

int main() {
    Management Mobj;
    return 0;
}