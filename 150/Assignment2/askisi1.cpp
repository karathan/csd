#include "std_lib_facilities.h"

int recursive(int number) {            /*typwnei kathe fora apo to 1 mexri to number ena ena kai*/
									   /*tin timi poy epistrefei i sunartisi */
	int temp;
    if (number>=1) {
        temp = number*recursive(number-1);
        cout << number << "     " << temp << endl;
        return temp;
    }
    else {
        return temp=1;
    }
  }

int main()
{
    int number;
 
    cout << "Please enter number: ";        /*diavazei ton arithmo */
    cin >> number;
    cout << "Factorial of " << number << " = " << recursive(number) << endl;
    return 0;
}
