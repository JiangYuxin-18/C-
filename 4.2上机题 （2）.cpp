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
	cout << "��ʦ���ã���ӭʹ�ã�";
	cout << "������������λѧ����ѧ�ţ����������˳ɼ���" << endl;
	for (int i = 0; i < NUM; i++) {
		stu[i].input();
	}
	cout << "��λͬѧ�ĳɼ���Ϣ����Ϊ��" << endl;
	sort(stu, stu + 4, cmp);
	for (int i = 0; i < NUM; i++) {
		stu[i].display();
	}
	return 0;
}