#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include<algorithm>
#include<vector>
using namespace std;

class login
{
public:
    string username;
    string password;
    string info;

    // Function to create a new account
    void create()
    {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Create the password: ";
        cin >> password;
        cout << "Confirmation of password, fill your personal info: ";
        cin >> info;

        // Store user input into the file
        ofstream store("store.txt", ios::app);
        if (!store)
        {
            cerr << "Error opening file" << endl;
        }
        else
        {
            store << username << " " << password << " " << info << endl;
            store.close();
        }
    }

    // Function to display user information
    void displayInfo()
    {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Information: " << info << endl;
    }
};

// Function to handle user login
bool log_in(login &acont)
{
    cout << "Enter the username: ";
    string input_username, input_password, u, p, i;
    cin >> input_username;

    ifstream readstore("store.txt");
    if (!readstore)
    {
        cerr << "Error opening file" << endl;
        return false;
    }

    // Read stored user data and validate login credentials
    while (readstore >> u >> p >> i)
    {
        if (u == input_username)
        {
            cout << "Enter the password: ";
            cin >> input_password;
            if (p == input_password)
            {
                acont.username = u;
                acont.password = p;
                acont.info = i;
                cout << "Login successful" << endl;
                acont.displayInfo();
                return true;
            }
            else
            {
                cout << "Invalid password" << endl;
                return false;
            }
        }
    }
    cout << "Username not found" << endl;
    return false;
}

// Function to handle forgotten password
bool forgetpass(login &acont)
{
    string input_username, input_info, u, p, i;
    cout << "Enter your username: ";
    cin >> input_username;
    cout << "Enter your personal info: ";
    cin >> input_info;

    ifstream readstore("store.txt");
    if (!readstore)
    {
        cerr << "Error opening file" << endl;
        return false;
    }

    bool found = false;
    string newpassword; // Declare newpassword here
    ofstream writestore("store_temp.txt", ios::app);
    if (!writestore)
    {
        cerr << "Error opening temporary file" << endl;
        return false;
    }

    // Read stored user data and validate user information
    while (readstore >> u >> p >> i)
    {
        if (u == input_username && i == input_info)
        {
            found = true;
            cout << "Enter the new password: ";
            cin >> newpassword;
            writestore << u << " " << newpassword << " " << i << endl;
        }
        else
        {
            writestore << u << " " << p << " " << i << endl;
        }
    }

    readstore.close();
    writestore.close();

    if (found)
    {
        remove("store.txt");
        rename("store_temp.txt", "store.txt");

        acont.username = input_username;
        acont.password = newpassword; // Now newpassword is accessible here
        acont.info = input_info;
        cout << "Password reset successful" << endl;
        acont.displayInfo();
        return true;
    }
    else
    {
        cout << "Username or personal info not found" << endl;
        remove("store_temp.txt");
        return false;
    }
}
void welcome_page()
{
    cout << "welcome to the ticket booking" << endl;
}
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
bool phonenum(const string &mobilenumber)
{
    // string mobilenumber;
    if (mobilenumber.length() != 10)
    {
        return false;
    }
    for (char c : mobilenumber)
    {
        if (!isdigit(c))
        {
            return true;
        }
        return true;
    }
}
void seat_num(){
   ofstream gstore("gstore.txt", ios::app);
    if (!gstore)
    {
        cerr << "Error opening file" << endl;
    }
    else
    {
        gstore  << seat_num << endl;
        gstore.close();
    }
}

