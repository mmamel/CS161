/*********************************************************************
 ** Program Filename: numbers.cpp
 ** Author: theonewhoknocks
 ** Date: 1/9/19
 ** Description: Uses the climits library and the cmath library to
 ** demonstrate the use of a macro to determine the bytes allocated
 ** by a data type as well as a calculated method.
 ** Input: No inputs
 ** Output: Outputs the largest and smallest number of a signed and
 ** unsigned int, short, and long
 *********************************************************************/


#include <climits>
#include <iostream>
#include <cmath>

int main(){
    
    std::cout << "The max size of a Signed Int is: " << INT_MAX << std::endl;
    
    std::cout << "The min size of a Signed Int is: " << INT_MIN << std::endl;
    
    std::cout << "The max size of a Signed Short is: " << SHRT_MAX << std::endl;
    
    std::cout << "The min size of a Signed Short is: " << SHRT_MIN << std::endl;
    
    std::cout << "The max size of a Signed Long is: " << LONG_MAX << std::endl;
    
    std::cout << "The min size of a Signed Long is: " << LONG_MIN << std::endl;
    
    std::cout << "The max size of a Unsigned Int is: " << UINT_MAX << std::endl;

    std::cout << "The max size of a Unsigned Short is: " << USHRT_MAX << std::endl;
    
    std::cout << "The max size of a Unsigned Long is: " << ULONG_MAX << std::endl;
    
    std::cout << "The calculated max size of a Signed Int is: "
  //  << (int) ( pow ( 2, sizeof (int) * 8 - 1) - 1)  << std::endl;
    << ( (int) (pow (2 , sizeof (int) * 8 - 1) ) ) - 1 << std::endl;
    
    std::cout << "The calculated min size of a Signed Int is: "
    << -1 * ( (int) (pow (2 , sizeof (int) * 8 - 1) ) )  << std::endl;

    std::cout << "The calculated max size of an Unsigned Int is: "
    << (unsigned int)( pow ( 2 , (sizeof (int) * 8) ) - 1 ) << std::endl;

    std::cout << "The calculated max size of a Signed Short is: "
    << ( (short) (pow (2 , sizeof (short) * 8 - 1) ) ) - 1 << std::endl;

    std::cout << "The calculated min size of an Signed Short is: "
    << -1 * ( (short) (pow (2 , sizeof (short) * 8 - 1) ) )  << std::endl;

    std::cout << "The calculated max size of an Unsigned Short is: "
    << (unsigned short)(pow (2 , (sizeof (short) * 8) ) - 1 ) << std::endl;

    std:: cout << "The calculated max size of a Signed Long is: "
    << ( (long) (pow (2 , sizeof (long) * 8 - 1) ) ) - 1 << std::endl;

    std::cout << "The calculated min size of a Signed Long is: "
    << -1 * ( (long) (pow (2 , sizeof (long) * 8 - 1) ) )  << std::endl;


    std::cout << "The calculated max size of an Unsigned Long is: "
    << (unsigned long) (pow (2 , (sizeof (long) * 8) ) ) - 1 << std::endl;

    return 0;
    
}
