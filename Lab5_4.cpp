// Lab_05_1.cpp
// Боднар Роман
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії 
// Варіант 2
#include <iostream>
#include <cmath>

using namespace std;

double term(double k, double N)
{
    return sqrt(pow(sin(k), 2) + pow(cos(N / k), 2));
}


double S0(const int K, const int N)
{
    double s = 0;
    for (int k = K; k <= 19; k++)
        s += term(k, N);
    return s;
}


double S1(const int K, const int N, const int i)
{
    if (i > 19)
        return 0;
    else
        return term(i, N) + S1(K, N, i + 1);
}


double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return term(i, N) + S2(K, N, i - 1);
}


double S3(const int K, const int N, const int i)
{
    if (i > 19)
        return 0;
    return term(i, N) + S3(K, N, i + 1);
}


double S3_up(const int K, const int N, int i, double t)
{
    t += term(i, N);
    if (i >= 19)
        return t;
    else
        return S3_up(K, N, i + 1, t);
}

double S4_up(const int K, const int N, int i, double t)
{
    t += term(i, N);
    if (i <= K)
        return t;
    else
        return S4_up(K, N, i - 1, t);
}

int main()
{
    int K, N;
    cout << "K (p.s. K <= 19) = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "----------------------------------------" << endl;
    cout << "(iter)       S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)  S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)  S2 = " << S2(K, N, 19) << endl;
    cout << "(rec down ++) S3 = " << S3_up(K, N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4_up(K, N, 19, 0) << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}