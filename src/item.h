#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    enum Type {income, expense, none};

    Item() = default;
    Item(QString, QString, double, Type = none);

    bool operator==(const Item&) const;

    QString name() const;
    QString category() const;
    double  value() const;
    Type    type() const;

private:
    QString _name;
    QString _category;
    double  _value;
    Type    _type{none};
};

#endif // ITEM_H
