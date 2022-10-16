#include<iostream>
#include<stack>
using namespace std;
class Course {
	string name;
	string code;
	int maxstuds;
	int Hours;
	int AcYear;
public:
	stack<string>preReq;
	int grade;
	Course() {
		name = "";
		code = "";
		maxstuds = 0;
		Hours = 0;
	}
	Course(string nc, string cc, int mx, int h) {
		name = nc;
		code = cc;
		maxstuds = mx;
		Hours = h;
	}
	//;
	void setNC(string coN) {
		this->name = coN;
	}
	string getNC() {
		return name;
	}
	void setCode(string subCode) {
		this->code = subCode;
	}
	string getCode() {
		return code;
	}
	void setMax(int Mx) {
		this->maxstuds = Mx;
	}
	int getMax() {
		return maxstuds;
	}
	void setAc(int g) {
		this->AcYear = g;
	}
	int getAc() {
		return AcYear;
	}
	void setHours(int H) {
		this->maxstuds = H;
	}
	int getHours() {
		return Hours;
	}
	
};
