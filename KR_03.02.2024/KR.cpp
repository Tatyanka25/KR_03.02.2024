#include <iostream>
#include <ctime>
#include <cstdio>

void fill_the_array_random(int** array, int length_2, int length_1) { // функция заполняем массив рандомными числами
	srand(time(NULL));
	int num;
	for (int i = 0; i < length_2; i++) {
		for (int j = 0; j < length_1; j++) {
			num = rand() % (70 - 1 + 1) + 1;; // случайные числа от 1 до 70
			array[i][j] = num;
		}
	}
}

void show_the_array(int** array, int length_2, int length_1) { // функция выводит массив на экран
	for (int i = 0; i < length_2; i++) {
		for (int j = 0; j < length_1; j++) {
			std::cout << array[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

int sum_of_elements(int** array, int length_2, int length_1) {
	int sum = 0;
	for (int i = 0; i < length_2; i++) {
		sum += array[i][length_1 - i - 1];
	}
	return sum;
}
struct User {
	int id;
	std::string name;
	std::string surname;
	std::string email;
};

const int maxUsers = 100;
User users[maxUsers];
int UsersCount = 0;

void addUserAccount() {
	if (UsersCount < maxUsers) {
		std::cout << "Enter id: ";
		std::cin >> users[UsersCount].id;
		std::cout << "Enter name: ";
		std::cin >> users[UsersCount].name;
		std::cout << "Enter surname: ";
		std::cin >> users[UsersCount].surname;
		std::cout << "Enter email: ";
		std::cin >> users[UsersCount].email;
		UsersCount++;
	}
	else {
		std::cout << "The limit of user accounts has been reached." << std::endl;
	}
}

void deleteUser() {
	int target_Id;
	std::cout << "Enter the id of the user account to delete: ";
	std::cin >> target_Id;
	for (int i = 0; i < UsersCount; i++) {
		if (users[i].id == target_Id) {
			for (int j = i; j < UsersCount - 1; j++) {
				users[j] = users[j + 1];
			}
			UsersCount--;
			return;
		}
	}
	std::cout << "We can not find an account with this id = " << target_Id << std::endl;
}

void upgradeUsersAccount() {
	int target_Id;
	std::cout << "Enter the id of the user account to upgrade: ";
	std::cin >> target_Id;
	for (int i = 0; i < UsersCount; i++) {
		if (users[i].id == target_Id) {
			std::cout << "Enter new name: ";
			std::cin >> users[i].name;
			std::cout << "Enter new surname: ";
			std::cin >> users[i].surname;
			std::cout << "Enter new email: ";
			std::cin >> users[i].email;
			return;
		}
	}
	std::cout << "We can not find an account with this id = " << target_Id << std::endl;
}

void printInformationAboutAllUsersAccounts() {
	std::cout << "All users accounts:" << std::endl;
	for (int i = 0; i < UsersCount; i++) {
		std::cout << "id: " << users[i].id << std::endl << "Name: " << users[i].name << std::endl << "Surname: " << users[i].surname << std::endl << "Email: " << users[i].email << std::endl << std::endl;
	}
}


int main() {
	//Task_1
	std::cout << std::endl << "#Task1#" << std::endl;
	int length_1(0);
	int length_2(0);
	std::cout << std::endl << "Enter the number of columns: ";
	std::cin >> length_1; // вводим количество столбцов
	std::cout << std::endl << std::endl << "Enter the number of rows: ";
	std::cin >> length_2; // вводим количество строк
	std::cout << std::endl;
	int** array = new int* [length_2]; // выделяем массив из length_2 указателей типа int (строки)
	for (int i = 0; i < length_2; ++i) {
		array[i] = new int[length_1]; // это наши столбцы
	}
	fill_the_array_random(array, length_2, length_1); // вызываем функцию заполнения массива
	show_the_array(array, length_2, length_1); // вызываем вункцию вывода массива на экран
	if (length_1 == length_2) {
		std::cout << std::endl << "The sum of the elements on the side diagonal = " << sum_of_elements(array, length_2, length_1) << std::endl << std::endl; // вызываем функцию которая посчитает сумму чисел на побочной диагонали
	}
	for (int i = 0; i < length_2; ++i) {
		delete[] array[i]; // очищаем память
	}
	delete[] array; // очищаем память

	//Task_2
	std::cout << std::endl << "#Task2#" << std::endl;
	void (*function_ptr[])() = { addUserAccount, deleteUser, upgradeUsersAccount, printInformationAboutAllUsersAccounts };

	while (true) {
		std::cout << "Select the desired action:" << std::endl;
		std::cout << "1) Add user account" << std::endl;
		std::cout << "2) Delete user" << std::endl;
		std::cout << "3) Upgrade user account" << std::endl;
		std::cout << "4) Print information about all users accounts" << std::endl;
		std::cout << "5) Exit" << std::endl;

		int choice;
		std::cin >> choice;

		if (choice == 5) {
			break;
		}
		else if (choice > 0 && choice < 5) {
			(*function_ptr[choice - 1])();
		}
		else {
			std::cout << "Mistake, try again." << std::endl;
		}
	}
	return 0;
}