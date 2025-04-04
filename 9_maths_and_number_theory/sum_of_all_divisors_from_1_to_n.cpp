class Solution
{
public:
        long long sumOfDivisors(int N)
        {
                // Write Your Code here
                long long int sum = 0;
                for (int i = 1; i <= N; i++) {
                        sum += (N / i) * i;
                }
                return sum;
                /*FIRST ITERATION

                see in the summation of f(1)+f(2)+f(3)+f(4)

                when you divide(4/1=4)

                and when you multiply divisor(1) by quotient(4) i.e 1*4

                (1*4) means 1 is occuring 4 times in the summation of f(1)+f(2)+f(3)+f(4)*/



                /*SECOND ITERATION

                when you divide(4/2=2)

                and when you multiply divisor(2) by quotient(2) i.e 2*2

                (2*2) means 2 is occuring 2 times in the summation of f(1)+f(2)+f(3)+f(4)*/



                /*THIRD ITERATION

                when you divide(4/3=1)

                and when you multiply divisor(3) by quotient(1) i.e 3*1

                (3*1) means 3 is occuring 1 times in the summation of f(1)+f(2)+f(3)+f(4)*/



                /*FOURTH ITERATION

                when you divide(4/4=1)

                and when you multiply divisor(4) by quotient(1) i.e 4*1

                (4*1) means 4 is occuring 1 times in the summation of f(1)+f(2)+f(3)+f(4)*/

        };
}
};

