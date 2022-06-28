#include <cs50.h>
#include <stdio.h>

int digitCalc(long int n);
void checksum(int digit, long int card);

int main(void)
{
    //Collect card number
    long int card = get_long("Enter a credit card number: \n");

    //Check digits
    int digit = digitCalc(card);

    //Implement checksum and assess card number validity
    checksum(digit, card);
}

//Function to calculate the number of digits
int digitCalc(long int n)
{
    int m = 0;
    long int card2 = n;
    while (card2 != 0)
    {
        card2 /= 10;
        m++;
    }
    return m;
}

//Function to check first digits, apply checksum algo and hence validate or invalidate credit card number
void checksum(int digit, long int card)
{
    //Check for American Express
    if (digit == 15 && ((card / 10000000000000 == 34) || (card / 10000000000000 == 37)))
    {
        long int card4 = card;
        long int card5 = card;
        int total;
        long int a = 0;//variable for first string of digits total
        long int b = 0;//variable for second string of digits total

        //Checksum code
        card4 /= 10;
        int c = (card4 % 10) * 2;
        while (c > 0)
        {
            a += c % 10;
            c /= 10;
        }

        while (card4 > 0)
        {
            card4 /= 100;
            int d = (card4 % 10) * 2;
            while (d > 0)
            {
                a += d % 10;
                d /= 10;
            }
        }

        while (card5 > 0)
        {
            b += card5 % 10;
            card5 /= 100;
        }
        total = a + b;

        if (total % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //Check for Mastercard
    else if (digit == 16 && ((card / 100000000000000 == 51) || (card / 100000000000000 == 52) || (card / 100000000000000 == 53)
                             || (card / 100000000000000 == 54) || (card / 100000000000000 == 55)))
    {
        long int card4 = card;
        long int card5 = card;
        int total;
        long int a = 0;//variable for first string of digits total
        long int b = 0;//variable for second string of digits total

        //Checksum code
        card4 /= 10;
        int c = (card4 % 10) * 2;
        while (c > 0)
        {
            a += c % 10;
            c /= 10;
        }

        while (card4 > 0)
        {
            card4 /= 100;
            int d = (card4 % 10) * 2;
            while (d > 0)
            {
                a += d % 10;
                d /= 10;
            }
        }

        while (card5 > 0)
        {
            b += card5 % 10;
            card5 /= 100;
        }
        total = a + b;

        if (total % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //Check for Visa
    else if ((digit == 13 && card / 1000000000000 == 4) || (digit == 16 && card / 1000000000000000 == 4))
    {
        long int card4 = card;
        long int card5 = card;
        int total;
        long int a = 0;//variable for first string of digits total
        long int b = 0;//variable for second string of digits total

        //Checksum code
        card4 /= 10;
        int c = (card4 % 10) * 2;
        while (c > 0)
        {
            a += c % 10;
            c /= 10;
        }

        while (card4 > 0)
        {
            card4 /= 100;
            int d = (card4 % 10) * 2;
            while (d > 0)
            {
                a += d % 10;
                d /= 10;
            }
        }

        while (card5 > 0)
        {
            b += card5 % 10;
            card5 /= 100;
        }
        total = a + b;

        if (total % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
