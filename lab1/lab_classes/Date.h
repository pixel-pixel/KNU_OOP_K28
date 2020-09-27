#ifndef KNU_OOP_K28_DATE_H
#define KNU_OOP_K28_DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(Date *date) {
        this->day = date->day;
        this->month = date->month;
        this->year = date->year;
    }

    Date(int year = 0, int month = 0, int day = 0){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(std::string str) {
        day = (str[0] - 48) * 10 + (str[1] - 48);
        month = (str[3] - 48) * 10 + (str[4] - 48);
        year = (str[6] - 48) * 1000 + (str[7] - 48) * 100 + (str[8] - 48) * 10 + (str[9] - 48);
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

    friend std::ostream &operator<<(std::ostream &out, const Date &date) {
        std::cout << date.year << '.' << date.month << '.' << date.day;
    }

    friend bool operator==(Date &date1, Date &date2) {
        if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
            return true;
        return false;
    }

    friend bool operator>(Date &date1, Date &date2){
        if(date1.year != date2.year) return date1.year > date2.year;
        //else if()
    }
};


#endif
