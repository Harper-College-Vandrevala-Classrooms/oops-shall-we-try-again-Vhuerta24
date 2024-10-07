#include <iostream>
#include <limits>
#include <string>

using namespace std;

int ValidateInput(int lowerBound = numeric_limits<int>::min(),int upperBound = numeric_limits<int>::max(),
    const string& prompt = "Please enter an integer: ",
    const string& errorMessage = "Invalid input. Please try again, Thank you!") 
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if the input is a valid integer
        if (cin.fail()) {
            cin.clear(); // Clears the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << errorMessage << endl;
            continue;
        }

        // Check if the input is within bounds
        if (value < lowerBound || value > upperBound) {
            cout << errorMessage << endl;
            continue;
        }

        // Clear the input buffer before returning the valid value
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

int main() {
    // Test 1: No bounds
    cout << "Test 1: No bounds" << endl;
    int value1 = ValidateInput();

    cout << "You entered: " << value1 << endl;

    // Test 2: With lower bound
    cout << "\nTest 2: Lower bound (10)" << endl;
    int value2 = ValidateInput(10,numeric_limits<int>::max(), "Enter an integer >= 10: ","Please enter a valid integer >= 10.");

    cout << "You entered: " << value2 << endl;

    // Test 3: upper bound
    cout << "\nTest 3: Upper bound (100)" << endl;
    int value3 = ValidateInput(numeric_limits<int>::min(), 100, "Enter an integer <= 100: ", "Please enter a valid integer <= 100.");

    cout << "You entered: " << value3 << endl;

    // Test 4: Two bounds
    cout << "\nTest 4: Lower and Upper bounds (10 to 50)" << endl;
    int value4 = ValidateInput(10, 50, "Enter an integer between 10 and 50: ", "Please enter a valid integer between 10 and 50.");

    cout << "You entered: " << value4 << endl;

    return 0;
}

