#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int factorial(int number);
float calcE(int number);
int main()
{
  int n=0;
  float e;
  cout<<"Enter a number for n"<<endl;
  cin>>n;
  e= calcE(n);
  cout<<fixed<<setprecision(5);
  cout<< "e equals "<< e << endl;
  return 0;
}
int factorial( int x )
 {
	int fact = x;
    for(int i = x - 1; i > 0; i--)
    {
        fact *= i;
	}
	cout << "fact " << x << " = " << fact << endl;
    return fact;
 }
float calcE(int x)
{
  float total = 0.0;
  for (int k=x; k > 0; k--)
    {
      total+= (1/float(factorial(k)));
	  cout << total << endl;
    }
       return total + 1;
    }