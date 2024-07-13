#include <iostream>
#include <iomanip>

int main() {
    // Get the current year and month
    int year, month;
    std::cout << "Enter the year: ";
    std::cin >> year;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    // Calculate the number of days in the given month
    int daysInMonth;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            daysInMonth = 29; // Leap year
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    // Print the calendar header
    std::cout << std::setw(12) << "Sun" << std::setw(6) << "Mon" << std::setw(6) << "Tue"
              << std::setw(6) << "Wed" << std::setw(6) << "Thu" << std::setw(6) << "Fri"
              << std::setw(6) << "Sat" << std::endl;

    // Calculate the day of the week for the first day of the month
    int startDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; i++) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                startDay += 29; // Leap year
            } else {
                startDay += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            startDay += 30;
        } else {
            startDay += 31;
        }
    }
    int dayOfWeek = startDay % 7;

    // Print the calendar
    for (int i = 0; i < dayOfWeek; i++) {
        std::cout << std::setw(6) << " ";
    }
    for (int day = 1; day <= daysInMonth; day++) {
        std::cout << std::setw(6) << day;
        if ((day + dayOfWeek) % 7 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}