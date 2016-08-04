#include "exceptions.hpp"


namespace forge {
namespace structures {
namespace array {
namespace exceptions {

    ShrinkOverflowError::ShrinkOverflowError(size_t oldLen, size_t newLen)
        : _OldLen(oldLen),
          _NewLen(newLen) { }

    ShrinkOverflowError::~ShrinkOverflowError() { }


    void ShrinkOverflowError::writeMessage() {
        _MessageBuffer.writef("Tried shrinking an array to %lu below its existing length %lu!",
                              _NewLen, _OldLen);
    }

}   // namespace exceptions
}   // namespace array
}   // namespace structures
}   // namespace forge
