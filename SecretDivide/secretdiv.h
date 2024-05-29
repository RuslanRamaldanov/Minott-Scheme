#ifndef SECRETDIV_H
#define SECRETDIV_H
typedef long long ll;
#include <vector>

const std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}; // ������ 15 ������� �����. ������ ������, ����� �� long long

// ������� ��� ���������� ��������� �������� �� ������
ll modInverse(ll a, ll m);

// ������� ��� ������� ��������� ������� �� ��������
ll chineseRemainderTheorem(const std::vector<int>& a, const std::vector<int>& m);

void divide(std::vector<int>& parts, std::vector<int>& primes, int N, int K);

ll recover(const std::vector<int> parts, const std::vector<int>& mods);
#endif