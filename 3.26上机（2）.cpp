#include <iostream>
using namespace std;

class Date{
public:
/* Ĭ�Ϲ��캯������fullyear����ʽ���������գ�Ĭ��ֵΪ1990��1��1�գ�ͬʱ����
���ڷָ���Ϊ��-�� */
Date(int year = 1990, int month = 1, int day = 1);
/* get��set���� */
// �������ڣ�����зǷ����»��գ�������Ϊ1
void setDate(int year, int month, int day);
void setYear(int year);
int getYear();
void setMonth(int month);
int getMonth();
void setDay(int month);
int getDay();
void printFullYear(); // ��YYYY-MM-DD����ʽ��ӡ��2011-01-08
void printStandardYear(); // ��YY-MM-DD����ʽ��ӡ������11-01-08
/* ���㺯�� */
// ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ����������
int fullYearsTo(int year, int month, int day);
/* ���㵱ǰ�������������֮����������(��������)��������������ڵ�ǰ����֮ǰ�����ظ����� */
int daysTo(int year, int month, int day);

private:
int year;
int month;
int day;
char separator; // ���ڷָ���
};

int isleap(int year){
	
	if(year % 400 == 0)  /* ��400�ı������������� */
		return 1;
	else if(year % 100 == 0)    /* ����400�ı�������������100�ı���������ƽ�� */
		return 0;
	else if(year % 4 == 0)      /* ����100�ı���������4�ı�����Ҳ������ */
		return 1;
	else
		return 0;
}

Date::Date(int year , int month , int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

int equal(Date date,Date date1){
	if(date.getYear()==date1.getYear()&&date.getMonth()==date1.getMonth()&&date.getDay()==date1.getDay()) return 0;
	else if(date.getYear()>date1.getYear()) return 1;
	else if(date.getYear()==date1.getYear()&&date.getMonth()>date1.getMonth()) return 1;
	else if(date.getYear()==date1.getYear()&&date.getMonth()==date1.getMonth()&&date.getDay()>date1.getDay()) return 1;
	else return -1;
}

void Date::setDate(int year,int month,int day){
	if(month<1||month>12) month=1;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day<1||day>31) day=1;
	}else if(month==2&&year%4==0){
		if(day<1||day>29) day=1;
	}else if(month==2){
		if(day<1||day>28) day=1;
	}else{
		if(day<1||day>30) day=1;
	}
	
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::setYear(int year){
	this->year = year;
}

int Date::getYear(){
	return this->year;
}

void Date::setMonth(int month){
	if(month<1||month>12) month=1;
	this->month = month;
}

int Date::getMonth(){
	return this->month;
}

void Date::setDay(int day){
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day<1||day>31) day=1;
	}else if(month==2&&year%4==0){
		if(day<1||day>29) day=1;
	}else if(month==2){
		if(day<1||day>28) day=1;
	}else{
		if(day<1||day>30) day=1;
	}
	this->day = day;
}

int Date::getDay(){
	return this->day;
}

void Date::printFullYear(){
	
	cout<<getYear()<<"-";
	if(getMonth()>9){
		cout<<getMonth()<<"-";
	}else{
		cout<<"0"<<getMonth()<<"-";
	}
	if(getDay()>9){
		cout<<getDay()<<endl;
	}else{
		cout<<"0"<<getYear()<<endl;
	}
	
}

void Date::printStandardYear(){
	cout<< getYear()%100<<"-";
	if(getMonth()>9){
		cout<<getMonth()<<"-";;
	}else{
		cout<<"0"<<getMonth()<<"-";;
	}
	if(getDay()>9){
		cout<<getDay()<<endl;
	}else{
		cout<<"0"<<getYear()<<endl;
	}
}

int Date::fullYearsTo(int year, int month, int day){
	int temp;
	if (month > this->month) {
		return temp = year - this->year;
	}
	else if (month == this->month) {
		if (day >= this->day)
			return temp = year - this->year;
		else
			return temp = year - this->year - 1;
	}
	else
		return temp = year - this->year - 1;
	
}

int Date::daysTo(int year, int month, int day){
	int m, d, y;
	int starTime ;
	int y1,m1,d1;
	y1 = this->year;
	m1 = this->month;
	d1 = this->day;

	
	y=year, m=month, d=day;
	Date date(y,m,d);
	Date date1(y1,m1,d1);
	int flag=0;
	if(equal(date,date1)<0) {  //�Ƚ�����date�����ʱ����0��
		flag=1;
		Date swag=date1;
		date1 = date;
		date = swag;
		
	}
	y=date.getYear();
	m=date.getMonth();
	d=date.getDay();
	
	y1=date1.getYear();
	m1=date1.getMonth();
	d1=date1.getDay();
	
	int N = 0;
	static int days[2][13] = {
		365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		366, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	};


	if(y1 + 1 < y){					/* ��һ���� + 1 ��С�ڵڶ����� */
		while(y1 + 1 < y){
			if(isleap(y1) == 1){		/* �������ֱ꣬�Ӽ�366 */
				N += 366;
				++y1;
			}else{						/* ����ƽ���365 */
				N += 365;
				++y1;
			}
		}
	}
	
	if(y1 + 1 == y){					/* ��һ����͵ڶ��������Ϊһ������2013��2014 */
		if(isleap(y1) == 1){
			N += (days[1][m1] - d1);	/* �Ƚ���һ������Ǹ��·ݼ��� */
			++m1;						/* ���·ݼӵ���һ���� */
			for(; m1 <= 12; ++m1)		/* �ٰ���һ����� */
				N += days[1][m1];
			++y1;
			m1 = 0;
		}else{
			N += (days[0][m1] - d1);
			++m1;
			for(; m1 <= 12; ++m1)
				N += days[0][m1];
			++y1;
			m1 = 0;
		}
	}

	if(y1 == y){
		if(isleap(y1) == 1){
			if(m1 == 0){
				for(m1 = 1; m1 < m; ++m1)
					N += days[1][m1];
				N += d;
			}else if(m1 != m){
				N += (days[1][m1] - d1);
				++m1;
				for(; m1 < m; ++m1)
					N += days[1][m1];
				N += d;
			}else{
				N = d - d1;
			}
		}else{
			if(m1 == 0){
				for(m1 = 1; m1 < m; ++m1)
					N += days[0][m1];
				N += d;
			}else if(m1 != m){
				N += (days[0][m1] - d1);
				++m1;
				for(; m1 < m; ++m1)
					N += days[0][m1];
				N += d;
			}else{
				N = d - d1;
			}
		}
	}
	if(flag==0)
		return N;
	else
		return N*(-1)-1;
}

//��ʵ�������࣬ʹ��������������£�
int main(){
	cout << "��ʦ���ã���ӭʹ��" << endl;
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear(); // ��ӡ��1969-08-11
	birthDate.printStandardYear(); // ��ӡ��69-08-11
	cout << birthDate.fullYearsTo(2010, 4, 15)<<endl; // ��ӡ��40������ʮ��
	cout << birthDate.daysTo(2010, 4, 15)<<endl; // ��ӡ14857������14857����
	// ��ӡ-7254�����͹������絮����7254��
	cout << birthDate.daysTo(1949, 10, 1)<<endl;
}
