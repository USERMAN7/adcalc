#include <iostream>
float calc1(float a, float b, char c) {
	switch(c) {
		case '1': return a+b; 
		case '2': return a-b; 
		case '3': return a*b; 
		case '4': return a/b; 
		case '5':{ double newroot = 1;
			  for(int i = 0; i < b; i++) {
				  newroot *= a; // 1 умножился на число 1 раз когда i = 0 поэтому не считается за цикл и все ок
			  }
			  return newroot; } // Когда уже достигло до этого места гарантировано что была умножена степень
		case '6': if(a < 0) {
				  return -1; // Код ошибки
			  }
			  else if(a == 0)
				  return 0; // Корень нуля это ноль
			  b = a;
			  for(int i = 0; i < 50; i++) {
				  b = 0.5 * (b + a / b); // Формула Ньютона для поиска квадратного корня
			  }
			  return b;
		default: return 0.0f; // чтобы компилятор не ругал за то что функция может ничего не выдать
	}
}
float calc2(float x,float y,float z,char v) {
	switch(v) {
	case '1': return x*y; break;
	case '2': return x/3.6; break;
	case '3': return x*10*y; break; // Ускорение воздуха константа
	case '5': float xy,by,ab;
		  xy=x*y;
		  by=z+x;
		  ab=xy/by;
		  return ab; break;
	default: return 0.0f; 
	}
	
}
float guessx(char p,float a,float b) {
	switch(p) {
		case '+': return b - a; 
		case '-': return b + a;
		case '*': return b / a;
		case '/': return b * a;
		default: return 0.0f;
	} 
}			  

struct Fraction { //  Структуры нужны чтобы выводить больше переменных как одно
	float num;
	float den;
};
struct Discriminant { // Очень удобно
	float d; // Дискриминант 
	float x; // икс1
	float x2; // икс2
};
Fraction frac(float a, float b, float x, float y, char z) {
	Fraction result;
	switch(z) {
		case '-': result.num = a * y - x * b;
			  result.den = b * y; break;
		case '+': result.num = a * y + x * b;
			  result.den = b * y; break;
		case '*': result.num = a * x;
			  result.den = b * y; break;
		case '/': result.num = a * y;
			  result.den = b * x; break;
		default: std::cout << "Нету в списке."; return result;
	}
	return result;
}
float fsu(float a, float b, char z) { // фсу
       switch(z) {
	       case '1': {
				 float ab2 = 2 * a * b; // Считаем сначала 2*a*b потому что потом они станут квадратами
				 b = calc1(b,2,'5');
				 a = calc1(a,2,'5');
				 std::cout << a << "+" << ab2 << "+" << b << "=";
				 return a + ab2 + b;
			 }
	       case '2': { float ab2 = 2 * a * b;
			   a = calc1(a,2,'5');
			   b = calc1(b,2,'5');
			   std::cout << a << "-" << ab2 << "+" << b << "=";
			   return a - ab2 + b; }
	       case '3': { float amb = a-b; //  Имя от а минус б
				 float apb = a+b;
				 std::cout << amb << "*" << apb << "=";
				 return amb*apb; }
	       default: std::cout << "Нету такой функции\n"; return 1;
       }
       return 0;
}
Discriminant d(float b,float a,float c) {
	Discriminant result;
	result.d = calc1(b,2,'5') - 4 * a * c;
	if(result.d > 0) {
		std::cout <<"D=" <<  -b << "+" << calc1(result.d,0,'6') << "/" << 2 << "*" << a << "=" << result.d;
		result.x = (-b + calc1(result.d, 0, '6')) / (2 * a);
		std::cout << "\nx=" << -b << '+' << calc1(result.d, 0, '6') << '/' << 2 << '*' << a << '=' << result.x;
		result.x2 = (-b - calc1(result.d, 0, '6')) / (2 * a);
		std::cout << "\nx2=" << -b << '-' << calc1(result.d, 0, '6') << '/' << 2 << '*' << a << '=' << result.x2;
	}
	else if(result.d == 0) {
		std::cout << "x = " << -b << "/" << 2 << "*" << a << "=";
		result.x = (-b) / (2 * a);
		result.x2 = 0;
	}
	else if(result.d < 0) {
		std::cout << "Нет решения.";
		result.x=0;
	        result.x2=0;	
	}
	return result;
}
void decorator(char c,char sym) { // Для сохранения места
	float a,b;
	std::cout << "Введите переменную a:";
	std::cin >> a;
	std::cout << a << sym << "b\n";
	std::cout << "Введите переменную b:";
	std::cin >> b;
	std::cout << "Результат:" << calc1(a,b,c) << "\n";
}

