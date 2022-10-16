#include"Students.h"
#include<vector>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
class Admin{
	string Name;
	string id;
	string password;
public:
	int idx;
	Admin() {
		 Name="";
		 id="";
		 password="";
	} 
	Admin(string n,string i,string p) {
		Name = n;
		id = i;
		password = p;
	}
	void setName(string Dname) {
		this->Name = Dname;
	}
	string getName() {
		return Name;
	}    
	void setAdPass(string passd) {
		this->password = passd;
	}
	string getAdPass() {
		return password;
	}
	void setI(string di) {
		this->id = di;
	}
	string getI() {
		return id;
	}
	static bool AdLogin(vector<Admin>Main){
		string NotFound;
		bool found = false;
		NotFound = "ID doesn't Match Any!";
		Admin ent;
		cout << "Enter Your Id : " << endl;
		cin >> ent.id;
		bool checked = false;
		while (!checked) {
			cout << endl << "Enter your password : \t";
			char pw;
			pw = _getch();
			while (pw != '\r') {
				ent.password.push_back(pw);
				cout << '*';
				pw = _getch();
			}
			if (ent.password.size() < 8) {
				cout << "invalid length, Try again" << endl;
				checked = false;
			}
			else checked = true;			
		}
		if (checked) {
			
			for (int i = 0; i < Main.size();i++) {
				if (ent.id==Main[i].getI()&&ent.password==Main[i].getAdPass()) {
					found = true;				
					break;
				}				
			}			
		}
		return found;
	}
	static void AddStudent(vector<vector<Course>>temps,vector<Students>s) {
		Students News;
		cout << "Enter Student Name : \n";
		string tempN;
		string m;
		cin>>tempN;
		s.push_back(News);
		News.setName(tempN);
		cout << endl << "Enter grade : \n";
		int temp;
		cin >> temp;
		News.setY(temp);
		
		cout << "your courses are :" << endl;
		if (temp == 1) {
			cout << "Select Mandatory Courses" << endl;
			for (int i = 0; i < temps[1].size(); i++) {
				cout << temps[1][i].getNC() << endl;
			}
		}
		else if (temp == 2) {
			cout << "Select Mandatory Courses" << endl;
			for (int i = 0; i < temps[2].size(); i++) {
				cout << temps[2][i].getNC() << endl;
			}
		}
		else if (temp == 3) {
			for (int i = 0; i < temps[3].size(); i++) {
				cout << temps[3][i].getNC() << endl;
			}

		}else cout << "Enter a valid Grade, from 1 to 3" << endl;
		
		
		
	}
	static void AddCourse() {
		Course* newcou = new Course();
		char s;
		bool m = false;
		string tempco, e;
		int max=0,g=0;
		cout << "enter Course name : ";
		cin >> e;
		newcou->setNC(e);
		cout << "\ninitially, this course is aimed for which year : ";
		cin >> g;
		newcou->setAc(g);
		if(g>1){
			cout << "Enter PreRequisite Course Name" << endl;
			cin >> tempco;
			newcou->preReq.push(tempco);
		}
		cout << "\nEnter 'f' for fall semester, 's' for spring semester : ";
		cin >> s;
		cout << "\nEnter Maximum Number of Students : ";
		cin >> max;
		newcou->setMax(max);
		e = toupper(e[0]);
		e.push_back(toupper(e[1]));
		newcou->setCode(e);
		int H;
		cout << "\nEnter credit Hours : ";
		cin >> H;
		newcou->setHours(H);
		newcou->setCode(newcou->getCode() + to_string(newcou->getHours()) + "H" + to_string(newcou->getAc()) );
		cout << "Generated Code is " << newcou->getCode();

		
		cout << "\nCourse Added Successfully";
		
	}
	static void View(  vector<vector<Course>>tempc,vector<Students>vtemp) {
		cout << "Enter id of student" << endl;
		string id;
		cin >> id;
		int x=0;
		bool f = false;
		for (int i = 0; i < vtemp.size(); i++) {
			if (id == vtemp[i].getid())
			{
				f = true;
			}
		}
		if (f)
		{
			for (int i = 0; i < vtemp[x].prog.size(); i++) {
				cout << "in Progress Course " << vtemp[x].prog[i] << endl;
			}
			for (int i = 0; i < vtemp[x].finished.size(); i++) {
				cout << "Finished Course " << vtemp[x].finished[i] << endl;
			}
		}
		else
		{
			cout << "incorrect id" << endl;
		}
		
	}
	
};
