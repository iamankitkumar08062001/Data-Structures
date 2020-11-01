- The results will still cause an integer overflow because the growth of n! is very very high and the maximum capacity of "unsigned long long int" is 2^64 - 1. So, modular arithematic should be used.
For example, properties like (a + b)%m = ((a%m) + (b%m))%m. Refer to concepts of Number Theory for the same. 
