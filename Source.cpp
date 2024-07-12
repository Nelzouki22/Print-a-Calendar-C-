#include <iostream>
#include <iomanip>

using namespace std;

// Function to check if the given year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
    case 1: return 31;
    case 2: return isLeapYear(year) ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}

// Function to get the day of the week for the first day of the given month and year
int getStartDay(int month, int year) {
    int d = 1;
    int m = (month + 9) % 12 + 1;
    int y = year - (month <= 2);
    int k = y % 100;
    int j = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
    return (h + 5) % 7;
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    int startDay = getStartDay(month, year);
    int daysInMonth = getDaysInMonth(month, year);

    for (int i = 0; i < startDay; ++i) {
        cout << "     ";
    }

    for (int day = 1; day <= daysInMonth; ++day) {
        cout << setw(5) << day;
        if ((day + startDay) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int year = 2024;
    int month = 7;

    cout << "Calendar for " << month << "/" << year << ":" << endl;
    printCalendar(month, year);

    return 0;
}
