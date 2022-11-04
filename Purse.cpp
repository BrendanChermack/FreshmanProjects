#include <iomanip>
#include <iostream>
using namespace std;
class Purse {
private:
  int pennies, nickels, dimes, quarters;
  float pAmount;

public:
  void init(int, int, int, int, int);
  float dollars(int);
  int insert(int, int, int, int);
  int remove(int, int, int, int);
  void display(int,int,int,int);
};

int main() {
    int p, n, d, q, am; 
    cout << endl << "Enter amount in the purse: $";
    cin >> am;
    Purse purse1;
    purse1.init(p,n,d,q, am);
    cout << "Current amount in the purse: $" << am << endl;
    cout << "\nEnter the money amount you want to add to the purse (pennies, nickels, dimes, quaters)\n";
    cin >> p >> n >> d >> q;
    cout << q << " quarter(s) + " << d << " dime(s) + " << n
         << " nickel(s) + " << p << " pennies added ";
    cout << "\nYou have " << purse1.insert(p,n,d,q) << " dollars remaining";
    cout << "\nEnter the money amount you want to remove to the purse (pennies, nickels, dimes, quaters)\n";
    cin >> p >> n >> d >> q;
    cout << q << " quarter(s) + " << d << " dime(s) + " << n
         << " nickel(s) + " << p << " pennies removed " << purse1.remove(p,n,d,q) << " dollars remaining";
    
    purse1.display(p,n,d,q);
}
void Purse::init(int p, int n, int d, int q, int dollar) {
    pennies = p;
    nickels = n;
    dimes = d;
    quarters = q;
    pAmount = dollar;
}
  int Purse::insert(int p, int n, int d, int q) {
    return pAmount += ((p + n*5 + d*10 + q*25)/100);
}
  float Purse::dollars(int am) {
    return pAmount;
}
  int Purse::remove(int p, int n, int d, int q) {
    return pAmount -= ((p + n*5 + d*10 + q*25)/100);
      }
  void Purse::display(int p, int n, int d, int q) {
    cout << "\nYou have $" << pAmount << " " << q << " quarter(s) + " << d << " dime(s) + " << n << " nickel(s) + " << p << " pennies";
}