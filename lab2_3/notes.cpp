#include "notes.h"
#include <iostream>

Notes::Notes() : size_(0), capacity_(default_capacity) {
  data = new Note[capacity_];
}

Notes::~Notes() { delete[] data; }

Notes::Notes(const Notes &other)
    : capacity_(other.capacity_), size_(other.size_) {
  data = new Note[capacity_];
  for (size_t i = 0; i < size_; ++i)
    data[i] = other.data[i];
}

Notes &Notes::operator=(const Notes &other) {
  if (this == &other)
    return *this;
  Note *newData = new Note[other.capacity_];
  for (size_t i = 0; i < other.size_; ++i)
    newData[i] = other.data[i];
  delete[] data;
  data = newData;
  capacity_ = other.capacity_;
  size_ = other.size_;
  return *this;
}

void Notes::resize() {
  capacity_ *= 2;
  Note *tmp = new Note[capacity_];
  for (size_t i = 0; i < size_; ++i)
    tmp[i] = data[i];
  delete[] data;
  data = tmp;
}

void Notes::add(const Note &note) {
  if (size_ == capacity_)
    resize();
  data[size_++] = note;
}

void Notes::add(const std::string &name, const std::string &surname,
                const std::string &phone, unsigned short birthday[3]) {
  Note note(name, surname, phone, birthday);
  add(note);
}

void Notes::remove(size_t id) {
  if (id >= size_)
    return;
  for (size_t i = id + 1; i < size_; ++i)
    data[i - 1] = data[i];
  --size_;
}

void Notes::remove_by_fullname(const std::string &surname,
                               const std::string &name) {
  for (size_t i = 0; i < size_; ++i) {
    if (data[i].surname() == surname && data[i].name() == name) {
      remove(i);
      return;
    }
  }
}

void Notes::sort() {
  for (size_t i = 0; i + 1 < size_; ++i) {
    size_t minIdx = i;
    for (size_t j = i + 1; j < size_; ++j) {
      if (data[j].cmp(data[minIdx]) < 0)
        minIdx = j;
    }
    if (minIdx != i) {
      Note tmp = data[i];
      data[i] = data[minIdx];
      data[minIdx] = tmp;
    }
  }
}

void Notes::print_all(std::ostream &os) const {
  for (size_t i = 0; i < size_; ++i) {
    os << (i + 1) << ". " << data[i] << '\n';
  }
}

void Notes::print_by_month(std::ostream &os, unsigned short month) const {
  bool any = false;
  for (size_t i = 0; i < size_; ++i) {
    if (data[i].month_of_birth() == month) {
      os << data[i] << '\n';
      any = true;
    }
  }
  if (!any)
    os << "Нет записей с днем рождения в указанном месяце." << '\n';
}
