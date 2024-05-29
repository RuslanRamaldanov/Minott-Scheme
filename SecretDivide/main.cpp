#include "secretdiv.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> parts;						//����� �������, ������������ ����� �����������
	vector<int> mods;						//����� ��������
	int n = 6, k = 5;						//n - ����� ����������, k - ���������� ����������, ������� ����� ������������ ���������
	divide(parts, mods, n, k);				
	
	cout << "Parts: ";
	for_each(parts.begin(), parts.end(), [](int& a) {cout << a << ' '; });
	cout << endl;
	cout << "Mods: ";
	for_each(mods.begin(), mods.end(), [](int& a) {cout << a << ' '; });

	vector<int> PARTS(parts.begin() + 1, parts.end()); //�������� ������, ������� ����� �� ������� ������ (� ������ ������ ��� n = 6 � k = 5) ������ ���������. ����� ������� ������� ������ ����� k
	vector<int> MODS(mods.begin() + 1, mods.end());    //����� ����� ��� ������� �������
	 
	cout << "\nRecovered secret: " << recover(PARTS, MODS); //����� ���������������� �������


	return 0;
}