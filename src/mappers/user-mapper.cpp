#include <user-mapper.h>

UserMapper::UserMapper():
    db{QSqlDatabase::database()}
{
    if (!db.open("root", "root"))
        throw std::runtime_error(
                "Não foi possível conectar com o banco de dados.");
}

bool UserMapper::checkUser(const QString& login, const QString& password) const
{
    QSqlQuery query;
    query.prepare("SELECT password FROM ine5417.user WHERE login = :login");
    query.bindValue(":login", login);
    query.exec();

    if (!query.next())
        return false;

    return query.value(0).toString() == password;
}

void UserMapper::insertUser(const QString& login, const QString& password) const
{
    QSqlQuery query;
    query.prepare("INSERT INTO ine5417.user (login, password)"
                  "VALUES (:login, :password)");

    query.bindValue(":login", login);
    query.bindValue(":password", password);

    query.exec();
}
