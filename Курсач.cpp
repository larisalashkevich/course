#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Account
{
public:
	Account() { logIn = ""; password = ""; admin = false; }

	string GetLog() { return logIn; };
	string GetPassword() { return password; };
	bool IsAdmin() { return admin; };

	void SetLog(string l) { logIn = l; }
	void SetPassword(string l) { password = l; }
	void SetAdmin(bool l) { admin = l; }

	friend ostream& operator<<(ostream& o, Account& obj);
	friend istream& operator>>(istream& o, Account& obj);
private:

	string encrypt(string str)
	{
		string a = "";
		for (int i = 0; i < str.length(); i++)
		{
			string b = "";
			if (str[i] < 0)
			{
				b = b + (char)(rand() % 26 + 'A');
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			int c = abs((int)str[i]);
			if (c / 128 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 128;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 64 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 64;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 32 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 32;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 16 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 16;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 8 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 8;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 4 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 4;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c / 2 == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 2;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			if (c == 1)
			{
				b = b + (char)(rand() % 26 + 'A');
				c -= 1;
			}
			else
			{
				b = b + (char)(rand() % 26 + 'a');
			}
			a = a + b;
		}
		return a;
	}
	string decrypt(string a)
	{
		string b = "";
		int n = a.length() / 9;
		for (int i = 0; i < n; i++)
		{
			char c = 0;
			if (a[i * 9 + 1] >= 'A' && a[i * 9 + 1] <= 'Z')
			{
				c += 128;
			}
			if (a[i * 9 + 2] >= 'A' && a[i * 9 + 2] <= 'Z')
			{
				c += 64;
			}
			if (a[i * 9 + 3] >= 'A' && a[i * 9 + 3] <= 'Z')
			{
				c += 32;
			}
			if (a[i * 9 + 4] >= 'A' && a[i * 9 + 4] <= 'Z')
			{
				c += 16;
			}
			if (a[i * 9 + 5] >= 'A' && a[i * 9 + 5] <= 'Z')
			{
				c += 8;
			}
			if (a[i * 9 + 6] >= 'A' && a[i * 9 + 6] <= 'Z')
			{
				c += 4;
			}
			if (a[i * 9 + 7] >= 'A' && a[i * 9 + 7] <= 'Z')
			{
				c += 2;
			}
			if (a[i * 9 + 8] >= 'A' && a[i * 9 + 8] <= 'Z')
			{
				c += 1;
			}
			if (a[i * 9] >= 'A' && a[i * 9] <= 'Z')
			{
				c *= -1;
			}
			b = b + c;
		}
		return b;
	}

	string logIn;
	string password;
	bool admin;
};

ostream& operator<<(ostream& o, Account& obj)
{
	o << obj.logIn << " " << obj.encrypt(obj.password) << " " << obj.admin << endl;
	return o;
}

istream& operator>>(istream& o, Account& obj)
{
	o >> obj.logIn >> obj.password >> obj.admin;
	obj.password = obj.decrypt(obj.password);
	return o;
}

class Exam
{
	int mark;
	string name;

public:
	Exam() { name = "Unnamed"; mark = 0; }
	Exam(string _name, int _mark) { SetName(_name); SetMark(_mark); }
	Exam(const Exam& obj) { SetName(obj.name); SetMark(obj.mark); }

	void SetName(string n) { name = n; }
	bool SetMark(int m) { if (m > -1 && m < 11) { mark = m; return true; } return false; }

	string GetName()const { return name; }
	int GetMark()const { return mark; }

	bool operator==(const Exam& obj) { return obj.name == name && obj.mark == mark; }
	Exam& operator=(const Exam& obj) { name = obj.name; mark = obj.mark; return *this; }

	friend ostream& operator<<(ostream& o, Exam& obj);
	friend istream& operator>>(istream& o, Exam& obj);
};

ostream& operator<<(ostream& o, Exam& obj)
{
	o << obj.mark << "\n" << obj.name;
	return o;
}

istream& operator>>(istream& o, Exam& obj)
{
	o >> obj.mark;
	getline(o, obj.name);
	getline(o, obj.name);
	return o;
}

class FIO
{
	string F;
	string I;
	string O;

public:
	FIO() { F = "Unnamed"; I = "Unnamed"; O = "Unnamed"; }
	FIO(string f, string i, string o) { F = f; I = i; O = o; }
	FIO(const FIO& obj) { F = obj.F; I = obj.I; O = obj.O; }

	string& GetF() { return F; }
	string& GetI() { return I; }
	string& GetO() { return O; }

	bool operator==(const FIO& obj) { return obj.F == F && obj.I == I && obj.O == O; }
	FIO& operator=(const FIO& obj) { F = obj.F; I = obj.I; O = obj.O; return *this; }

	friend ostream& operator<<(ostream& o, FIO& obj);
	friend istream& operator>>(istream& o, FIO& obj);
};

ostream& operator<<(ostream& o, FIO& obj)
{
	o << obj.F << " ";
	o << obj.I << " ";
	o << obj.O;
	return o;
}

istream& operator>>(istream& o, FIO& obj)
{
	o >> obj.F >> obj.I >> obj.I;
	return o;
}

class Student
{
	bool CheckNum(string str)
	{
		if (str.length() != 6)return false;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] < '0' || str[i]>'9')return false;
		}
		return true;
	}

