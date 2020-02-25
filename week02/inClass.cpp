#include <iostream>
#include <cmath>
//#pragma warning(disable:4700)
using namespace std;
struct Point {
	double x;
	double y;

    double distance(Point other) {
        double differenceX = this->x - other.x;
        double differenceY = this->y - other.y;
        return sqrt(differenceX * differenceX + differenceY * differenceY);
    }
};

struct Triangle {
	Point pointA, pointB, pointC;

    double Perimiter() {
        return distance(pointA, pointB) + distance(pointA, pointC) +
		distance(pointB, pointC);
    }
};

double distance(Point point1, Point point2) {
	double differenceX = point1.x - point2.x;
	double differenceY = point1.y - point2.y;
	return sqrt(differenceX * differenceX + differenceY * differenceY);
}

double Perimeter(Triangle t) {
	return distance(t.pointA, t.pointB) + distance(t.pointA, t.pointC) +
		distance(t.pointB, t.pointC);
}

double Area(Triangle t)
{
	
	double halfPerimeter = Perimeter(t) / 2;
	double sideC = distance(t.pointA, t.pointB);
	double sideB = distance(t.pointA, t.pointC);
	double sideA = distance(t.pointB, t.pointC);
	return sqrt(halfPerimeter * (halfPerimeter - sideC) * (halfPerimeter - sideB) * 
		(halfPerimeter - sideA));
	
}

struct Student 
{
	char name[32];
	int age, FN;
};
void setStudent(Student & s,const char name[], int age, int FN)
{
	s.age = age;
	s.FN = FN;
	strcpy_s(s.name, strlen(name), name);
}

void setStudent(Student * s,const char name[], int age, int FN)
{
    //(*s).age = age;
	s->age = age;
	s->FN = FN;
	strcpy_s(s->name, strlen(name), name);
}

void swap(int & a, int & b) {
    int temp = a;
    b = a;
    b = temp;
}


int main()
{
    func();
    Triangle pencho;
    pencho.pointA = ...;
    pencho.pointB = ...;
    pencho.pointC = ...;

    pencho.Perimiter();


    Point kancho, lacho;
    kancho.distance(lacho);

    return 0;
}

