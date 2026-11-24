#include <stdio.h>

int main() {
    
    char s [100];
    char vocali[100] = "";
    char vocali_figo [] = "aeiou";
    char consonanti[100] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    printf("inserisci una stringa: \n");
    scanf("%s", s);
    
    while(s[i]!= '\0'){
        
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' \
                || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ){
        
            vocali[j] = s[i];
            j++;
        }
        else {
            consonanti[k] = s[i];
            k++;
        }
        
        i++;      
           
    }

    vocali[j] = '\0';
    consonanti[k] = '\0';
    
    printf("VOCALI: %s\n", vocali);
    printf("consonanti: %s\n", consonanti);
    
    return 0;
}

