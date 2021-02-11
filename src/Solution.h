#pragma once

#include "ExistenceType.h"

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