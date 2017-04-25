#include <mainwidget.h>
#include <item.h>

#include <QInputDialog>

MainWidget::MainWidget(QWidget *parent):
    QTreeWidget(parent)
{
    QObject::connect(&items, SIGNAL(changed()),
                     this, SLOT(updateEntries()));
}

void MainWidget::addNewItem(int type) // 0 = income, 1 = expense
{
    items.addItem(promptNewItem(static_cast<Item::Type>(type)));
}

void MainWidget::removeSelectedItem()
{
    items.removeItem(getSelected());
}

void MainWidget::editSelectedItem()
{
    auto old = getSelected();
    auto edited = promptNewItem(old.type(), old);
    items.removeItem(old);
    items.addItem(edited);
}

void MainWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    for (auto item: items) {
        QStringList data = {item.name(), item.category(),
                          QString::number(item.value(), 'f', 2)};

        auto parent = item.type() == Item::Type::income ? &incomes : &expenses;
        new QTreeWidgetItem(parent, data, item.type());
    }
}

Item MainWidget::promptNewItem(const Item::Type& type, const Item& hint)
{
    QString title = type == Item::Type::income ? "Receita:" : "Despesa:";

    auto name = QInputDialog::getText(this, title, "Nome do item:",
                                      QLineEdit::Normal, hint.name());

    auto category = QInputDialog::getText(this, title, "Categoria do item:",
                                          QLineEdit::Normal, hint.category());

    auto value = QInputDialog::getDouble(this, title, "Valor do item:",
                                         QLineEdit::Normal, hint.value());

    return Item(name, category, value, type);
}

Item MainWidget::getSelected() const
{
    auto selected = selectedItems();
    auto type = static_cast<Item::Type>(selected[0]->type());
    return Item(selected[0]->text(0), selected[0]->text(1),
            selected[0]->text(2).toDouble(), type);
}
