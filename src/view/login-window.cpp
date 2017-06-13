#include <QInputDialog>
#include <QMessageBox>

#include <login-window.h>
#include <user-mapper.h>
#include <ui_loginwindow.h>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(ui->newUser, SIGNAL(clicked(bool)),
            this, SLOT(createUser()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

QString LoginWindow::login() const
{
    return ui->login->text();
}

QString LoginWindow::password() const
{
    return ui->password->text();
}

void LoginWindow::createUser()
{
    QString title = "Novo usuário";

    bool ok;

    auto login = QInputDialog::getText(
                this, title, "Login:", QLineEdit::Normal, "", &ok);
    if (!ok) return;
    if (login.isEmpty()) {
        QMessageBox::warning(this, "Erro", "O login não pode ser vazio.");
        return;
    }

    auto password = QInputDialog::getText(
                this, title, "Senha:", QLineEdit::Password, "", &ok);
    if (!ok) return;

    UserMapper um;
    um.insertUser(login, password);

    QMessageBox::about(this, "Novo usuário", "Usuário criado com sucesso!");
}
