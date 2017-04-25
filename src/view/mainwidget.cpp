#include <mainwidget.h>
#include <item.h>

#include <QInputDialog>

MainWidget::MainWidget(QWidget *parent):
    QTreeWidget(parent)
{}

void MainWidget::addNewItem(const Item::Type& type)
{
    items.addItem(promptNewItem(type));
    updateEntries();
}

void MainWidget::removeSelectedItem()
{
    items.removeItem(getSelected());
    updateEntries();
}

void MainWidget::editSelectedItem()
{
    auto old = getSelected();
    auto edited = promptNewItem(old.type(), old);
    items.removeItem(old);
    items.addItem(edited);
    updateEntries();
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
