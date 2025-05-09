#include <iostream>
using namespace std;
void calc1(float a, float b, short unsigned c) {
	switch(c) {
		case 1: cout << (a + b); break;
		case 2: cout << (a - b); break;
		case 3: cout << (a * b); break;
		case 4: if(a == 0 or b == 0) {
				cout << "Don't divide by zero!!";
			}
			else
			cout << (a / b); break;
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
	short unsigned c;
	cout << "Hello, welcome to the adcalc++\n";
	cout << "Use simple or adcanced calc?\n";
	cout << "1:Simple calc a+b etc.. 2:Advanced calc kinetic energy etc.. Input:";
	short unsigned u;
	cin >> u;
	if(u > 2 or u < 1)
		return 2;
	switch(u) {
		case 1: cout << "Which operation would you choose?\n";
			cout << "1:a+b 2:a-b 3:a*b 4:a/b Input:";
			cin >> c;
			if(c < 1 or c > 4) {
			cout << "Choose valid option";
			return 1;
			}
			cout << "Input a var:";
			cin >> a;
			if(c == 1) 
				cout << a << " + b";
			else if(c == 2)
				cout << a << " - b";
			else if(c == 3)
				cout << a << " * b";
			else if(c == 4)
				cout << a << " / b" ;
			cout << "\nInput b var:";
			cin >> b;
			cout << "You answer:";
			calc1(a,b,c);
			cout << "\n"; break;
		case 2: cout << "Choose formulas\n";
			cout << "1:Kinetic energy Ek=mv2/2\n";
			cout << "2:Kilometers per hour to m/s\n";
			cout << "3:Potencitial energy En=mgh\n";
			cout << "4:Moment of Force M=F*d\n";
			cout << "5:Center of mass(read the book)\n";
			cin >> c;
			if(c < 1 or c > 5) {
				cout << "Choose valid option";
				return 3;
			}
			switch(c) {
				default:cout << "Not ready yet! :(\n";
					return 4;
				case 1: cout << "Input mass(kg):";
					cin >> a;
					cout << "\nInput metres in second:";
					cin >> b;
					cout << "\nAnswer:";
					calc2(a,b,0,c);
					cout << " J\n"; break;
				case 2: cout << "Input km/h:";
					cin >> a;
					cout << a << " km/h is ";
					calc2(a,b,0,c);
					cout << " m/s\n"; break;
				case 3: cout << "Input object mass(kg):";
					cin >> a;
					cout << "\nInput height of obj(m):";
					cin >> b;
					calc2(a,b,0,c); break;
				case 4: cout << "Input force in Newthon(H):";
					cin >> a;
					cout << "\nInput radius-vector(m):";
					cin >> b;
					cout << "\nOutput:";
					calc2(a,b,0,1);
					cout << "\n"; break;
				case 5: cout << "Input mass of a second obj(kg):";
					cin >> a;
					cout << "\nInput a length:";
					cin >> b;
					cout << "\nInput mass 1:";
					cin >> u;
					cout << "\nPoint of mass is in the ";
					calc2(a,b,u,c);
					cout << " m\n"; break;
						
			}


		}
	
	
	return 0;
}
