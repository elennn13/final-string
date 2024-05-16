#include <iostream>
#include <string>

std::string spaces_str(std::string str);

bool have_spam(std::string str);


int main() {
	setlocale(LC_ALL, "ru");
	int n;
	
	//Задача 1. Пробелы в строку
	
	std::cout << "Задача 1.\nВведите строку ->";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";

	//Задача 2. Проверка спама
	// написать функцию для проверки спама в переданной строке. 
	// Функция возвращает true, если чтрока содержит спам.Cпамом считать след. 
	// словосочетания:100%free, sales increase, only today. Функция должна быть нерегистрозависимой
	std::cout << "Задача 2.\nВведите строку ->";
	std::string str2;
	std::getline(std::cin, str2);
	//Функции типа bool лучше всего проверять с помощью if.
	if (have_spam(str2))
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спама не обнаружено.\n\n";


	return 0;
}
//1
std::string spaces_str(std::string str) {
	for (int i = str.size() - 1; i > 0; i--)
		str.insert(i, " ");
	return str;

}
//2
bool have_spam(std::string str) {
	// Обеспечение нерегистрозависимости функции
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	// Массив словосочетаний обозначающих спам
	const int spams_number = 4;
	static const std::string spams_messeges[spams_number]{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};
	// Перебор спамовых словосочетаний с целью выявления их в строке
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams_messeges[i]) < str.length()) //если позиция подстроки в строке,  меньше длины в самой строке, 
			//то значит она присутствует в строке т.к если элемента нет встроке, то функция find вернет максимальное 
			//значение в типе данных  unsigned long long
			return true;

	return false;
}