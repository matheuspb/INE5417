#ifndef USERMAPPER_H
#define USERMAPPER_H

#include <QtSql>

class UserMapper
{

public:
    UserMapper();
    bool checkUser(const QString&, const QString&) const;
    void insertUser(const QString&, const QString&) const;

private:
    QSqlDatabase db;

};

#endif // USERMAPPER_H
