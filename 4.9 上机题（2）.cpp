#include <iostream>
using namespace std;

class RECT {
public:
	RECT(double x1, double y1);
	virtual double area();
	double peri();
	virtual int isSquare();
protected:
	double x;//���εĳ�
	double y;//���εĿ�
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
	cout << "��ʦ���ã���ӭʹ�ã�" << endl << "���������볤����ĳ���ߣ�";
	double x, y, h;
	cin >> x >> y >> h;
	CUB cu(x, y, h);
	RECT* re;
	re = &cu;
	cout << "�����" << cu.volume() << endl;
	cout << "�������" << re->area() << endl;
	cout << "�Ƿ�Ϊ�����壺";
 	if (re->isSquare())
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}