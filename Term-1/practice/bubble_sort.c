#include <stdio.h>

#include <string.h>

struct Student

{

  char name[20];

  int score;

};

int main() {

  Student student[5];

  strcpy(student[0].name, "Alex");

  student[0].score = 60;

  strcpy(student[1].name, "DiannA");

  student[1].score = 75;

  strcpy(student[2].name, "Neal");

  student[2].score = 70;

  strcpy(student[3].name, "Jessica");

  student[3].score = 83;

  strcpy(student[4].name, "Jack");

  student[4].score = 54;

  int i, j;

  Student temp;

  for (i = 0; i < 5; i++) {

    for (j = 0; j < 5 - i; j++)

    {

      if (student[j].score > student[j + 1].score) {
          int t = student[j].score;
          student[j].score = student[j+1].score;
          student[j+1].score = student[j].score;
      }

    }

  }

  printf("%s:%d", student[0].name, student[0].score);

  for (i = 1; i < 5; i++) {

    printf("\n%s:%d", student[i].name, student[i].score);

  }

  printf("\n");

  return 0;

}


