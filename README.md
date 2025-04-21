# Online Ticket Booking System

A comprehensive C++ based ticket booking system that allows users to book tickets for trains, buses, and flights. This system provides a user-friendly interface for managing travel bookings with various features including user authentication, ticket booking, and seat selection.

## Features

### User Management
- User registration and login system
- Password recovery functionality
- Secure storage of user credentials

### Transportation Options
1. **Train Booking**
   - Multiple train options (Rajdhani Express, Shatabdi Express, etc.)
   - Different seat classes (Sleeper, Non-Sleeper, AC 3rd Tier, AC 2nd Tier, AC 1st Tier)
   - Seat number selection
   - Price display for different routes and classes

2. **Bus Booking**
   - Various bus operators (Hans Travels, Pallavi MP Bus, etc.)
   - Different seat types (AC, Sleeper, Ordinary)
   - Route selection
   - Price display for different routes and seat types

3. **Flight Booking**
   - Multiple airlines (Indigo, Air India, SpiceJet, etc.)
   - Different routes and timings
   - Seat selection
   - Price display for different routes

### Additional Features
- Date validation for bookings
- Phone number validation
- Detailed booking confirmation
- User information management

## Technical Details

### Dependencies
- Standard C++ libraries
- No external dependencies required

### File Structure
- `main.cpp`: Contains the main program logic
- `store.txt`: Stores user credentials and information
- `gstore.txt`: Stores seat booking information

### Data Validation
- Phone number validation (10 digits)
- Date validation (dd/mm/yyyy format)
- User authentication validation

## Usage

1. **Account Management**
   ```
   Select the option:
   1. Create account
   2. Login
   3. Forgot Password
   ```

2. **Booking Process**
   - Choose transportation type (Train/Bus/Flight)
   - Select specific service provider
   - Choose seat type and number
   - Enter travel details
   - Confirm booking

## Booking Information Display

### Train Booking
- Displays train name, route, and timing
- Shows different seat classes and their prices
- Provides seat number selection

### Bus Booking
- Shows bus operator details
- Displays route information
- Provides seat type selection with prices

### Flight Booking
- Displays airline information
- Shows route details and timing
- Provides seat selection options

## Security Features
- Secure password storage
- User authentication system
- Password recovery with personal information verification

## Future Enhancements
- Online payment integration
- Email/SMS booking confirmation
- Booking history tracking
- Cancellation and refund system
- Multiple passenger booking
- Seat availability checking

## Getting Started

1. Clone the repository
2. Compile the code using a C++ compiler
3. Run the executable
4. Follow the on-screen instructions for booking

## Contributing
Feel free to contribute to this project by:
- Reporting bugs
- Suggesting new features
- Improving documentation
- Submitting pull requests

## License
This project is open-source and available for personal and educational use.

## Contact
For any queries or suggestions, please open an issue in the repository. 
