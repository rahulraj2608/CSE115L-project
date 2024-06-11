#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Passenger
{
    char name[100];
    int id;
    char phone[100];
    char password[100];
};
struct seat
{
    int number;
    int bus;
    char name[100];
    char phone[50];
    int ticket_no;
    int booked;
};
struct bus
{
    int route;
    int num;
    char date[50];
    char time[50];
    struct seat seats[40];
};

void registerUser()
{
    int count = 0;
    FILE *file1;
    FILE *file = fopen("passengers.txt", "a+"); // Open the file for appending and reading

    if (file == NULL)
    {
        printf("Error opening the file.\n");
    }
    // Open the file for reading
    file1 = fopen("count.txt", "r");
    if (file1 != NULL) {
        fscanf(file1, "%d",&count);
        fclose(file1);
    }
    if (count < 40)
    {
        struct Passenger newPassenger;

        printf("Enter a name: ");
        scanf("%s", newPassenger.name);
        printf("Enter a password: ");
        scanf("%s", newPassenger.password);
        printf("Enter phone number: ");
        scanf("%s", newPassenger.phone);
        newPassenger.id = count;

        fprintf(file, "%s %d %s %s\n", newPassenger.name, newPassenger.id, newPassenger.phone, newPassenger.password);

        printf("Registration successful.\n");
    }
    else
    {
        printf("User limit reached. Registration failed.\n");
    }
     count++;

    // Open the file for writing
    file1 = fopen("count.txt", "w");
    if (file1 != NULL) {
        fprintf(file1, "%d", count);
        fclose(file1);
    }
     fclose(file);
}

int login(FILE *file, char phone[], char password[])
{
    struct Passenger currentPassenger;

    while (fscanf(file, "%s %d %s %s\n", currentPassenger.name, &currentPassenger.id, currentPassenger.phone, currentPassenger.password) != EOF)
    {
        if (strcmp(currentPassenger.phone, phone) == 0 && strcmp(currentPassenger.password, password) == 0)
        {
            return currentPassenger.id;
        }
    }
    return -1; // User not found
}

void passenger_fetch(FILE *file,int userIndex,char name[])
{
    struct Passenger currentPassenger;

    while (fscanf(file, "%s %d %s %s\n", currentPassenger.name, &currentPassenger.id, currentPassenger.phone, currentPassenger.password) != EOF)
    {
        if (currentPassenger.id==userIndex)
        {
           strcpy(name,currentPassenger.name);
        }
    }

}
void print_ticket(int seat,int bus,char name[],char phone[],int ticket){
    struct bus bus1;
    FILE *file1=fopen("bus.txt","r");
    FILE *file = fopen("ticket.txt","a+");
    fprintf(file,"My tickets service\n");
    fprintf(file,"Passenger Name:\t %s \n",name);
    fprintf(file,"Phone:\t %s\n",phone);
    fprintf(file,"Ticket number: %d\n",ticket);
    fprintf(file,"Bus no : %d\n",bus);
    fprintf(file,"seat no: %d\n",seat);
       while (fscanf(file1, "%d %d %s %s\n", &bus1.route, &bus1.num, bus1.date, bus1.time) != EOF){
        if(bus1.num==bus){
            fprintf(file,"Route is %d\n",bus1.route);
            fprintf(file,"Journey date is %s\n",bus1.date);
            fprintf(file,"journey time is %s\n",bus1.time);
        }
      }
      fclose(file1);
    fclose(file);

}
void cancel_ticket(){
    char phone[50];
    int ticket;
    printf("Enter phone number:");
    scanf("%s",phone);
    printf("Enter ticket number:");
    scanf("%d",&ticket);
     struct seat seat1;
    int i=1;
    FILE *file =fopen("seats.txt","r");
        while (fscanf(file, "%d %d %s %s %d\n",&seat1.number, &seat1.bus, seat1.name, seat1.phone,&seat1.ticket_no) != EOF)
        {
           
          if(seat1.ticket_no==ticket && strcmp(seat1.phone,phone)==0){
             i=0;
            FILE *file1=fopen("cancel_seats.txt","a");
            fprintf(file1,"%d %d \n",seat1.bus,seat1.number);
            fclose(file1);
            break;
         }
        }
    fclose(file);

        if(i==0){
            printf("ticket deleted\n");
        }else{
            printf("ticket not found\n");
        }
    
}
void book_seat(int seat,int bus,char name[],char phone[]){
    int ticket=rand();
    FILE *file=fopen("seats.txt","a");
    fprintf(file,"%d %d %s %s %d\n",seat,bus,name,phone,ticket);
    fclose(file);
    printf("\nYour ticket number is %d\n",ticket);
    print_ticket(seat,bus,name,phone,ticket);
    printf("your ticket is printed as ticket.txt\n");
}
void display_bus()
{
    int bus;
    printf("Enter bus number:");
    scanf("%d",&bus);
   struct seat seat1;
    FILE *file =fopen("seats.txt","r");
        while (fscanf(file, "%d %d %s %s %d\n",&seat1.number, &seat1.bus, seat1.name, seat1.phone,seat1.ticket_no) != EOF)
        {
            if(seat1.bus==bus){
            printf("Seat %d\t",seat1.number);
            printf("Name %s\t",seat1.name);
            printf("Phone %s\n",seat1.phone);
            }
        }
    fclose(file);
}
int check_seat(int bus,int seat){
    struct seat seat1;
    int i=1;
    FILE *file =fopen("seats.txt","r");
        while (fscanf(file, "%d %d %s %s %d\n",&seat1.number, &seat1.bus, seat1.name, seat1.phone,seat1.ticket_no) != EOF)
        {
            if(seat1.bus==bus && seat1.number==seat){
                i=0;
                break;
            }
        }
    fclose(file);
    return i;
}
void display_seats(int bus,char name[],char phone[])
{
    int i,j,seat;

    printf("Siting pattern: \n");
    printf("1 2\t\t3 4\n");
    printf("5 6\t\t7 8\n");
    printf("9 10\t\t11 12\n");
    printf("13 14\t\t15 16\n");
    printf("17 18\t\t19 20\n");
    printf("21 22\t\t23 24\n");
    printf("25 26\t\t27 28\n");
    printf("29 30\t\t31 32\n");
    printf("33 34\t\t35 36\n");
    printf("37 38\t\t39 40\n");
    printf("\nAvailable seats:\n");
    for (i = 0; i < 40; i++)
    {
        if (check_seat(bus,i+1)==1)
        {
            printf("%d\n",i+1);
        }
    }
    int seat_number;
    int bus_number;
    FILE *file1=fopen("cancel_seats.txt","r");
    while(fscanf(file1,"%d %d\n",&bus_number,&seat_number)!= EOF){
        if(bus_number==bus){
            printf("%d\n",seat_number);
        }
    }
    fclose(file1);

    printf("\nEnter sit number:");
    scanf("%d",&seat);
    book_seat(seat,bus,name,phone);
}
void add_bus()
{      int count,route;
      FILE *file1 =fopen("bus_count.txt","r");
    fscanf(file1,"%d",&count);

    fclose(file1);
    FILE *file =fopen("bus.txt","a+");
    char date[50];
    char time[50];
    printf("Add bus\n");
    printf("Enter route number:");
    scanf("%d",&route);
    printf("Enter date:");
    scanf("%s", date);
    printf("Enter time:");
    scanf("%s", time);
   fprintf(file,"%d %d %s %s \n",route,count,date,time);
   count = count + 1;
   FILE *file2= fopen("bus_count.txt","w");
   fprintf(file2,"%d",count);
   fclose(file2);

}

