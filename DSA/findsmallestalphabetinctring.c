// you are given a function :
//def smallest character(s): the function takes a string as input and returns the smallest character which is not present in string.
// and return the same
// input: s = "abcd"
// output: "e"

#include <stdio.h>
#include <string.h>

int main(){
    char str[20];
    for(int i=0;i<20;i++){
        scanf("%c", &str[i]);
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    int len = strlen(str);
    int arr[26] = {0};
    for(int i=0;i<len;i++){
        arr[str[i] - 'a'] = 1;
    }
    for(int i=0;i<26;i++){
        if(arr[i] == 0){
            printf("%c", i+'a');
            break;
        }
    }
    return 0;
}
