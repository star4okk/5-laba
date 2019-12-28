#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Human {
	string name;
	bool male;
	int age;
	int height;
	Human(string s = "", bool m = true, int a = 0, int b = 0) {
		name = s;
		male = m;
		age = a;
		height = b;
	}
};
Human findmaxheight(Human* mas, int length) {
	int masH = 0;
	Human ret;
	for (int i = 0;i < length;i++) {
		if (mas[i].height > masH) {
			masH = mas[i].height;
			ret = mas[i];
		}
	}
	return  ret;
}
Human findminheight(Human* mas, int length) {
	int masH = 1000;
	Human ret;
	for (int i = 0;i < length;i++) {
		if (mas[i].height < masH) {
			masH = mas[i].height;
			ret = mas[i];
		}
	}
	return  ret;
}
void findageheight(Human* mas, int length) {
	for (int i = 0;i < length;i++) {
		for (int j = i;j < length;j++) {
			if (mas[i].age == mas[j].age && mas[i].height == mas[j].height && mas[i].male != mas[j].male && i != j) {
				cout << mas[i].name << " - " << mas[j].name << endl;
			}
		}
	}
}
float findmediumheight(Human* mas, int length, int minage, int maxage)
{
	int startk = 0;
	int sigheight = 0;
	for (int i = 0;i < length;i++) {
		if (mas[i].age >= minage && mas[i].age <= maxage) {
			startk++;
			sigheight += mas[i].height;
		}
	}
	if (startk != 0)
		return float(sigheight / startk);
	else
		return 0;
}
int main()
{
	setlocale(LC_ALL, "ru");
	ifstream input("input.txt");
	int k = 0;
	input >> k;
	Human* BD = new Human[k];
	for (int i = 0;i < k;i++) {
		string s;
		input >> s;
		BD[i].name += s;
		input >> s;
		BD[i].name += " " + s;
		input >> s;
		BD[i].name += " " + s;
		input >> BD[i].male;
		input >> BD[i].age;
		input >> BD[i].height;
	}
	cout << "Средний рост от 15 -20" << endl;
	cout << findmediumheight(BD, k, 15, 20) << endl;
	cout << "Средний рост от 21 -25" << endl;
	cout << findmediumheight(BD, k, 21, 25) << endl;
	cout << "Средний рост от 26 -30" << endl;
	cout << findmediumheight(BD, k, 26, 30) << endl;
	cout << "Максимальный рост" << endl;
	cout << findmaxheight(BD, k).name << endl;
	cout << "Минимальный рост" << endl;
	cout << findminheight(BD, k).name << endl;
	cout << "Одинаковый рост и возраст,но разный пол:" << endl;
	(findageheight(BD, k));
}