void train()
{
    string mobilenumber,gender;
    int day, month, year,seatnum;
    cout << "TRAIN BOOKING" << endl;
    cout << "train details" << endl;
    cout << "BUS TICKET BOOKING" << endl;
    cout << " |------------------------------------------------------------|" << endl;
    cout << " || " << "TRAIN NAME" << "       ||   " << "TRAVAL TO FROM:" << " ||   " << "timing:" << "       ||" << endl;
    cout << " ||----------------------------------------------------------||" << endl;
    cout << " ||" << "Rajdhani Express" << "  ||" << "Delhi to Mumbai" << "    ||" << "11:00 PM delhi" << "   || " << endl;
    cout << " ||" << "Shatabdi Express" << "  ||" << "Delhi to Chandigarh" << "||" << "8:00 AM delhi" << "    ||" << endl;
    cout << " ||" << "Duronto Express" << "   ||" << "Chennai to Kolkata" << " ||" << " 6:00 PM chennai" << " ||" << endl;
    cout << " ||" << "Garib Rath Express" << "||" << "Mumbai to Ahmedabad" << "||" << " 10:00 AM mumbai" << " ||" << endl;
    cout << " ||" << "Humsafar Express" << "  ||" << "Patna to Delhi" << "     ||" << "5:00 PM patna" << "    ||" << endl;
    cout << " |------------------------------------------------------------|" << endl;
    cout << "enter the passenger name:" << endl;
    string name;
    cin >> name;
    cout << "enter the age:" << endl;
    int age;
    cin >> age;
    cout<<"enter the gender"<<endl;
    cin>>gender;
    cout << "enter the mobilenumber ,10 digit" << endl;
    cin >> mobilenumber;
    if (phonenum(mobilenumber))
    {
        cout << "valid mobilenumber" << endl;
    }
    else
    {
        cout << "invalid formate of mobilenumber,enter the 10 digit number" << endl;
    }
    cout << "Enter the date (dd mm yyyy): ";
    cin >> day >> month >> year;

    if (is_valid_date(day, month, year)) {
        string formatted_date = format_date(day, month, year);
        cout << "Valid date: " << formatted_date << endl;
    } else {
        cout << "Invalid date format. Please enter in dd mm yyyy format." << endl;
    }
    cout << "SELECT TRAIN TO TRUBLE" << "1.is rajdhani express(Delhi to Mumbai ),2 is shtabdi express(Delhi to Chandigarh),3 is duronto express(Chennai to Kolkata),4 is garibrath express (Mumbai to Ahmedabad) and 5 is humsafar express(Patna to Delhi )" << endl;
    int select;
    cin >> select;
    int type;
     cout << "---------------------------------------------------------------------------------------------------|" << endl;
        cout << "       ROUTE       " << "|" << "SLEEPER(INR)  " << "|" << "NON SLEEPER(INR)" << "|" << "AC3rd TIER(INR)" << "|" << "AC2nd TIER(INR)" << "|" << "AC1st TIER(INR)" << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------------|" << endl;
        cout << "Delhi to Mumbai    " << "|" << "1,200-1,500   " << "|" << "1,500 - 2,000   " << "|" << "2,000 - 3,000  " << "|" << "3000-4000      " << "|" << "4000-5000"       << "|" << endl;
        cout << "Delhi to Chandigarh" << "|" << " 600  - 800   " << "|" << "800 - 1000      " << "|" << "1,200 - 1,500  " << "|" << "1500-2000      " << "|" << "4500-5500"       << "|" << endl;
        cout << "Chennai to Kolkata " << "|" << "1,500-2,000   " << "|" << "2,000 -2,500    " << "|" << "2,500 - 3,500  " << "|" << "3500-4500      " << "|" << "3500-4500      " << "|" << endl;
        cout << "Mumbai to Ahmedabad" << "|" << "800  - 1,200  " << "|" << "1200-1600       " << "|" << "1,600 - 2,500  " << "|" << "2500-3500      " << "|" << "3500-4500      " << "|" << endl;
        cout << "Patna to Delhi     " << "|" << "700  - 1,000  " << "|" << "1000-1300       " << "|" << "1,300 - 2,000  " << "|" << "2000-2500      " << "|" << "2500-3000      " << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------------|" << endl;
    switch (select)
    {
    case 1:
        cout << "RAJDHANI EXPRESS" << endl;
         cout<<"delhi to mumbai express(1,200-1,500 ):"<<endl;
        cout << "select seat type :" << "1.is non sleeper,2.is sleeper,3.is AC3rd,4. is AC2nd ,5.is AC1st" << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "NON SLEEPER TICKET BOOKING(1,500 - 2,000)" << endl;
            cout<<"";
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 2:
            cout << "sleepar TICKET BOOKING(1,200-1,500 )" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
            seat_num();
            break;
        case 3:
            cout << "AC3rd TICKET BOOKING(2,000 - 3,000)" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
            seat_num();
            break;
        case 4:
            cout << "AC2nd TICKET BOOKING(1500-2000 )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 5:
            cout << "AC1st TICKET BOOKING(4000-5000) " << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        default:
            break;
        }
        break;
    case 2:
        cout << "SHATABDI EXPRESS" << endl;
         cout<<"Delhi to Chandigarh( 600  - 800 )"<<endl;
        cout << "select seat type :" << "1.is non sleeper,2.is sleeper,3.is AC3rd,4. is AC2nd ,5.is AC1st" << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "NON SLEEPER BOOKING(800 - 1000  )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 2:
            cout << "sleepar TICKET BOOKING(600  - 800 )" << endl;
            cout << "enter the seat number" << endl; 
            cin>>seatnum;
             seat_num();
            break;
        case 3:
             cout << "AC3rd TICKET BOOKING(1,200 - 1,500)" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 4:
            cout << "AC2nd TICKET BOOKING(3000-4000)" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 5:
            cout << "AC1st TICKET BOOKING(4500-5500) " << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        default:
            break;
        }
        break;
    case 3:
        cout << "DURONTO EXPRESS" << endl;
         cout<<"Chennai to Kolkata(1,500-2,000 )"<<endl;
        cout << "select seat type :" << "1.is non sleeper,2.is sleeper,3.is AC3rd,4. is AC2nd ,5.is AC1st" << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "NON SLEEPER TICKET BOOKING(2,000 -2,500  )" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 2:
            cout << "sleepar TICKET BOOKING(1,500-2,000 )" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 3:
            cout << "AC3rd TICKET BOOKING(2,500 - 3,500)" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 4:
            cout << "AC2nd TICKET BOOKING(3500-4500 )" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 5:
            cout << "AC1st TICKET BOOKING(3500-4500 ) " << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        default:
            break;
        }
        break;
    case 4:
        cout << "GAREEBRATH EXPRESS" << endl;
        cout<<"Mumbai to Ahmedabad(800  - 1,200 )"<<endl;
        cout << "select seat type :" << "1.is non sleeper,2.is sleeper,3.is AC3rd,4. is AC2nd ,5.is AC1st" << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "NON SLEEPER TICKET BOOKING(1200-1600 )" << endl;
            cout << "enter the seat number" << endl;
            cin>>seatnum;
             seat_num();
            break;
        case 2:
            cout << "sleepar TICKET BOOKING(800  - 1,200)" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 3:
            cout << "AC3rd TICKET BOOKING(1,600 - 2,500 )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 4:
            cout << "AC2nd TICKET BOOKING(2500-3500  )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 5:
            cout << "AC1st TICKET BOOKING(3500-4500 ) " << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        default:
            break;
        }
        break;
    case 5:
        cout << "HUMSAFAR EXPRESS" << endl;
        cout<<"Patna to Delhi (700  - 1,000 )"<<endl;
        cout << "select seat type :" << "1.is NON SLEEPER,2.is sleeper,3.is AC3rd,4. is AC2nd ,5.is AC1st" << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "NON SLEEPER TICKET BOOKING(1000-1300   )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 2:
            cout << "sleepar TICKET BOOKING(700  - 1,000 )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 3:
         cout << "AC3rd TICKET BOOKING(1,300 - 2,000)" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 4:
            cout << "AC2nd TICKET BOOKING(2000-2500 )" << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        case 5:
            cout << "AC1st TICKET BOOKING(2500-3000 ) " << endl;
            cout << "enter the seat number" << endl;
             cin>>seatnum;
              seat_num();
            break;
        default:
            cout << "invalid input" << endl;
            break;
        }
        break;
    default:
        cout << "invalid input:" << endl;
        break;
    }
     cout<<"~~~~~YOUR TICKET IS SUCCESSFULLY BOOKED~~~~~~~"<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"date: "<<day<<"/"<<month<<"/"<<year<<endl;
    cout<<"mobilenumber: "<<mobilenumber<<endl;
    cout<<"train info "<< select<< type<<endl;
    cout<<"seat num: "<<seatnum<<endl;


}

