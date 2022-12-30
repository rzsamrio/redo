#include <cs50.h>
#include <stdio.h>

bool checkluhn(long number, int length);

int main(void) 
{
	long card_number = get_long("Number: ");

	// Card length validity

	// Return card length
	int card_length = 0;
	long clone_no = card_number;
	for (int i = 0; clone_no != 0; i++, card_length++)
		clone_no /= 10;
	
	// Verify Conditions
	// AMEX?
	checkluhn(card_number, card_length);

	return 0;
}

bool checkluhn(long number, int length)
{
	// Store card number in array
	int num[20];
	for (int temp = 0, l = length; l > 0; l--)
	{
		temp = number % 10;
		number /= 10;
		num[l - 1] = temp;
	}
	
	// Calculate
	int msum = 0; // Sum of the multiplied
	for (int l = length - 2; l > 0; l -=2)
	{
		// To-do
		// Sum of the multiplied number digits
		msum += num[l] * 2;
		printf("%i ", msum);
	}
	printf("\n%i\n", msum);
}

