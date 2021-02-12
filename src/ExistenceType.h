#ifndef EXISTENCETYPE_SOLUTION_H
#define EXISTENCETYPE_SOLUTION_H

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
        AmbiguousInfinity,
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

    //  Imposes the provided sign onto the ExistenceType
    //      (this is used to impose a sign on AmbiguousInfinity).
    //
    //  isPositive -> If true, the ExistenceType will be a positive quantity,
    //      if false, the ExistenceType will be a negative quantity.
    ExistenceType imposeSign(ExistenceType, bool isPostive);

    //  Unary negation operator for ExistenceTypes (in reality, all this does is change 
    //      -Infinity to Infinity, and vice versa)
    ExistenceType operator-(ExistenceType);

    //  Gets the existence of two existence types summed.
    ExistenceType operator+(ExistenceType, ExistenceType);

    //  Gets the existence of two existence types subtracted.
    ExistenceType operator-(ExistenceType, ExistenceType);

    //  Gets the existence of two existence types multiplied.
    ExistenceType operator*(ExistenceType, ExistenceType);

    ExistenceType operator/(ExistenceType, ExistenceType);
}


#endif
