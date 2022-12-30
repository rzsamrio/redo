#include <cs50.h>
#include <stdio.h>

bool checkluhn(int length);
int num[20];

int main(void) 
{
	long card_number = get_long("Number: ");

	// Card length validity

	// Return card length
	int card_length = 0;
	long clone_no = card_number;
	while (clone_no != 0)
	{
		clone_no /= 10;
		card_length++;
	}

	for (int temp = 0, l = card_length; l > 0; l--)
	{
		temp = card_number % 10;
		card_number /= 10;
		num[l - 1] = temp;
	}


	// Verify Conditions
	// AMEX?
	if (card_length == 15 && num[0] == 3 && (num[1] == 4 || num[1] == 7))
	{
		if (checkluhn(card_length))
		{
			printf("AMEX\n");
			return 0;
		}
	}

	// Visa?
	if ((card_length == 13 || card_length == 16) && num[0] == 4)
	{
		if (checkluhn(card_length))
		{
			printf("VISA\n");
			return 0;
		}
	}

	//MasterCard?
	if (card_length == 16 && num[0] == 5 && num[1] < 6 && num[1] > 0)
	{
		if (checkluhn(card_length))
		{
			printf("MASTERCARD\n");
			return 0;
		}
	}
	
	printf("INVALID\n");
	return 0;
}

bool checkluhn(int length)
{
	// Calculate
	int msum = 0; // Sum of the multiplied
	int asum = 0; // Sum of the unmultplied
	int tsum = 0; // Total sum
	for (int l = length - 2, temp = 0; l >= 0; l -=2)
	{
		temp = num[l] * 2;
		msum += (temp % 10) + (temp / 10); // multiplied units are tens
	}
	for (int i = length - 1; i >= 0; i -=2)
		asum += num[i];
	tsum = asum + msum;

	// Return
	if (tsum % 10 == 0)
		return true;
	else
		return false;
}

