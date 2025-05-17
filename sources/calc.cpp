#include <iostream>
using namespace std;
void calc1(float a, float b, short unsigned c) {
	switch(c) {
		case 1: cout << (a + b); break;
		case 2: cout << (a - b); break;
		case 3: cout << (a * b); break;
		case 4: cout << (a / b); break;
		default: cout << "Error! Not user fault the proggrammer is just dumb\n"; break;
	
	}
}
void calc2(float x, float y, float z, short unsigned v) {
	switch(v) {
		case 1:	z = x * y;
			cout << z; break;
		case 2:	z = x / 3.6;
			cout << z; break;
		case 3:	z = x * 10 * y;
			cout << z; break;
		case 5: float xy,by,ab;
			xy = x * y;
			by = z + x;
			ab = xy / by;
			cout << ab; break;


	}
}
int main() {
	float a = 0; 
	float b = 0;
	short unsigned c,u;
	cout << "Добро пожаловать в adcalc++!\n";
	cout << "Вы можете выбрать простой калькулятор и продвинутый\n";
	cout << "1:Обычный калькулятор 2:Продвинутый калькулятор \nвыбор:";
	cin >> u;
	if(u > 2 or u < 1) {
		cout << "Пожалуйста выберите из списка!(ошибка #2)\n"; 
		return 2;
	}
	switch(u) {
		case 1: cout << "Какую операцию хотите использовать\n";
			cout << "1:a+b 2:a-b 3:a*b 4:a/b Выбор:";
			cin >> c;
			if(c < 0 or c > 4) {
			cout << "вводите операция из списка(ошибка #1)";
			return 1;
			}
			cout << "Введите переменную a:";
			cin >> a;
			if(c == 1) 
				cout << a << " + b";
			else if(c == 2)
				cout << a << " - b";
			else if(c == 3)
				cout << a << " * b";
			else if(c == 4)
				cout << a << " / b" ;
			cout << "\nВведите переменную b:";
			cin >> b;
			cout << "Вывод:";
			calc1(a,b,c);
			cout << "\n"; break;
		case 2: cout << "Выберите формулу \n";
			cout << "1:Кинетическая энергия Ek=mv2/2\n";
			cout << "2:Км/час в метр/сек\n";
			cout << "3:Потенциальная энергия En=mgh\n";
			cout << "4:Момент силы M=F*d\n";
			cout << "5:Центр массы с двумя точками\n";
			cin >> c;
			if(c < 1 or c > 5) {
				cout << "Choose valid option";
				return 3;
			}
			switch(c) {
				default:cout << "Нет такого(ошибка #4)\n";
					return 4;
				case 1: cout << "Введи массу(kg):";
					cin >> a;
					cout << "\nВведите скорость (м/с):";
					cin >> b;
					cout << "\nВывод:";
					calc2(a,b,0,c);
					cout << "Дж\n"; break;
				case 2: cout << "Введите км/час:";
					cin >> a;
					cout << a << " км/час это ";
					calc2(a,b,0,c);
					cout << " метров в секунду\n"; break;
				case 3: cout << "Введите массу объекта(кг):";
					cin >> a;
					cout << "\nВведите высоту над землей(м):";
					cin >> b;
					calc2(a,b,0,c);
					cout << "Дж\n"; break;
				case 4: cout << "Введите силу(H):";
					cin >> a;
					cout << "\nВведите радиус вектор(м):";
					cin >> b;
					cout << "\nВывод:";
					calc2(a,b,0,1);
					cout << "\n";
				case 5: cout << "Введите массу объекта 2(кг):";
					cin >> a;
					cout << "\nВведите длинну(м):";
					cin >> b;
					cout << "\nВведите массу объекта 1(кг):";
					cin >> u;
					cout << "\nЦентр массы находится в ";
					calc2(a,b,u,c);
					cout << " метрах\n"; break;
						
			}


		}
	
	return 0;
}
