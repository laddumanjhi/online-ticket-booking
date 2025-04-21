#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

int main() {
    cout << "Enter the travel date (yyyy/mm/dd):" << endl;
    string date_input;
    cin >> date_input;

    // Validate date format and length
    if (date_input.length() != 10 || date_input[4] != '/' || date_input[7] != '/') {
        cout << "Invalid date format. Please use YYYY/MM/DD." << endl;
        return 1;
    }

    int year, month, day;
    try {
        year = stoi(date_input.substr(0, 4));
        month = stoi(date_input.substr(5, 2));
        day = stoi(date_input.substr(8, 2));
    } catch (const std::invalid_argument& e) {
        cout << "Invalid date format. Please use numeric values for YYYY/MM/DD." << endl;
        return 1;
    }

    // Validate date values
    if (year < 2024 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "Invalid date. Please enter a valid date between 2024 and 2100." << endl;
        return 1;
    }

    // Create a tm structure to store the date
    tm travel_date = {};
    travel_date.tm_year = year - 1900; // Years since 1900
    travel_date.tm_mon = month - 1;    // Months are 0-11
    travel_date.tm_mday = day;

    // Format and display the date
    char date_str[11];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", &travel_date);
    cout << "Travel date: " << date_str << endl;

    return 0;
}
