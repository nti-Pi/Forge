#include <iostream>

#include "forge/logging.hpp"
#include "forge/structures/DArray.hpp"
#include "forge/structures/StaticString.hpp"

using namespace forge;
using namespace forge::structures;


void printArray(DArray<int> &A) {
    logging::out() << str("Array is of length ") << A.length() << '\n';

    for (unsigned int i = 0; i < A.length(); ++i) {
        logging::out() << '\t' << i << str(": ") << A[i] << '\n';
    }

}


int main() {
    logging::init(std::cout, std::cerr);

    DArray<int> myArray(10U, 1, 2, 3, 4, 5, 6, 7, 8, 9, 314159);
    printArray(myArray);

    // DArray<int> myArray(10);
    new(myArray.force_push_back()) int(5);
    new(myArray.force_push_back()) int(5);
    printArray(myArray);

    myArray.resize(80);
    myArray.reserve(5);

    for (int i = 0; i < 80; ++i) {
        new(myArray.force_push_back()) int(5 * i);
    }

    printArray(myArray);

    logging::deInit();
}
