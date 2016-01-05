#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime( int n ) // O ( sqrt(n) / 2 )
{
    if( n % 2 == 0 && n != 2 || n <= 1 ) return false;
    int limit = (int)sqrt(n) + 1;
    for( int i = 3; i < limit; i+=2 )
        if( n % i == 0 )
            return false;
    return true;
}


int main()
{
    int n;
    cin >> n;
    cout << boolalpha << endl;
    while( n != 0 )
    {
        cout << isPrime( n ) << endl;
        cin >> n;
    }
    return 0;
}
