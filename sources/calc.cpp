#include <iostream>
float calc1(float a, float b, char c) {
	switch(c) {
		case '1': return a+b; 
		case '2': return a-b; 
		case '3': return a*b; 
		case '4': return a/b; 
		case '5':{ double newroot = 1;
			  for(int i = 0; i < b; i++) {
				  newroot *= a;
			  }
			  return newroot; }
		case '6': if(a < 0) {
				  return -1;
			  }
			  else if(a == 0)
				  return 0;
			  b = a;
			  for(int i = 0; i < 50; i++) {
				  b = 0.5 * (b + a / b);
			  }
			  return b;
		default: return 0.0f;
	}
}
float calc2(float x,float y,float z,char v) {
	switch(v) {
	case '1': return x*y; break;
	case '2': return x/3.6; break;
	case '3': return x*10*y; break;
	case '5': float xy,by,ab;
		  xy=x*y;
		  by=z+x;
		  ab=xy/by;
		  return ab; break;
	default: return 0.0f; 
	}
}
int main() {
	float a,b,z = 0;
	char c,u;
	std::cout << "Добро пожаловать в adcalc++!\n";
	std::cout << "Вы можете выбрать простой калькулятор и продвинутый\n";
	std::cout << "1:Обычный калькулятор 2:Продвинутый калькулятор\nВыбор:";
	std::cin >> u;
	switch(u) {
		case '1': std::cout << "Какую операцию хотите использовать\n1:a+b 2:a-b 3:a*b 4:a/b 5:a^b 6:\u221Aa\nВыбор:";
			  std::cin >> c;
			  switch(c) {
				  default: std::cout << "Пожалуйста выберите из списка!(Ошибка #2)\n";
					   return 2;
				  case '1': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    std::cout << a << "+b\n";
					    std::cout << "Введите переменную b:";
					    std::cin >> b; 
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				  case '2': std::cout << "Введите переменную a:"; 
					    std::cin >> a;
					    std::cout << a << "-b\n";
					    std::cout << "Введите переменную b:";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				  case '3': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    std::cout << a << "*b\n";
					    std::cout << "Введите переменную b:";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				  case '4': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    std::cout << a << "/b\n";
					    std::cout << "Введите переменную b:";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				  case '5': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    std::cout << "Введите переменную b:";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				  case '6': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    std::cout << "Вывод:" << calc1(a,b,c) << "\n"; break;
				}
			  break;
		case '2': std::cout << "Выберите формулу\n1:Кинетическая энергия Ek-mv2/2\n2:Км/час в метр/сек\n3:Потенциальная энергия En=mgh\n4:Момент силы M=F*d\n5:Центр массы с двумя точками\nВыбор:"; 
			  std::cin >> c;
			  switch(c) {
				  default: std::cout << "Пожалуйста выберите из списка!(Ошибка #2)\n";
					   return 1; break;
				  case '1': std::cout << "Введите массу(kg):";
					    std::cin >> a;
					    std::cout << "Введите скорость (м/с):";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc2(a,b,z,c) << "Дж\n"; break;
				  case '2': std::cout << "Введите км/час:";
					    std::cin >> a;
					    std::cout << a << "(км/час) это ";
					    std::cout << calc2(a,b,z,c) << "(м/с)\n"; break;
				  case '3': std::cout << "Введите массу объекта(кг):";
					    std::cin >> a;
					    std::cout << "Введите высоту над землей(м):";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc2(a,b,z,c) << "Дж\n"; break;
				  case '4': std::cout << "Введите силу(H):";
					    std::cin >> a;
					    std::cout << "Введите радиус вектора(м):";
					    std::cin >> b;
					    std::cout << "Вывод:" << calc2(a,b,z,'1') << "\n"; break;
				  case '5': std::cout << "Введите массу объекта 2(кг):";
					    std::cin >> a;
					    std::cout << "Введите длинну(м):";
					    std::cin >> b;
					    std::cout << "Введите массу объекта 1(кг):";
					    std::cin >> z;
					    std::cout << "Центр массы находится в " << calc2(a,b,z,c) << "(м)\n"; break;
			  }
			  break;
		default: std::cout << "Пожалуйста выберите из списка!(Ошибка #2)\n";
			 return 1; 
	}
	return 0;
}
