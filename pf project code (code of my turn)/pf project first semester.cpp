#include <iostream>
#include <string>

using namespace std;

double Dscunt_for_roadtrip(double rentalCost, string role) {
    double discount = 0.0;
    if (role == "student" || role == "employee") {
        discount = 0.40;
    }
    double finalCost = rentalCost - (rentalCost * discount);
    return finalCost;
}

double Dscunt_for_sports(double rentalCost, double sports_rental, string eventType) {
    double discount = 0.0;
    if (eventType == "off-city") {
        discount = 0.50;
    } else if (eventType == "on-city") {
        discount = 0.30;
    }
    double finalCost = sports_rental - (sports_rental * discount);
    return finalCost;
}

double Dscunt_for_socialRentals(double rentalCost, double SocialRentals, string role, string eventType, string eventLocation) {
    double discount = 0.0;
    if (role == "student") {
        discount = 0.15;
    } else if (role == "faculty") {
        discount = 0.25;
    } else if (role == "employee") {
        discount = 0.20;
    }
    if (eventType == "yes") {
        if (eventLocation == "off-city") {
            discount = 0.30;
        }
        if (eventType == "yes") {
            discount = 0.35;
        }
    }
    double finalCost = SocialRentals - (SocialRentals * discount);
    return finalCost;
}

int main() {
    string category, role, eventType, eventLocation;
    double rentalCost, sports_rental, SocialRentals;

    cout << "Enter the category of rental (roadtrip/sports/familysocial): ";
    cin >> category;

    if (category == "roadtrip") {
        cout << "Enter the rental cost: $";
        cin >> rentalCost;
        cout << "Enter your role (student/faculty/employee): ";
        cin >> role;
        double finalCost = Dscunt_for_roadtrip(rentalCost, role);
        cout << "The total cost after discount is: $" << finalCost << endl;
    } 
	
	else if (category == "sports") {
        cout << "Enter the rental cost: $";
        cin >> rentalCost;
        cout << "Enter the sports rental cost: $";
        cin >> sports_rental;
        cout << "Enter event type (off-city/on-city): ";
        cin >> eventType;
        double finalCost = Dscunt_for_sports(rentalCost, sports_rental, eventType);
        cout << "The total cost after discount is: $" << finalCost << endl;
    }
	
	else if (category == "familysocial") {
        cout << "Enter the rental cost: $";
        cin >> rentalCost;
        cout << "Enter the social rentals cost: $";
        cin >> SocialRentals;
        cout << "Enter your role (student/faculty/employee): ";
        cin >> role;
        cout << "Is this for community service or charity event? (yes/no): ";
        cin >> eventType;
        if (eventType == "yes") {
            cout << "Enter event location (off-city): ";
            cin >> eventLocation;
        }
        double finalCost = Dscunt_for_socialRentals(rentalCost, SocialRentals, role, eventType, eventLocation);
        cout << "The total cost after discount is: $" << finalCost << endl;
    }

    return 0;
}
