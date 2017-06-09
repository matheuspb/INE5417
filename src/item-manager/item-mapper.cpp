#include <item-mapper.h>

ItemMapper::ItemMapper():
    db{QSqlDatabase::addDatabase("QMYSQL")}
{
    if (!db.open("root", "root"))
        throw std::runtime_error(
                "Não foi possível conectar com o banco de dados.");
}

QSet<QPair<QString, Item>> ItemMapper::fetchAllItems() const
{
    QSqlQuery query = db.exec("SELECT * FROM ine5417.item");

    QSet<QPair<QString, Item>> items;

    while (query.next()) {
        QString name = query.value(0).toString();
        QString category = query.value(1).toString();
        double value = query.value(2).toDouble();
        Item::Type type = query.value(3).toInt() == 0 ?
                    Item::Type::income : Item::Type::expense;
        QString month = query.value(4).toString();

        Item item{name, category, value, type};
        items.insert(QPair<QString, Item>(month, item));
    }

    return items;
}

void ItemMapper::insertItem(const Item& item, const QString& month) const
{
    QSqlQuery query;

    query.prepare("INSERT INTO ine5417.item "
                  "(name, category, value, type, month) VALUES"
                  "(:name, :category, :value, :type, :month)");

    query.bindValue(":name", item.name());
    query.bindValue(":category", item.category());
    query.bindValue(":value", item.value());
    query.bindValue(":type", item.type());
    query.bindValue(":month", month);

    query.exec();
}

void ItemMapper::deleteItem(const QString& name) const
{
    QSqlQuery query;
    query.prepare("DELETE FROM ine5417.item WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();
}
