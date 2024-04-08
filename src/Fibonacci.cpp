using namespace std;

#include <iostream>
#include <vector>

/*
    My initial solution to the problem of finding the nth digit of the fibonacci sequence.
*/
int main()
{
    // We create a vector with the largest positive numbers the standard library will allow for the dynamic sizing of a vector (as opposed to an array.)
    // Very space-inefficient and I hope to improve on this later, but it works well for larger numbers.
    vector<unsigned long long int> fibonacci;
    // This is just the element they wish to access.
    int n;

    // Prompting the user.
    cout << "Insert the index of the element of the fibonacci sequence you'd like to find: ";
    cin >> n;

    // We insert the base (0 and 1) for the process to work.
    fibonacci.push_back(0);
    fibonacci.push_back(1);

    // And now we just loop all the way to n.
    for (int i = 2; i <= n; ++i)
    {
        fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
    }   // End for loop

    // Then we output the element.
    cout << fibonacci[n] << endl;

    return 0;
}

/*
    Overall, pretty happy that this works. I had never tried anything like this before, so for an initial solution, despite lacking elegance, it works!
*/