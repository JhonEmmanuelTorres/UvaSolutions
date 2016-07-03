import java.util.Scanner;
import java.math.BigInteger;

class Main 
{
    public static void main(String[] args)
    {
        Scanner is = new Scanner( System.in );
        BigInteger[] fibo = new BigInteger[5001];
        fibo[0] = BigInteger.ZERO;
        fibo[1] = BigInteger.ONE;
        int n = 2;
        while( n < 5001 )
        {
            fibo[n] = fibo[ n - 1 ].add( fibo[n - 2] );
            n++;
        }
        while( is.hasNext() )
        {
            n = is.nextInt();
            System.out.println( "The Fibonacci number for " + n + " is " + fibo[n] );
        }

    }
}
