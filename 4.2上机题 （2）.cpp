#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cstudent {
public:
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	int getScore() {
		return score;
	}
	int getTeamScore() {
		return teamScore;
	}
	void input() {
		cin >> number >> name >> score;
	}
	void display() {
		cout << number << " " << name << " " << score << endl;
	}
private:
	int number;
	string name;
	int score;
	int teamScore;

};

bool cmp(Cstudent _, Cstudent __) {
	if (_.getScore() > __.getScore()) return 1;
	else if (_.getScore() == __.getScore() && _.getNumber() > __.getNumber()) return 1;
	else return 0;
}

int main() {
	const int NUM = 4;
	Cstudent stu[NUM];
	cout << "老师您好，欢迎使用！";
	cout << "请依次输入四位学生的学号，姓名，个人成绩：" << endl;
	for (int i = 0; i < NUM; i++) {
		stu[i].input();
	}
	cout << "四位同学的成绩信息排名为：" << endl;
	sort(stu, stu + 4, cmp);
	for (int i = 0; i < NUM; i++) {
		stu[i].display();
	}
	return 0;
}