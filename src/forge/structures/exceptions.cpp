#include "exceptions.hpp"



namespace forge {
namespace structures {
namespace exceptions {

    IndexError::IndexError(size_t index, size_t arrayLength)
        : _Index(index),
          _Length(arrayLength) { }

    IndexError::~IndexError() { }


    void IndexError::writeMessage() {
        _MessageBuffer.writef("Encountered an Index Error! Index: (%lu) | Length: (%lu)\n",
                              _Index, _Length);
    }


    OverflowError::OverflowError()  { }
    OverflowError::~OverflowError() { }


    void OverflowError::writeMessage() {
        _MessageBuffer.writef("Exceeded the reserved space in pushing to an Array.");
    }


    UnderflowError::UnderflowError() { }
    UnderflowError::~UnderflowError() { }


    void UnderflowError::writeMessage() {
        _MessageBuffer.writef("Tried popping from an empty array!");
    }

}   // namespace exceptions
}   // namespace structures
}   // namespace forge
