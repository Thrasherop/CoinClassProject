
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::chrono;

int getRandom(int min, int max) {


    /*
     * Gets random number in provided range
     *
     * params::
     *      min: the minimum boundary for the range
     *      max: the maximum boundary for the range (exclusive)
     *
     * return::
     *      the chosen random number
     */
    return rand() % (max + 1 - 1) + min;
}

class Coin {

private:

    // private attributes
    double value;

    // private methods
    

protected:

    // Protected attributes
    int lastHeads;
    int lastTails;

public:

    // Constructors
    Coin(double dollarValue) {

        /*
         * Constructor to initialize the dollarValue
         * 
         * params::
         *      dollarValue: the value of the new coin object
         * 
         * return::
         *      the new coin object
         */

        srand(time(0));

        if (dollarValue <= 0) {
            throw "Invalid parameter: value must be positive";
        }
        else {
            value = dollarValue;
        }
    }

    // public methods
    int doSingleFlip() {
        /*
         * Performs a single flip
         *
         * return::
         *      the result of the coin flip (0 for tails, 1 for heads)
         */
        return getRandom(0, 2);
    }

    void doMultipleFlips(const int numFlips) {
        /*
         * Simulates multiple flips. This has a time cost of
         * O(numFlips)
         *
         * params::
         *      numFlips: the number of flips to simulate
         *
         * return::
         *      none
         */


        // Initilizes score variables
        int heads = 0;
        int tails = 0;

        // Initilizes temp var to hold each flip
        int thisFlip;

        // Simulates all the coin flips individually (O(n))
        for (int i = 0; i < numFlips; i++) {

            // Simulates this flip
            thisFlip = getRandom(0,2);

            // Determines the result and adds the score
            if (thisFlip == 1) {
                heads++;
            }
            else {
                tails++;
            }

        }


        // Sets lastHeads and lastTails
        lastHeads = heads;
        lastTails = tails;

        return;

    }

    int getLastHeads() {
        /*
         * Returns the heads value of last flip sequence
         * 
         * params::
         *      None
         * 
         * return::
         *      lastHeads
         */
        return lastHeads;
    }

    int getLastTails() {
        /*
         * Returns the tails value of the last flip sequence
         * 
         * params::
         *      None
         * 
         * return::
         *      lastTails
         */
        return lastTails;
    }



    void saveScoresToFile(string filename = "scores.txt") {


        
        // Opens the file
        ofstream myFileObject(filename);

        myFileObject << "Heads: " << lastHeads << ", Tails: " << lastTails;

        myFileObject.close();

    }

};

int main() {


    // Gets the number of flips from the user
    int numFlips;
    cout << "Input the number of flips you want to simulate: ";
    cin >> numFlips;

    // gets the output filename from user
    string outputFilename;
    cout << "\n\nInput the filename for the output (put a 1 to not save it): ";
    cin >> outputFilename;


    // Announces that the simulating has begun
    cout << "\nSimulating " << numFlips << " coin flips. This may take awhile..." << endl;


    // Creates coin of value 10 cents
    Coin myCoin(.1);

    // Gets starting time
    double startingTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();


    // Performs the flips
    myCoin.doMultipleFlips(numFlips);


    // Gets the outputs and prints to the screen
    cout << "\n\nHeads: " << myCoin.getLastHeads() << ", Tails: " << myCoin.getLastTails() << endl;

    
    // Calculates the elapsed time
    double endingTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    double deltaTime = endingTime - startingTime;
    long double timeInSeconds = deltaTime / 1000;

    cout << "\nElapsed time:    " << timeInSeconds << " seconds\n";
    

    // If the filename wasn't 1, then save the file
    if (outputFilename.compare("1") != 0) {
        cout << "\nSaving results to " << outputFilename << endl << endl;

        // Saves the scores
        myCoin.saveScoresToFile(outputFilename);
    }
    

    return 0;
};