public:
	Student() { math.SetName("Вышмат"); oaip.SetName("ОАиП"); physics.SetName("Физика"); mme.SetName("ММЭ"); trpo.SetName("ТРПО"); groupNum = "000000"; };
	Student(const Student& o)
	{
		groupNum = o.groupNum;
		fio = o.fio;
		math = o.math;
		oaip = o.oaip;
		physics = o.physics;
		mme = o.mme;
		trpo = o.trpo;
	};

	bool SetNum(string n) { if (CheckNum(n)) { groupNum = n; return true; } else return false; }
	void SetFIO(FIO n) { fio = n; }
	bool SetMath(int mark) { return math.SetMark(mark); }
	bool SetTRPO(int mark) { return trpo.SetMark(mark); }
	bool SetMME(int mark) { return mme.SetMark(mark); }
	bool SetPhysics(int mark) { return physics.SetMark(mark); }
	bool SetOAIP(int mark) { return oaip.SetMark(mark); }

	string GetNum() { return groupNum; }
	FIO GetFIO() { return fio; }
	int GetMath() { return math.GetMark(); }
	int GetMME() { return mme.GetMark(); }
	int GetTRPO() { return trpo.GetMark(); }
	int GetOAIP() { return oaip.GetMark(); }
	int GetPhysics() { return physics.GetMark(); }

	friend ostream& operator<<(ostream& o, Student& obj);
	friend istream& operator>>(istream& o, Student& obj);

	static void Print(Student* arr, int n)
	{
		if (n == 0)
		{
			cout << "Данных не найдено\n";
		}
		else
		{
			puts("***************************************************************************");
			puts("| № |       ФИО        | Группа | Математика | ММЭ | Физика | ОАиП | ТРПО |");
			puts("***************************************************************************");
			for (int i = 0; i < n; i++)
			{
				printf("|%3d|%13s %c.%c.| %6s |     %2d     |  %2d |   %2d   |  %2d  |  %2d  \n", i + 1, arr[i].fio.GetF().c_str(), arr[i].fio.GetI()[0], arr[i].fio.GetO()[0], arr[i].groupNum.c_str(), arr[i].GetMath(), arr[i].GetMME(), arr[i].GetPhysics(), arr[i].GetOAIP(), arr[i].GetTRPO());
				puts("***************************************************************************");
			}
		}
		system("pause");
	}

private:
	string groupNum;
	FIO fio;
	Exam math;
	Exam oaip;
	Exam mme;
	Exam trpo;
	Exam physics;
};

