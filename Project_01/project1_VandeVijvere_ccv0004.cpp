//============================================================================
// Name        : project1_VandeVijvere_ccv0004.cpp
// Author      : Colin Vande Vijvere
// AU UserID   : ccv0004
// Description : COMP2710 Software Construction Project 1
// Compile     : g++ project1_VandeVijvere_ccv0004.cpp -std=c++11
// Run         : ./a.out
// Help        : No help received
//============================================================================

#include <iostream>
using namespace std;

int main() {
    // VARIABLE INITIALIZATION
    double loan = 0;
    double interestRate = 0;
    double interestRateC = 0;
    double monthlyPaid = 0;
    int currentMonth = 0;
    double interestTotal = 0;
    double interestMonthly = 0;
    double principal = 0;

    // CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // USER INPUT
    // NOTE: For valid input, the loan, interest, and monthly payment must
    // be positive. The monthly payment must also be large enough to
    // terminate the loan.
    cout << "\nLoan Amount: ";
    cin >> loan;

    /*check loan input for positive number. can't be zero either 
    since you can't calculate a loan on zero dollars */
    while (loan <= 0) {
        cout << "\n invalid input, please submit a positive number: ";
        cin >> loan;
    }

    cout << "Interest Rate (% per year): ";
    cin >> interestRate;

    //check interestRate input for positive number
    // zero allowed since no interest can be an option
    while (interestRate < 0) {
        cout << "\n invalid input, please submit a positive number: ";
        cin >> interestRate;
    }
    
    // GET PROPER INTEREST RATES FOR CALCULATIONS
    interestRate /= 12;
    interestRateC = interestRate / 100;
    cout << "Monthly Payments: ";
    cin >> monthlyPaid;

    //check to see if monthly payment is higher than the interest
    while (monthlyPaid <= loan * interestRateC) {
        cout << "\ninvalid input, your payment is lower than your interest,\nplease enter a higher payment: ";
        cin >> monthlyPaid;
    }


    
    // AMORTIZATION TABLE
    cout << "*****************************************************************\n"
    << "\tAmortization Table\n"
    << "*****************************************************************\n"
    << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
    // LOOP TO FILL TABLE
    while (loan > 0) {
        if (currentMonth == 0) {
        cout << currentMonth++ << "\t$" << loan;
        if (loan < 1000) cout << "\t"; // Formatting MAGIC
        cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
        else {
            //calculations
            interestMonthly = loan * interestRateC;
            interestTotal += interestMonthly;
            principal = monthlyPaid - interestMonthly;
            
            //if else statement for last line in the table
            if (loan > monthlyPaid) {
            loan -= principal;
            } else {
                principal = loan;
                monthlyPaid = loan + interestMonthly;
                loan = 0;

            }


            //Statement for formatting
            if (loan < 1000) {
                cout << currentMonth++ << "\t$" << loan << "\t\t" << monthlyPaid << "\t" 
                    << interestRate << "\t" << interestMonthly << "\t\t" << principal << "\n";
            } else {
                cout << currentMonth++ << "\t$" << loan << "\t" << monthlyPaid << "\t" 
                    << interestRate << "\t" << interestMonthly << "\t\t" << principal << "\n";             
            }
        }
    }
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off "
    << "the loan.\n"
    << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;
}

