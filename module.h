#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int isPrime(int a)
{
    if (a < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

string Prime(string message)
{
    int a;
    a = atoi(message.c_str());
    if (a != 0 && a >= 2)
    {
        int count = 0;
        string temp = "";
        for (int i = 2; i <= a; i++)
        {
            if (isPrime(i))
            {
                temp += to_string(i) + "\t";
                count++;
            }
        }
        return temp + "\n\nTotal: " + to_string(count);
    }
    return "NULL";
}
