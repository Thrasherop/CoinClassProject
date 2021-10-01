Overview
Whenever I learn a new programming language, I like to benchmark it against the ones I have already learned. I do this by making a program that can simulate millions of coin flips, and that displays the time it took. Recently I learned C++, and this program is the benchmark that I made.

Below is how this script benchmarked against similar scripts in other languages. This was done by simulating 1,000,000 coin flips in 10 seperate flips, and then taking the average of the 10 attempts. Here are the scores:

C++ (this program) --------------> 0.1694 seconds
Python (vanilla interpreter) ------> 1.0159 seconds
Python (PyPy interpreter) --------> 0.2237 seconds
Java -------------------------------> 0.02 seconds
Software Demo Video

Development Environment
I used C++ in Visual Studio 2019. I used purely libraries in the standard library.

Useful Websites
w3schools.com served as an excellent resource for learning C++, and I highly recommend it for anyone considering learning C++ as well.

W3 Schools C++ tutorial
Future Work
There are a few issues that could be fixed

Java is faster than C++. This is not what I would expect, and I suspect that my coin flipping algorithm has some inefficiencies that could be ironed out.
The code and comments are incredibly messy, and I would like to clean things up a bit in the main function.