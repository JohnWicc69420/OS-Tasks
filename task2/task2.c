#include <stdio.h>

int main(){
int num, count = 0;
printf("Enter a number: ");
scanf("%d", &num);
printf("The first 100 factors of %d are: \n", num);

for (int i=1; i<=num; i++){
if (num % i == 0) {
printf("%d ", i);
count++;
}
if (count == 100)
break;
}
return 0;
}

