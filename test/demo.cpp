#include <cstdio>
#include <iostream>

#include "forge/logging/Log.hpp"
#include "forge/memory/Allocator.hpp"

using namespace std;


int main() {
    // We initialize the logging module to write standard messages to stdout, and error messages to
    // stderr.
    // Any attempts to write using the logging module prior to initialization will fail.
    // They can be substituted for any C FILE streams, including those from files on the disk.
    forge::logging::init(stdout, stderr);

    // We next initialize the memory module.
    #ifdef __FORGE__DBG__   
        // In debug-mode, I want to cap the size of my heap at 512 bytes.
        // The memory module will raise an exception if this limit is exceeded:
        forge::memory::init(512);
    #else
        forge::memory::init();
    #endif // __FORGE__DBG__

    // Testing out the logging:
    forge::logging::out::print("Hello, World!");
    forge::logging::err::print("Hello, error stream! The dark side of logged messages...");

    // The logging module supports two streams: out and err
    // Each stream has a single 'print' method that behaves exactly like printf, except with a new-line at the
    // end!
    // Each print statement also has its own time-stamp in debug mode.     

    // We will take some user input to illustrate that allocations are truly dynamic:
    // Regardless of where the log writes to, we need this message to print to stdout, so we use cout:
    std::cout << "Please enter the size of the array you wish to create for testing purposes: ";
    unsigned int arraySize; std::cin >> arraySize;
    forge::logging::out::print("The secret number was: %d", *mySecretInt);

    std::cout << "Enter the maximum integer value the array will store: ";
    unsigned int arrayMaxV; std::cin >> arrayMaxV;

    // We will now get started with a few allocations:
    int *mySecretInt = forge_new int(5);
    unsigned int *myIntArray = forge_new unsigned int[arraySize];

    // Writing and reading allocated memory:
    for (int i = 0; i < arraySize; ++i)
        myIntArray[i] = rand() % (arrayMaxV + 1);
    for (int i = 0; i < arraySize; ++i)
        forge::logging::out::print("A[%d]: %d", i, myIntArray[i]);

    // Querying the total heap size right now:
    forge::logging::out::print("It seems that %d bytes of the heap have been allocated so far!",
                               forge::memory::get_AllocatedHeapSize());

    // Freeing mySecretInt
    forge_del mySecretInt;

    // De-initializing the memory module;
    // All allocations we made that haven't been de-allocated should be printed to stderr if the program
    // is in debug mode:
    forge::memory::deInit();

    // De-initializing the logging module; from here on out, all calls to forge::logging will fail.
    forge::logging::deInit();

    return 0;
}
