#include "matr.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	matr Matrix;
	matr Matrix2;
	while (true) { // непрерывный цикл 
		cout << "Что вы хотите выполнить? \n"
			<< "1. Ввести матрицу с клавиатуры\n"
			<< "2. Печать матрицы в консоль\n"
			<< "3. Количество столбцов\n"
			<< "4. Количество строк\n"
			<< "5. Вернуть (i,j) элемент\n"
			<< "6. Сложения матриц\n"
			<< "7. Умножения двух матриц\n"
			<< "8. След матрицы (сумма диагональных элементов квадратной матрицы)\n"
			<< "9. Определитель матрицы (для квадратных)\n"
			<< "10. Умножение матрицы на число\n"
			<< "11. Выход\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			/*вызов функции для решения задания 1*/;
			Matrix.input();
			break; // если его не ставить, то после вызова task1(), начнет выполнятся task2() 
		}
		case 2: {
			/*вызов функции для решения задания 2*/;
			Matrix.print();
			break;
		}
		case 3: {
			/*вызов функции для решения задания 3*/;
			cout << "Количество столбцов: " << Matrix.get_columns() << endl;
			break;
		}
		case 4: {
			/*вызов функции для решения задания 4*/;
			cout << "Количество строк: " << Matrix.get_rows() << endl;
			break;
		}
		case 5: {
			/*вызов функции для решения задания 5*/;
			int row, column;
			cout << "Введите i: ";
			cin >> row;
			cout << "Введите j: ";
			cin >> column;
			cout << "Элемент (i, j): " << Matrix.get_elem(row, column) << endl;
			break;
		}
		case 6: {
			/*вызов функции для решения задания 6*/;
			Matrix2.input();
			if (Matrix.get_rows() != Matrix2.get_rows() || Matrix.get_columns() != Matrix2.get_columns()) {
				cout << "Ошибка! Размеры матриц не одинаковы" << endl;
			}
			else {
				Matrix.sumM(Matrix2).print();
			}
			break;
		}
		case 7: {
			/*вызов функции для решения задания 7*/;
			Matrix2.input();
			if (Matrix.get_columns() != Matrix2.get_rows()) {
				cout << "Ошибка! Количество столбцов первой матрицы не равно количеству строк второй" << endl;
			}
			else {
				Matrix.mult(Matrix2).print();
			}
			break;
		}
		case 8: {
			/*вызов функции для решения задания 8*/;
			if (Matrix.get_rows() != Matrix.get_columns()) {
				cout << "Ошибка! Матрица не квадратная" << endl;
			}
			else if (Matrix.get_rows() < 1) {
				cout << "След вычислить невозможно!" << endl;
			}
			else {
				cout << "След матрицы: " << Matrix.trace() << endl;
			}
			break;
		}
		case 9: {
			/*вызов функции для решения задания 9*/;
			if (Matrix.get_rows() != Matrix.get_columns()) {
				cout << "Ошибка! Матрица не квадратная" << endl;
			}
			else if (Matrix.get_rows() < 1) {
				cout << "Определитель вычислить невозможно!" << endl;
			}
			else {
				cout << "Определитель матрицы равен " << Matrix.det() << endl;
			}
			break;
		}
		case 10: {
			/*вызов функции для решения задания 10*/;
			int num;
			cout << "Введите число для умножения матрицы: ";
			cin >> num;
			Matrix.mult_by_num(num);
			Matrix.print();
			break;
		}
		case 11: {
			/*вызов функции для решения задания 11*/;
			return 0;
			break;
		}
		default: {
			cout << "Некорректный ввод, такой функции нет!" << endl;
		}
		}
	}
}