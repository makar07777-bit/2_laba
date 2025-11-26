#ifndef _NOTES_H_
#define _NOTES_H_
#include "note.h"

class Notes {
  Note *data;
  size_t capacity_, size_;
  static constexpr size_t default_capacity = 10;

  void resize();

public:
  Notes();
  ~Notes();
  Notes(const Notes &other);
  Notes &operator=(const Notes &other);

  void add(const Note &note);
  void add(const std::string &name, const std::string &surname,
           const std::string &phone, unsigned short birthday[3]);

  void remove(size_t id);
  void remove_by_fullname(const std::string &surname, const std::string &name);

  void sort();

  void print_all(std::ostream &os) const;
  void print_by_month(std::ostream &os, unsigned short month) const;

  size_t size() const { return size_; }
  size_t capacity() const { return capacity_; }
};

#endif