ostream& operator<<(ostream& o, Student& obj)
{
	o << obj.groupNum << "\n" << obj.fio << "\n" << obj.math << "\n" << obj.oaip << "\n" << obj.trpo << "\n" << obj.mme << "\n" << obj.physics << endl;
	return o;
}

istream& operator>>(istream& o, Student& obj)
{
	o >> obj.groupNum;
	o >> obj.fio;
	o >> obj.math;
	o >> obj.oaip;
	o >> obj.trpo;
	o >> obj.mme;
	o >> obj.physics;
	return o;
}

void getFileStudent(Student*& arr, int& n);
void setFileStudent(Student* arr, int n);
void getFileAccount(Account*& arr, int& n);
void setFileAccount(Account* arr, int n);

void addStudent(Student*& arr, int& n);
void delStudent(Student*& arr, int& n);
void editStudent(Student* arr, int n);
void sortStudent(Student* arr, int n);
void searchStudent(Student* arr, int n);

int createInt();
double createDouble();
string createString();
string createGroup();
int createMark(string name);

void menuLogIn();
bool logIn(int choise, Account* arr, int& n);

void menuAdmin();
void menuUser();
void menuUserControle();

void Task(Student* arr, int n);

void addAccount(Account*& arr, int& n);
void delAccount(Account*& arr, int& n);
void viewAccount(Account* arr, int n);

void registration(Account*& arr, int& n);

bool checkLogInAccount(Account* arr, int n, string logIn);

void getFileStudent(Student*& arr, int& n)
{
	ifstream f;
	f.open("student.txt", ios_base::in);
	n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("student.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
	}
	arr = new Student[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
}

void setFileStudent(Student* arr, int n)
{
	ofstream f;
	f.open("student.txt", ios_base::trunc);
	f << n << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i];
	}
	f.close();
}

void getFileAccount(Account*& arr, int& n)
{
	ifstream f;
	f.open("account.txt", ios_base::in);
	n = 0;
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("account.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
	}
	arr = new Account[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
}

void setFileAccount(Account* arr, int n)
{
	ofstream f;
	f.open("account.txt", ios_base::trunc);
	f << n << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i];
	}
	f.close();
}

void addStudent(Student*& arr, int& n)
{
	cout << "Введите фамилию\n";
	string f = createString();
	cout << "Введите имя\n";
	string i = createString();
	cout << "Введите отчество\n";
	string o = createString();
	cout << "Введите номер группы\n";
	string group = createGroup();
	int math = createMark("Математика");
	int mme = createMark("ММЭ");
	int trpo = createMark("ТРПО");
	int oaip = createMark("ОАиП");
	int physics = createMark("Физика");

	arr[n].SetNum(group);
	arr[n].SetFIO(FIO(f, i, o));
	arr[n].SetMath(math);
	arr[n].SetTRPO(trpo);
	arr[n].SetMME(mme);
	arr[n].SetOAIP(oaip);
	arr[n].SetPhysics(physics);

	n++;
}

void delStudent(Student*& arr, int& n)
{
	Student::Print(arr, n);
	int z = -1;
	cout << "Введите номер записи для удаления\n";
	do
	{
		z = createInt();
	} while (z<1 || z> n);
	z--;
	bool work = true;
	system("cls");
	cout << "Вы уверены, что хотите удалить запись?\n";
	cout << "1.Да\n";
	cout << "2.Нет\n";
	while (work)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			n--;
			if (n != 0)
			{
				for (int i = z; i < n; i++)
				{
					arr[i] = arr[i + 1];
				}
			}
			cout << "Данные успешно удалены\n";
			system("pause");
			work = false;
			break;
		}
		case '2':
		{
			work = false;
			break;
		}
	dafault:
		system("cls");
		cout << "Некорректный ввод\n";
		system("pause");
		break;
		}
	}
}

