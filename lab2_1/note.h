#ifndef _NOTE_H_
#define _NOTE_H_

#include <iostream>

class Note
{
    std::string name_, surname_, phone_;
    unsigned short date_of_birth[3];

public:
    Note(const std::string &name, const std::string &surname, const std::string &phone, unsigned short birthday[3]);

    std::string name() const;
    std::string surname() const;
    std::string phone() const;
    unsigned short day_of_birth() const;
    unsigned short month_of_birth() const;
    unsigned short year_of_birth() const;
};

#endif