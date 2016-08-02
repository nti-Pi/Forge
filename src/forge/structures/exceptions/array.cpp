#include "array.hpp"


namespace forge {
namespace structures {
namespace exceptions {
namespace array {

    IndexError::IndexError(size_t index, size_t arrayLength)
        : _Index(index),
          _Length(arrayLength) { }

    IndexError::~IndexError() { }


    void IndexError::writeMessage() {
        _MessageBuffer.writef("Encountered an Index Error! Index: (%lu) | Length: (%lu)\n",
                              _Index, _Length);
    }


    ShrinkOverflowError::ShrinkOverflowError(size_t oldLen, size_t newLen)
        : _OldLen(oldLen),
          _NewLen(newLen) { }

    ShrinkOverflowError::~ShrinkOverflowError() { }


    void ShrinkOverflowError::writeMessage() {
        _MessageBuffer.writef("Tried shrinking an array to %lu below its existing length %lu!",
                              _NewLen, _OldLen);
    }


    OverflowError::OverflowError()  { }
    OverflowError::~OverflowError() { }


    void OverflowError::writeMessage() {
        _MessageBuffer.writef("Exceeded the reserved space in pushing to an Array.");
    }

}   // namespace array
}   // namespace exceptions
}   // namespace structures
}   // namespace forge