void editStudent(Student* arr, int n)
{
	if (n == 0)
	{
		cout << "Данные не найдены\n";
		system("pause");
		return;
	}
	Student::Print(arr, n);
	int z = -1;
	cout << "Введите номер записи для редактирования\n";
	do
	{
		z = createInt();
	} while (z<1 || z> n);
	z--;
	bool work = true;
	while (work)
	{
		system("cls");
		cout << "Выберите поле для редактирования:\n";
		cout << "1.Номер группы\n";
		cout << "2.ФИО\n";
		cout << "3.Оценка по математике\n";
		cout << "4.Оценка по ММЭ\n";
		cout << "5.Оценка по физике\n";
		cout << "6.Оценка по ТРПО\n";
		cout << "7.Оценка по ОАиП\n";
		cout << "8.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
			cout << "Введите номер группы\n";
			arr[z].SetNum(createGroup());
			break;
		case '2':system("cls");
		{
			cout << "Введите ФИО\n";
			cout << "Введите фамилию\n";
			string f = createString();
			cout << "Введите имя\n";
			string i = createString();
			cout << "Введите отчество\n";
			string o = createString();
			arr[z].SetFIO(FIO(f, i, o));
		}
		break;
		case '3':system("cls");
			arr[z].SetMath(createMark("Математика"));

			break;
		case '4':system("cls");
			arr[z].SetMME(createMark("ММЭ"));

			break;
		case '5':system("cls");
			arr[z].SetPhysics(createMark("Физика"));

			break;
		case '6':system("cls");
			arr[z].SetTRPO(createMark("ТРПО"));

			break;
		case '7':system("cls");
			arr[z].SetOAIP(createMark("ОАИП"));
			break;
		case '8':system("cls");
			work = false;
			break;
		default:
			system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
	}
}

void sortStudent(Student* arr, int n)
{
	if (n <= 0)
	{
		cout << "Нет данных для сортировки\n";
	}
	bool work = true;
	while (work)
	{
		cout << "Выберите поле для сортировки\n";
		cout << "1.Номер группы\n";
		cout << "2.Фамилия\n";
		cout << "3.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].GetNum().c_str(), arr[j].GetNum().c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			Student::Print(arr, n);
		}break;
		case '2':system("cls");
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arr[i].GetFIO().GetF().c_str(), arr[j].GetFIO().GetF().c_str()) == 1)
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			Student::Print(arr, n);
		}break;
		case '3':system("cls");
		{
			work = false;
		}break;
		default:system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
	}
}

void searchStudent(Student* arr, int n)
{
	if (n <= 0)
	{
		cout << "Нет данных для поиска\n";
	}
	bool work = true;
	while (work)
	{
		Student* arr1 = new Student[n];
		int it = 0;
		cout << "Выберите поле для поиска\n";
		cout << "1.Номер группы\n";
		cout << "2.Фамилия\n";
		cout << "3.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			string num;
			cout << "Введите номер группы\n";
			num = createGroup();
			for (int i = 0; i < n; i++)
			{
				if (arr[i].GetNum() == num)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			Student::Print(arr1, it);
		}break;
		case '2':system("cls");
		{
			string f;
			cout << "Введите фамилию\n";
			f = createString();
			for (int i = 0; i < n; i++)
			{
				if (arr[i].GetFIO().GetF() == f)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
			Student::Print(arr1, it);
		}break;
		case '3':system("cls");
		{
			work = false;
		}break;
		default:system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
		delete[] arr1;
	}
}

int createInt()
{
	string a;
	bool correct = false;
	do
	{
		correct = true;
		cin >> a;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < '0' || a[i]>'9')
			{
				correct = false;
			}
		}
	} while (!correct);
	return atoi(a.c_str());
}

