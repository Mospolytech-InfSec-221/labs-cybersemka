#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

// bool Palindrom - функция проверяет, является ли строка палидромом 
// Вход: char * str - Указатель на массив char, который является строкой ввода пользователем
// Вывод: true - если строка является палидромом, иначе false, в таком случае строка НЕ является палиндромом
// Входные данные НЕ изменяются в результате работы функции
bool Palindrom(char* str) {
	bool checkingForPalindrom = true; // Проверка на Палиндром, если переменная не изменится, то строка является палиндромом
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		if (str[i] == ' ') {
			i++;
		}
		if (str[j] == ' ') {
			j--;
		}
		if (tolower(str[i]) != tolower(str[j])) { // перевод в один регистр, если условие даст true, то строка НЕ является палиндромом
			checkingForPalindrom = false;
		}
	}
	return checkingForPalindrom;
}

// void task1 - функция которая, выполняет 1 задание
// Вход: Нет
// Вывод: Ответ на 1 задание
// Входных данных нет
void task1() {
	const int streamSize = 255; // Максимально количество символов, которое может быть записано в строку
	char inputString[streamSize]; // Строка для проверки на палиндром

	cin.ignore();
	cout << "Введите предложение для проверки на палиндром: " << endl;
	cin.getline(inputString, streamSize); // Ввод строки

	// Проверка на палиндромом
	// Если Palindrom вернет true, то строка палиндром, иначе строка НЕ является палиндромом
	if (Palindrom(inputString)) {
		cout << "Строка является палиндромом";
	}
	else {
		cout << "Строка НЕ является палиндромом";
	}

	cout << endl;
}

// int find_substring1 - функция возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in, поиск ведется с позиции start_position
// Вход: const char * str_for_search_in - Указатель на массив char, который является строкой ввода пользователем
// const char * substring - Указатель на массив char, который является подстрокой ввода пользователем
// int start_position - Позиция с которой начинается поиск подстроки в строке 
// Вывод: функция возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in, иначе -1 как результат отсутствия подстроки
// Входные данные, а точнее start_position изменяется в результате работы функции, оно может уменьшаться на 1
int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int i, j; // Счетчики для циклов
	int lenSubstring, lenStrForSearchIn; // Длины строк

	//Находим размеры строки исходника и искомого
	for (lenSubstring = 0; substring[lenSubstring]; lenSubstring++);
	for (lenStrForSearchIn = 0; str_for_search_in[lenStrForSearchIn]; lenStrForSearchIn++);

	for (i = 0; i <= lenStrForSearchIn - lenSubstring; i++) { // Пока есть возможность поиска
		for (j = 0; str_for_search_in[i + j] == substring[j]; j++); // Проверяем совпадение посимвольно
		// Если посимвольно совпадает по длине искомого
		// Вернем из функции номер ячейки, откуда начинается совпадение
		// Учитывать 0-терминатор  ( '\0' )
		if (j - lenSubstring == 1 && i == lenStrForSearchIn - lenSubstring && !(start_position - 1)) return i;
		if (j == lenSubstring)
			if (start_position - 1) start_position--;
			else return i;
	}
	// Иначе вернем -1 как результат отсутствия подстроки
	return -1;
}

int* find_substring2(const char* str_for_search_in, const char* substring) {
	int position = 0; // позиции, с которой начинается подстрока
	int counter = 0; // счетчик
	int* mas = new int[255]; // динамический массив
	for (int i = 1; position != -1; i++) {
		position = find_substring1(str_for_search_in, substring, i);

		if (position >= 0) {
			mas[counter] = position;
			counter++;
		}
	}
	return mas;
}

