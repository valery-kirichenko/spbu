#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

struct JournalRecord {
	int course;
	int group;
	std::string lastName;
	std::string date;
	int gradebook;
	std::string discipline;
	int mark;
};

struct Date {
	int day, month, year;
};

void printRecordbook(std::vector< JournalRecord > recordbook) {
	for (int i = 0; i < recordbook.size(); i++) {
		std::cout << recordbook[i].course << " курс, "
				  << recordbook[i].group << " группа, "
				  << recordbook[i].lastName << ", "
				  << "поступил " << recordbook[i].date << ", "
				  << "зачетка №" << recordbook[i].gradebook << ", "
				  << "сдал предмет " << recordbook[i].discipline
				  << " на \"" << recordbook[i].mark << "\"\n" << std::endl;
	}
};

Date stringToDate(std::string str) {
	Date ret;

	int s = 0;
	std::string temp = "";
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '.') {
			switch (s) {
				case 0:
					ret.day = std::stoi(temp);
					break;
				case 1:
					ret.month = std::stoi(temp);
					break;
			}
			temp = "";
			s++;
		} else if (c != '0' || (i != 0 || str[i - 1] != '.')) {
			temp += c;
		}
	}
	ret.year = std::stoi(temp);
	
	return ret;
}

int sortByCourse(const JournalRecord &lhs, const JournalRecord &rhs) {
	return lhs.course < rhs.course;
}

int sortByGradebook(const JournalRecord &lhs, const JournalRecord &rhs) {
	return lhs.gradebook < rhs.gradebook;
}

int sortByDate(const JournalRecord &lhs, const JournalRecord &rhs) {
	Date l = stringToDate(lhs.date), r = stringToDate(rhs.date);
	if (l.year < r.year) return 1;
	else if (l.year > r.year) return 0;
	else {
		if (l.month < r.month) return 1;
		else if (l.month > r.month) return 0;
		else {
			if (l.day < r.day) return 1;
			else  return 0;
		}
	}
}

std::vector< JournalRecord > searchByCourse(std::vector< JournalRecord > recordbook, int course) {
	std::vector< JournalRecord > searchResult;
	for (int i = 0; i < recordbook.size(); i++)
		if (recordbook[i].course == course) searchResult.push_back(recordbook[i]);

	return searchResult;
}

std::vector< JournalRecord > searchByGradebook(std::vector< JournalRecord > recordbook, int gradebook) {
	std::vector< JournalRecord > searchResult;
	for (int i = 0; i < recordbook.size(); i++)
		if (recordbook[i].gradebook == gradebook) searchResult.push_back(recordbook[i]);

	return searchResult;
}

std::vector< JournalRecord > searchByDate(std::vector< JournalRecord > recordbook, Date date) {
	std::vector< JournalRecord > searchResult;
	for (int i = 0; i < recordbook.size(); i++) {
		Date td = stringToDate(recordbook[i].date);
		if (td.year == date.year && td.month == date.month && td.day == date.day)
			searchResult.push_back(recordbook[i]);
	}

	return searchResult;
}

int main() {
	std::vector< JournalRecord > recordbook;
	std::ifstream input("records.txt");
	std::string line;
	while (std::getline(input, line)) {
		int i = 0, s = 0;
		char c;
		std::string temp = "";
		JournalRecord record;
		while (i != line.size()) {
			c = line[i];
			if (c == ' ') {
				switch (s) {
					case 0:
						record.course = std::stoi(temp);
						break;
					case 1:
						record.group = std::stoi(temp);
						break;
					case 2:
						record.lastName = temp;
						break;
					case 3:
						record.date = temp;
						break;
					case 4:
						record.gradebook = std::stoi(temp);
						break;
					case 5:
						record.discipline = temp;
						break;
				}
				s++;
				temp = "";
			} else {
				temp += c;
			}
			i += 1;
		}
		record.mark = std::stoi(temp);
		recordbook.push_back(record);
	}

	printRecordbook(recordbook);

	/*
	std::cout << "===== Sorted By Course =====" << std::endl;
	std::sort(recordbook.begin(), recordbook.end(), sortByCourse);
	printRecordbook(recordbook);

	std::cout << "===== Sorted By Gradebook =====" << std::endl;
	std::sort(recordbook.begin(), recordbook.end(), sortByGradebook);
	printRecordbook(recordbook);
	

	std::cout << "===== Sorted By Date =====" << std::endl;
	std::sort(recordbook.begin(), recordbook.end(), sortByDate);
	printRecordbook(recordbook);
	*/
	int action;
	int work = 1;
	while (work) {
		if (work == 1) {
			std::cout << "Выберите действие:\n1) Сортировать\n2) Поиск\n3) Выход\n";
			std::cin >> action;
			switch (action) {
				case 1:
					work = 2;
					break;
				case 2:
					work = 3;
					break;
				case 3:
					work = 0;
					break;
			}
		} else if (work == 2) {
			std::cout << "Выберите способ сортировки:\n1) По курсу\n2) По номеру зачетки\n3) По дате поступления\n";
			std::cin >> action;
			switch (action) {
				case 1:
					std::cout << "===== Сортировка по курсу =====" << std::endl;
					std::sort(recordbook.begin(), recordbook.end(), sortByCourse);
					printRecordbook(recordbook);
					break;
				case 2:
					std::cout << "===== Сортировка по номеру зачетки =====" << std::endl;
					std::sort(recordbook.begin(), recordbook.end(), sortByGradebook);
					printRecordbook(recordbook);
					break;
				case 3:
					std::cout << "===== Сортировка по дате поступления =====" << std::endl;
					std::sort(recordbook.begin(), recordbook.end(), sortByDate);
					printRecordbook(recordbook);
					break;
			}
			work = 1;
		} else if (work == 3) {
			std::cout << "Выберите способ поиска:\n1) По курсу\n2) По номеру зачетки\n3) По дате поступления\n";
			std::cin >> action;
			switch (action) {
				case 1:
					int course;
					std::cout << "Введите номер курса: ";
					std::cin >> course;
					std::cout << "===== Результаты поиска =====" << std::endl;
					printRecordbook(searchByCourse(recordbook, course));
					break;
				case 2:
					int gradebook;
					std::cout << "Введите номер зачетки: ";
					std::cin >> gradebook;
					std::cout << "===== Результаты поиска =====" << std::endl;
					printRecordbook(searchByGradebook(recordbook, gradebook));
					break;
				case 3:
					std::string date;
					std::cout << "Введите дату поступления: ";
					std::cin >> date;
					std::cout << "===== Результаты поиска =====" << std::endl;
					printRecordbook(searchByDate(recordbook, stringToDate(date)));
					break;
			}
			work = 1;
		}
	}

	return 0;
}
