import java.util.*;

public class Main
{
	private PriorityQueue<Integer> heapMax, heapMin;

	public Main()
	{
		heapMin = new PriorityQueue<>();
		heapMax = new PriorityQueue<>( 10, new Comparator<Integer>()
		{
			public int compare( Integer a, Integer b )
			{
				if( a > b ) return -1;
				if( a < b ) return 1;
				return 0;
			}
		} );
	}

	public void add( int theElement )
	{
		if( heapMax.isEmpty() )
			heapMax.add( theElement );
		else {
			if( (heapMin.size() + heapMax.size()) % 2 != 0 ) // impar
			{
				if( theElement <= heapMax.peek()  )
				{
					heapMin.add( heapMax.poll() );
					heapMax.add( theElement );
				}
				else
					heapMin.add( theElement );
			}
			else{
				if( theElement >= heapMin.peek() )
				{
					heapMax.add( heapMin.poll() );
					heapMin.add( theElement );
				}
				else
					heapMax.add( theElement );
			}
		}
	}

	public int getMedian()
	{
		if( (heapMin.size() + heapMax.size()) % 2 == 0 )
			return (heapMax.peek() + heapMin.peek())/2;
		return heapMax.peek();
	}

	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );
		Main heapMedian = new Main();
		while( is.hasNext() )
		{
			heapMedian.add( is.nextInt() );
			System.out.println( heapMedian.getMedian() );
		}
	}

}
