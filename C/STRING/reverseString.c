solved gfg prob

char* reverseWord(char* str) {
    int n=strlen(str);
    
    for(int i=0;i<n/2;i++){
        int temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    return str;
}
