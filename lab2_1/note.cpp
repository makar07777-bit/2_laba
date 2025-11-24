#include "note.h"

Note::Note(const std::string &name, const std::string &surname, const std::string &phone, unsigned short birthday[3])
    : name_(name), surname_(surname), phone_(phone)
{
    std::copy(birthday, birthday + 3, date_of_birth);
}

std::string Note::name() const
{
    return name_;
}

std::string Note::surname() const
{
    return surname_;
}

std::string Note::phone() const
{
    return phone_;
}

unsigned short Note::day_of_birth() const
{
    return date_of_birth[0];
}

unsigned short Note::month_of_birth() const
{
    return date_of_birth[1];
}

unsigned short Note::year_of_birth() const
{
    return date_of_birth[2];
}
