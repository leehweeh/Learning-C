#include <stdio.h>
int main()
{
    float length , width;
    int product;
    printf("Enter length: ");
    scanf("%f", &length);
    printf("Enter width: ");
    scanf("%f", &width);
    product = length * width;
    printf("area is: %d", product);
    return 0;

}
