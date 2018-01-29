#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, determinant, root1,root2;

    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf",&a, &b, &c);

    determinant = b*b-4*a*c;

    root1 = (-b+sqrt(determinant))/(2*a);
    root2 = (-b-sqrt(determinant))/(2*a);

    printf("root1 = %.2lf and root2 = %.2lf \n",root1 , root2);

}
