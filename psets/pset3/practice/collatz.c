//function for collatz practice problem for recursion on cs50

int collatz(int n)
{
    //base case
    if (n == 1)
    {
	    return 0;
    }
    //even numbers
    else if ((n % 2) == 0)
    {
	    return 1 + collatz(n/2);
    }
    //odd numbers
    else ((n % 2) != 0)
    {
	    return 1 + collatz(3*n + 1);
    }
}