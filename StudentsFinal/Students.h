#include"Course.h"
#include<queue>
#include<conio.h>
#include<unordered_map>

class Students {
	string ID;
	string name;
	string password;
	int AcdYear;
	
public:
	vector<string>finished;
	vector<string> prog;
	Students() {
		ID ="";
		name = "";
		password = "1234";
		AcdYear = 1;
	}
	Students(string Sid, string sname,int y, vector<string>finished, vector<string> prog) {
		ID = Sid;
		name = sname;
		password = "1234";
		AcdYear = y;
		this->finished = finished;
		this->prog = prog;
	}
	Students(string Sid, string sname, int y,  vector<string> prog) {
		ID = Sid;
		name = sname;
		password = "1234";
		AcdYear = y;
	
		this->prog = prog;
	}
	
	void setName(string s) {
		this->name = s;
	}
	string getName() {
		return name;
	}
	void setpass(string stp) {
		this->password = stp;
	}
	string getpass() {
		return password;
	}
	void setid(string D) {
		this->ID = D;
	}
	string getid() {
		return ID;
	}
	void setY(int yer) {
		this->ID = yer;
	}
	int getY() {
		return AcdYear;
	}
	static int sdLogin(vector<Students>SMain) {
		bool NotFound;
		int idx=0;
		bool found = false;
		bool checked = false;
		NotFound = "ID doesn't Match Any!";
		Students Sent;
		cout << "Enter Your Id : " << endl;
		cin >> Sent.ID;
			cout << endl << "Enter your password : \t";
			char pw;
			pw = _getch();
			while (pw != '\r') {
				Sent.password.push_back(pw);
				cout << '*';
				pw = _getch();	
			}
			if (Sent.password.size() < 8) {
				NotFound = true;
			}
			if (NotFound) {
				checked = true;
				cout << endl << "Please, kindly go to edit and Reset Default Password" << endl;
				
			}
		if (checked) {
			for (int i = 0; i < SMain.size(); i++) {
				if (Sent.ID.compare( SMain[i].ID) && Sent.password.compare(SMain[i].password)) {
					found = true;	
				}
		     }
		}
		return Sent.AcdYear;
	}

	void ViewAvail(int op, vector<Students>SMain, vector<vector<Course>>tempc) {
		int choice = 0;
		string saved;
		if (SMain[op].AcdYear == 1) {
			for (int i = 0; i < tempc[0].size(); i++) {
				cout<<i+1<<"." << tempc[0][i].getNC() << endl;
			}
		}
		else if (SMain[op].AcdYear == 2) {
			for (int i = 0; i < tempc[1].size(); i++) {
				cout << i + 1 << "." << tempc[1][i].getNC() << endl;
			}
		}
		else if (SMain[op].AcdYear == 3) {
			for (int i = 0; i < tempc[2].size(); i++) {
				cout << i + 1 << "." << tempc[2][i].getNC() << endl;
			}
		}
		cout << "to register to Any of these courses, Press Number of choice : " << endl;
		cin >> choice;
		choice -= 1;
		if (op > 2) {
			 saved = tempc[op - 1][choice].preReq.top();
		}
		cout << saved;
	}

	static void ViewCourse(vector<vector<Course>>tempc) {
		string c;
		int idx;
		cout << "Enter Year" << endl;
		cin >> idx;
		cout << "Enter course ID" << endl;
		cin >> c;
		for (int i = 0; i < tempc[idx - 1].size(); i++) {
			if (c == tempc[idx - 1][i].getCode()) {
				cout << "Course " << tempc[idx - 1][i].getNC() << " is a " << idx + 1 << "Course" << endl;
				cout << "Code for Course : " << tempc[idx][i].getCode() << endl;
				cout << " it Has " << tempc[idx - 1][i].getHours() << " Credit Hours" << endl;
				break;
			}
		}
			
			
	}
	/*void CourseReg(string myi,string myP, vector<Students>SMain, vector<vector<Course>>tempc) {
		bool chk=false;
		int g = 0;
		cout << "You must Enter ID and Password" << endl;
		cin >> myi;
		cin >> myP;
		for (int i = 0; i < SMain.size(); i++) {
			if (myi.compare(SMain[i].ID) && myP.compare(SMain[i].password)) {
				chk = true;	
				g = SMain[i].AcdYear;
			}
			break;
		}
		if (chk) {
			int choice;
			ViewAvail(g, SMain, tempc);
			cout << endl << "Choose a Course :" << endl;
			cin >> choice;

		}*/

	

	
	static void Edit(vector<Students> s) {
		string id, name, pass;
		int ch;
		cout << "Enter id :";
		cin >> id;
		int x=0;
		for (int i = 0; i < s.size(); i++) {
			if (id == s[i].ID)
			{
				x == i;
			}
			else
			{
				cout << "incorrect id" << endl;
			}
		}
		cout << "1.Edit Name" << endl << "2.Edit password" << endl;
		cin >> ch;
		if (ch == 1) {
			cin >> name;
			s[x].setName(name);
		}
		else if (ch == 2) {
			cin >> pass;
			s[x].setpass(pass);
		}
	}
	void ViewMyCourses(vector<Course>progg) {
		cout << "Your Finished Courses are : " << endl;
		for (int i = 0; i < progg.size(); i++) {
			cout << progg[i].getNC() << endl;
		}
	}

	

};



