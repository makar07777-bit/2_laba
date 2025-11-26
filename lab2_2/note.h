#ifndef _NOTE_H_
#define _NOTE_H_

#include <iostream>
#include <string>

class Note {
  std::string name_, surname_, phone_;
  unsigned short date_of_birth[3]{}; // {day, month, year}

public:
  Note() = default;
  Note(const std::string &name, const std::string &surname,
       const std::string &phone, unsigned short birthday[3]);

  std::string name() const;
  std::string surname() const;
  std::string phone() const;
  unsigned short day_of_birth() const;
  unsigned short month_of_birth() const;
  unsigned short year_of_birth() const;

  void set_name(const std::string &name);
  void set_surname(const std::string &surname);
  void set_phone(const std::string &phone);
  void set_birthday(unsigned short birthday[3]);

  int cmp(const Note &other) const;

  friend std::ostream &operator<<(std::ostream &os, const Note &n);
  friend std::istream &operator>>(std::istream &is, Note &n);
};

#endif