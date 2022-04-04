#include <ctime>
#include <iostream>
using namespace std;

int main(){
srand(time(0));
long array_size, array_double_size;
cout << "Enter the size value for the first two arrays:" << endl;
cin >> array_size;
array_double_size = array_size * 2;

long *first_array = new long[array_size];
long *second_array = new long[array_size];
long *third_array = new long[array_double_size];

for(int i = 0; i < array_size; i++)
{
	first_array[i] = rand() % 100;
	second_array[i] = rand() % 100;
}

long* frst_arr_begin = &first_array[0];
long* scnd_arr_begin = &second_array[0];
long* thrd_arr_begin = &third_array[0];
long* scnd_arr_end = &second_array[array_size-1];

asm(
	"mov %[frst_arr_begin], %%rax\n\t"
	"mov %[scnd_arr_begin], %%rbx\n\t"
	"mov %[thrd_arr_begin], %%rcx\n\t"
	"mov (%%rax), %%rdx\n\t"
	
	"arr1:\n\t"
	"push (%%rax)\n\t"
	"pop (%%rcx)\n\t"
	"add $8, %%rax\n\t"
	"add $8, %%rcx\n\t"
	"mov (%%rax), %%rdx\n\t"
	"jmp arr2\n\t"
	
	"arr2:\n\t"
	"push (%%rbx)\n\t"
	"pop (%%rcx)\n\t"
	"cmp %%rbx, %[scnd_arr_end]\n\t"
	"je end\n\t"
	"add $8, %%rbx\n\t"
	"add $8, %%rcx\n\t"
	"mov (%%rbx), %%rdx\n\t"
	"jmp arr1\n\t"
	
	"end:\n\t"
	:
	: [frst_arr_begin]"m"(frst_arr_begin), [scnd_arr_begin]"m"(scnd_arr_begin), [thrd_arr_begin]"m"(thrd_arr_begin), [scnd_arr_end]"m"(scnd_arr_end)
	: "%rax", "%rbx", "%rcx", "%rdx"
);

cout << "First array: [";

for(int i = 0; i < array_size-1; i++)
{
	cout << first_array[i] << ", ";
}

cout << first_array[array_size-1] << "]" << endl;

cout << "Second array: [";

for(int i = 0; i < array_size-1; i++)
{
	cout << second_array[i] << ", ";
}

cout << second_array[array_size-1] << "]" << endl;

cout << "New array: [";

for(int i = 0; i < array_double_size-1; i++)
{
	cout << third_array[i] << ", ";
}

cout << third_array[array_double_size-1] << "]" << endl;

delete [] first_array;
delete [] second_array;
delete [] third_array;

return 0;
}
