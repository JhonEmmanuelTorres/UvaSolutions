import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );
		int t = Integer.parseInt( is.nextLine() ), aux;
		Map<String, Integer> tree = new TreeMap<>();
		is.nextLine();
		String tmp;
		while( t-- > 0 )
		{
			do{
				tmp = is.nextLine();
				if( tmp.isEmpty() )
					break;
				if( tree.containsKey( tmp ) )
					tree.replace( tmp, tree.get( tmp ) + 1 );
				else
					tree.put( tmp, 1 );
			}while( is.hasNextLine() );
			aux = 0;
			for( String o: tree.keySet() )
				aux += tree.get( o );
			for( String o: tree.keySet() )
			{
				System.out.print( o );
				System.out.printf( " %.4f\n", (tree.get(o)*100.0)/aux );
			}
			if( t != 0 )
				System.out.println();
			tree.clear();
		}
	}
}
