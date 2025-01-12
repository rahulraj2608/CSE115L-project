Documentation for Bus Ticket Reservation System Project
Overview
This Bus Ticket Reservation System allows passengers to register, log in, view available buses, book seats, cancel tickets, and view ticket details. It also provides an administrative interface to manage buses. The system is implemented in C, with a file-based approach for data persistence.

Features
Passenger Registration: Users can create a new account with a name, phone number, and password.
Login System: Passengers can log in using their phone number and password.
Bus Seat Booking: Passengers can view available buses, check seat availability, and book tickets.
Ticket Cancellation: Users can cancel tickets based on the ticket number and their phone number.
Ticket Printing: Once a seat is booked, a ticket is generated and saved to a file.
Admin Panel: Admins can add new buses to the system, view bus details, and manage seat bookings.
File Structure
The system relies on the following text files for storing data:

passengers.txt: Stores passenger information (name, ID, phone, password).
count.txt: Tracks the total number of passengers.
bus.txt: Stores bus information (route, bus number, date, time).
bus_count.txt: Tracks the total number of buses.
seats.txt: Stores seat booking information (seat number, bus number, passenger details, ticket number).
cancel_seats.txt: Stores canceled seat details.
ticket.txt: Stores ticket details for printed tickets.
Functions
1. registerUser()
Registers a new user by taking the name, phone number, and password as input. It checks if the user count is less than 40 before allowing registration. The new user's details are saved in passengers.txt.

2. *login(FILE file, char phone[], char password[])
Validates the user's phone number and password against the data in passengers.txt. Returns the user ID if credentials match; otherwise, returns -1.

3. *passenger_fetch(FILE file, int userIndex, char name[])
Fetches the name of a passenger by their user ID.

4. print_ticket(int seat, int bus, char name[], char phone[], int ticket)
Prints a ticket with details such as passenger name, phone, bus number, seat number, and ticket number. Also includes the bus route, date, and time.

5. cancel_ticket()
Allows a passenger to cancel a ticket by providing their phone number and ticket number. If the ticket is found, it is removed, and the seat becomes available.

6. book_seat(int seat, int bus, char name[], char phone[])
Books a seat for the passenger, assigns a random ticket number, and saves the details to seats.txt. A ticket is printed and saved to ticket.txt.

7. display_bus()
Displays all the booked seats for a specific bus from seats.txt.

8. check_seat(int bus, int seat)
Checks if a specific seat on a bus is already booked or not by checking seats.txt.

9. display_seats(int bus, char name[], char phone[])
Displays available seats for a given bus. If a seat is available, it can be booked by the passenger.

10. add_bus()
Allows the admin to add a new bus by entering the route number, date, and time. The bus is saved to bus.txt.

11. get_bus(char name[], char phone[])
Displays a list of available buses for booking. Passengers can select a bus and book a seat.

12. admin()
Provides the administrative interface, allowing the admin to:

Add new buses.
View the seat bookings for a specific bus.
13. main()
The entry point of the system, where the user is presented with a menu. The user can choose between registering, logging in, canceling a ticket, or accessing the admin panel.

Admin Panel
The admin panel provides the following options:

Add a new bus: The admin can add a new bus by providing the route number, date, and time.
Get data of a bus: The admin can view all seat bookings for a particular bus.
Exit: The admin can exit the admin panel.
Admin Authentication
The admin is authenticated by a pre-defined password (abc123).

How It Works
User Registration:

A user registers by entering their name, phone number, and password. The system checks if the user limit (40 passengers) is reached. If not, the details are saved in passengers.txt, and the user count is updated in count.txt.
Login:

A user can log in using their phone number and password. If the credentials are correct, they are given access to book seats.
Booking a Seat:

The passenger is shown a list of available buses. After selecting a bus, the available seats are displayed. The passenger can choose a seat to book, which is saved in seats.txt. A ticket is generated and saved to ticket.txt.
Ticket Cancellation:

If a passenger wants to cancel a ticket, they provide their phone number and ticket number. The system looks for the matching entry in seats.txt and removes it. The canceled seat is stored in cancel_seats.txt.
Admin Functions:

Admins can add buses to the system and manage bus information (route, date, time). Admins can also view the booking details of all passengers for each bus.
Error Handling
File Errors: The system checks if files open correctly (e.g., fopen() returning NULL).
Input Validation: Ensures correct data types are entered for user registration, login, and seat booking.
Future Enhancements
User Interface: A graphical user interface (GUI) for better user interaction.
Payment Integration: Implement payment processing for online ticket bookings.
Data Encryption: Encrypt sensitive data like passwords for enhanced security.
This documentation provides an overview of the project, its functionalities, and how it works. It describes the core features of the Bus Ticket Reservation System, its file structure, functions, and future possibilities for improvement.