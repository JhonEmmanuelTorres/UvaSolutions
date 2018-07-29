#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> sieveModified( 1e6 + 1, 0 );
    for( int i = 2; i <= 1e6; i++ )
        if( sieveModified[ i ] == 0 )
            for( int j = i; j <= 1e6; j += i )
                sieveModified[ j ]++;
    int n;
    cin >> n;
    while( n != 0 )
    {
        cout << n << " : " << sieveModified[ n ] << endl;
        cin >> n;
    }
    return 0;
}
