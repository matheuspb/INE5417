#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    QString login() const;
    QString password() const;

private slots:
    void createUser();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
