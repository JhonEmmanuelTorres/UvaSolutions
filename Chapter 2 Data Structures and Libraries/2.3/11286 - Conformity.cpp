#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio( false );
    int t, tmp, max;
    vector<int> aux( 5 );
    map< string ,int > container;
    string key;
    while( cin >> t, t )
    {
        while( t-- )
        {
            tmp = 5;
            while( tmp-- )
                cin >> aux[ tmp ];
            sort( aux.begin(), aux.end() );
            key = "";
            for( int i = 0; i < 5; i++ )
                key += to_string( aux[i] );
            container[ key ]++;
        }
        tmp = 0;
        for( map<string,int>::iterator i = container.begin(); i != container.end(); i++ )
            if( i->second > tmp )
                tmp = i->second;
        max = tmp;
        tmp = 0;
        for( map<string,int>::iterator i = container.begin(); i != container.end(); i++ )
            if( i->second == max )
                tmp += max;
        cout << tmp << endl;
        container.clear();
    }
    return 0;
}
