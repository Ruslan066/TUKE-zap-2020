#include <stdio.h>
#include <math.h>
//ll
float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);
int opposite_number(const int n, const int number);
void counter(const int input_array[], const int array_size, int result_array[2]);
unsigned long sum_squared(const int line);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_array[], const int array_size);
unsigned long special_counter(const int input_array[], const int array_size);
int special_numbers(const int input_array[], const int array_size, int result_array[]);


int main()
{
	printf( "\nTask 1!\n");
	printf("%.4f\n", lift_a_car(2, 80, 1400));
	printf("%.4f\n", lift_a_car(4, 90, 1650));

	printf( "\nTask 2!\n");
	printf("%.4f\n", unit_price(4.79, 16, 150));
	printf("%.4f\n", unit_price(5.63, 20, 200));

	printf( "\nTask 3!\n");
	printf("%d\n", collatz(20));
	printf("%d\n", collatz(35));

	printf( "\nTask 4!\n");
	printf("%d\n", opposite_number(10, 2));
	// prints: 7
	printf("%d\n", opposite_number(12, 9));
	// prints: 3

	printf( "\nTask 5!\n");
	int input_array[] = { 1,2,3,4,5 };
	int result_array[2];
	counter(input_array, 5, result_array);
	printf("%d %d\n", result_array[0], result_array[1]);
	// prints: 9 6

	printf( "\nTask 6!\n");
	printf("%lu\n", sum_squared(1));
	// prints: 2
	printf("%lu\n", sum_squared(4));
	// prints: 70
	printf("%lu\n", sum_squared(39));
	// prints: 7219428434016265740

    printf("\nTask 7!\n");
    printf("%d\n", array_min(input_array, 5));
	// prints: 1
	printf("%d\n", array_max(input_array, 5));
	// prints: 5
	printf("%d\n", array_max(NULL, 5));
	// prints: -1

    printf("\nTask 8!\n");
	int input_array2[] = { 11,12,13,14,15 };
	printf("%lu\n", special_counter(input_array2, 5));
	// prints: 379

	printf( "\nTask 9!\n");
	int input_array3[] = { 16,17,4,3,5,2 };
	int result_array3[6];
	int count = special_numbers(input_array3, 6, result_array3);
	for (int i = 0; i < count; i++) {
		printf("%d ", result_array3[i]);
	}
	printf("\n");
	// prints: 17 5 2

}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight)
{
	float m = round(((stick_length * human_weight+0.0) / (human_weight+car_weight+0.0)) * 100) / 100.0;
    return m;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count)
{
	return round((pack_price * 100.0 / (rolls_count * pieces_count)) * 100) / 100;
}

int collatz(const int number)
{
	int numb = number;
	int count = 1;
	while (numb != 1)
	{
		if (numb % 2 == 0) {

			numb /= 2;
			count++;

		}
		else {
			numb = numb * 3 + 1;
			count++;
		}
	}
	return count;
}

int opposite_number(const int n, const int number){

	int centr = n / 2;
	int counter = n / 2;
	int index = 0;
	
	int first_arr  [10000];
	int second_arr  [10000];

	for (int i = 0; i < centr; i++)
	{
		first_arr[i] = i;
	}

	for (int i = 0; i < n / 2; i++)
	{
		second_arr[i] = counter;
		counter++;
	}

	if (number < centr) {
		index = number;
		return second_arr[index];
	}

	else if (number == 0) {
		index = 0;
		return second_arr[centr];
	}

	else if (number == centr) {
		return first_arr[0];
	}

	else if (number > centr) {
		index = number - centr;
		return first_arr[index];
	}
	return 0;

}

void counter(const int input_array[], const int array_size, int result_array[2])
{
	int count_1 = 0;
	int count_2 = 0;
	for (int i = 0; i < array_size; i++)
	{
		count_1 += input_array[i];
		i ++;
	}
	for (int i = 1; i < array_size; i++)
	{
		count_2 += input_array[i];
		i ++;
	}
	result_array[0] = count_1;
	result_array[1] = count_2;
}

unsigned long sum_squared(const int line)
{
	long c[1000];
	long n = line, i, j;
	long summ = 0;
	for (i = 1; i <= n; i++)
		c[i] = 0;
	c[0] = 1;
	for (j = 1; j <= n; j++)
		for (i = j; i >= 1; i--)
			c[i] = c[i - 1] + c[i];

	for (i = 0; i <= n; i++)
		c[i] = c[i] * c[i];
	for (i = 0; i <= n; i++){
		summ += c[i];
	}
	return summ;
}

int array_min(const int input_array[], const int array_size)
{
	if (input_array == NULL)
	{
		return -1;
	}
	else
	{
		int min = input_array[0];
		for (int i = 0; i < array_size; ++i)
		{
			if (input_array[i] < min)
			{
				min = input_array[i];
			}
		}
		return min;
	}
}

int array_max(const int input_array[], const int array_size)
{
	if (input_array == NULL)
	{
		return -1;
	}
	else
	{
		int max = input_array[0];
		for (int i = 0; i < array_size; ++i)
		{
			if (input_array[i] > max)
			{
				max = input_array[i];
			}
		}
		return max;
	}	
}

unsigned long special_counter(const int input_array[], const int array_size)
{
	int sum = 0;
	int numb;
	for (int i = 1; i <= array_size; i++)
	{
		numb = input_array[i-1];
		if (i % 2 == 0)
		{
			numb = numb * numb;
		}
		sum += numb;
	}
	return sum;
}

int special_numbers(const int input_array[], const int array_size, int result_array[])
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum = 0;
		for (int j = i+1; j < array_size; j++)
		{
			sum += input_array[j];
		}
		if (input_array[i]>sum)
		{
			result_array[count] = input_array[i];
			count++;
		}
	}
	return count;
}
