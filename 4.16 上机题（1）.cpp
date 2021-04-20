#include <iostream>
#include <string>
using namespace std;

//基类Person
class Person {
public:
	Person(string  _num, string _name, char _sex, string _add, string _tel) {
		num = _num;
		name = _name;
		sex = _sex;
		add = _add;
		tel = _tel;
	}
	string getNum() {
		return num;
	}
	void setNum(string Num) {
		Num = num;
	}
	string getName() {
		return name;
	}
	void setName(string Name) {
		Name = name;
	}
	string getAdd() {
		return add;
	}
	void setAdd(string Add) {
		Add = add;
	}
	string getTel() {
		return tel;
	}
	void setTel(string Tel) {
		Tel = tel;
	}
	char getSex() {
		return sex;
	}
	void setSex(char Sex) {
		Sex = sex;
	}
	void output() {
		cout << "编    号：" << num << endl;
		cout << "姓    名：" << name << endl;
		cout << "性    别：" << sex << endl;
		cout << "家庭住址：" << add << endl;
		cout << "联系电话：" << tel << endl;
	}
protected:
	char sex;
	string num;
	string name;
	string add;
	string tel;

};

//派生类Student
class Student :public Person {
public:
	Student(int _m, int _p, int _e, int _c) {
		m = _m;
		p = _p;
		e = _e;
		c = _c;

	}
	void setM(int M)
	{
		cin >> M;
		M = m;
	}
	void setP(int P)
	{
		cin >> P;
		P = p;
	}
	void setE(int E)
	{
		cin >> E;
		E = e;
	}
	void setC(int C)
	{
		cin >> C;
		C = c;
	}
	void setScore(char tag, int score) {
		if (tag == 'm') {
			m = score;
		}
		if (tag == 'p') {
			p = score;
		}
		if (tag == 'e') {
			e = score;
		}
		if (tag == 'c') {
			c = score;
		}
	}
	void output1() {
		cout << "编    号：" << num << endl;
		cout << "姓    名：" << name << endl;
		cout << "性    别：" << sex << endl;
		cout << "家庭住址：" << add << endl;
		cout << "联系电话：" << tel << endl;
		cout << "数    学：" << m << endl;
		cout << "物    理：" << p << endl;
		cout << "英    语：" << e << endl;
		cout << "程序设计：" << c << endl;
	}
protected:
	int m;//数学成绩
	int p;//物理成绩
	int e;//英语成绩
	int c;//程序设计成绩
};

class Teacher :public Person {
public:
	Teacher(string _call, double _pay) {
		call = _call;
		pay = _pay;
	}
	void setCall(string Call) {
		call = Call;
	}
	void setPay(double Pay) {
		pay = Pay;
	}
	void output2() {
		cout << "编    号：" << num << endl;
		cout << "姓    名：" << name << endl;
		cout << "性    别：" << sex << endl;
		cout << "家庭住址：" << add << endl;
		cout << "联系电话：" << tel << endl;
		cout << "职    称：" << call << endl;
		cout << "工    资：" << pay << endl;
	}
protected:
	string call;
	double pay;
};

int main() {
	cout << "老师您好，欢迎使用！" << endl;
	Person A;
	string num1;
	string name1;
	char sex1;
	string add1;
	string tel1;
	string tel12;

	string num2;
	string name2;
	char sex2;
	string add2;
	string tel2;
	int m;
	int p;
	int e;
	int c;
	char op;
	int opScore;

	string num3;
	string name3;
	char sex3;
	string add3;
	string tel3;
	string call;
	double pay;
	double opPay;

	cin >> num1 >> name1 >> sex1 >> add1 >> tel1 >> tel12;
	cin >> num2 >> name2 >> sex2 >> add2 >> tel2 >> m >> p >> e >> c;
	cin >> num3 >> name3 >> sex3 >> add3 >> tel3 >> call >> pay;
	A.setNum(num1);
	A.setName(name1);
	A.setSex(sex1);
	A.setAdd(add1);
	A.setTel(tel1);
	A.output();
	cout << endl;
	A.setTel(tel12);
	A.output();
	cout << endl;

	Student B;
	B.setNum(num2);
	B.setName(name2);
	B.setSex(sex2);
	B.setAdd(add2);
	B.setTel(tel2);
	B.setScore('m', m);
	B.setScore('p', p);
	B.setScore('e', e);
	B.setScore('c', c);
	B.output1();
	cout << endl;
	B.setScore(op, opScore);
	B.output1();
	cout << endl;

	Teacher C;
	C.setNum(num3);
	C.setName(name3);
	C.setSex(sex3);
	C.setAdd(add3);
	C.setTel(tel3);
	C.setCall(call);
	C.setPay(pay);
	cout << endl;
	C.setPay(opPay);
	C.output2();

	return 0;
}