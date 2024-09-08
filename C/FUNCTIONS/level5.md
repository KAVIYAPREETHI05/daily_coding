### 628. Maximum Product of Three Numbers

```c
int maximumProduct(int* nums, int n) {
    int firstmax=INT_MIN;int secondmax=INT_MIN;int thirdmax=INT_MIN;
    int firstmin=INT_MAX;int secondmin=INT_MAX;
    for(int i=0;i<n;i++){
        if(nums[i]>firstmax ) {
            thirdmax=secondmax;
            secondmax=firstmax;
            firstmax=nums[i];
        }
        else if(nums[i]>secondmax){
            thirdmax=secondmax;
            secondmax=nums[i];
        }
        else if(nums[i]>thirdmax){
            thirdmax=nums[i];
        }
        if(nums[i]<firstmin){
            secondmin=firstmin;
            firstmin=nums[i];
        }
        else if(nums[i]<secondmin){
            secondmin=nums[i];
        }
    }
        int product1=firstmax*secondmax*thirdmax;
        int product2=firstmin*secondmin*firstmax;
        if(product1>product2){
            return product1;
        }
        return product2;
    
}
    

```
### find permutation
```c
#include <stdio.h>
int fact(int a){
    int product=1;
    if(a<0) return 0;
    for(int i=1;i<=a;i++){
        product*=i;
    }
    return product;
}

int main() {
   int n,r;
   scanf("%d",&n);
   scanf("%d",&r);
   if(n<r){
       printf("permutation is not possible");
   }
   int permu=fact(n)/fact(n-r);
   printf("%d",permu);
    return 0;
}
```
###  724. Find Pivot Index

```c
int pivotIndex(int* nums, int n) {
    
    int total=0;int leftsum=0;
    for(int i=0;i<n;i++){
        total+=nums[i];
    }
    for(int i=0;i<n;i++){
        if(leftsum == total-leftsum-nums[i]){
            return i;
        }
        leftsum+=nums[i];
    }
      return -1;
    
}
```
### 2273. Find Resultant Array After Removing Anagrams
```c

int isAnagram(char* word1,char*word2){
    int temp[26]={0};
    int n1=strlen(word1);
    int n2=strlen(word2);
    if(n1!=n2) return 0;
    for(int i=0;i<n1;i++){
        temp[word1[i]-'a']++;
    }
    for(int i=0;i<n2;i++){
        temp[word2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(temp[i]!=0){
            return 0;
        }
    }
    return  1;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char ** result=(char**) malloc(wordsSize*sizeof(char*));
    int index=0;
    result[index++]=strdup(words[0]);
    for(int i=1;i<wordsSize;i++){
        if(!isAnagram(words[i],words[i-1])){
            result[index++]=strdup(words[i]);

        }

    }
    *returnSize=index;
    return result;
    
}
```
### 5. Longest Palindromic Substring

```c

char* expandAroundCenter(char* s, int left, int right) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    
    // Allocate memory for the palindrome substring
    int length = right - left - 1;
    char* palindrome = (char*)malloc((length + 1) * sizeof(char));
    if (palindrome == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    strncpy(palindrome, s + left + 1, length);
    palindrome[length] = '\0'; // Null-terminate the string
    return palindrome;
}

/**
 * Function to find the longest palindromic substring.
 */
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    char* longest = (char*)malloc((n + 1) * sizeof(char));
    if (longest == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    longest[0] = '\0'; // Initialize the result to an empty string
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        // Odd-length palindromes
        char* p1 = expandAroundCenter(s, i, i);
        if (strlen(p1) > maxLen) {
            free(longest);
            maxLen = strlen(p1);
            longest = p1;
        } else {
            free(p1);
        }

        // Even-length palindromes
        char* p2 = expandAroundCenter(s, i, i + 1);
        if (strlen(p2) > maxLen) {
            free(longest);
            maxLen = strlen(p2);
            longest = p2;
        } else {
            free(p2);
        }
    }

    return longest;
}
```
### all pairs of anagram
```c
#include <stdio.h>
int isAnagram(int first,int second){
    int reversed=0;
    while(second>0){
        int digit=second%10;
        reversed=reversed*10+digit;
        second/=10;
    }
    if(reversed==first){
        return 1;
    }
    return 0;
    
    
}
int isprime(int n){
    if(n<2){
        return 0;
    }
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main() {
  int start,end;
  scanf("%d",&start);
  scanf("%d",&end);
  for(int i=start;i<=end;i++){
      if(isprime(i)){
          for(int j=i+1;j<=end;j++){
              if(isprime(j)&&isAnagram(i,j)){
                  printf("(%d,%d)\n",i,j);
              }
          }
      }
  }

    return 0;
}
```
### 2d matrix
```c
#include <stdio.h>
int countNonZero(int row,int col,int arr[row][col]){
      int count=0;

      for(int i=0;i<row;i++){
     for(int j=0;j<col;j++){
        if(arr[i][j]!=0){
            count++;
        }
       }
       }
  return count;
}
int main() {
  int row,col;
  scanf("%d",&row);
  scanf("%d",&col);
   int arr[row][col];
  for(int i=0;i<row;i++){
     for(int j=0;j<col;j++){
         scanf("%d",&arr[i][j]);
     }
  }
  int rowsum=0;
  int colsum=0;

  printf("%d\n",countNonZero(row,col,arr));
  for(int i=0;i<row;i++){
      rowsum=0;
     for(int j=0;j<col;j++){
         rowsum+=arr[i][j];
     }
     printf("%d - %d\n",i,rowsum);
  }
   for(int i=0;i<row;i++){
       colsum=0;
     for(int j=0;j<col;j++){
         colsum+=arr[j][i];
     }
     printf("%d - %d\n",i,colsum);
  }
    return 0;
}
```
### First occurrence of anagram
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool areAnagrams(char* str1, char* str2) {
    int temp[26]={0};
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    for(int i=0;i<strlen(str1);i++){
        temp[str1[i]-'a']++;
    }
     for(int i=0;i<strlen(str2);i++){
        temp[str2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(temp[i]!=0){
            return false;
        }
    }
      return true;
}
int main() {
    int n;

    scanf("%d", &n);
    
    char words[n][100];  
    bool printed[n];     
    
    for (int i = 0; i < n; i++) {
        printed[i] = false;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!printed[i]) {
            printf("%s\n", words[i]);
            for (int j = i + 1; j < n; j++) {
                if (areAnagrams(words[i], words[j])) {
                    printed[j] = true;
                }
            }
        }
    }
    
    return 0;
}
```
### binary to decimal
```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100
int binaryToDecimal(char *str1){
    int decimal=0;
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]=='1'){
            decimal+=pow(2,strlen(str1)-1-i);
        }
    }
    return decimal;
}

