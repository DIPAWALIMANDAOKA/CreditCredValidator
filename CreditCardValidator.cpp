#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool CheckIfString(const string& s) {

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string CreditCardNumber;
    
    cout << "enter EXIT to quit." << endl;    
    while (true) {
        
        cout << "Please enter your credit card number to validate: ";
        cin >> CreditCardNumber;
        
        if (CreditCardNumber == "exit")
            break;
        
        else if (!CheckIfString(CreditCardNumber)) {
            cout << "Bad input! ";
            continue;
        }
            
        int len = CreditCardNumber.length();
        int doubleEvenSum = 0;
        
        // Step 1 is to double every second digit, starting from the RHS. If it
        // results in a two digit number, add both the digits to GET a single
        // digit number. Finally, sum all the answers to obtain 'doubleEvenSum'.   
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((CreditCardNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }
        
        // Step 2 is to add every odd placed digit from the right to the value
        // 'doubleEvenSum'.
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (CreditCardNumber[i] - 48);
        }
        
        // Step 3 is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.
        
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        
        continue;        
    }

    return 0;
}