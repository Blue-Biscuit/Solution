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