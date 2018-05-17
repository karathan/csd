#include "std_lib_facilities.h"

int DoubleReference(int &key)               /*ypologizei to diplasio me call by reference */
{

    key = 2 * key;
}

int DoubleValue(int key)                    /*ypologizei to diplasio me call by value */
{
   
    return (2 * key);
}
    


int main() 
{
    int number;
    cout << "Please enter number: ";            /*diavazei arithmo */
    cin >> number;

    cout << "DoubleValue (call by value) is: " << DoubleValue(number) << endl;
    DoubleReference(number);
    cout << "DoubleValue (call by reference) is: " << number << endl;

    return 0;
}