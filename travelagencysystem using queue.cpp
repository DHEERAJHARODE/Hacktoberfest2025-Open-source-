#include <iostream>
#include <queue>  
#include <string>
using namespace std;

class ReservationSystem 
    {
         private:
         queue<string> reservationQueue; // queue to store reservations
         int maxSize; // maximum number of reservations allowed
         public:
         ReservationSystem(int size) 
             {
                maxSize = size;
             }
    // Add reservation
    void addReservation(const string& name) 
    {
        if (reservationQueue.size() >= maxSize) 
        {
            cout << "Sorry! Reservation is full\n";
        } 
        else 
        {
            reservationQueue.push(name);
            cout << "Reservation successful for: " << name << endl;
        }
    }
    // Cancel reservation
    void cancelReservation() 
    {
        if (reservationQueue.empty())
        {
            cout << "No reservations to cancel.\n";
        } 
        else 
        {
            cout << "Reservation cancelled for: " << reservationQueue.front() << endl;
            reservationQueue.pop();//pops the element that we wish to delete in the queue 
        }
    }
    // Display all reservations
    void showReservations()
    {
        if (reservationQueue.empty())
        {
            cout << "No reservations found.\n";
            return;
        }
        cout << "Current Reservations:\n";
        queue<string> temp = reservationQueue; // copy queue to display
        int pos = 1;
        while (!temp.empty()) 
        {
            cout << pos++ << ". " << temp.front() << endl;
            temp.pop();
        }
    }
};
int main()
{
    int choice, size;
    string name;

    cout << "Enter maximum number of reservations allowed: ";
    cin >> size;

    ReservationSystem system(size);

    do {
        cout << "\n--- Reservation System Menu ---\n";
        cout << "1. Add Reservation\n";
        cout << "2. Cancel Reservation\n";
        cout << "3. Show Reservations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name for reservation: ";
            cin >> name;
            system.addReservation(name);
            break;

        case 2:
            system.cancelReservation();
            break;

        case 3:
            system.showReservations();
            break;

        case 4:
            cout << "Exiting Reservation System...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}