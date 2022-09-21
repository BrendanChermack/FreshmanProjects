#include <iostream>
using namespace std;
class solution
{

    public: string intToRomanNumerals(int num)
    {
        string result = "";
        int i = 0;
        int romanNumeralValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanNumeralSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        while (num > 0)//your entered number
        {
            int div = num / romanNumeralValues[i];//div is the number entered divided by the roman numeral value at index i
            num = num % romanNumeralValues[i];//num is then the remainder of the number entered divided by the roman numeral value at index i
            while (div--) //reduces div by 1 
            {
                result += romanNumeralSymbols[i];
            }
            i++;
        }

        return result;
    }

    int main()
    {
        int num;
        cin >> num;
        cout << intToRomanNumerals(num);
        return 0;
    }

};
