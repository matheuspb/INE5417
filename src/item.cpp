#include "item.h"

Item::Item(QString name, QString category, double value, Type type):
    _name{name},
    _category{category},
    _value{value},
    _type{type}
{}

bool Item::operator==(const Item& other) const
{
    return _name == other._name &&
           _category == other._category &&
           _value == other._value;
}

Item::Type Item::type() const
{
    return _type;
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
