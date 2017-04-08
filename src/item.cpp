#include "item.h"

Item::Item(QString name, QString category, double value):
    _name{name},
    _category{category},
    _value{value}
{}

bool Item::operator==(const Item& other) const
{
    return _name == other._name &&
           _category == other._category &&
           _value == other._value;
}

QString Item::name() const
{
    return _name;
}

QString Item::category() const
{
    return _category;
}

double Item::value() const
{
    return _value;
}
