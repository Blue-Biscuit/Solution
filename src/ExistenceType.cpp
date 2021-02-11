#include "ExistenceType.h"


bool cc::exists(cc::ExistenceType t)
{
    return t == cc::ExistenceType::Exists;
}


bool cc::doesNotExist(cc::ExistenceType t)
{
    return !cc::exists(t);
}


bool cc::infinity(cc::ExistenceType t)
{
    return t == cc::ExistenceType::Infinity || t == cc::ExistenceType::NegInfinity;
}

bool cc::oppositeInfinities(cc::ExistenceType x, cc::ExistenceType y)
{
    return 
        (x == cc::ExistenceType::Infinity && y == cc::ExistenceType::NegInfinity) ||
        (y == cc::ExistenceType::Infinity && x == cc::ExistenceType::NegInfinity)
    ;
}

cc::ExistenceType cc::operator-(cc::ExistenceType x)
{
    if (x == cc::ExistenceType::Infinity)
    {
        return cc::ExistenceType::NegInfinity;
    }
    else if (x == cc::ExistenceType::NegInfinity)
    {
        return cc::ExistenceType::Infinity;
    }
    else
    {
        return x;
    }
}


cc::ExistenceType cc::operator+(cc::ExistenceType x, cc::ExistenceType y)
{
    //  1. If either types are undefined, then the answer is undefined.
    //  2. If either types are indeterminate, then the answer is indeterminate.
    //  3. If one of the types are an infinity, and the other is not the opposite,
    //      then the infinity wins out.
    //  4. If the two types are opposite infinities, then the answer is indeterminate.
    //  5. Else, the solution exists.

    //  1. If either types are undefined, then the answer is undefined.
    if (x == cc::ExistenceType::Undefined || y == cc::ExistenceType::Undefined)
    {
        return cc::ExistenceType::Undefined;
    }

    //  2. If either types are indeterminate, then the answer is indeterminate.
    else if (x == cc::ExistenceType::Indeterminate || y == cc::ExistenceType::Indeterminate)
    {
        return cc::ExistenceType::Indeterminate;
    }

    //  3. If one of the types are an infinity, and the other is not the opposite,
    //      then the infinity wins out.
    else if (infinity(x) && !oppositeInfinities(x, y))
    {
        return x;
    }
    else if (infinity(y) && !oppositeInfinities(x, y))
    {
        return y;
    }

    //  4. If the two types are opposite infinities, then the answer is indeterminate.
    else if (oppositeInfinities(x, y))
    {
        return cc::ExistenceType::Indeterminate;
    }

    //  5. Else, the solution exists.
    else
    {
        return cc::ExistenceType::Exists;
    }
}

cc::ExistenceType cc::operator-(cc::ExistenceType x, cc::ExistenceType y)
{
    return x + (-y);
}