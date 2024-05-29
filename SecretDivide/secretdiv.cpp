#include "secretdiv.h"
#include <iostream>
#include <numeric>
using namespace std;
// Функция для вычисления обратного элемента по модулю
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Функция для решения китайской теоремы об остатках
ll chineseRemainderTheorem(const vector<int>& a, const vector<int>& m) {
    ll x = 0, M = 1;
    for (int i = 0; i < a.size(); i++)
        M *= m[i];
    for (int i = 0; i < m.size(); i++) {
        ll Mi = M / m[i];
        x += a[i] * modInverse(Mi, m[i]) * Mi;
    }
    return x % M;
}

void divide(vector<int>& parts, vector<int>& mods, int N = 2, int K = 1)
{
    parts.clear();
    mods.clear();

    ll alpha = -1;
    ll beta = 0;
    ll secret = 0;
    vector<int>::const_iterator iter = primes.cbegin();

    while (alpha <= beta || iter + N == primes.cend())
    {
        iter += 1;
        alpha = accumulate(iter, iter + K, 1LL, multiplies<int>());
        beta = accumulate(iter + (N - K + 1), iter + N, 1, multiplies<int>());
    }
    
    cout << "Input number between " << beta << " and " << alpha << ": ";
    cin >> secret;

    if (secret > alpha || secret < beta)
        throw runtime_error("Incorrect input");

    //вычисляем доли
    for (int i = 0; i < N; i++)
    {
        parts.push_back(secret % *iter);
        mods.push_back(*iter++);
    }
}

ll recover(const std::vector<int> parts, const vector<int>& mods)
{
    ll secret = 0;
    if (parts.size() != mods.size())
        throw runtime_error("PARTS and MODS vectors must be same length");
    secret = chineseRemainderTheorem(parts, mods);
}

