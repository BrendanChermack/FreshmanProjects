#include <iostream>
using namespace std;
#include <math.h>
int main() 
{
   
    int numIn;
    cout << "enter a number between 1 and 3999: "<< endl;
    cin >> numIn;
    
    //MMMCMXCIX = 3999
    // MCMXCIV =1994
    
    //1000's
    
    int Mcount = floor(numIn/1000);
    if(Mcount>0)
   { 
       for(int m = 0; m < Mcount; m++)
        {
            cout <<'M';
        }
    
    numIn = numIn - Mcount*1000;
    }
    //c can be placed before m and that will equal 900 , one of 6 intances which are as follows:
        
    //100's
    
    int Dcount = floor(numIn/500);
        if (Dcount == 1)
            {
                cout <<"CM"; // 900
            }
        else if(numIn==500)
            {
                for(int d = 0; d < Dcount; d++)
                {
                    cout <<'D';
                }
            }
    
        numIn = numIn - Dcount*500;
        int Ccount = floor(numIn/100);
     if(Dcount != 1)
    {
   
        
    
        if (Ccount == 4)
        {
            cout << "CD"; // 400
        }
    
    else if(numIn<400)
       for(int c = 0; c < Ccount; c++)
            {
                cout <<'C';
            }
    }
    numIn = numIn - Ccount*100 ;

    //10's
    
    int Lcount = floor(numIn/50);
    if (Lcount == 1)
        {
            numIn = numIn - 90;
            cout<< "XC"; // 90
        }
    else if(numIn == 50)
        {
            numIn = numIn - 50;
            cout<<"L"; // 50
        }
        
    
    if(Lcount != 1)
   { 
       int Xcount = floor(numIn/10);
        if (Xcount == 4)
        { 
            numIn = numIn - 40;
            cout<<"XL"; // 40
        }
        else if(numIn < 40)
        {
            numIn = numIn - 10;
            cout<<"X"; // 10
            }
    }

    //1's
    
    if(numIn == 9)
    {
        cout<<"IX"; // 9
    }
    else if(numIn == 5)
    {
        cout<<"V"; // 5
    }
        else if(numIn == 4)
    {
        cout<<"IV"; // 4
    }
   else if(numIn< 4)
   {
       for(int c = 0; c < numIn; c++)
            {
                cout <<'I';
            }
   }
}

