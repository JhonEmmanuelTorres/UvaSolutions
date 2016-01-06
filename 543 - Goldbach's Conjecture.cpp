#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<bool> sieve( 1e6 + 1, true );
    vector<int> primes;
    sieve[ 0 ] = sieve[ 1 ] = false;
    for( long i = 2; i <= 1e6; i++ )
        if( sieve[i] )
        {
            for( long j = i*i; j <= 1e6; j+=i )
                sieve[j] = false;
            primes.push_back( i );
        }
    int n, i;
    cin >> n;
    while( n != 0 )
    {
        i = 0;
        while( !sieve[ n - primes[i]] )
            i++;
        cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
        cin  >> n;
    }
    return 0;
}
