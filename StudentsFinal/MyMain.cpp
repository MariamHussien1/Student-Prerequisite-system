#include"Admin.h"
#include<set>
const int s = 100;

int main() {

	//Data
	vector< Admin>MasterV;
	Admin Adm1("Ahmed Wael", "TA1", "char4321");
	Admin Adm2("Ahmed Magdy", "TA2", "	TA1352&6");
	Admin Adm3("Karen Fouad", "TA3", "	7894pfp1");
	Admin Adm4("Adel sami", "TA4", "passd456");
	Admin Adm5("Mohamed saeed", "TA5", "chpu8761");
	MasterV.push_back(Adm1);
	MasterV.push_back(Adm2);
	MasterV.push_back(Adm3);
	MasterV.push_back(Adm4);
	MasterV.push_back(Adm5);
	vector<vector<Course>>years;
	Course c1y1("Intro to Programming", "Pg1Y1", 150, 3);
	Course c2y1("Electronics", "EL1Y1", 100, 4);
	Course c3y1("Business Administration", "ADT1Y1", 150, 2);
	Course c4y1("Calculus2", "MT1Y1", 150, 3);
	vector<Course>Year1;
	Course c1y2("Logic Design", "E2Y2", 150, 3);
	Course c2y2("Object oriented Proramming", "PgL2Y2", 100, 4);
	Course c3y2("Report Writing", "ADT2Y2", 150, 2);
	Course c4y2("Discrete MAths", "MT2Y2", 150, 3);
	vector<Course>Year2;
	Course c1y3("Computer Architecture", "E1Y3", 150, 3);
	Course c2y3("Algorithems", "E3Y3", 100, 4);
	Course c3y3("Ethics", "ADT3Y3", 150, 2);
	Course c4y3("Linear Algebra", "MT3Y3", 150, 3);
	vector<Course>Year3;
	Year1.push_back(c1y1);
	Year1.push_back(c2y1);
	Year1.push_back(c3y1);
	Year1.push_back(c4y1);
	Year2.push_back(c1y2);
	Year2.push_back(c2y2);
	Year2.push_back(c3y2);
	Year2.push_back(c4y2);
	Year3.push_back(c1y3);
	Year3.push_back(c2y3);
	Year3.push_back(c3y3);
	Year3.push_back(c4y3);
	years.push_back(Year1);
	years.push_back(Year2);
	years.push_back(Year3);
	vector<string>finished2;
	vector<string>finished3;
	vector<string>progress1;
	vector<string>progress2;
	vector<string>progress3;

	progress1.push_back("Pg1Y1");
	progress1.push_back("EL1Y1");
	progress1.push_back("ADT1Y1");
	progress1.push_back("MT1Y1");

	progress2.push_back("E2Y2");
	progress2.push_back("PgL2Y2");
	progress2.push_back("ADT2Y2");
	progress2.push_back("MT2Y2");

	progress3.push_back("E1Y3");
	progress3.push_back("ADT3Y3");
	progress3.push_back("ADT3Y3");
	progress3.push_back("MT3Y3");

	finished2.push_back("Pg1Y1");
	finished2.push_back("EL1Y1");
	finished2.push_back("ADT1Y1");
	finished2.push_back("MT1Y1");

	finished3.push_back("Pg1Y1");
	finished3.push_back("EL1Y1");
	finished3.push_back("ADT1Y1");
	finished3.push_back("MT1Y1");
	finished3.push_back("E2Y2");
	finished3.push_back("PgL2Y2");
	finished3.push_back("ADT2Y2");
	finished3.push_back("MT2Y2");
	vector<Students> studP1;
	Students S1("y11", "Kareem Ahmed", 1, progress1);
	Students S2("y12", "Ali wael", 1, finished2, progress2);
	Students S3("y13", "ibrahim mohamed", 1, finished3, progress3);
	studP1.push_back(S1);
	studP1.push_back(S2);
	studP1.push_back(S3);


	//////////////////////////////////////////////////////////////
	int Mainchoice = 0;
	int adminchoice = 0;
	int Schoice = 0;
	Students s;
	while (1) {
		cout << "\t\t\t" << "Welcome to System's Main Page\n" << endl;
		cout << "Press The Option of Your choice :\n" << endl;
		cout << "1.LogIn As Admin\n\n" << "2.LogIn As Student\n\n" << "3.Close\n\n";
		cin >> Mainchoice;
		switch (Mainchoice)
		{
		case 1:
			
				if (Admin::AdLogin(MasterV)) {
					while (1) {
					cout << "\t\t\t" << "Welcome to Admin's Main Page\n" << endl;
					cout << "Press The Option of Your choice :\n" << endl;
					cout << "1.Add a New Student\n\n" << "2.Add a New Course\n\n" << "3.View Courses\n\n" << "4.Back \n\n";
					cin >> adminchoice;
					switch (adminchoice)
					{
					case 1:Admin::AddStudent(years,studP1);
						break;
					case 2:Admin::AddCourse();
						break;
					case 3:Admin::View(years,studP1);
						
					}break;
				}
					
			}
			/*int opId = Students::sdLogin(studP1) - 1;
			cout << endl << endl << "Here's All Available courses for Your Academic Year : " << endl;
			studP1[opId].ViewAvail(opId, studP1, years);
			cout << endl << "Press Course Number to View Details" << endl;
			cin >> Cchoice;
			*/
		case 2:if (Students::sdLogin(studP1)) {
			while (1) {
			
				cout << "\t\t\t" << "Students's Main Page\n" << endl;
				cout << "Press The Option of Your choice :\n" << endl;
				cout << "1.View Available Courses\n\n" << "2.View Course Details\n\n" <<  "3.Edit" << "4.Back\n\n";
				cin >> Schoice;
				int opId = Students::sdLogin(studP1) - 1;
				switch (Schoice)
				{
				case 1:s.ViewAvail(opId,studP1,years);
					break;
				case 2:Students::ViewCourse(years);
					break;
				case 3: Students::Edit(studP1);
				}
			}
		}

		}break;
	}
		/*



					switch (adminchoice)
					{
					case 1:

						break;

					}

				}
			case 2://




		}*/
		/*void data() {
			//Admin data
			vector<Admin>MasterV;
			Admin m;
			string u, p, id;
			bool s = false;
			ifstream admindata("Admindatabase.csv");
			while (admindata >> u >> p >> id) {
				m.setName(u);
				m.setI(id);
				m.setAdPass(p);
				MasterV.push_back(m);
			}

			///Student data
			vector<Students> studP1;
			Students stud;
			string sname, spass, sid;
			int acdyear;
			ifstream studdata("Studentdatabase.csv");
			while (studdata >> sname >> spass >> sid >> acdyear) {
				stud.setName(sname);
				stud.setid(sid);
				stud.setpass(spass);
				stud.setY(acdyear);
				studP1.push_back(stud);
			}

			//Courses data
			vector<vector<Course>>years;
			vector<Course>Year1;
			vector<Course>Year2;
			vector<Course>Year3;
			Course tempcourse;
			string code, cname;
			int chour, cMax, cgrade;
			ifstream coursed("Coursedatabase.csv");
			while (coursed >> cname >> chour >> code >> cMax >> cgrade) {
				if (cgrade == 1) {
					tempcourse.setNC(cname);
					tempcourse.setCode(code);
					tempcourse.setHours(chour);
					tempcourse.setMax(cMax);
					Year1.push_back(tempcourse);
				}
				else if (cgrade == 2) {
					tempcourse.setNC(cname);
					tempcourse.setCode(code);
					tempcourse.setHours(chour);
					tempcourse.setMax(cMax);
					Year2.push_back(tempcourse);
				}
				else if (cgrade == 2) {
					tempcourse.setNC(cname);
					tempcourse.setCode(code);
					tempcourse.setHours(chour);
					tempcourse.setMax(cMax);
					Year3.push_back(tempcourse);
				}
			}
			years.push_back(Year1);
			years.push_back(Year2);
			years.push_back(Year3);
		}*/
		/*cout << "\t\t\t" << "Welcome to System's Main Page\n" << endl;
		cout << "Press The Option of Your choice :\n" << endl;
		cout << "1.LogIn As Admin\n\n" << "2.LogIn As Student\n\n" << "3.Close\n\n";
		cin >> Mainchoice;
		switch (Mainchoice)
		{
		case 1:
			if (Admin::AdLogin(MasterV)) {
				cout << "\t\t\t" << "Welcome to Admin's Main Page\n" << endl;
				cout << "Press The Option of Your choice :\n" << endl;
				cout << "1.Add a New Student\n\n" << "2.Add a New Course\n\n" << "3.View Courses\n\n" << "4.View Students\n\n";
				//cin >> adminchoice;
			}
			else cout << "Invalid input" << endl;
			break;
		case 2:	int opId = Students::sdLogin(studP1) - 1;
			cout << endl << endl << "Here's All Available courses for Your Academic Year : " << endl;
			studP1[opId].ViewAvail(opId, studP1, years);
			cout << endl << "Press Course Number to View Details" << endl;
			cin >> Cchoice;
			int Vindx = studP1[opId].getY() - 1;
			studP1[opId].ViewCourse(Cchoice, Vindx, years);
		}
		}*/
		//cout << endl << studP1[1].getpass() << " " << studP1[1].getid() << " " << studP1[1].getName() <<"  "<< studP1[1].getY();
}
