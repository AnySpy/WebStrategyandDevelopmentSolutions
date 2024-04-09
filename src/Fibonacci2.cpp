/*
    In this one, I want to make it more space efficient.
*/
using namespace std;

#include <iostream>

int main()
{
    /* 
        I wanted to use an array and make it perform cyclically.
        I noticed that we only really need 3 elements: a storage for the new element and the two previous elements. 
        So, I create an array with 3 elements and initialize the first two elements to 0 and 1 (our base).
    */
    unsigned long long int arr[3] { 0, 1 };
    // cycle acts as the wheel of our modular division.
    // Unsigned short int for size reasons.
    unsigned short int cycle;
    // n is the input.
    int n;

    // Prompting the user for inputs
    cout << "Insert the index of the element of the fibonacci sequence you'd like to find: ";
    cin >> n;

    // This is handling the case that n is the first or second element. If they want that, it will output 0 or 1, respectively.
    if (n < 2)
    {
        std::cout << arr[n] << endl;
        // We also end execution because this is all they wanted.
        return 0;
    }

    // And here's where the fun math happens.
    for (int i = 2; i <= n; ++i)
    {
        // I create an unsigned short int (for space reasons) which acts as our wheel.
        // It will return 0, 1, or 2 due to modular division, which is perfect for indexing the array.
        cycle = i % 3;

        // Using this new variable, we use a switch that swaps over our cycle.
        // Temp represents the storage variable. The other two elements are the previous numbers.
        switch(cycle)
        {
            case 0:
                arr[cycle] = arr[1] + arr[2];
                break;
            case 1:
                arr[cycle] = arr[0] + arr[2];
                break;
            case 2:
                arr[cycle] = arr[0] + arr[1];
                break;
        }
    }   // End for loop

    std::cout << arr[cycle] << endl;

    return 0;
}