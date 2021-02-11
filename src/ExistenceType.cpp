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
    return t == cc::ExistenceType::Infinity || t == cc::ExistenceType::NegInfinity || t == cc::ExistenceType::AmbiguousInfinity;
}

bool cc::oppositeInfinities(cc::ExistenceType x, cc::ExistenceType y)
{
    return 
        (x == cc::ExistenceType::Infinity && y == cc::ExistenceType::NegInfinity) ||
        (y == cc::ExistenceType::Infinity && x == cc::ExistenceType::NegInfinity)
    ;
}

cc::ExistenceType cc::imposeSign(cc::ExistenceType x, bool isPositive)
{
    if (infinity(x))
    {
        if (isPositive)
        {
            x = cc::ExistenceType::Infinity;
        }
        else
        {
            x = cc::ExistenceType::NegInfinity;
        }
    }

    return x;
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

cc::ExistenceType cc::operator*(cc::ExistenceType x, cc::ExistenceType y)
{
    //  1. If either types are undefined, the answer is undefined.
    //  2. If either types are indeterminate, the answer is indeterminate.
    //  3. If both are positive infinity, the answer is positive infinity.
    //  4. If both are negative infinity, the answer is positive infinity.
    //  5. If the types are opposite infinities, the answer is negative infinity.
    //  6. If either are an infinity, then the answer is an infinity of an unknown sign.
    //  7. Otherwise, the answer exists.

    //  1. If either types are undefined, the answer is undefined.
    if (x == cc::ExistenceType::Undefined || y == cc::ExistenceType::Undefined)
    {
        return cc::ExistenceType::Undefined;
    }

    //  2. If either types are indeterminate, the answer is indeterminate.
    else if (x == cc::ExistenceType::Indeterminate || y == cc::ExistenceType::Indeterminate)
    {
        return cc::ExistenceType::Indeterminate;
    }

    //  3. If both are positive infinity, the answer is positive infinity.
    else if (x == cc::ExistenceType::Infinity && y == cc::ExistenceType::Infinity)
    {
        return cc::ExistenceType::Infinity;
    }

    //  4. If both are negative infinity, the answer is positive infinity.
    else if (x == cc::ExistenceType::NegInfinity && y == cc::ExistenceType::NegInfinity)
    {
        return cc::ExistenceType::Infinity;
    }

    //  5. If the types are opposite infinities, the answer is negative infinity.
    else if (cc::oppositeInfinities(x, y))
    {
        return cc::ExistenceType::NegInfinity;
    }

    //  6. If either are an infinity, then the answer is an infinity of an unknown sign.
    else if (cc::infinity(x) || cc::infinity(y))
    {
        return cc::ExistenceType::AmbiguousInfinity;
    }

    //  7. Otherwise, the answer exists.
    else
    {
        return cc::ExistenceType::Exists;
    }
}

cc::ExistenceType cc::operator/(cc::ExistenceType x, cc::ExistenceType y)
{
    //  1. If either types are undefined, the answer is undefined.
    //  2. If either types are indeterminate, the answer is indetermiante.
    //  3. If the numerator exists and the denominator is an infinity, then the answer exists.
    //  4. If the numerator is an infinity and the denominator exists, then the answer is an infinity of an unknown sign.
    //  5. If both are infinities, then the answer is indeterminate.
    //  6. Otherwise, the answer exists.

    //  1. If either types are undefined, the answer is undefined.
    if (x == cc::ExistenceType::Undefined || y == cc::ExistenceType::Undefined)
    {
        return cc::ExistenceType::Undefined;
    }

    //  2. If either types are indeterminate, the answer is indetermiante.
    else if (x == cc::ExistenceType::Indeterminate || y == cc::ExistenceType::Indeterminate)
    {
        return cc::ExistenceType::Indeterminate;
    }

    //  3. If the numerator exists and the denominator is an infinity, then the answer exists.
    else if (exists(x) && infinity(y))
    {
        return cc::ExistenceType::Exists;
    }

    //  4. If the numerator is an infinity and the denominator exists, then the answer is an infinity of an unknown sign.
    else if (infinity(x) && exists(y))
    {
        return cc::ExistenceType::AmbiguousInfinity;
    }

    //  5. If both are infinities, then the answer is indeterminate.
    else if (infinity(x) && infinity(y))
    {
        return cc::ExistenceType::Indeterminate;
    }

    //  6. Otherwise, the answer exists.
    else
    {
        return cc::ExistenceType::Exists;
    }
}