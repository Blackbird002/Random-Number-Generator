/*
Riad Shash (Ray)
Program #1 part A
*/
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;

//The number of random numbers to generate...
const int MaxNum = 10000;

int main()
{
    double randomNum = 0;

    /*
    Generates a seed based on elapsed time since Coordinated Universal Time (UTC)
    and now. Current time - January 1st, 1970
    This makes a unique seed every time the program is executed.
    */
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    //32-bit Mersenne Twister Random Number Engine (part of Random library)
    mt19937 randomEngine(seed);

    /*
    Produces type double values according to a uniform distribution using following
    probability density function:
    p(x|a,b) = 1 / (b-a), a <= x < b
    */
    uniform_real_distribution<double> myDistribution(-100000,100000);

    ofstream outputFile;
    outputFile.open("RandomNumbers.dat");
    outputFile.setf(ios::fixed);

    cout<<endl;
    cout<<"The maximum number possible is: " <<myDistribution.max() <<endl;
    cout<<"The minimum number possible is: " <<myDistribution.min() <<endl;
    cout<<endl;

    for (int i = 0; i < MaxNum; i++)
    {
        //Generates a random number and writes it to file
        randomNum = myDistribution(randomEngine);
        outputFile<<setprecision(4) <<setw(15) <<randomNum;

        //Prevents an extra line from being sent to file
        if (i != (MaxNum - 1))
            outputFile<<endl;
    }

    outputFile.close();
    cout<<"A file with " <<MaxNum <<" random numbers was created! \n";
    cout<<"Please check the current directory for: RandomNumbers.dat\n";
    return 0;
}