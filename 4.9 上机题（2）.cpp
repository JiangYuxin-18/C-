#include <iostream>
using namespace std;

class RECT {
public:
	RECT(double x1, double y1);
	virtual double area();
	double peri();
	virtual int isSquare();
protected:
	double x;//矩形的长
	double y;//矩形的宽
};

class CUB : public RECT{
	double height;
public:
	CUB(double x, double y, double h);
	double volume();
	double area();
	int isSquare();
};

RECT::RECT(double x1, double y1) :x(x1), y(y1) {
}

double RECT::area() {
	int s;
	s = x * y;
	return s;
}

double RECT::peri() {
	int c;
	c = (x + y) * 2;
	return c;
}

int RECT::isSquare() {
	if (x == y) return 1;
	else return 0;
}

CUB::CUB(double x, double y, double h) :RECT(x, y) {
	height = h;
}

double CUB::volume() {
	double vol;
	vol = RECT::area() * height;
	return vol;
}

double CUB::area() {
	double A;
	A = 2 * RECT::area() + peri() * height;
	return A;
}

int CUB::isSquare() {
	if (RECT::isSquare()) return x == height;
	else return 0;
}

int main() {
	cout << "老师您好，欢迎使用！" << endl << "请依次输入长方体的长宽高：";
	double x, y, h;
	cin >> x >> y >> h;
	CUB cu(x, y, h);
	RECT* re;
	re = &cu;
	cout << "体积：" << cu.volume() << endl;
	cout << "表面积：" << re->area() << endl;
	cout << "是否为正方体：";
 	if (re->isSquare())
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}