#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// void isAnagram(char s[], char t[]);
// int main()
// {
// char string1[20],string2[20];
// printf("Enter the strings");
// scanf("%s",string1);
// scanf("%s",string2);
// isAnagram(string1,string2);

// }
// void isAnagram(char s[], char t[]) {
//     bool found=true;
// int c[26] = {0};
// for (int i = 0; i < strlen(s); i ++) {
// c[s[i]-97] ++;
// }
// for (int i = 0; i < strlen(t); i ++) {
// c[t[i]-97]--;
// }
// for (int i = 0; i < 26; i ++) {
// if (c[i] != 0) {
// printf("No, it's not");
// found=false;
// break;
// }
// }
// if(found==true){
// printf("Yes, it is");
// }
// }
#include <stdio.h>
#include <conio.h>
#include <string.h>
 // below is the sorting function to sort strings in lexicographical order.
void sortArr(char a[]) {
  int temp = 0, i, l;
  // below used logic is of bubble sort 
  for (i = 0; i < strlen(a) - 1; i++) {
    for (l = i + 1; l < strlen(a); l++) {
      if (a[i] > a[l]) {
        temp = a[i];
        a[i] = a[l];
        a[l] = temp;

      }
    }
  }

}
// below function is used to check whether two strings are anagrams.
int is_anagram(char a[], char b[]) {
  int i = 0;
  int freq_a[26] = {0};
  int freq_b[26] = {0};
  // converting uppercase to lowercase
  while (a[i] != '\0') {
    if (a[i] >= 'A' && a[i] <= 'Z') {
      a[i] = 'a' + (a[i] - 'A');
    }
    i++;
  }

  i = 0;
  // converting uppercase to lowercase
  while (b[i] != '\0') {
    if (b[i] >= 'A' && b[i] <= 'Z') {
      b[i] = 'a' + (b[i] - 'A');
    }
    i++;
  }

  sortArr(a); // sorting the string
  sortArr(b); // sorting the string
  // after sorting the strings just check whether both strings are equal or not.
  // if equal return 1 else return 0.
  for (i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char a[50], b[50];

  printf("Enter first string : ");
  scanf("%s", a); // first string

  printf("Enter second string : ");
  scanf("%s", b); // secobd string

  //  calling function to check whether the strings are anagrams or not.
  if (is_anagram(a, b) == 1) {
    printf("Two strings are an anagram to each other");
  } else {
    printf("Two strings are not an anagram to each other");
  }

  return 0;
}


