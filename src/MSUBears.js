/*
    This one is pretty much the c++ one, just with slight changes because of JavaScript's ✨ uniqueness ✨
*/
for (let i = 1; i <= 100; ++i)
{
    if (i % 3 != 0 && i % 5 != 0)
    {
        console.log(i);
    }
    else
    {
        // This is the big thing. JS's console.log automatically prints a newline. BAD!!! HATE!
        // So, to get around this, I just use string concatenation in order to achieve the same effect.
        var str = "";
        if (i % 3 == 0)
        {
            str += "MSU";
        }
        if (i % 5 == 0)
        {
            str += "Bears";
        }
        console.log(str);
    }
}