#include "notes.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

static bool isEngLetter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static bool isVowel(char c) {
  char lc = (char)std::tolower((unsigned char)c);
  return lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u' ||
         lc == 'y';
}

static void task2_file_and_string_streams() {
  std::cout << "Введите путь к английскому текстовому файлу: ";
  std::string path;
  std::cin >> path;

  std::ifstream in(path, std::ios::binary);
  if (!in) {
    std::cout << "Не удалось открыть файл: " << path << "\n";
    return;
  }

  std::ostringstream oss;
  oss << in.rdbuf();
  std::string text = oss.str();

  for (size_t i = 0; i < text.size(); ++i) {
    if (isEngLetter(text[i]) && (i == 0 || !isEngLetter(text[i - 1]))) {
      if (isVowel(text[i]))
        text[i] = (char)std::toupper((unsigned char)text[i]);
    }
  }

  std::cout << "\nРезультат обработки:\n" << text << "\n";
}

static void print_menu() {
  std::cout
      << "\n==== Меню ====\n"
      << "1. Добавить запись\n"
      << "2. Удалить запись по индексу\n"
      << "3. Удалить запись по Фамилии и Имени\n"
      << "4. Отсортировать записи по алфавиту (Фамилия, Имя)\n"
      << "5. Показать все записи\n"
      << "6. Показать людей, у которых ДР в заданном месяце\n"
      << "7. Задание 1: Отсортировать и вывести именинников месяца\n"
      << "8. Задание 2: Файл/строковые потоки — заглавная у слов на гласную\n"
      << "0. Выход\n"
      << "Выбор: ";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Notes book;

  while (true) {
    print_menu();
    int choice = -1;
    if (!(std::cin >> choice))
      return 0;

    if (choice == 0)
      break;

    if (choice == 1) {
      std::string surname, name, phone;
      unsigned short d = 0, m = 0, y = 0;
      std::cout << "Фамилия: ";
      std::cin >> surname;
      std::cout << "Имя: ";
      std::cin >> name;
      std::cout << "Телефон: ";
      std::cin >> phone;
      std::cout << "День месяц год рождения: ";
      std::cin >> d >> m >> y;
      unsigned short b[3] = {d, m, y};
      book.add(name, surname, phone, b);
      std::cout << "Добавлено. Всего: " << book.size() << "\n";
    } else if (choice == 2) {
      size_t idx = 0;
      std::cout << "Индекс [1.." << book.size() << "]: ";
      std::cin >> idx;
      if (idx == 0 || idx > book.size()) {
        std::cout << "Некорректный индекс." << '\n';
      } else {
        book.remove(idx - 1);
        std::cout << "Удалено. Осталось: " << book.size() << "\n";
      }
    } else if (choice == 3) {
      std::string surname, name;
      std::cout << "Фамилия: ";
      std::cin >> surname;
      std::cout << "Имя: ";
      std::cin >> name;
      book.remove_by_fullname(surname, name);
      std::cout << "Готово. Текущее количество: " << book.size() << "\n";
    } else if (choice == 4) {
      book.sort();
      std::cout << "Отсортировано." << '\n';
    } else if (choice == 5) {
      book.print_all(std::cout);
    } else if (choice == 6) {
      unsigned short month = 0;
      std::cout << "Месяц (1-12): ";
      std::cin >> month;
      if (month < 1 || month > 12) {
        std::cout << "Неверный номер месяца." << '\n';
      } else {
        book.print_by_month(std::cout, month);
      }
    } else if (choice == 7) {
      unsigned short month = 0;
      book.sort();
      std::cout << "Месяц (1-12): ";
      std::cin >> month;
      if (month < 1 || month > 12) {
        std::cout << "Неверный номер месяца." << '\n';
      } else {
        std::cout << "Именинники месяца:" << '\n';
        book.print_by_month(std::cout, month);
      }
    } else if (choice == 8) {
      task2_file_and_string_streams();
    } else {
      std::cout << "Неизвестная команда." << '\n';
    }
  }

  return 0;
}