void bus()
{
    string from;
    int seatnum;
    string to;
    string mobilenumber;
    int day, month, year;
    string male,female;
    string choose;
    cout << "BUS TICKET BOOKING" << endl;
    cout << " -----------------------------------------------------------------------------------------------|" << endl;
    cout << " ||" << "BUS NAME:" << "               ||" << "TRAVAL TO FROM:" << "    ||   " << "TRAVAL TIME:" << "     ||   " << "BUS TYPE:" << "           || " << endl;
    cout << " ||--------------------------------------------------------------------------------------------||" << endl;
    cout << " ||" << "Hans Travels" << "            ||" << "Indore to Bhopal" << "   ||" << "Approx: 4-5 hours" << "   ||" << "Volvo, AC Sleeper:" << "     || " << endl;
    cout << " ||" << "Pallavi mp bus" << "          ||" << "Pune to Indore" << "     ||" << "Approx: 10-12 hours" << " ||" << "AC Sleeper, Semi-Deluxe" << "||" << endl;
    cout << " ||" << "Hans Travels" << "            ||" << "Ujjain to Delhi" << "    ||" << " Approx: 12-14 hours" << "||" << "Volvo, AC Seater" << "       || " << endl;
    cout << " ||" << "MP Transport Corporation" << "||" << "Gwalior to Jhansi" << "  ||" << " Approx: 2-3 hours" << "  ||" << "Ordinary" << "               || " << endl;
    cout << " ||" << "MPRTC" << "                   ||" << "Bhopal to Jabalpur" << " ||" << "Approx: 6-7 hours" << "   ||" << "Deluxe, AC Seater" << "      || " << endl;
    cout << " -----------------------------------------------------------------------------------------------|" << endl;
    cout << "enter the pasenger full name" << endl;
    string name;
    cin >> name;
    cout << "enter the pesenger gendar" << endl;
    string gender;
    cin >> gender;
    cout << "Enter the date (dd mm yyyy): ";
    cin >> day >> month >> year;

    if (is_valid_date(day, month, year)) {
        string formatted_date = format_date(day, month, year);
        cout << "Valid date: " << formatted_date << endl;
    } else {
        cout << "Invalid date format. Please enter in dd mm yyyy format." << endl;
    }
    cout << "enter the mobilenumber ,10 digit" << endl;
    cin >> mobilenumber;
    if (phonenum(mobilenumber))
    {
        cout << "valid mobilenumber" << endl;
    }
    else
    {
        cout << "invalid formate of mobilenumber,enter the 10 digit number" << endl;
    }
    cout << "select the bus and booked the ticket : enter the 1 is hanse travals,2 is pallavi travals,3 is hanse traval,4 is mp transport corporation,5 is mprtc" << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "HANS TRAVAL BUS" << endl;
        cout << "TRAVAL INDORE TO BHOPAL" << endl;
        cout << "PRICE" << endl;
        cout<<"choose the seat type:AC.AC seat price is ₹600 - ₹800,sleeper . if you choose sleeper seat price is ₹400 - ₹600"<<endl;
        cin>>choose;
        if(choose=="AC"){
            cout << "AC seat: " << " ₹600 - ₹800" << endl;
        }
        else if(choose=="sleeper"){
            cout << "SELEPER seat:" << " ₹400 - ₹600" << endl;
        }
        else{
            cout<<"invalid input"<<endl;
        }
        cout << "enter the seat number:" << endl;
        cin >> seatnum; seat_num();

        cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;
        break;
    case 2:
        cout << "PALLAVI MP BUS :" << endl;
        cout << "TRAVAL PUNE TO INDORE:" << endl;
        cout << "PRICE" << endl;
         cout<<"choose the seat type:AC.AC seat price is ₹1,200 - ₹1,800, IF you choose sleeper .sleeper seat price is ₹800 - ₹1,200"<<endl;
        cin>>choose;
        if(choose=="AC"){
            cout << "AC seat: " << "  ₹1,200 - ₹1,800" << endl;
        }
        else if(choose=="sleeper"){
            cout << "SELEPER seat:" << " ₹800 - ₹1,200" << endl;
        }
        else{
            cout<<"invalid input"<<endl;
        }
        cout << "enter the seat number:" << endl;
        cin >> seatnum; seat_num();
        cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;
        break;
    case 3:
        cout << "HANS TRAVAL BUS" << endl;
        cout << "TRAVAL UJJAIN TO DELHI" << endl;
        cout << "PRICE" << endl;
       cout<<"choose the seat type:AC.AC seat price is ₹400 - ₹600,sleeper .NON sleeper seat price is ₹200 - ₹300"<<endl;
        cin>>choose;
        if(choose=="AC"){
            cout << "AC seat: " << " ₹400 - ₹600" << endl;
        }
        else if(choose==" nonsleeper"){
            cout << "NON SELEPER seat:" << "₹200 - ₹300" << endl;
        }
        else{
            cout<<"invalid input"<<endl;
        }
        cout << "enter the seat number:" << endl;
        cin >> seatnum; seat_num();
        cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;
        break;
    case 4:
        cout << "MP TRANSPORT CORPORATION:" << endl;
        cout << "TRAVAL GWOLIAR TO JHANSHI" << endl;
        cout << "PRICE" << endl;
        cout<<"this bus is only for ordinary seat available"<<endl;
        cout<<"price is"<<"₹200 - ₹300"<<endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum; seat_num();
        cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;
        break;
    case 5:
        cout << "MPRTC" << endl;
        cout << "BHOPAL TO JABALPUR" << endl;
        cout << "PRICE" << endl;
      cout<<"choose the seat type:AC.AC seat price is₹600 - ₹900, if you select sleeper .sleeper seat price is ₹500 - ₹800"<<endl;
        cin>>choose;
        if(choose=="AC"){
            cout << "AC seat: " << "  ₹600 - ₹900" << endl;
        }
        else if(choose=="sleeper"){
            cout << "SELEPER seat:" << " ₹500 - ₹800" << endl;
        }
        else{
            cout<<"invalid input"<<endl;
        }
        cout << "enter the seat number:" << endl;
        cin >> seatnum; seat_num();
        cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;
        break;
    default:
        cout << "invalid input" << endl;
        break;
    }
     cout<<"~~~~~YOUR TICKET IS SUCCESSFULLY BOOKED~~~~~~~"<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"gender: "<<gender<<endl;
    cout<<"date: "<<day<<"/"<<month<<"/"<<year<<endl;
    cout<<"mobilenumber: "<<mobilenumber<<endl;
    cout<<"traval date: "<<day<<"/"<<month<<"/"<<year<<endl;
    cout<<"busname and route: "<<select<<endl;
    cout<<"price of your selected seat: "<<choose<<endl;
    cout<<"seat num: "<<seatnum<<endl;
    cout<<"ride start from: "<<from<<endl;
    cout<<"ride end to: "<<to<<endl;
}

