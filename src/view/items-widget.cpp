#include <QInputDialog>

#include <items-widget.h>
#include <item.h>

ItemsWidget::ItemsWidget(QWidget *parent):
    QTreeWidget(parent)
{}

void ItemsWidget::addNewItem(const Item::Type& type)
{
    itemManager.addItem(promptNewItem(type));
    updateEntries();
}

void ItemsWidget::removeSelectedItem()
{
    itemManager.removeItem(getSelected());
    updateEntries();
}

void ItemsWidget::editSelectedItem()
{
    auto old = getSelected();
    auto edited = promptNewItem(old.type(), old);
    itemManager.editItem(old, edited);
    updateEntries();
}

void ItemsWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    auto itemsList = itemManager.sortedItems();
    for (auto item: itemsList) {
        QStringList data = {item.name(), item.category(),
                          QString::number(item.value(), 'f', 2)};

        auto parent = item.type() == Item::Type::income ? &incomes : &expenses;
        new QTreeWidgetItem(parent, data, item.type());
    }
}

Item ItemsWidget::promptNewItem(const Item::Type& type, const Item& hint)
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

Item ItemsWidget::getSelected() const
{
    auto selected = selectedItems();
    auto type = static_cast<Item::Type>(selected[0]->type());
    return Item(selected[0]->text(0), selected[0]->text(1),
            selected[0]->text(2).toDouble(), type);
}
