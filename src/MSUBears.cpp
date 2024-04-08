using namespace std;

#include <iostream>

/*
    My initial solution for the MSU Bears problem
*/
int main()
{
    // We iterate from 1 to 100 (inclusive)
    for (int i = 1; i <= 100; ++i)
    {
        // This makes sure that I isn't a multiple of 3 or 5.
        if (i % 3 != 0 && i % 5 != 0)
        {
            std::cout << i << endl;
        }
        // If it is, we know that it's one of the two.
        else
        {
            // So, then we just check to see if it's divisible by 3 or 5 (or both).
            if (i % 3 == 0)
            {
                std::cout << "MSU";
            }
            if (i % 5 == 0)
            {
                std::cout << "Bears";
            }

            // And then we can end the line.
            std::cout << endl;
        }
    }   // End for loop
}