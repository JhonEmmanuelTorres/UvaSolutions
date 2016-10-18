#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio( false );
    int a, b, n, pow2;
    bool sideA;
    while( cin >> n, n )
    {
        pow2 = 1;
        sideA = true;
        a = b = 0;
        do{
            if( n & 1 )
            {
                if( sideA )
                    a += pow2;
                else
                    b += pow2;
                sideA = !sideA;
            }
            n >>= 1;
            pow2 <<= 1;
        }while( n );
        cout << a << " " << b << "\n";
    }
    return 0;
}
