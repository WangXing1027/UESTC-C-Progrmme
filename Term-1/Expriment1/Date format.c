#include <stdio.h>

int main(void)
{
  int a, b, c;

  printf("Enter a date(mm/dd/yyyy): ");
  scanf("%d/%d/%d", &a, &b, &c);
  printf("You entered the date: %d%.2d%.2d\n", c, a, b);

  return 0;
}
