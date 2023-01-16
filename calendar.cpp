using namespace std;
#include <iostream>
#include <cstdlib>

string monthName(int monthNumber) /// to find the months name 
{
    string months[] = {"January", "February", "March","April", "May", "June","July", "August", "September","October", "November", "December"};
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

    if (monthNumber == 0)
        return (31); 

    if (monthNumber == 1) //Jan
    {
        // leap years have 29 days in feb
    
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29); //leap Feb
        else
            return (28); //Feb
    }

    if (monthNumber == 2)
        return (31); // March

    if (monthNumber == 3)
        return (30); //April

    if (monthNumber == 4)
        return (31); //May

    if (monthNumber == 5)
        return (30); //June

    if (monthNumber == 6)
        return (31); //July

    if (monthNumber == 7)
        return (31); //Aug 

    if (monthNumber == 8)
        return (30); //Sept

    if (monthNumber == 9)
        return (31); // Oct

    if (monthNumber == 10)
        return (30); // Nov

    if (monthNumber == 11)
        return (31); // Dec
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
    cout << monthName(month) + printCalendarYear(year) + "\n";
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
    cout << "Would you like a monthly calendar (press 2 or yearly and 1 for monthly)" << endl;
    cin >> type;
    if (type == 2)
    {
        cout << "enter the year" << endl;
        cin >> year;
        printCalendarYear(year);
    }
    if (type == 1)
    {
        cout << "Enter year then month" << endl;
        cin >> year;
        cin >> monthNumber;
        printCalendarMonth(year, monthNumber);
    }

    return (0);
}