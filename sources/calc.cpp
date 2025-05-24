#include <iostream>
//using namespace std;
void calc1(float a, float b, short unsigned c) {
	switch(c) {
		case 1: std::cout << (a + b); break;
		case 2: std::cout << (a - b); break;
		case 3: std::cout << (a * b); break;
		case 4: std::cout << (a / b); break;
		default: std::cout << "Error! Not user fault the proggrammer is just dumb\n"; break;
	
	}
}
void calc2(float x, float y, float z, short unsigned v) {
	switch(v) {
		case 1:	z = x * y;
			std::cout << z; break;
		case 2:	z = x / 3.6;
			std::cout << z; break;
		case 3:	z = x * 10 * y;
			std::cout << z; break;
		case 5: float xy,by,ab;
			xy = x * y;
			by = z + x;
			ab = xy / by;
			std::cout << ab; break;


	}
}
int main() {
	float a = 0; 
	float b = 0;
	short unsigned c,u;
	std::cout << "Добро пожаловать в adcalc++!\n";
	std::cout << "Вы можете выбрать простой калькулятор и продвинутый\n";
	std::cout << "1:Обычный калькулятор 2:Продвинутый калькулятор \nвыбор:";
	std::cin >> u;
	if(u > 2 or u < 1) {
		std::cout << "Пожалуйста выберите из списка!(ошибка #2)\n"; 
		return 2;
	}
	switch(u) {
		case 1: std::cout << "Какую операцию хотите использовать\n";
			std::cout << "1:a+b 2:a-b 3:a*b 4:a/b Выбор:";
			std::cin >> c;
			if(c < 0 or c > 4) {
				std::cout << "вводите операция из списка(ошибка #1)";
			return 1;
			}
			std::cout << "Введите переменную a:";
			std::cin >> a;
			if(c == 1) 
				std::cout << a << " + b";
			else if(c == 2)
				std::cout << a << " - b";
			else if(c == 3)
				std::cout << a << " * b";
			else if(c == 4)
				std::cout << a << " / b" ;
			std::cout << "\nВведите переменную b:";
			std::cin >> b;
			if(c == 4) {
				if(a == 0 or b == 0) {
				std::cout << "Не возможно делить на 0, ошибка #5\n";
				return 5;
			}
			}
			std::cout << "Вывод:";
			calc1(a,b,c);
			std::cout << "\n"; break;
		case 2: std::cout << "Выберите формулу \n";
			std::cout << "1:Кинетическая энергия Ek=mv2/2\n";
			std::cout << "2:Км/час в метр/сек\n";
			std::cout << "3:Потенциальная энергия En=mgh\n";
			std::cout<< "4:Момент силы M=F*d\n";
			std::cout << "5:Центр массы с двумя точками\n";
    			std::cin >> c;
			if(c < 1 or c > 5) {
				std::cout << "Choose valid option";
				return 3;
			}
			switch(c) {
				default: std::cout << "Нет такого(ошибка #4)\n";
					return 4;
				case 1: std::cout << "Введи массу(kg):";
					std::cin >> a;
					std::cout << "\nВведите скорость (м/с):";
					std::cin >> b;
					std::cout << "\nВывод:";
					calc2(a,b,0,c);
					std::cout << "Дж\n"; break;
				case 2: std::cout << "Введите км/час:";
					std::cin >> a;
					std::cout << a << " км/час это ";
					calc2(a,b,0,c);
					std::cout << " метров в секунду\n"; break;
				case 3: std::cout << "Введите массу объекта(кг):";
					std::cin >> a;
					std::cout << "\nВведите высоту над землей(м):";
					std::cin >> b;
					calc2(a,b,0,c);
					std::cout << "Дж\n"; break;
				case 4: std::cout << "Введите силу(H):";
					std::cin >> a;
					std::cout << "\nВведите радиус вектор(м):";
					std::cin >> b;
					std::cout << "\nВывод:";
					calc2(a,b,0,1);
					std::cout << "\n"; break;
				case 5: std::cout << "Введите массу объекта 2(кг):";
					std::cin >> a;
					std::cout << "\nВведите длинну(м):";
					std::cin >> b;
					std::cout << "\nВведите массу объекта 1(кг):";
					std::cin >> u;
					std::cout << "\nЦентр массы находится в ";
					calc2(a,b,u,c);
					std::cout << " метрах\n"; break;
						
			}


		}
	
	return 0;
}
