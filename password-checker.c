#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    //a password checker in c language.//
    char password[100];
    int upper =0, lower =0, digit =0;
    printf("Enter password: \n");
    scanf("%99s", password);

        for (int i =0; password[i] !='\0';
        i++){
        if (isupper(password[i])){
            upper =1;
        }

        else if (islower(password[i])){
            lower =1;
        }
        else if(isdigit(password[i])){
            digit =1;
        }
}
if(strlen(password) >=8 && upper &&
lower && digit) {
    printf("strong password \n");

}
else{
    printf("weak password \n");
}

return 0;
}
