#include "item.h"

Item::Item(QString name, QString category, double value):
    _name{name},
    _category{category},
    _value{value}
{}

bool Item::operator==(const Item& other) const
{
    return _name == other._name;
}

QString Item::name() const
{
    return _name;
}

QString Item::category() const
{
    return _category;
}

QString Item::value() const
{
    return QString::number(_value);
}
