#include <iostream>
using namespace std;
int main() {
	cout << "Привет это инжернерный калькулятор(без синусов и кос)\n";
	float a,b,x,y;
	cout << "Хотите сначала попробовать обычную версию?\n";
	cout << "1: да(калькулятор)" << " 2: нет(калькулятор++)\n";
	short calc,calcoption;
	cin >> calc;
	switch(calc) {
		case 1: calcoption = 1; break;
		case 2: calcoption = 2; break;
	}
	if(calcoption == 1) {
		cout << endl << "Отлично вот обычный калькулятор\n";
		cout << "Введите первое число!:";
		cin >> a;
		cout << endl << "Введите второе число!:";
		cin >> b;
		cout << endl << "Какую операцию совершить с данными числами?\n";
		cout << "1: +" << " 2: -" << " 3: /" << " 4: *\n";
		calc = 0;
		float ab;
		cin >> calc;
		switch(calc) {
			case 1: ab = a + b; break;
			case 2: ab = a - b; break;
			case 3: ab = a / b; break;
			case 4: ab = a * b; break;	
			}
		cout << "Вывод операции:" << ab << endl;
	}
	else if(calcoption == 2) {
	       cout << "Привет это инженерный калькулятор единственная доступная формула это KE=1/2*mv2" << endl;
       	       cout << "Введи первое число массу M:";
		cin >> x;
 		cout << endl << "Второе число скорость метры в секунду";
		cin >> y;
		float xy = x * y;
		cout << "Ответ:" << xy << " Дж";
		}		



	return 0;
}
