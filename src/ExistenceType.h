#pragma once

// An enumeration of the existence of a mathematical solution.
//
// author: Andrew Huffman

namespace cc
{
    enum class ExistenceType
    {
        Exists,
        Undefined,
        Infinity,
        NegInfinity,
        Indeterminate
    };

    // True if the solution exists.
    //
    // t -> The existence type to check.
    bool exists(ExistenceType t);

    // True if the solution does not exist.
    //
    // t -> The existence type to check.
    bool doesNotExist(ExistenceType t);

    // True if the solution is one of the infinities.
    //
    // t -> The existence type to check.
    bool infinity(ExistenceType t);

    //  True if the two types are opposite infinities.
    bool oppositeInfinities(ExistenceType, ExistenceType);

    // Gets the existence of two existence types summed.
    ExistenceType operator+(ExistenceType, ExistenceType);
}