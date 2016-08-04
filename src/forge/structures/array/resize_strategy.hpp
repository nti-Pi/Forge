#ifndef __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__

/**
 *  A Resize Strategy is a _function_ (not procedure) that accepts the minimum buffer size that must be
 *  maintained, and returns some buffer size larger than this target size that the buffer can assume.
 *  For example:
 *      ->  The po2Strat function (power of two strategy) picks the smallest power of 2 greater than the target
 *          size, implying O(lg(N)) re-allocations for a series of force_push_back operations.
 *      ->  The fitStrat function (fit strategy) just returns the target size, implying O(N) re-allocations for
 *          force_push_back operations.
 */
namespace forge {
namespace structures {
namespace array {
namespace resize_strategy {

    // Every resize-strategy accepts the size that must be accommodated at a minimum
    // and returns the length of the new buffer after the resize operation.
    template <typename TLen>
    using ResizeStrategyFP = TLen (*) (TLen targetSize);


    template <typename TLen>
    inline TLen po2Strat(TLen minSize) {
        // We identify the smallest power of 2 bigger than minSize:
        TLen opSize = 1;
        while (opSize < minSize)
            opSize = opSize << 1;   // x2 operation

        return opSize;
    }


    template <typename TLen>
    inline TLen fitStrat(TLen minSize) { return minSize; }

}   // namespace resize_strategy
}   // namespace array
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__
