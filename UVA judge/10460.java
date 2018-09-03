import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    ArrayList<BigInteger> facto = new ArrayList<>(27);
    facto.add(BigInteger.ONE);
    for (long i = 1; i < 27; i++) {
      facto.add(BigInteger.valueOf(i).multiply(facto.get((int)(i - 1))));
    }

    for (long t = cin.nextInt(); t > 0; t--) {
      String word = cin.next();
      BigInteger n = cin.nextBigInteger();
      ArrayList<Character> theFinalWord = new ArrayList<>();
      theFinalWord.add(word.charAt(0));

      BigInteger left = BigInteger.ZERO;
      BigInteger right = facto.get(word.length());
      long step = 1;
      while (left.compareTo(right) < 0) {
        if (left.add(BigInteger.ONE).compareTo(right) == 0) {
          for (int i = 0; i < theFinalWord.size(); i++)
            System.out.print(theFinalWord.get(i));
          System.out.println();
          break;
        }

        step++;
        BigInteger interval = right.subtract(left).divide(BigInteger.valueOf(step));
        for (long i = 0; i < step; i++) {
          if (
            left.add(interval.multiply(BigInteger.valueOf(i))).compareTo(n) <= 0 &&
            0 <= left.add(interval.multiply(BigInteger.valueOf(i + 1))).compareTo(n)
          ) {
            BigInteger aux = left;
            left = aux.add(interval.multiply(BigInteger.valueOf(i)));
            right = aux.add(interval.multiply(BigInteger.valueOf(i + 1)));
            theFinalWord.add((int)i, word.charAt((int)(step - 1)));
            break;
          }
        }
      }

    }
  }
}
