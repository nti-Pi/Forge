#ifndef __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__
#define __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__


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
    inline TLen fitStrat(TLen minSize) {
        return minSize;
    }

}   // namespace resize_strategy
}   // namespace Array
}   // namespace structures
}   // namespace forge


#endif // __HG__FORGE__STRUCTURES__ARRAY__RESIZE_STRATEGY_HPP__
