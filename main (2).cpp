#include <iostream>
using namespace std;
#include <ctime> 
#include <cstdlib>
int main() 
{
    srand(time(0));
    int lottery = rand() % 100;
    int guess = 0;
    int digit1 = lottery/10;
    int digit2 = lottery%10;
    cout << "Enter your 2 digit guess. "<< endl;
    cin >> guess;

    if(lottery == guess)
    {
        cout << "WINNER. You have won $10000. " << endl;
    }
    else if(guess%10 == digit1 && guess/10 == digit2)
    {
        cout << "WINNER. You have won $3000. The right number was "<< lottery << endl;
    }
    else if(digit1 == guess/10)
    {
        cout << "WINNER. You have won $1000. The right number was "<< lottery << endl;
    }
    else if (digit2 == guess%10)
    {
        cout << "WINNER. You have won $1000. The right number was "<< lottery << endl;
    }
    else
    {
        cout << "LOSER. The right number was "<< lottery;
    }
    
}