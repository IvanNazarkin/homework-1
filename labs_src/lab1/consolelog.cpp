#include <iostream>
#include "lab1_functions.h"

using namespace std;

int main()
{
	//динамический массив объектов для проверки работы полиморфизма
	int n = 5;
	Polygon** poly = new Polygon * [n];
	poly[0] = new Triangle(new Point[3]{ Point(1,3),Point(2,-5),Point(-8,4) }, 3);
	poly[1] = new Polygon(new Point[7]{ Point(1.4,3.58),Point(5.96,2.46),Point(4.64,1.04),Point(5,-2),
		Point(3.44,0.72),Point(1.1,-0.7),Point(4,2) }, 7);
	poly[2] = new Polygon(new Point[5]{ Point(-3,-2),Point(-1,4),Point(6,1),Point(3,10),Point(-4,9) }, 5);
	poly[3] = new Trapezoid(new Point[4]{ Point(2,6),Point(8,6),Point(10,0),Point(0,0) }, 4);
	poly[4] = new CPolygon(new Point[4]{ Point(0,0),Point(0,1),Point(1,1),Point(1,0) }, 4);
	for (int i = 0; i < n; i++) {
		cout << poly[i]->P() << endl;
		cout << poly[i]->S() << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}