double createDouble()
{
	string c = "a";
	bool correct = false;
	while (!correct)
	{
		cin >> c;
		int flag = 0;
		correct = true;
		for (int i = 0; i < c.length(); i++)
		{

			if ((c[i] < '0' && c[i] != '.' && c[i] != ',') || (c[i] > '9' && c[i] != '.' && c[i] != ',') || (flag > 0 && c[i] == '.') || (flag > 0 && c[i] == ','))
			{
				cout << "Некорректный ввод\n";
				correct = false;;
			}
			else if (c[i] == '.' || c[i] == ',')
			{
				flag++;
			}
		}
	}
	double a = 0;
	double b = 0;
	int i = 0;
	while (c[i] != '.' && c[i] != ',' && i != c.length())
	{
		char d[2];
		d[0] = c[i];
		d[1] = '\0';
		a *= 10;
		a += atoi(d);
		i++;
	}
	i++;
	if (i < c.length())
	{
		while (c[i] >= '0' && c[i] <= '9' && i != c.length())
		{
			char d[2];
			d[0] = c[i];
			d[1] = '\0';
			b *= 10;
			b += atoi(d);
			i++;
		}
		while (b > 1)
		{
			b = b / 10;
		}
	}

	return (a + b);
}

string createString()
{
	string s;
	bool correct = false;
	while (!correct)
	{
		correct = true;
		getline(cin, s);
		if (s.length() == 0)correct = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				correct = false;
				break;
			}
		}
		if (!correct)
		{
			cout << "Некорректный ввод\n";
		}
	}
	return s;
}

string createGroup()
{
	string s;
	bool correct = false;
	while (!correct)
	{
		correct = true;
		getline(cin, s);
		if (s.length() != 6)
		{
			correct = false;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				correct = false;
				break;
			}
		}
		if (!correct)
		{
			cout << "Некорректный ввод\n";
		}
	}
	return s;
}

int createMark(string name)
{
	cout << "Введите отметку по предмету " << name << " или 0, если у студента долг по этому предмету" << endl;
	int mark = -1;
	while (mark < 0 || mark>10)
	{
		mark = createInt();
		if (mark < 0 || mark>10)cout << "Некорректный ввод" << endl;
	}
	return mark;
}

void menuLogIn()
{
	system("cls");
	bool work = true;
	while (work)
	{
		int n = 0;
		Account* arr = NULL;
		getFileAccount(arr, n);
		if (n == 0)
		{
			arr = new Account[2];
		}
		cout << "Выберите нужное действие:\n";
		cout << "1.Вход от имени администратора\n";
		cout << "2.Вход от имени пользователя\n";
		cout << "3.Регистрация\n";
		cout << "4.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			if (logIn(1, arr, n))
				menuAdmin();
		}break;
		case '2':system("cls");
		{
			if (logIn(2, arr, n))
				menuUser();
		}break;
		case '3':system("cls");
		{
			registration(arr, n);
		}break;
		case '4':system("cls");
		{
			work = false;
		}break;
		default:system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
		setFileAccount(arr, n);
		delete[] arr;
	}
}

