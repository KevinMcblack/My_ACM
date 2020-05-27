#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
char str[1000], mir[1000];  
char mirror[]={"1SE Z  8        A   3  HIL JM O   2TUVWXY5"};  
  
int main(){  
    int len;  
    int i, flag1, flag2;  
    while(scanf("%s", str)!=EOF){  
  
        len = strlen(str);  
        for(i = 0; i<len; i++){         /*镜像选择*/  
            mir[len-i-1] = mirror[str[i]-'1'];  
        }  
        mir[len] = '\0';                /*最后要有结束的符号*/  
  
        flag1=flag2=0;                  /*标记的初始化，0代表是，非0代表不是*/  
        for(i = 0; i<=(len/2); i++){    /*判断是不是回文串*/  
            if(str[i]!=str[len-i-1]){  
                flag1 = 1;  
                break;  
            }  
        }  
  
        flag2 = strcmp(mir, str);       /*判断是不是镜像串*/  
  
        printf("%s -- ", str);  
        if(flag1!=0&&flag2!=0){  
            printf("is not a palindrome.");  
        }  
        else if(flag1==0&&flag2!=0){  
            printf("is a regular palindrome.");  
        }  
        else if(flag1!=0&&flag2==0){  
            printf("is a mirrored string.");  
        }  
        else if(flag1==0&&flag2==0){  
            printf("is a mirrored palindrome.");  
        }  
        printf("\n\n");  
    }  
}  