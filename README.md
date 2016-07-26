# Forge #
_A *simple* library for memory allocation, logging, and memory-efficient data-structures._

## Usage: ##
Forge is a header-only library.
Therefore, to use Forge, simply add "Forge/src" as an include-path when compiling.
 
Forge supports two build targets:
*   debug
    In the debug build, the Forge library makes several compromises to the performance of your application to aid in  debugging.
    
    *   The memory module takes note of all allocations you make, and prints outstanding allocations to the console when asked to de-initialize the memory module. 
    *   The memory module can provide you with a list of all active allocations.
    *   The memory module can cap the total amount of heap-memory allocated.
    *   The logging module prepends each message with a (date/time)-stamp

    To build in debug mode, define *\__FORGE__DBG\__*
*   release
    In the release build, the Forge library is optimized for performance, and disables multiple introspection-features and checks.

Take a look at demo.cpp for more information.

