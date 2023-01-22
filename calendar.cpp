using namespace std;
#include <iostream>
#include <cstdlib>

string monthName(int monthNumber) /// to find the months name 
{
    string months[] = {"","January", "February", "March","April", "May", "June","July", "August", "September","October", "November", "December"};
    return (months[monthNumber]);
}

//  in order to find the first day
int firstDay(int day, int month, int year)
{

    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1,
                      4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 +
            year / 400 + t[month - 1] + day) %
           7;
}

int numOfDays(int monthNumber, int year) // finds the number of days in that month
{

    if (monthNumber == 1)//Jan
        return (31); 

    if (monthNumber == 2)  //Feb
    {
        // leap years have 29 days in feb
    
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29); //leap Feb
        else
            return (28);
    }

    if (monthNumber == 3)// March
        return (31); 

    if (monthNumber == 4)//April
        return (30); 

    if (monthNumber == 5)//May
        return (31); 

    if (monthNumber == 6)//June
        return (30); 

    if (monthNumber == 7)//July
        return (31); 

    if (monthNumber == 8)//Aug
        return (31);  

    if (monthNumber == 9)//Sept
        return (30); 

    if (monthNumber == 10)// Oct
        return (31); 

    if (monthNumber == 11)// Nov
        return (30); 

    if (monthNumber == 12)// Dec
        return (31); 
    return monthNumber; 
}

void printCalendarYear(int year)
{

    int days;

    
    int current = firstDay(1, 1, year); // days mon = 0 sunday = 6

    for (int i = 0; i < 12; i++)
    {
        days = numOfDays(i, year);

        
        cout << monthName(i).c_str(); // the months name
        
        cout << "  \n"
                "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        
        int k; // spacing between days
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}
void printCalendarMonth(int year, int month) ///For the month and year option
{
    int days;
    int current = firstDay(1, month, year);
    days = numOfDays(month, year);

    // Prints the month name
    cout << monthName(month) <<" " << year << "\n";
    // Prints columns
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    // Prints spaces
    int k;
    for (k = 0; k < current; k++)
        printf("     ");

    for (int j = 1; j <= days; j++)
    {
        printf("%5d", j);

        if (++k > 6)
        {
            k = 0;
            printf("\n");
        }
    }

    if (k)
        printf("\n");

    current = k;
}

int main()
{
    int monthNumber;
    int year;
    int type;
    cout << "Which Calendar would you like (a monthly calendar press 1 or a yearly press 2)" << endl;
    cin >> type;
    if (type == 2)
    {
        cout << "Enter the year" << endl;
        cin >> year;
        printCalendarYear(year);
    }
    if (type == 1)
    {
        cout << "Enter the year number then the month number (1-12)" << endl;
        cin >> year;
        cin >> monthNumber;
        printCalendarMonth(year, monthNumber);
    }

    return (0);
}