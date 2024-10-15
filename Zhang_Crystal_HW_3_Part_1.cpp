//Crystal Zhang 
//10/15/2024 
//HW 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    //defining the variables of the balance, withdraw or deposit, and the balance increase/decrease
    int balance; 
    char character; 
    int num;  

    ifstream inFile; //input file stream variable
    ofstream outFile;
    inFile.open("inData.txt"); //opens the input and output files
    outFile.open("outData.txt");

    inFile >> balance; 
    //makes the computer read the first line of the int file which is now determined as balance
    outFile << "Your starting balance is: " << balance << " dollars" << endl;
    //prints what the starting balance is to record it

    for (int i = 1; i <=7; i++) //loops this for seven times which is the amount of transactions 
    {
        inFile >> character >> num; 
        //makes the code read the first character and the number that goes with it (next to it) ((for seven times for all of the transactions))


        if (character == 87) 
        //if the letter in front of all the transactions equals to 87 on ascii, which is W = withdraw
            {
            balance = balance - num;
            //if it meetds this condition, minus the number next to the character from the balance and set the balance equal to what it's now

            outFile << "This transaction was a withdrawal and the balance is now: " << balance << endl; 
             //in the output file, print out what type of transaction this was and what the balance is after the transaction
            }


        if (character == 68)
        //if the letter in front of all the transactions equals to 68 on ascii, which is D = Deposit
           {
           balance = balance + num;
           //if it meetds this condition, add the number next to the character from the balance and set the balance equal to what it's now
           outFile << "This transaction was a deposit and the balance is now: " << balance << endl; 
           //in the output file, print out what type of transaction this was and what the balance is after the transaction
           }
    }

    outFile << "Your balance at the end of the day is: " << balance << " dollars";
    //prints in the output file what the balance is after the code runs all of the transactions 

    inFile.close(); //closes the files
    outFile.close();

    return 0;
    /*
    Your starting balance is: 5000 dollars
    This transaction was a withdrawal and the balance is now: 4800
    This transaction was a withdrawal and the balance is now: 4000
    This transaction was a withdrawal and the balance is now: 3960
    This transaction was a deposit and the balance is now: 4050
    This transaction was a deposit and the balance is now: 4150
    This transaction was a deposit and the balance is now: 5150
    This transaction was a withdrawal and the balance is now: 5130
    Your balance at the end of the day is: 5130 dollars
    */
}