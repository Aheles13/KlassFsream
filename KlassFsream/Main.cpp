#include <iostream>
#include <fstream>
#include <string>

// Вывод содержимого файла по переданному пути в консоль 
bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}
	return false;
}

bool insert_file(std::string file_path, int position, std::string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt"; // Путь к файлу 

	//Класс fstream
	/*std::fstream file;
	file.open(path, std::ios::in | std::ios::app); // В режимах открытия по умолчанию будет ошибка если файлов не существует 

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";

		// Запись в файл 
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		file << str << "\n";
		std::cout << "Запись добавлена в файл.\n\n";

		//seekg - seek get pointer ( Переместить курсор считывания)
		//seekp - seek put pointer ( Переместить курсор записи)
		//tellg - Вывод позиции курсора 
		//tellp -

		file.seekg(0, std::ios::beg); // Перемещение курсора в начало файла для дальнейшего считывания. 

		//Чтение из файла 
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		
	}
	else
		std::cout << "Файл не отвечает!\n";

	file.close();*/

	// Задание 1. Добавление в середину файла.
	/*	std::cout << "Исходный файл:\n";
	print_file(path);
	std::cout << "Введите позицую ->";
	std::cin >> n;
	std::cin.ignore();
	std::cout << "Введите строку -> ";
	std::string str;
	std::getline(std::cin, str);
	if (insert_file(path, n, str)) {
		std::cout << "Вставка выполнена успешно.\n\n";
		std::cout << "Содержимое файла.\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "Ошибка выполнения функции!\n\n";*/

	// Задание 2. Чтение даты из файла.
	std::cout << "Задача 2.\nДата: ";
	print_file("Date.txt");
	std::string date;
	std::ifstream read;
	read.open("Date.txt");

	if (read.is_open()) {
		read >> date;
		read.close();
	}
	int day = std::stoi(date);
	int month = std::stoi(date.substr(date.find('.') + 1));
	int year = std::stoi(date.substr(date.rfind('.') + 1));

	std::cout << "День: " << day << std::endl;
	std::cout << "Месяц:" << month << std::endl;
	std::cout << "Год:  " << year << std::endl;


	return 0;
}

bool insert_file(std::string file_path, int position, std::string str) {
	std::fstream file;
	std::string file_text;

	//Шаг 1. Копировнаие содержимого файла в строку.
	file.open(file_path, std::ios::in);
	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
		file.close();
	}
	else
		return false;

	//Шаг 2. Изменения строки.
	file_text.insert(position, str);

	//Шаг 3. Обновление содержимого файла.
	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		return true;
	}
	return false;
}