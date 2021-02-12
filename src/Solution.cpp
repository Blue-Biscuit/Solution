#include "Solution.h"

#include <cmath>

#include "Common.h"

cc::Solution::Solution(double val, cc::ExistenceType e):
_val(val), _type(e)
{

}

cc::Solution::Solution(double val):
Solution(val, cc::ExistenceType::Exists)
{

}

cc::Solution::Solution(cc::ExistenceType e):
Solution(0.0, e)
{

}

cc::Solution::Solution():
Solution(0.0, cc::ExistenceType::Exists)
{

}

bool cc::Solution::exists() const
{
    return cc::exists(_type);
}

bool cc::Solution::doesNotExist() const
{
    return cc::doesNotExist(_type);
}

bool cc::Solution::infinity() const
{
    return cc::infinity(_type);
}


cc::Solution cc::Solution::operator+(const cc::Solution& o) const
{
    return cc::Solution(_val + o._val, _type + o._type);
}

cc::Solution cc::Solution::operator-(const cc::Solution& o) const
{
    return cc::Solution(_val - o._val, _type - o._type);
}

cc::Solution cc::Solution::operator*(const cc::Solution& o) const
{
    double val = _val * o._val;
    cc::ExistenceType type = _type * o._type;

    if (type == cc::ExistenceType::AmbiguousInfinity)
    {
        if (infinity())
        {
            if (abs(o._val) < DEFAULT_EPSILON)
            {
                type = cc::ExistenceType::Indeterminate;
            }
            else
            {
                type = cc::imposeSign(type, o._val > 0);
            }
        }
        else
        {
            if (abs(_val) < DEFAULT_EPSILON)
            {
                type = cc::ExistenceType::Indeterminate;
            }
            else
            {
                type = cc::imposeSign(type, _val > 0);
            }
        }
    }

    return cc::Solution(val, type);
}

cc::Solution cc::Solution::operator/(const cc::Solution& o) const
{
    double val = 0.0;

    //  Do the division, if both the denominator exists and is not zero.
    if (cc::exists(o._type))
    {
        if (abs(o._val) < cc::DEFAULT_EPSILON)
        {
            return cc::Solution(cc::ExistenceType::Undefined);
        }
        else
        {
            val = _val / o._val;
        }
    }

    //  Calc the existence of the value.
    cc::ExistenceType type = _type / o._type;

    if (type == cc::ExistenceType::AmbiguousInfinity)
    {
        type = cc::imposeSign(type, o._val > 0);
    }
    else if (cc::exists(_type) && cc::infinity(o._type))
    {
        val = 0.0;
    }

    return cc::Solution(val, type);
}

cc::Solution cc::Solution::operator-() const
{
    return Solution(-_val, -_type);
}

void cc::Solution::setVal(double v)
{
    _val = v;
}

void cc::Solution::setType(cc::ExistenceType t)
{
    _type = t;
}

double cc::Solution::getVal() const
{
    return _val;
}

cc::ExistenceType cc::Solution::getType() const
{
    return _type;
}