bool logIn(int choise, Account* arr, int& n)
{
	string logIn;
	string password;
	if (n == 0)
	{
		cout << "Это первый вход.Зарегистрируйтесь\n";
		cout << "Введите логин\n";
		cin >> logIn;
		cout << "Введите пароль\n";
		cin >> password;
		arr[n].SetAdmin(choise == 1 ? true : false);
		arr[n].SetLog(logIn);
		arr[n].SetPassword(password);
		n++;
		return true;
	}
	int k = 3;
	while (k != 0)
	{
		string login;
		printf("Введите логин\n");
		cin >> login;
		int flag = 0;
		int index = -1;
		for (int i = 0; i < n; i++)
		{

			if (arr[i].GetLog() == login && arr[i].IsAdmin() == (choise == 1 ? true : false))
			{
				index = i;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("Такого логина не существует\n");
		}
		else
		{
			printf("Введите пароль\n");
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						printf("\b \b");
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			if (strcmp(str, arr[index].GetPassword().c_str()) == 0)
			{
				printf("Вход выполнен успешно\n");
				return true;
			}
			else
			{
				printf("Не верный пароль\n");
			}
		}
		k--;
	}
	printf("Вы исчерпали все попытки\n");
	system("pause");
	return false;
}

void menuAdmin()
{

	system("cls");
	bool work = true;
	while (work)
	{
		Student* arr = NULL;
		int n = 0;
		getFileStudent(arr, n);
		if (n == 0)
		{
			arr = new Student[2];
		}
		cout << "Выберите нужное действие:\n";
		cout << "1.Вывод данных в табличной форме\n";
		cout << "2.Ввод данных\n";
		cout << "3.Изменение данных\n";
		cout << "4.Удаление данных\n";
		cout << "5.Сортировка данных\n";
		cout << "6.Поиск данных\n";
		cout << "7.Меню управления пользователями\n";
		cout << "8.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			Student::Print(arr, n);
		}break;
		case '2':system("cls");
		{
			addStudent(arr, n);
			setFileStudent(arr, n);
		}break;
		case '3':system("cls");
		{
			editStudent(arr, n);
			setFileStudent(arr, n);
		}break;
		case '4':system("cls");
		{
			delStudent(arr, n);
			setFileStudent(arr, n);
		}break;
		case '5':system("cls");
		{
			sortStudent(arr, n);
		}break;
		case '6':system("cls");
		{
			searchStudent(arr, n);
		}break;
		case '7':system("cls");
		{
			menuUserControle();
		}break;
		case '8':system("cls");
		{
			work = false;
		}break;
		default:system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
		setFileStudent(arr, n);
		delete[] arr;
	}

}

void menuUser()
{
	Student* arr = NULL;
	int n = 0;

	system("cls");
	bool work = true;
	while (work)
	{
		getFileStudent(arr, n);
		if (n == 0)
		{
			arr = new Student[2];
		}
		cout << "Выберите нужное действие:\n";
		cout << "1.Вывод данных в табличной форме\n";
		cout << "2.Сортировка данных\n";
		cout << "3.Поиск данных\n";
		cout << "4.Инд.задание\n";
		cout << "5.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			Student::Print(arr, n);
		}break;
		case '2':system("cls");
		{
			sortStudent(arr, n);
		}break;
		case '3':system("cls");
		{
			searchStudent(arr, n);
		}break;
		case '4':system("cls");
		{
			Task(arr, n);
		}break;
		case '5':system("cls");
		{
			work = false;
		}break;
		default:system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
		setFileStudent(arr, n);
		delete[] arr;
	}

}

void menuUserControle()
{
	Account* arr = NULL;
	int n = 0;
	getFileAccount(arr, n);
	if (n == 0)
	{
		arr = new Account[2];
	}
	system("cls");
	bool work = true;
	while (work)
	{
		cout << "Выберите нужное действие:\n";
		cout << "1.Вывод данных в табличной форме\n";
		cout << "2.Добавление нового аккаунта\n";
		cout << "3.Удаление аккаунта\n";
		cout << "4.Выход\n";
		char c;
		cin >> c;
		switch (c)
		{
		case '1':system("cls");
		{
			viewAccount(arr, n);
		}break;
		case '2':system("cls");
		{
			addAccount(arr, n);
			setFileAccount(arr, n);
		}break;
		case '3':system("cls");
		{
			delAccount(arr, n);
			setFileAccount(arr, n);
		}break;
		case '4':system("cls");
		{
			work = false;
		}break;
		default:
		{
			system("cls");
			cout << "Некорректный ввод\n";
			system("pause");
			break;
		}
		}
	}
	setFileAccount(arr, n);
	delete[] arr;

}

