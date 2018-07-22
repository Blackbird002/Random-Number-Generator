# RandomNumberGenerator
Generates a RandomNumbers.dat file with random numbers (set up to generate 10,000 numbers).

<b>Seed:</b>
Generates a seed based on elapsed time since Coordinated Universal Time (UTC)
and now. Current time - January 1st, 1970
This makes a unique seed every time the program is executed.

<b>Random Number Engine:</b>
Uses the 32-bit Mersenne Twister Random Number Engine (part of Random library)

Produces type double values according to a uniform distribution using following
probability density function:
p(x|a,b) = 1 / (b-a), a <= x < b
