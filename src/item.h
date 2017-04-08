#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item() = default;
    Item(QString, QString, double);

    bool operator==(const Item&) const;

    QString name() const;
    QString category() const;
    double value() const;

private:
    QString _name;
    QString _category;
    double _value;
};

#endif // ITEM_H
