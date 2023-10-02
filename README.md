# Lab 22: #recursionfail omg lol

Recursion can be an elegant way to express an algorithm, but it has a major limitation. Every time a function recurses, it consumes stack memory for its parameters, local variables, and return value. If the recursion is binary (size reduces by half each time) or the maximum number of recursions is always small in practice (such as factorial), this isn't a problem. However, in the case of unbounded linear recursion, a stack overflow can occur and crash the program.

Let's see how recursion can fail using the _LinearSum_ example in Section 3.5.2 of the textbook. The psuedocode for this algorithm is provided in [Code Fragment 3.38](https://learning-oreilly-com.lpclibrary.idm.oclc.org/library/view/data-structures-and/9780470383278/ch03.html#summing_the_elements_in_an_array_using_l) and is repeated below:

    Algorithm LinearSum(A,n):
        Input: An integer array A and an integer n ≥ 1, such that A has at least n elements
        Output: The sum of the first n integers in A
        if n = 1 then
            return A[0]
        else
            return LinearSum(A,n-1) + A[n−1]

## Part 1: Implementation

To begin, implement an iterative solution to _LinearSum_ in the `iterativeLinearSum` function. That is, write a loop that adds all elements of `A` and returns the sum. (Do not recurse.)

Next, implement a recursive solution to _LinearSum_ in the `recursiveLinearSum` function. Use the pseudeocode above as a guide.

Make sure all unit tests pass before continuing.

## Part 2: Test the Limit

Now let's examine the limits of recursion. Follow these steps:

1. In `main`, create a `vector<int>` of size 10,000 and set each element to 1. (Hint: Define a constant `SIZE = 10000` and reserve this capacity in the vector, then fill it using [std::fill](https://en.cppreference.com/w/cpp/algorithm/fill).)
2. On one line, print `Iterative:` followed by the result of `iterativeLinearSum` with the vector as input.
3. On the next line, print `Recursive:` followed by the result of `recursiveLinearSum` with the same vector as input.
4. Run the program and you should see `Iterative: 10000` on one line and `Recursive: 10000` on the next.

Next, increase the size of the vector by a factor of 10 and re-run the program. Keep increasing the size by 10x and eventually you should observe that the iterative function succeeds but the recursive function fails due to a crash (indicated by a "segmentation fault" message or no output at all).

What happened? Why did the iterative function succeed but the recursive function fail?

## Part 3: Find the Limit

Let's find out exactly how big the array can become before the recursive function fails. One way is to test all possible values, starting from the smallest, until it fails. (How many tests would this require?)

A better way is to perform a binary search:

1. Re-run the recursive function on the largest size that succeeded (e.g., 10000) from the Part 2 experiment and confirm that it still succeeds.
2. Re-run the recursive function on the next largest size that failed (e.g., 100000) from the Part 2 experiment and confirm that it still fails.
3. Using these two sizes as the lower and upper bounds, perform a binary search to find the largest size that the array can be without causing a crash.

How many steps did you take in the binary search? What is this value as a function of the orginal delta (that is, the distance between the upper and lower bounds)?

### Hint

Prepare your binary search with some helper variables, such as:

	const int HIGH = 1000000;
	const int LOW  =  100000;
	int delta      = HIGH - LOW;
	int size       = LOW;

And start the array size in the middle of the search space:
    
	delta /= 2;
	size += delta;

Then run the program. If the recursive _LinearSum_ succeeds, reduce your search space to the _larger_ half and repeat:

	delta /= 2;
	size += delta;

Or, if the recursive _LinearSum_ fails (crashes), reduce your search space to the _smaller_ half and repeat:

	delta /= 2;
	size -= delta;

Keep repeating these steps until the delta reaches zero. (It helps to print the delta on each run.)

At this point you will have found the largest array size that the recursive _LinearSum_ can handle given the stack size of your particular environment. (Note: You will need to repeat the steps about 20 times.)