void get_bus(char name[],char phone[])
{
    int bus=-1;
    struct bus bus1;
    FILE *file= fopen("bus.txt","r");
    printf("\nList of available buses\n");
    printf("Route 1: Dhaka -> Jessore\n");
    printf("Route 2: Jessore -> Dhaka\n");
    printf("Route 3: Dhaka -> Khulna\n");
    printf("Route 4: Khulna -> Dhaka\n");
    printf("Route 5: Dhaka -> Barishal\n");
    printf("Route 6: Barishal -> Dhaka\n");
    printf("\nRoute\tNumber\tdate\ttime\n");
      while (fscanf(file, "%d %d %s %s\n", &bus1.route,&bus1.num,bus1.date,bus1.time) != EOF)
    {
        printf("%d\t%d\t%s\t%s\n",bus1.route,bus1.num,bus1.date,bus1.time);


    }
     printf("Enter bus number to book seat:");
        scanf("%d",&bus);
        if(bus>=0){
            display_seats(bus,name,phone);
        }

}

int admin(struct bus buses[])
{
    int choice;
    printf("Welcome to admin panel\n");
    while (1)
    {

        printf("1.Add new bus\n");
        printf("2.Get data of a bus\n");
        printf("3.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_bus(buses);
            break;
        case 2:
            display_bus();
            break;
        case 3:
            return 0;

        default:
            printf("Invalid input");
        }
    }
    return 0;
}

int main()
{
     char phone[100];
     char password[100];
     char name[100];
    int i, j;
    struct bus buses[30];

    int Count=0;
    char admin_pass[50] = "abc123";
    char pass[50];
    int choice;


    while (1)
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Cancel ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            registerUser();

            break;
        case 2:

            printf("Enter your phone number: ");
            scanf("%s", phone);
            printf("Enter your password: ");
            scanf("%s", password);
            FILE *file = fopen("passengers.txt", "r");
            int userIndex = login(file, phone, password);
            if (userIndex >= 0)
            {
                rewind(file);
                passenger_fetch(file,2,name);
                printf("Login successfull.Welcome ");
                printf("%s\n",name);
                get_bus(name,phone);
            }

            else
            {
                printf("Login failed. Incorrect phone number or password.\n");
            }
            fclose(file);
            break;
        case 3:
                cancel_ticket();
            break;   
        case 4:
         printf("Goodbye!\n");
            return 0;
        
        case 5:
            printf("Enter admin password:");
            scanf("%s", pass);
            if (strcmp(pass, admin_pass) == 0)
            {
                admin(buses);
            }
            break;
        default:
            printf("Invalid. Please try again.\n");
        }
    }

    return 0;
}