int main() {
    char binary1[MAX];
    char binary2[MAX];
    scanf("%s",&binary1);
    scanf("%s",&binary2);
    int num1=binaryToDecimal(binary1);
    int num2=binaryToDecimal(binary2);
    int sum=num1+num2;
int difference=num1-num2;
    printf("%d",sum);
printf("%d",difference);
    return 0;
}

```
### decimal to binary
```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define MAX 100
int binaryToDecimal(char *str1){
    int decimal=0;
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]=='1'){
            decimal+=pow(2,strlen(str1)-1-i);
        }
    }
    return decimal;
}
char * decimalToBinary(int decimal){
    int index=0;
    char*binary=(char*)malloc(MAX *sizeof(char));
    if(decimal==0){
        strcpy(binary,"0");
        return binary;
    }
    while(decimal>0){
        binary[index++]=(decimal%2)+'0';
        decimal/=2;
    }
    binary[index]='\0';
   
    for(int i=0;i<index/2;i++){
        char temp=binary[i];
        binary[i]=binary[index-1-i];
        binary[index-1-i]=temp;
    }
    return binary;
    
}

int main() {
    char binary1[MAX];
    char binary2[MAX];
    scanf("%s",binary1);
    scanf("%s",binary2);
    int num1=binaryToDecimal(binary1);
    int num2=binaryToDecimal(binary2);
    int sum=num1+num2;
    printf("%d",sum);
    
    printf("%s",decimalToBinary(sum));
   
    
    return 0;
}
```
### sum of odd numbers in recursion
```c
#include <stdio.h>
int sumOfOdd(int n){
    if (n<=0){
        return 0;
    }
    if(n%2==1){
        return n+sumOfOdd(n-2);
    }
    return sumOfOdd(n-1);
}
int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Sum of odd numbers: %d\n", sumOfOdd(n));

    return 0;
}

```
### edit distance
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the minimum distance between two strings
int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    // Create a 2D array for dynamic programming
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Initialize base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;  // Deleting all characters of word1
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;  // Inserting all characters of word2
    }

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insertOp = dp[i][j - 1];
                int deleteOp = dp[i - 1][j];
                int replaceOp = dp[i - 1][j - 1];
                dp[i][j] = min(insertOp, deleteOp, replaceOp) + 1;
            }
        }
    }

    // The answer is in dp[m][n]
    int result = dp[m][n];

    // Free the allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char word1[100], word2[100];

    // Input the two words
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);

    // Calculate the minimum edit distance
    int result = minDistance(word1, word2);

    // Output the result
    printf("Minimum Edit Distance: %d\n", result);

    return 0;
}

```
### group anagram
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool areAnagrams(char* str1, char* str2) {
    int temp[26]={0};
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    for(int i=0;i<strlen(str1);i++){
        temp[str1[i]-'a']++;
    }
     for(int i=0;i<strlen(str2);i++){
        temp[str2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(temp[i]!=0){
            return false;
        }
    }
      return true;
}
int main() {
    int n;

    scanf("%d", &n);
    
    char words[n][100];  
    bool printed[n];     
    
    for (int i = 0; i < n; i++) {
        printed[i] = false;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    for (int i = 0; i < n; i++) {
       
            printf("[%s", words[i]);
            printed[i]=true;
            for (int j = i + 1; j < n; j++) {
                if (areAnagrams(words[i], words[j])) {
                    printf(",%s",words[j]);
                    printed[j] = true;
                }
            }
        printf("]\n");
    }
    
    return 0;
}
```
### circular prime
```c
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

// Function to rotate the digits of a number
int rotateNumber(int num, int rotation) {
    int digits = (int)log10(num) + 1;  // Number of digits
    int divisor = pow(10, rotation);   // Divisor to isolate the rotation part
    int remainder = num % divisor;     // Get the last part
    int quotient = num / divisor;      // Get the first part

    return (remainder * pow(10, digits - rotation)) + quotient;
}

// Function to check if a number is a circular prime
bool isCircularPrime(int num) {
    int digits = (int)log10(num) + 1;

    for (int i = 0; i < digits; i++) {
        if (!isPrime(rotateNumber(num, i))) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isCircularPrime(num)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}

```
