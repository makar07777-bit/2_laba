#include "note.h"

Note::Note(const std::string &name, const std::string &surname,
           const std::string &phone, unsigned short birthday[3])
    : name_(name), surname_(surname), phone_(phone) {
  date_of_birth[0] = birthday[0];
  date_of_birth[1] = birthday[1];
  date_of_birth[2] = birthday[2];
}

std::string Note::name() const { return name_; }

std::string Note::surname() const { return surname_; }

std::string Note::phone() const { return phone_; }

unsigned short Note::day_of_birth() const { return date_of_birth[0]; }

unsigned short Note::month_of_birth() const { return date_of_birth[1]; }

unsigned short Note::year_of_birth() const { return date_of_birth[2]; }

void Note::set_name(const std::string &name) { name_ = name; }
void Note::set_surname(const std::string &surname) { surname_ = surname; }
void Note::set_phone(const std::string &phone) { phone_ = phone; }
void Note::set_birthday(unsigned short birthday[3]) {
  date_of_birth[0] = birthday[0];
  date_of_birth[1] = birthday[1];
  date_of_birth[2] = birthday[2];
}

int Note::cmp(const Note &other) const {
  if (surname_ < other.surname_)
    return -1;
  if (surname_ > other.surname_)
    return 1;
  if (name_ < other.name_)
    return -1;
  if (name_ > other.name_)
    return 1;
  return 0;
}

std::ostream &operator<<(std::ostream &os, const Note &n) {
  os << n.surname_ << ' ' << n.name_ << ' ' << n.phone_ << ' '
     << n.day_of_birth() << '.' << n.month_of_birth() << '.'
     << n.year_of_birth();
  return os;
}

std::istream &operator>>(std::istream &is, Note &n) {
  unsigned short d = 0, m = 0, y = 0;
  if (is >> n.surname_ >> n.name_ >> n.phone_ >> d >> m >> y) {
    n.date_of_birth[0] = d;
    n.date_of_birth[1] = m;
    n.date_of_birth[2] = y;
  }
  return is;
}
