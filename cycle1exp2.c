#include<stdio.h>
#include<string.h>

void display(char str[]){
    int i=0;
    while(str[i]!='\0'){
        printf("%c", str[i++]);
    }
    printf("\n");
}

void substring(char str[], int ck[]) {
    int length = strlen(str);
    char c[length];
    int s=0;
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            for (int k = i; k <= j; k++) {
                if(ck[str[k]] != 0){
                    break;
                }  
                c[s++]=str[k];
                ck[str[k]] = 1;
            }
        }
    }
    c[s++]='\0';
    display(c);

}

int main(){
    char str[] = "abcabcd";
    display(str);
    int checklist[256] = {0};

    substring(str, checklist);

}