// void task2 - функция которая, выполняет 2 задание
// Вход: Нет
// Вывод: Ответ на 2 задание
// Входных данных нет
void task2() {
	const int streamSize = 255; // Максимально количество символов, которое может быть записано в строку
	char inputString[streamSize]; // Строка для поиска подстроки
	char inputSubString[streamSize]; // Строка для поиска подстроки

	cin.ignore();
	cout << "str_for_search_in = " << endl;
	cin.getline(inputString, streamSize); // Ввод строки
	cout << "substring = " << endl;
	// streamSize - 1, так как подстрока должна быть меньше строки
	cin.getline(inputSubString, streamSize - 1); // Ввод подстроки

	int* mas = find_substring2(inputString, inputSubString);
	int size = sizeof(mas) / sizeof(mas[0]);

	// Вывод
	cout << "[";
	for (int i = 0; i <= size; i++) {
		if (i != size) {
			cout << mas[i] << ", ";
		}
		else {
			cout << mas[i];
		}
	}
	cout << "]";

	cout << endl;
}

// void str_for_encrypt - функция которая, выводит все названия (то, что внутри кавычек) из текста
// Вход: char * str_for_encrypt - Указатель на массив char, который является строкой ввода пользователем, int key - ключ
// Вывод: Нет
// Входные данные, а точнее str_for_encrypt изменяется в результате работы функции, а именно эта строка шифруется шифром Цезаря
void encrypt(char* str_for_encrypt, int key) {
	for (int i = 0; i < strlen(str_for_encrypt); i++) {
		if (str_for_encrypt[i] >= 'a' && str_for_encrypt[i] <= 'z') {
			str_for_encrypt[i] = ((str_for_encrypt[i] - 'a' + key) % 26) + 'a';
		}
		else if (str_for_encrypt[i] >= 'A' && str_for_encrypt[i] <= 'Z') {
			str_for_encrypt[i] = ((str_for_encrypt[i] - 'A' + key) % 26) + 'A';
		}
	}
}

// void task3 - функция которая, выполняет 3 задание
// Вход: Нет
// Вывод: Ответ на 3 задание
// Входных данных нет
void task3() {
	const int streamSize = 255; // Максимально количество символов, которое может быть записано в строку
	char inputString[streamSize]; // Строка 
	int key; // Ключ

	cin.ignore();
	cout << "Вход = " << endl;
	cin.getline(inputString, streamSize); // Ввод строки
	cin >> key; // Ввод ключа

	encrypt(inputString, key); // Зашифровать

	cout << inputString << endl; // Вывод строки
}

// void printAllNamesInsideQuotationMarks - функция которая, выводит все названия (то, что внутри кавычек) из текста
// Вход: const char * inputString - Указатель на массив char, который является строкой ввода пользователем
// Вывод: Все названия (то, что внутри кавычек) из текста
// Входные данные НЕ изменяются в результате работы функции
void printAllNamesInsideQuotationMarks(const char* inputString) {
	for (int i = 0; i < strlen(inputString); i++) {
		if (inputString[i] == '"') {
			char* mas = new char[255]; // Название внутри кавычек
			int position = i + 1; // позиция char в inputString
			int counter = 0; // счетчик
			while (inputString[position] != '"' && position != strlen(inputString)) {
				mas[counter] = inputString[position];
				counter++;
				position++;
			}
			if (position != strlen(inputString)) {
				mas[counter] = '\0';
				cout << mas << " ";
			}

			i = position + 1;
			delete[]mas;
		}
	}
}

// void task4 - функция которая, выполняет 4 задание
// Вход: Нет
// Вывод: Ответ на 4 задание
// Входных данных нет
void task4() {
	const int streamSize = 255; // Максимально количество символов, которое может быть записано в строку
	char inputString[streamSize]; // Строка 

	cin.ignore();
	cout << "Вход = " << endl;
	cin.getline(inputString, streamSize); // Ввод строки

	printAllNamesInsideQuotationMarks(inputString);

	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) { // непрерывный цикл 
		cout << "Что вы хотите выполнить? \n"
			<< "1. Проверка на палиндром\n"
			<< "2. Поиск подстроки в строке\n"
			<< "3. Шифрование сдвигами (шифр Цезаря)\n"
			<< "4. Вывести все названия (то, что внутри кавычек) из текста\n"
			<< "5. Выход\n";
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
			return 0;
			break;
		}
		default: {
			cout << "Некорректный ввод, такой функции нет!" << endl;
		}
		}
	}
}
