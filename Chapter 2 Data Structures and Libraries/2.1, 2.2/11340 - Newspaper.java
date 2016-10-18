import java.util.*;
import java.io.*;

public class Main
{
	public static void main( String[] args ) throws IOException
	{
		BufferedReader is = new BufferedReader( new InputStreamReader(System.in) );
		int t = Integer.parseInt( is.readLine() ), k;
		String tmp;
		String[] tmp2;
		Map<Character, Integer> container;
		long answer;
		while( t-- > 0 )
		{
			answer = 0;
			container = new HashMap<>();

			k = Integer.parseInt( is.readLine() );
			while( k-- > 0 )
			{
				tmp2 = is.readLine().split(" ");
				container.put( tmp2[0].charAt(0) , Integer.parseInt(tmp2[1]) );
			}

			k = Integer.parseInt( is.readLine() );
			while( k-- > 0 )
			{
				tmp = is.readLine().trim();
				for( int i = 0; i < tmp.length(); i++ )
					if( container.containsKey( tmp.charAt(i) ) )
						answer += container.get( tmp.charAt(i) );
			}
			System.out.printf( "%.2f$\n", (answer/100.0) );
		}
		is.close();
	}
}
