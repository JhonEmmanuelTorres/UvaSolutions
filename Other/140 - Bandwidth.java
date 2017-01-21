import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );

		String[] auxSplit;
		String line = is.nextLine();
		Map<Character,HashSet<Character>> container = new TreeMap<>();
		Map<Character,Integer> indexOf = new HashMap<>();
		ArrayList<Character> sequence = new ArrayList<>();
		ArrayList<Character> possible = new ArrayList<>();

		int maxBrand, minBrand;
		for( char i = 'A'; i <= 'Z'; i++ )
			indexOf.put( i, 0 );

		while( !line.equals( "#" ) )
		{
			for( int i = 0; i < line.length(); i++ )
				if( line.charAt(i) != ';' && line.charAt(i) != ':' )
					container.put( line.charAt(i), new HashSet<>() );
			for( char i: container.keySet() ){
				sequence.add( i );
				possible.add( i );
			}

			auxSplit = line.split( ";" );
			for( String tok: auxSplit )
				for( int i = 2; i < tok.length(); i++ ) {
					container.get( tok.charAt(0) ).add( tok.charAt(i) );
					container.get( tok.charAt(i) ).add( tok.charAt(0) );
				}

			minBrand = 1000;
			do {
				for( int i = 0; i < sequence.size(); i++ )
					indexOf.replace( sequence.get(i), i );

				maxBrand = -1;
				for( char node: container.keySet() )
					for( char link: container.get(node) )
						maxBrand = Math.max( maxBrand, Math.abs( indexOf.get(node) - indexOf.get(link) ) );

				if( maxBrand < minBrand ) {
					minBrand = maxBrand;
					Collections.copy( possible, sequence );
				}
			}while( next_permutation( sequence ) );

			for( char i: possible )
				System.out.print( i + " " );
			System.out.println( "-> " + minBrand );

			sequence.clear();
			possible.clear();
			container.clear();
			line = is.nextLine();
		}


	}

	static boolean next_permutation( ArrayList<Character> ele )
	{
		for( int i = ele.size() - 2; i >= 0; i-- )
			if( ele.get(i) < ele.get(i + 1) )
			{
				for( int j = ele.size() - 1; j >= 0; j-- )
					if( ele.get(i) < ele.get(j) ) {
						Collections.swap( ele, i, j );

						i++;
						for( j = ele.size() - 1;  i < j; i++, j-- )
							Collections.swap( ele, i, j );

						return true;
					}
			}
		return false;
	}
}
