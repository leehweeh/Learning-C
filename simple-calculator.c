 #include<stdio.h>

int main()
{
    double num1, num2, results;
    char operator;
    printf("========================");
    printf("      CALCULATOR          ");
    printf("========================\n\n");
    
   //asks the user to input the first number//
    printf("Enter first number: ");
    scanf("%lf", &num1);
    
    //asks the user to choose an operator//
    printf("Enter an operator(+, -, *, /): ");
    scanf(" %c", &operator);
    
     //asks the user to input the second number//
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("\n--- Result ---\n");

    if(operator == '+'){
        results = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, results);
    }
    else if(operator == '-'){
       results = num1 - num2;
       printf("%.2lf - %.2lf = %.2lf\n", num1, num2, results);
    }
     else if(operator == '*'){
       results = num1 * num2;
       printf("%.2lf * %.2lf = %.2lf\n", num1, num2, results);
     }
     else if(operator == '/'){
        if(num2 == 0){
            printf("Math error.\n");
        }else {
            results = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, results);}
     }
     else {
        printf("Invalid input!");
     }
     return 0;

}