void Task(Student* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int zi = 0;
			if (!arr[i].GetMath())zi++;
			if (!arr[i].GetMME())zi++;
			if (!arr[i].GetOAIP())zi++;
			if (!arr[i].GetPhysics())zi++;
			if (!arr[i].GetTRPO())zi++;
			int zj = 0;
			if (!arr[j].GetMath())zj++;
			if (!arr[j].GetMME())zj++;
			if (!arr[j].GetOAIP())zj++;
			if (!arr[j].GetPhysics())zj++;
			if (!arr[j].GetTRPO())zj++;

			if (zi < zj)
			{
				Student temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Студенты в порядке убывания задолженностей:" << endl;
	Student::Print(arr, n);

	cout << "\n\nВведите номер группы\n";
	string num = createGroup();

	Student* arr1 = new Student[n];
	int n1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].GetNum() == num)
		{
			arr1[n1] = arr[i];
			n1++;
		}
	}

	if (n1 == 0)
	{
		cout << "Такой группы нет" << endl;
		system("pause");
		delete[] arr1;
		return;
	}

	double average = 0;
	for (int i = 0; i < n1; i++)
	{
		double mark = arr1[i].GetMath() + arr1[i].GetMME() + arr1[i].GetOAIP() + arr1[i].GetPhysics() + arr1[i].GetTRPO();
		mark /= 5;
		cout << setprecision(2) << "Студент " << arr1[i].GetFIO().GetF() << " " << arr1[i].GetFIO().GetI() << " " << arr1[i].GetFIO().GetO() << " --- срдений бал = " << mark << endl;
		average += mark;
	}
	average /= n1;
	cout << "Средний бал группы = " << setprecision(2) << average << endl;
	system("pause");
	delete[] arr1;
}

void addAccount(Account*& arr, int& n)
{
	cout << "1.Добавить администратора\n2.Добавить пользователя\n";
	bool choice = false;
	bool work = true;
	while (work)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case '1':
		{
			choice = true;
			work = false;
			break;
		}
		case '2':
			choice = false;
			work = false;
			break;
		default:
			cout << "Некорректный ввод\n";
			break;
		}
		arr[n].SetAdmin(choice);
		cout << "Введите логин\n";
		string log;
		cin >> log;
		arr[n].SetLog(log);
		cout << "Введите  пароль\n";
		cin >> log;
		arr[n].SetPassword(log);
		n++;
	}
}

void delAccount(Account*& arr, int& n)
{
	viewAccount(arr, n);
	int z = -1;
	cout << "Введите номер записи для удаления\n";
	do
	{
		z = createInt();
	} while (z<1 || z> n);
	z--;
	bool work = true;
	system("cls");
	cout << "Вы уверены, что хотите удалить запись?\n";
	cout << "1.Да\n";
	cout << "2.Нет\n";
	while (work)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case '1': {
			(n)--;
			if (n != 0)
			{
				for (int i = z; i < n; i++)
				{
					arr[i] = arr[i + 1];
				}
			}
			cout << "Данные успешно удалены\n";
			system("pause");
			work = false;
			break;
		}
		case '2':
		{
			work = false;
			break;
		}
	dafault:
		system("cls");
		cout << "Некорректный ввод\n";
		system("pause");
		break;
		}
	}

}

void viewAccount(Account* arr, int n)
{
	if (n == 0)
	{
		cout << "Данных не найдено\n";
	}
	else
	{
		puts("************************************************");
		puts("| № |    Логин    |   Пароль   | Администратор |");
		puts("************************************************");
		for (int i = 0; i < n; i++)
		{
			printf("|%3d|%13s|%12s|      %3s      |\n", i + 1, arr[i].GetLog().c_str(), arr[i].GetPassword().c_str(), arr[i].IsAdmin() ? "Да " : "Нет");
			puts("************************************************");
		}
	}
	system("pause");
}

void registration(Account*& arr, int& n)
{
	arr[n].SetAdmin(false);
	cout << "Введите логин\n";
	string log;
	cin >> log;
	arr[n].SetLog(log);
	cout << "Введите пароль\n";
	cin >> log;
	arr[n].SetPassword(log);
	n++;
}

bool checkLogInAccount(Account* arr, int n, string logIn)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].GetLog() == logIn)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	menuLogIn();
	return 0;
}