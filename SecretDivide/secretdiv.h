#ifndef SECRETDIV_H
#define SECRETDIV_H
typedef long long ll;
#include <vector>

const std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}; // первые 15 простых чисел. Больше нельзя, выдет за long long

// Функция для вычисления обратного элемента по модулю
ll modInverse(ll a, ll m);

// Функция для решения китайской теоремы об остатках
ll chineseRemainderTheorem(const std::vector<int>& a, const std::vector<int>& m);

void divide(std::vector<int>& parts, std::vector<int>& primes, int N, int K);

ll recover(const std::vector<int> parts, const std::vector<int>& mods);
#endif