#include <iostream>
using namespace std;
int main() {
	cout << "Привет это инжернерный калькулятор(без синусов и кос)\n";
	float a,b;
	float xy,by;
	float x,y,g;
	g = 10;
	cout << "Хотите сначала попробовать обычную версию?\n";
	cout << "1: да(калькулятор)" << " 2: нет(калькулятор++)\n";
	int calc,calcoption;
	cin >> calc;
	switch(calc) {
		case 1: calcoption = 1; break;
		case 2: calcoption = 2; break;
		default: return 1;
	}
	if(calcoption == 1) {
		cout << endl << "Отлично вот обычный калькулятор\n";
		cout << "Введите первое число!:";
		cin >> a;
		cout << "\n" << "Введите второе число!:";
		cin >> b;
		cout << "\n" << "Какую операцию совершить с данными числами?\n";
		cout << "1: +" << " 2: -" << " 3: /" << " 4: *\n";
		calc = 0;
		float ab;
		cin >> calc;
		// normal calc
		switch(calc) {
			case 1: ab = a + b; break;
			case 2: ab = a - b; break;
			case 3: ab = a / b; break;
			case 4: ab = a * b; break;	
			}
		cout << "Вывод операции:" << ab << "\n"; 
		calc = 0;
	}
	else if(calcoption == 2) {
	      	cout << "Привет это калькулятор с поддержкой физ. формул" << "\n"; 
		// advanced calculator menu
	        cout << "Выберите нужную формулу" << "\n";
       		cout << "1:Кинетическая энергия Ek=mv2/2\n";
 		cout << "2:Км/час в метр/с\n";
		cout << "3:Потенциальная энергия En=mgh\n";
		cout << "4:Момент силы M = f * d\n";
		cin >> calc;
		switch(calc) {
			case 1:
			// kinetic energy calculator	
       	       		cout << "Введи первое число массу M:";
			cin >> x;
 			cout << "\n" << "Второе число скорость метры в секунду";
			cin >> y;
			xy = 0.5 * x * y;
			cout << "Ответ:" << xy << " Дж";
		       	break;
			case 2: // km/h to m/s
			cout << "Введите скорость километров в час просто как 10 для примера:";
			cin >> x;
			y = x / 3.6;
			cout << "Это будет " << y << " метров в секунду"; break;
			case 3:
			// potential energy calculator
			cout << "Введите массу объекта в кг:";
			cin >> x;
			cout << endl << "Введите растояни над землей в метрах:";
			cin >> y;
			by = x * g * y;
			cout << "\n" << "Потенциальная энергия равна:" << by << " Дж" << "\n"; break;
			// Калькулятор момента силы
			case 4:
			cout << "Введите силы в Ньютонах(Н):";
			cin >> x;
			cout << "\nВведите радиус-вектор (метры):";
			cin >> y;
			xy = x * y;
			cout << "\nВывод:" << xy << "\n";
		}
	}



	return 0;
}
