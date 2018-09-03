#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


short t, n, h;
char binary_word[17];

void dfs(short i, short ones) {
  if (i == n) {
    if (ones == h)
      printf("%s\n", binary_word);
    return;
  }

  binary_word[i] = '0';
  dfs(i + 1, ones);
  binary_word[i] = '1';
  dfs(i + 1, ones + 1);
}


int main() {
  scanf("%hd\n", &t);
  while (t--) {
    scanf("%hd%hd\n", &n, &h);
    binary_word[n] = '\0';
    dfs(0, 0);

    if (t)
      printf("\n");
  }
  return 0;
}
