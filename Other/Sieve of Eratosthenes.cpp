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
    for( int i = 2; i <= n; i++ )
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

vector<long> primesFactor( long n )
{
    vector<long> factors;
    long i = 0;
    long PF = primes[i];
    while( PF * PF <= n )
    {
        while( n % PF == 0 )
        {
            n /= PF;
            factors.push_back( PF );
        }
        PF = primes[ ++i ];
    }
    if( n != 1 ) factors.push_back( n );
    return factors;
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
