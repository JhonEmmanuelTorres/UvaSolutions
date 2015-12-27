#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long fact( int n )
{
	long accumutor = n;
	while( --n )
		accumutor *= n;
	return accumutor;
}

int main()
{
	short n, length;
	string text;
	cin >> n;
	long denominator, accountant;
	for( short i = 0; i < n; i++ )
	{
		cin >> text;
		sort( text.begin(), text.end() );
		accountant = 2;
		denominator = 1;
		for( short j = 0; j < text.length() - 1; j++ )
			if( text[j] == text[j+1] )
				denominator *= accountant++;
			else
				accountant = 2;
		cout << "Data set "  << i + 1 << ": " << fact( text.length() ) / denominator << endl;
	}
	return 0;
}