void plain()
{
    string from;
    int seatnum;
    string to;
    string mobilenumber;
    int day, month, year;
    cout << "PLAIN TICKETBOOKING" << endl;
    cout << " --------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << " ||" << "FLIGHT NAME :" << "      ||" << "FLIGHT ROOT:" << "                      || " << "LEANDING TIME:" << "||   " << "PRICE:" << "               ||       " << "HOUR" << "        ||" << endl;
    cout << " ||-----------------------------------------------------------------------------------------------------------------------||" << endl;
    cout << " ||" << "  Indigo Airlines" << "  ||" << "Delhi (DEL) to Mumbai (BOM)" << "       ||" << "10:30 AM (IST)" << " ||" << "Starting from INR 4,500:" << "||" << "2 hours 30 minutes" << " || " << endl;
    cout << " ||" << ".   Air India" << "      ||" << " Bangalore (BLR) to Chennai (MAA)" << " ||" << "8:45 AM (IST)" << "  ||" << "Starting from INR 3,800" << " ||" << "1 hour 15 minutes" << "  ||" << endl;
    cout << " ||" << "   SpiceJet" << "        ||" << "Hyderabad (HYD) to Kolkata (CCU)" << "  ||" << "12:30 PM (IST)" << " ||" << " Starting from INR 4,200" << "|| " << "2 hours 30 minutes" << "||" << endl;
    cout << " ||" << "    GoAir" << "          ||" << "Pune (PNQ) to Delhi (DEL)" << "         ||" << "  9:30 AM (IST)" << "||" << "Starting from INR 4,000" << " || " << "2 hours 30 minutes" << "||" << endl;
    cout << " ||" << "   Vistara Airlines" << "||" << "Mumbai (BOM) to Bangalore (BLR)" << "   ||" << "11:30 AM (IST)" << " ||" << "Starting from INR 5,000" << " || " << " 1 hour 45 minutes" << "||" << endl;
    cout << " --------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "enter the pasenger full name" << endl;
    string name;
    cin >> name;
    cout << "enter the age:" << endl;
    int age;
    cin >> age;
    cout << "enter the pesenger gendar" << endl;
    string gendar;
    cin >> gendar;
    cout << "Enter the date (dd mm yyyy): ";
    cin >> day >> month >> year;

    if (is_valid_date(day, month, year)) {
        string formatted_date = format_date(day, month, year);
        cout << "Valid date: " << formatted_date << endl;
    } else {
        cout << "Invalid date format. Please enter in dd mm yyyy format." << endl;
    }
    cout << "enter the mobilenumber ,10 digit" << endl;
    cin >> mobilenumber;
    if (phonenum(mobilenumber))
    {
        cout << "valid mobilenumber" << endl;
    }
    else
    {
        cout << "invalid formate of mobilenumber,enter the 10 digit number" << endl;
    }
    cout << "select the bus and booked the ticket : enter the 1 is Indigo Airlines,2 is Air India,3 is SpiceJet,4 is GoAir,5 is Vistara Airlines" << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "INDIGO AIRLINES" << endl;
        cout << "PRICE" << endl;
        cout << "Delhi (DEL) to Mumbai (BOM): Around ₹4,000" << endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum;
       // cout << "ride start from" << endl;
      //  cin >> from;
       // cout << "ride end to" << endl;
       // cin >> to;
        break;
    case 2:
        cout << "AIR INDIA :" << endl;
        cout << "PRICE" << endl;
        cout << "Bangalore (BLR) to Chennai (MAA): Around ₹2,310" << endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum;
       /* cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;*/
        break;
    case 3:
        cout << "SPICEJET" << endl;
        cout << "PRICE" << endl;
        cout << "Hyderabad (HYD) to Kolkata (CCU): around ₹3,000 - ₹4,000" << endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum;
        /*cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;*/
        break;
    case 4:
        cout << "GOAIR:" << endl;
        cout << "PRICE" << endl;
        cout << "Pune (PNQ) to Delhi (DEL): Around ₹2,500 - ₹3,500" << endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum;
       /*cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;*/
        break;
    case 5:
        cout << "VISTRA AIRLINES" << endl;
        cout << "PRICE" << endl;
        cout << "Mumbai (BOM) to Bangalore (BLR): Around ₹3,000 - ₹4,000" << endl;
        cout << "enter the seat number:" << endl;
        cin >> seatnum;
       /* cout << "ride start from" << endl;
        cin >> from;
        cout << "ride end to" << endl;
        cin >> to;*/
        break;
    default:
        cout << "invalid input" << endl;
        break;
    }
    cout<<"~~~~~YOUR TICKET IS SUCCESSFULLY BOOKED~~~~~~~"<<endl;
       cout<<"name: "<<name<<endl;
    cout<<"gender: "<<gendar<<endl;
    cout<<"date: "<<day<<"/"<<month<<"/"<<year<<endl;
    cout<<"mobilenumber: "<<mobilenumber<<endl;
    cout<<"flight name and route: "<<select<<endl;
    cout<<"seat num: "<<seatnum<<endl;
}

