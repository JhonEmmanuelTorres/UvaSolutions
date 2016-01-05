#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime( int n ) //
{
    if( n % 2 == 0 ) return false;
    int limit = (int)sqrt(n);
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
