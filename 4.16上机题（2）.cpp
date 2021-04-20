#include <iostream>
using namespace std;

class animal{
	public:
		animal(){
		}
    	animal(int h,int w,char s):m_H(h),m_W(w),m_S(s){
    		
		}
	protected:
		int m_H;
		int m_W;
		char m_S;
};

class ter_animal:public virtual animal{
	public:
		ter_animal(){
		};
    	ter_animal(int h,int w,char s,int r_s):animal(h,w,s),running_speed(r_s){
		}
	protected:
		int running_speed;
};

class aqu_animal:public virtual animal{
	public:
		aqu_animal(){
		}
    	aqu_animal(int h,int w,char s,int s_p):animal(h,w,s),swimming_speed(s_p){
		}
	protected:
		int swimming_speed;
};

class amp_animal:public ter_animal,public aqu_animal{
	public:
		amp_animal(){
		}
    	amp_animal(int h,int w,char s,int s_p,int r_s):animal(h,w,s),aqu_animal(h,w,s,s_p), ter_animal(h,w,s,r_s){
		}
   		void input(){
   			cin>>m_H>>m_W>>m_S>>swimming_speed>>running_speed;
		   }
		void output(){
			cout<<"height:"<<animal::m_H<<endl;
			cout<<"weight:"<<animal::m_W<<endl;
			cout<<"sex:"<<animal::m_S<<endl;
			cout<<"swimming_speed:"<<amp_animal::swimming_speed<<endl;
			cout<<"running_speed:"<<ter_animal::running_speed<<endl;
			
		}
};

int main(){
	cout<<"老师您好，欢迎使用！"<<endl;
	amp_animal A1(50,20,'m',100,120);
    amp_animal A2;
    A2.input();
    A1.output();
    cout<<endl;
    A2.output();
    
	return 0;
}