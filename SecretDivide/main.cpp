#include "secretdiv.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> parts;						//части секрета, разделенного между участниками
	vector<int> mods;						//числа Миньотта
	int n = 6, k = 5;						//n - число участников, k - количество участников, которые могут восстановить сообщение
	divide(parts, mods, n, k);				
	
	cout << "Parts: ";
	for_each(parts.begin(), parts.end(), [](int& a) {cout << a << ' '; });
	cout << endl;
	cout << "Mods: ";
	for_each(mods.begin(), mods.end(), [](int& a) {cout << a << ' '; });

	vector<int> PARTS(parts.begin() + 1, parts.end()); //создадим вектор, который будет на единицу меньше (в данном случае при n = 6 и k = 5) меньше исходного. Таким образом получим вектор длины k
	vector<int> MODS(mods.begin() + 1, mods.end());    //точно также для вектора модулей
	 
	cout << "\nRecovered secret: " << recover(PARTS, MODS); //вывод восстановленного секрета


	return 0;
}