#pragma once

#include "ExistenceType.h"

// A wrapper class around a double, handling the case where a mathematical solution to the value does not exist.
//
// Author: Andrew Huffman

namespace cc
{

    class Solution
    {
    public:
    //  CONSTRUCTORS

        Solution(double val, ExistenceType type);
        Solution(double val);
        Solution(ExistenceType type);
        Solution();

    //  METHODS

        //  True if the solution exists.
        bool exists() const;

        // True if the solution does not exist.
        bool doesNotExist() const;

        //  True if the solution is an infinity.
        bool infinity() const;

    //  MAIN OPERATORS

        Solution operator+(const Solution&) const;
        Solution operator-(const Solution&) const;
        Solution operator*(const Solution&) const;
        Solution operator/(const Solution&) const;

        Solution operator-() const;

    //  SECONDARY OPERATORS

        Solution operator+(double) const;
        friend Solution operator+(double, const Solution&);

        Solution operator-(double) const;
        friend Solution operator-(double, const Solution&);

        Solution operator*(double) const;
        friend Solution operator*(double, const Solution&);

        Solution operator/(double) const;
        friend Solution operator/(double, const Solution&);

    //  ACCESSORS

        void setVal(double);
        void setType(ExistenceType);

        double getVal() const;
        ExistenceType getType() const;

    private:
        double _val;
        ExistenceType _type;
    };
}