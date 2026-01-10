//the binary number system only uses two digits, 0 and 1. 
//any string that represent number in binar can be callled binary string
//function accespts string as argumant , string has binary number seperated by alphabet
//a denotes AND
//b denotes OR
//c denotes XOR
// calculate result of string
//input: 1a0b1c1

#include <stdio.h>
#include <string.h>

int main(){

    char str[20];
    
    for(int i=0;i<strlen(str);i++){
        scanf(("%c"), &str[i]);
    }
    int result = str[0] - '0';
    int len = strlen(str);
    for(int i=1;i<len;i+=2){
        if(str[i] == 'a'){
            result = result & (str[i+1] - '0');
        }
        else if(str[i] == 'b'){
            result = result | (str[i+1] - '0');
        }
        else if(str[i] == 'c'){
            result = result ^ (str[i+1] - '0');
        }
    }
    printf("%d", result);
    return 0;
    
    }