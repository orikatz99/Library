#ifndef DATE_H
#define DATE_H

// Array with the number of days in each month for non-leap years
//We defined February as 28 days
const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {

private:
    int day;
    int month;
    int year;


public:
    Date();  // Default constructor
    Date(int d, int m, int y);
    Date(const Date& other);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

    void printDate() const;
};

#endif // DATE_H
