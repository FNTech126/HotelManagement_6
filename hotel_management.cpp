#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {
private:
    string name;
    int roomNumber;

public:
    // Constructor
    Guest(string n, int rn) : name(n), roomNumber(rn) {}

    // Getters
    string getName() const {
        return name;
    }

    int getRoomNumber() const {
        return roomNumber;
    }
};

class Hotel {
private:
    vector<Guest> guests;

public:
    // Add a new guest to the hotel
    void addGuest(const Guest& guest) {
        guests.push_back(guest);
    }

    // Display all guests in the hotel
    void displayGuests() const {
        cout << "Guests in the hotel:" << endl;
        for (const auto& guest : guests) {
            cout << "Name: " << guest.getName() << ", Room Number: " << guest.getRoomNumber() << endl;
        }
    }

    // Search for a guest by name
    void searchGuest(const string& name) const {
        bool found = false;
        cout << "Searching for guest: " << name << endl;
        for (const auto& guest : guests) {
            if (guest.getName() == name) {
                cout << "Guest found: Name: " << guest.getName() << ", Room Number: " << guest.getRoomNumber() << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Guest not found." << endl;
        }
    }

    // Remove a guest by name
    void removeGuest(const string& name) {
        for (auto it = guests.begin(); it != guests.end(); ++it) {
            if (it->getName() == name) {
                guests.erase(it);
                cout << "Guest " << name << " removed from the hotel." << endl;
                return;
            }
        }
        cout << "Guest " << name << " not found in the hotel." << endl;
    }
};

int main() {
    Hotel hotel;

    // Adding some initial guests
    hotel.addGuest(Guest("Alice", 101));
    hotel.addGuest(Guest("Bob", 102));

    int choice;
    string name;
    int roomNumber;

    do {
        cout << "Hotel Management System" << endl;
        cout << "1. Add Guest" << endl;
        cout << "2. Display Guests" << endl;
        cout << "3. Search Guest" << endl;
        cout << "4. Remove Guest" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter guest name: ";
                cin >> name;
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.addGuest(Guest(name, roomNumber));
                break;
            case 2:
                hotel.displayGuests();
                break;
            case 3:
                cout << "Enter guest name to search: ";
                cin >> name;
                hotel.searchGuest(name);
                break;
            case 4:
                cout << "Enter guest name to remove: ";
                cin >> name;
                hotel.removeGuest(name);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
