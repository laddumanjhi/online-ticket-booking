#include <iostream>
#include <string>

using namespace std;

bool isValidMobileNumber(const string& mobileNumber) {
    // Check if the number is exactly 10 digits long
    if (mobileNumber.length() != 10) {
        return false;
    }

    // Check if all characters are digits
    for (char c : mobileNumber) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main() {
    string mobileNumber;
    cout << "Enter your mobile number (10 digits): ";
    cin >> mobileNumber;

    if (isValidMobileNumber(mobileNumber)) {
        cout << "Valid mobile number!" << endl;
    } else {
        cout << "Invalid mobile number. Please enter exactly 10 digits." << endl;
    }

    return 0;
}
