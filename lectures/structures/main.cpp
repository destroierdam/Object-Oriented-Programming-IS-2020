#include <iostream>

struct Point {
	double x;
	double y;
};

struct Rational {
	double numerator;
	double denominator;
};

Rational multiply(Rational num1, Rational num2) {
	Rational result;
	result.numerator = num1.numerator*num2.numerator;
	result.denominator = num1.denominator*num2.denominator;
	return result;
}

Rational sum(Rational num1, Rational num2) {
	Rational result;
	result.numerator = num1.numerator*num2.denominator + 
					   num2.numerator*num1.denominator;
	result.denominator = num1.denominator*num2.denominator;
	return result;
}

void print(Rational number) {
	std::cout << number.numerator << '/' << number.denominator;
}


struct Date {
	int day, month, year;
};

struct Person {
	char name[100];
	Date birthdate;
};
/*
void read(Person & p) {
	std::cin >> p.birthdate.day >> p.birthdate.month >> p.birthdate.year;
	std::cin.getline(p.name, 100);
}
*/

bool earlier(Date leftDate, Date rightDate) {
	if (leftDate.year < rightDate.year) {
		return true;
	}
	if (leftDate.year == rightDate.year &&
		leftDate.month < rightDate.month) {
		return true;
	}
	if (leftDate.year == rightDate.year &&
		leftDate.month == rightDate.month &&
		leftDate.day < rightDate.day) {
		return true;
	}
	return false;
}

Person findYoungest(Person people[], int size) {
	Date minDate;
	minDate.day = 1;
	minDate.month = 1;
	minDate.year = 0;

	Person youngest;
	for (int i = 0; i < size; i++) {
		if (earlier(minDate, people[i].birthdate)) {
			minDate = people[i].birthdate;
			youngest = people[i];
		}
	}
	return youngest;
}

void read(Person * p) {
	//std::cin >> (*p).birthdate.day;
	std::cin >> p->birthdate.day;
	std::cin >> p->birthdate.month;
	std::cin >> p->birthdate.year;
}

struct A {
	char c;
	int :0;
	int number:3;
	char p;
};

int main()
{
	A a;
	std::cout << sizeof(A);
}
