/*

Aaron Bengochea - ab6503

1)

    Base case:
    When n = 1, (1+2^1) <= 3^1 is true.

    Hypothesis:
    Suppose that P(k) is true for an arbritary int k >=1
    This implies that (1 + 2^k) <= 3^k

    Show that (1 + 2^k + 1) <= 3^k+1

        2^(k+1) + 1 = (2 x 2^k) + 1
                    = 2(2^k + 1) - 1
                    = (2^k + 1) + (2^k + 1) - 1
                    <= 3^k + 3^k -1
                    = 3^(k+1) - 1 - 3^k
                    <= 3^(k+1)

    Therefore, by induction mathematical induction, we prove that 
    (1 + 2^n) <= 3^n for every integer n greater >= 1.


2)

    a)
    61 total choices for selections between lower, upper and digit.

    9 * 61 * 61 * 61 * 61 = 124,612,569 total units of time

    b)

    P(8,5) = 8! / (8! - 5!) = 8! / 3! = 6720
    or 8 * 7 * 6 * 5 * 4 = 6720

3)
    a) 
    The total number of strings is 2^8 = 256
    The total number of strings with exactly the same amt of 0's and 1's = C(8,4) = 70

    The total number of strings with more 0's than 1's is symmetrical, so we can say it is
    equal to (258 - 70) / 2 = 94

    The probability that a bit string contains more 0's then 1's is equal to
    94 / 256 = 0.3671875

    b)

    roll total - occurences --> Expected value
    2 - 4 / 36 --> 0.222
    3 - 12 / 36 --> 1.000
    4 - 13 / 36 --> 1.444
    5 - 6 / 36 --> 0.833
    6 - 1 / 36 --> 0.166

    total expected value = 
    0.222 + 1.000 + 1.444 + 0.833 + 0.166 = 3.665

    


4)

    Function 1:
    In the first for loop, the limitor is 100 (a constant) while i is growing by a multiple of 2 each loop.
    In the second for loop, the limitor is now n while j also grows by a multiple of 2 each loop.
    As j grows, k grows as well. It is important to keep in mind that j's limitor is n (a constant).
    Since k is contingent on j's growth, and j is limited by n.
    We can say that the worst case is a function of n
    Therefore, this functions runtime complexity
    is Theta(n)

    Function 2:
    In both functions, the n is being divided by 2. 
    Therefore, in both functions the runtime complexity 
    is Theta(log n)

*/