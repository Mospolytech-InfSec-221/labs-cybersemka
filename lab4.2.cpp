#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

// string file_format - Функция по введенному полному расположению файла получает расширение
// Вход: const string file_path_full - Полное расположение файла
// Вывод: Расширение из полного расположения файла
// Входные данные НЕ изменяются в результате работы функции
string file_format(const string file_path_full) {
	size_t pos = file_path_full.rfind('.');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, string::npos);
}

// void task1 - функция которая, выполняет 1 задание
// Вход: Нет
// Вывод: Ответ на 1 задание
// Входных данных нет
void task1() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_format(file_path_full) << endl; // Вывод расширения из полного расположения файла
}

// string file_name - Функция по введенному полному расположению файла получает название
// Вход: const string file_path_full - Полное расположение файла
// Вывод: Название из полного расположения файла
// Входные данные НЕ изменяются в результате работы функции
string file_name(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	size_t pos2 = file_path_full.rfind('.');
	if (pos2 <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, pos2 - pos - 1);
}

// void task2 - функция которая, выполняет 2 задание
// Вход: Нет
// Вывод: Ответ на 2 задание
// Входных данных нет
void task2() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_name(file_path_full) << endl; // Вывод названия из полного расположения файла
}

// string file_path - Функция по введенному полному расположению файла получает расположение
// Вход: const string file_path_full - Полное расположение файла
// Вывод: Расположение из полного расположения файла
// Входные данные НЕ изменяются в результате работы функции
string file_path(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(0, pos + 1);
}

// void task3 - функция которая, выполняет 3 задание
// Вход: Нет
// Вывод: Ответ на 3 задание
// Входных данных нет
void task3() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_path(file_path_full) << endl; // Вывод расположения из полного расположения файла
}

// char file_disk - Функция по введенному полному расположению файла получает название диска
// Вход: const string file_path_full - Полное расположение файла
// Вывод: Название диска из полного расположения файла
// Входные данные НЕ изменяются в результате работы функции
char file_disk(const string file_path_full) {
	return file_path_full[0];
}

// void task4 - функция которая, выполняет 4 задание
// Вход: Нет
// Вывод: Ответ на 4 задание
// Входных данных нет
void task4() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_disk(file_path_full) << endl; // Вывод названия диска из полного расположения файла
}

// bool file_rename - Функция по введенному полному расположению файла и новому имени переименовает файл
// Вход: const string file_path_full - Полное расположение файла, const string new_file_path_full - Новое имя файл
// Вывод: Результат переименования файла (true или false)
// Входные данные НЕ изменяются в результате работы функции
bool file_rename(const string file_path_full, const string new_file_path_full) {
	return rename(file_path_full.c_str(), new_file_path_full.c_str());
}

// void task5 - функция которая, выполняет 5 задание
// Вход: Нет
// Вывод: Ответ на 5 задание
// Входных данных нет
void task5() {
	string file_path_full; // Полное расположение файла
	string new_file_name; // Новое имя файл

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла
	cout << "Введите новое имя файл: " << endl;
	cin >> new_file_name; // Ввод нового имени файла

	if (!file_rename(file_path_full, file_path(file_path_full) + new_file_name + '.' + file_format(file_path_full))) {
		cout << "Файл был успешно переименован" << endl;
	}
	else {
		cout << "Не удалось переименовать файл" << endl;
	}
}

// bool file_copy - Функция по введенному полному расположению файла создает копию файла (имя копии получается приписыванием  «_copy» к имени файла)
// Вход: const string file_path_full - Полное расположение файла
// Вывод: Результат создания копия файла (true или false)
// Входные данные НЕ изменяются в результате работы функции
bool file_copy(const string file_path_full) {
	// а) открыть файл, полное расположение которого задано аргументом file_path_full, если такого файла нет или он не открывается вернуть false;

	ifstream fin(file_path_full); // Открыли файл для чтения

	if (!fin.is_open()) { // Если такого файла нет или он не открывается вернуть false
		return false;
	}

	// б) создать (открыть) файл, полное расположение которого получается из file_path_full приписыванием  «_copy» к имени файла, если неуспешно, вернуть false;

	ofstream fin_copy(file_path(file_path_full) + file_name(file_path_full) + "_copy." + file_format(file_path_full)); // Создали копию файл для записи

	if (!fin_copy.is_open()) { // Если файл не открыт вернуть false
		return false;
	}

	// в) реализовать построчное или посимвольное считывание из file_path_full и соответствующую запись в созданный файл. Буфер не должен быть меньше длины файла.

	string line;

	while (fin) {
		getline(fin, line);
		if (fin.fail()) {
			break;
		}
		fin_copy << line << '\n';
	}

	// г) Закрыть оба файла и вернуть true.

	fin.close(); // Закрываем файл
	fin_copy.close(); // Закрываем копию файла

	return true;
}

// void task6 - функция которая, выполняет 6 задание
// Вход: Нет
// Вывод: Ответ на 6 задание
// Входных данных нет
void task6() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	if (file_copy(file_path_full)) {
		cout << "Копия файла была успешна создана" << endl;
	}
	else {
		cout << "Не удалось создать копию файла" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) { // непрерывный цикл 
		cout << "Что вы хотите выполнить? \n"
			<< "1. По введенному полному расположению файла получить расширение\n"
			<< "2. По введенному полному расположению файла получить название\n"
			<< "3. По введенному полному расположению файла получить расположение\n"
			<< "4. По введенному полному расположению файла получить название диска\n"
			<< "5. По введенному полному расположению файла и новому имени переименовать файл\n"
			<< "6. По введенному полному расположению файла создать копию файла (имя копии получается приписыванием  «_copy» к имени файла)\n"
			<< "7. Выход\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			/*вызов функции для решения задания 1*/;
			task1();
			break; // если его не ставить, то после вызова task1(), начнет выполнятся task2() 
		}
		case 2: {
			/*вызов функции для решения задания 2*/;
			task2();
			break;
		}
		case 3: {
			/*вызов функции для решения задания 3*/;
			task3();
			break;
		}
		case 4: {
			/*вызов функции для решения задания 4*/;
			task4();
			break;
		}
		case 5: {
			/*вызов функции для решения задания 5*/;
			task5();
			break;
		}
		case 6: {
			/*вызов функции для решения задания 6*/;
			task6();
			break;
		}
		case 7: {
			/*вызов функции для решения задания 7*/;
			return 0;
			break;
		}
		default: {
			cout << "Некорректный ввод, такой функции нет!" << endl;
		}
		}
	}
}