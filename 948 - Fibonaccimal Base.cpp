#include <iostream>

using namespace std;
typedef unsigned char ubyte;

int main()
{
    unsigned int *serieFibo = new unsigned[38];
    serieFibo[0] = 1;
    serieFibo[1] = 2;
    ubyte i = 2;
    for(; i < 38; i++ )
        serieFibo[ i ] = serieFibo[ i-1 ] + serieFibo[ i-2 ];
    unsigned short t;
    unsigned int n;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        cout << n << " = ";
        i = 37;
        while( n < serieFibo[i])
            i--;
        do{
            if( n >= serieFibo[i] )
            {
                n -= serieFibo[i];
                cout << 1;
            }
            else{
                cout << 0;
            }
        }while( i-- );
        cout << " (fib)" << endl;
    }
    return 0;
}
