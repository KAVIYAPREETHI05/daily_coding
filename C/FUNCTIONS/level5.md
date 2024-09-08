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
