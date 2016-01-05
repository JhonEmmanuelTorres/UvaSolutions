#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

void generePrimes( int n )
{
    vector<bool> sieve( n + 1, true );
    vector<int> primes;
    sieve[0] = sieve[1] = 0;
    int limit = sqrt(n);
    for( int i = 2; i <= limit; i++ )
        if( sieve[i] )
        {
            for( int j = i * i; j <= n; j+=i )
                sieve[j] = 0;
            primes.push_back( i );
        }
    for( int i: primes )
        cout << i << " ";
    cout << endl;
}

int main()
{
    int n;
    do{
        cin >> n;
        generePrimes(n);
    }while( n != 0 );

    return 0;
}