int main() {
	char c,u;
	std::cout << "Добро пожаловать в adcalc++!\n";
	std::cout << "Вы можете выбрать простой калькулятор и продвинутый\n";
	std::cout << "1:Обычный калькулятор 2:Продвинутый калькулятор\nВыбор:";
	std::cin >> u;
	float a,b,z = 0;
	switch(u) {
		default: std::cout << "Выберите!\n"; return 1;
		case '1': std::cout << "Какую операцию хотите использовать\n1:a+b 2:a-b 3:a*b 4:a/b 5:a^b 6:\u221Aa 7:x +,-,/,* n = n\nВыбор:";
			  std::cin >> c;
			  switch(c) {
				  default: std::cout << "Пожалуйста выберите из списка!(Ошибка #2)\n";
					   return 2;
				  case '1': decorator(c,'+'); break;
				  case '2': decorator(c,'-'); break;
				  case '3': decorator(c,'*'); break; // Преисполнился в функциях ;)
				  case '4': decorator(c,'/'); break;
				  case '5': decorator(c,'^'); break;
				  case '6': std::cout << "Введите переменную a:";
					    std::cin >> a;
					    if(calc1(a,b,c) < 0) {
						    std::cout << "Ошибка корень меньше 0.\n"; return -1;
					    }
				       	   std::cout << "Результат:" << calc1(a,b,c) << "\n"; break;
				  case '7':{ std::cout << "Введите имя переменной она должна быть длинной в 1 символ потом действие (+,-,*,/) после цифру после знак = после ответ\n";
					    std::cout << "Ввод:";
					    std::cin >> c;
					    char p;
					    std::cin >> p;
					    std::cin >> a;
					    char eq;
					    std::cin >> eq;
					    std::cin >> b;
					    std::cout << c << "=" << guessx(p,a,b) << "\n"; break;
					   } 
				}
			  break;
		case '2': std::cout << "Выберите формулу\n1:Кинетическая энергия Ek-mv2/2\n2:Км/час в метр/сек\n3:Потенциальная энергия En=mgh\n4:Момент силы M=F*d\n5:Центр массы с двумя точками\n6:Дробь\n7:ФСУ\n8:Дискриминант\nВыбор:"; // Один раз вызвать печать на экран быстрее 
			  std::cin >> c;
			  switch(c) {
				  default: std::cout << "Пожалуйста выберите из списка!(Ошибка #2)\n";
					   return 2; break;
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
				  case '6': { float x,y;
						    char v;
					    std::cout << "Дробь номер один сначала числитель потом знаменатель:";
					    std::cin >> a;
					    std::cin >> b;
					    std::cout << "Выберите действие\"+,-,*,/\":";
					    std::cin >> v;
					    std::cout << "Дробь номер два сначала числитель потом знаменатель:";
					    std::cin >> x;
					    std::cin >> y;
					    Fraction result = frac(a,b,x,y,v);
					    std::cout << "Результат:" << result.num << "/" << result.den; 
					    std::cout << "=" << result.num / result.den << "\n"; break; }
				  case '7': std::cout << "Введите переменную a и b:";
					    std::cin >> a;
					    std::cin >> b;
					    std::cout << "1:Квадрат суммы,2:Квадрат разности,3:Разность квадратов:";
					    std::cin >> c;
					    std::cout << "Результат:" << fsu(a,b,c) << "\n"; break; 
				  case '8': { std::cout << "Введите b a c:";
					    std::cin >> b;
					    std::cin >> a;
					    float cf = 0;
					    std::cin >> cf;
					    Discriminant result = d(b,a,cf);
					    std::cout <<  "\nДискриминант:" << result.d << "\nX1:" << result.x  << "\nX2:" << result.x2 << "\n";
			  }
			  break;
	}
	return 0;
}
}
