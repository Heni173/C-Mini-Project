//NUMBER SYSTEM CONVETER
#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

//Abstract class
class Converter 
{
public:
    string calculate(int n, int base) 
    {
        if (n == 0) return "0";

        string result = "";
        while (n > 0) 
        {
            int rem = n % base;
            if (rem < 10) 
                result += (char)(rem + '0');
            else 
                result += (char)((rem - 10) + 'A');

            n /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void printHeader() 
    {
        cout << "\n--- System Message: Starting Conversion ---" << endl;
    }

    void printHeader(string mode)         //Function Overloading
    {
        cout << "\n[Mode: " << mode << " Conversion]" << endl;
    }

    virtual string convert(int n) = 0;      //Pure Virtual Function
      
    virtual ~Converter() {}                 //Destructor
};

//Inheritance and Function Overriding
class BinaryConverter : public Converter 
{
public:
    string convert(int n) override
    {
        printHeader("Binary"); 
        return calculate(n, 2); 
    }
};

class OctalConverter : public Converter 
{
public:
    string convert(int n) override 
    {
        printHeader("Octal");
        return calculate(n, 8);
    }
};

class HexConverter : public Converter 
{
public:
    string convert(int n) override {
        printHeader("Hexadecimal");
        return calculate(n, 16);
    }
};

int main() {
    int decimalNum, choice;
    char repeat;

    do {
        cout << "\n========================================";
        cout << "\n       NUMBER SYSTEM CONVERTER";
        cout << "\n========================================";
        
        cout << "\nEnter a Decimal Number: ";
        if (!(cin >> decimalNum)) {
            cout << "Error: Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cout << "\nSelect Conversion Target:";
        cout << "\n1. Binary (Base 2)";
        cout << "\n2. Octal (Base 8)";
        cout << "\n3. Hexadecimal (Base 16)";
        cout << "\nEnter Choice (1-3): ";
        cin >> choice;

        Converter* ptr = nullptr;

        switch (choice) 
        {
            case 1: ptr = new BinaryConverter(); break;
            case 2: ptr = new OctalConverter();  break;
            case 3: ptr = new HexConverter();    break;
            default:
                cout << "Invalid Selection!" << endl;
                continue;
        }

        cout << "RESULT: " << ptr->convert(decimalNum) << endl;

        delete ptr;

        cout << "\nDo you want to perform another conversion? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nExiting... Thank you for using the Converter!" << endl;

    return 0;
}