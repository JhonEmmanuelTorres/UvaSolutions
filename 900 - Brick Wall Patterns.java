#include <iostream>

using namespace std;

typedef char byte;
typedef unsigned char ubyte;

int main()
{
    unsigned long long *serieFibonacci = new unsigned long long[50];
    serieFibonacci[0] = 1;
    serieFibonacci[1] = 2;
    ubyte n = 2;
    for(; n < 52; n++ )
        serieFibonacci[n] = serieFibonacci[n-2] + serieFibonacci[n-1];
    scanf( "%hhu", &n );
    while( n != 0 )
    {
        cout << serieFibonacci[n-1] << endl;
        scanf( "%hhu", &n );
    }
    return 0;
}