int main()
{
    login acont;
    cout << "Select the option: 1. Create account, 2. Login, 3. Forgot Password" << endl;
    int select;
    cin >> select;
    if (select == 1)
    { 
        acont.create();
        cout << "Your profile is created" << endl;
        welcome_page();
        cout << "choose the 1. is train booking, 2.is bus booking and 3. is plane booking " << endl;
        int choose;
        cin >> choose;
        if (choose == 1)
        {
            train();
        }
        else if (choose == 2)
        {
            bus();
        }
        else
        {
            plain();
        }
    }
    else if (select == 2)
    {
        if (log_in(acont))
        {
            cout << "Login successful" << endl;
            welcome_page();
            cout << "choose the 1. is train booking, 2.is bus booking and 3. is plane booking " << endl;
            int choose;
            cin >> choose;
            if (choose == 1)
            {
                train();
            }
            else if (choose == 2)
            {
                bus();
            }
            else
            {
                plain();
            }
        }
        else
        {
            cout << "Login failed" << endl;
        }
    }
    else if (select == 3)
    {
        if (forgetpass(acont))
        {
            cout << "Password reset successful" << endl;
            welcome_page();
            cout << "choose the 1. is train booking, 2.is bus booking and 3. is plane booking " << endl;
            int choose;
            cin >> choose;
            if (choose == 1)
            {
                train();
            }
            else if (choose == 2)
            {
                bus();
            }
            else
            {
                plain();
            }
        }
        else
        {
            cout << "Password reset failed" << endl;
        }
    }
    return 0;
}