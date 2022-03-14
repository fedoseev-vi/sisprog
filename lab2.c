#include <stdio.h>
int main(){
unsigned char a[10] = {238, 42, 134, 168, 4, 85, 219, 171, 182, 15};
int sum = 0;
unsigned char mask;
for (int i = 0; i<10; i++)
{
	mask = a[i] & 34;
	if (34 == mask)
		sum += (int)a[i];
}
printf("%d\n", sum);
return 0;
}
