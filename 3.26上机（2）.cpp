#include <iostream>
using namespace std;

class Date{
public:
/* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置
日期分隔符为“-” */
Date(int year = 1990, int month = 1, int day = 1);
/* get、set方法 */
// 设置日期，如果有非法的月或日，将其置为1
void setDate(int year, int month, int day);
void setYear(int year);
int getYear();
void setMonth(int month);
int getMonth();
void setDay(int month);
int getDay();
void printFullYear(); // 以YYYY-MM-DD的形式打印，2011-01-08
void printStandardYear(); // 以YY-MM-DD的形式打印，比如11-01-08
/* 计算函数 */
// 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
int fullYearsTo(int year, int month, int day);
/* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
int daysTo(int year, int month, int day);

private:
int year;
int month;
int day;
char separator; // 日期分隔符
};

int isleap(int year){
	
	if(year % 400 == 0)  /* 是400的倍数，就是闰年 */
		return 1;
	else if(year % 100 == 0)    /* 不是400的倍数，但是它是100的倍数，就是平年 */
		return 0;
	else if(year % 4 == 0)      /* 不是100的倍数，但是4的倍数，也是闰年 */
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
	if(equal(date,date1)<0) {  //比较两个date，相等时返回0。
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


	if(y1 + 1 < y){					/* 第一个年 + 1 后还小于第二个年 */
		while(y1 + 1 < y){
			if(isleap(y1) == 1){		/* 若是闰年，直接加366 */
				N += 366;
				++y1;
			}else{						/* 若是平年加365 */
				N += 365;
				++y1;
			}
		}
	}
	
	if(y1 + 1 == y){					/* 第一个年和第二个年相差为一，比如2013和2014 */
		if(isleap(y1) == 1){
			N += (days[1][m1] - d1);	/* 先将第一个年的那个月份加满 */
			++m1;						/* 将月份加到下一个月 */
			for(; m1 <= 12; ++m1)		/* 再把这一年加满 */
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

//请实现日期类，使得主函数输出如下：
int main(){
	cout << "老师您好，欢迎使用" << endl;
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear(); // 打印：1969-08-11
	birthDate.printStandardYear(); // 打印：69-08-11
	cout << birthDate.fullYearsTo(2010, 4, 15)<<endl; // 打印：40，满四十岁
	cout << birthDate.daysTo(2010, 4, 15)<<endl; // 打印14857，活了14857天了
	// 打印-7254，共和国比我早诞生了7254天
	cout << birthDate.daysTo(1949, 10, 1)<<endl;
}
