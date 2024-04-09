/*
    I am not the most comfortable with js but I figured that this would be a good one to get started with. Oh boy...

    Luckily, I learned quite a lot about JS while making this. Yippe!
*/

// These are just putting the modules under the alias fs, readLine, and stdout.
const fs = require('fs');
const stdout = require('process');
const readLine = require('readline');

// Here we set up a readline interface.
let rl = readLine.createInterface({
    /* 
    Input just sets the input, which is Bears.txt.
        For some reason, I needed to put require.resolve here. No idea why, but I just randomly found that on a StackOverflow page that had it as a solution.
        link: https://stackoverflow.com/questions/70909755/fs-readfilesync-says-no-such-file-or-directory-although-require-returns-the
        The comments help solve the problem and explain why, but I don't know why just ./Bears.txt doesn't work.
    */
    input: fs.createReadStream(require.resolve('./Bears.txt')),
    // Output is just stdout because we don't actually use it here, so we default to stdout.
    output: stdout,
    // Terminal is asking if we're using a teletypewriter (??). While researching what it was, I found a lot of stuff that didn't explain too much.
    // The best I found as an introduction was this: http://www.linusakesson.net/programming/tty/index.php
    // Weird.  They always talk about how Zoomers don't know about floppy discs (I do) but never about freaking teletypewriters...
    terminal: false
});

// Anyways, this is just reading the first line.
rl.on('line', line => {
    // We use String.includes() which searches a string for a specific instance of characters.
    // I wasn't sure if we were supposed to include 'Bear' too, so I did. If not, we can always delete the '|| line.includes("Bear").'
    if( line.includes("bear") || line.includes("Bear"))
    {
        // If it's in there, we print this.
        console.log("The first line contains the word bear.");
    }
    else
    {
        // Otherwise, we print this (sad).
        console.log("There are no bears :(");
    }

    // Then we close the line reader.
    rl.close();
    // And for some reason, we need to also remove the listeners. In readline's documentation, it says rl.close() does not immediately stop other events.
    // This is probably because the close event needs rl.close() to be called AND the InterfaceConstructor to relinquish control over iostreams. As seen under
    //  this documentation https://nodejs.org/api/readline.html#event-close
    // Solution found by Oz Shabat here https://stackoverflow.com/questions/44153552/readline-doesnt-stop-line-reading-after-rl-close-emit-in-nodejs
    rl.removeAllListeners();
});