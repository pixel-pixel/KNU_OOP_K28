#ifndef KNU_OOP_K28_DATE_H
#define KNU_OOP_K28_DATE_H

#include <iostream>

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(Date *date) {
        this->day = date->day;
        this->month = date->month;
        this->year = date->year;
    }
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    friend std::ostream& operator<< (std::ostream &out, const Date &date){
        std::cout << date.year << '.' << date.month << '.' << date.day;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        this->day = day;
    }
};


#endif //KNU_OOP_K28_DATE_H
