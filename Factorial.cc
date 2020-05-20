#include <iostream>
using namespace std;
long double factorial( int a );
int main()
{   int n;
    cout << "Introduce the number: ";
    cin >> n;
    cout << "The factorial is: " << factorial(n) << endl;
    return 0;
}
long double factorial( int n )
{
    if ( n == 0 )
        {
            return 1;
        }
    else
         {
             return n*factorial(n-1);
         }

}
