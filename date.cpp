#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

bool is_valid_date(int day, int month, int year) {
    // Check for invalid year, month, or day
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Determine the number of days in the month
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        days_in_month[1] = 29; // Leap year
    }

    // Check if the day is valid for the given month and year
    return day <= days_in_month[month - 1];
}

string format_date(int day, int month, int year) {
    ostringstream oss;
    oss << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year;
    return oss.str();
}

int main() {
    int day, month, year;

    cout << "Enter the date (dd mm yyyy): ";
    cin >> day >> month >> year;

    if (is_valid_date(day, month, year)) {
        string formatted_date = format_date(day, month, year);
        cout << "Valid date: " << formatted_date << endl;
    } else {
        cout << "Invalid date format. Please enter in dd mm yyyy format." << endl;
    }

    return 0;
}