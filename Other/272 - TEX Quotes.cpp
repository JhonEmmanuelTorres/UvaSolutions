#include <iostream>

using namespace std;

int main()
{
	string text;
	bool quotes = true;
	while( cin >> text )
	{
		for( short i = 0; i < text.length(); i++ )
		{
			if( text[i] == '\"' )
			{
				if( quotes )
				{
					text[i] = '`';
					text.insert( text.begin() + i + 1, '`' );
				}
				else{
					text[i] = '\'';
					text.insert( text.begin() + i + 1, '\'' );
				}
				quotes = !quotes;
			}
		}
		cout << text << endl;
	}
	return 0;
}
  
