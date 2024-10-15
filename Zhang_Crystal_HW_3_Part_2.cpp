//Crystal Zhang 
//10/15/2024 
//HW 3

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
    //defining the variables of the balance, withdraw or deposit, and the balance increase/decrease
    double balance; 
    char character; 
    double num;  
    double withdraw = 0; 
    double deposit = 0; 

    ifstream inFile; //input file stream variable
    ofstream outFile;
    inFile.open("inData2.txt"); //opens the input and output files
    outFile.open("outData2.txt");

    //rounds/prints every number below this code with 2 decimal points 
    outFile << fixed << showpoint; 
    outFile << setprecision(2); 

    inFile >> balance; 
    //makes the computer read the first line of the int file which is now determined as balance

    outFile << "STARTING BALANCE: $" << balance << endl;
    //prints what the starting balance is to record it
    outFile << "" << endl; //used to make the output look cleaner
    outFile << "" << endl; 


    outFile << setfill('.'); //to make it so that any code containting setw, that the empty spaces are filled with this character
    outFile << "TYPE......AMOUNT....................BALANCE" << endl; //sorts each value/character into what/start of 'bank statement'

    while (!inFile.eof()) //this loop with continue until the inFile has no more lines to run
    {
        inFile >> character >> num; 
        //makes the code read the first character and the number that goes with it (next to it) ((for seven times for all of the transactions))


        if (character == 87) 
        //if the letter in front of all the transactions equals to 87 on ascii, which is W = withdraw
            {
            balance = balance - num;
            //if it meetds this condition, minus the number next to the character from the balance and set the balance equal to what it's now

            withdraw = withdraw + num;
            //adds to the amount of money withdrawed to create a total amount of money withdrawed once the program ends 

            outFile << "W.........$" << num << setw(27) << "$" << balance << endl; 
            //prints what transaction occured here, how much, and what the balance is now in a format that matches the beginning line
            }


        if (character == 68)
        //if the letter in front of all the transactions equals to 68 on ascii, which is D = Deposit
           {
           balance = balance + num;
           //if it meetds this condition, add the number next to the character from the balance and set the balance equal to what it's now

           deposit = deposit + num;
           //adds to the amount of money despotited to create a total amount of money deposited once the program ends 

           outFile << "D.........$" << num << setw(27) << "$" << balance << endl;
            //prints what transaction occured here, how much, and what the balance is now in a format that matches the beginning line
           }
    }

    outFile << "" << endl; //used to make the output look cleaner
    outFile << "" << endl; 

    outFile << "ENDING BALANCE: $" << balance << endl; //prints what the balance is after all transactions have occured
    outFile << "TOTAL WITHDRAWALS: $" << withdraw << endl; //prints how much money was withdrawed
    outFile << "TOTAL DEPOSITS: $" << deposit << endl; //prints how muhc money was deposited

    inFile.close(); //closes the files
    outFile.close();

    return 0;
    /*
    STARTING BALANCE: $5000.00


    TYPE......AMOUNT....................BALANCE
    W.........$200.00..........................$4800.00
    W.........$800.00..........................$4000.00
    W.........$40.00..........................$3960.00
    D.........$90.00..........................$4050.00
    D.........$100.00..........................$4150.00
    D.........$1000.00..........................$5150.00
    W.........$20.00..........................$5130.00


    ENDING BALANCE: $5130.00
    TOTAL WITHDRAWALS: $1060.00
    TOTAL DEPOSITS: $1190.00
    */
}