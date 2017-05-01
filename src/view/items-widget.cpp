#include <QInputDialog>
#include <QMessageBox>

#include <items-widget.h>
#include <item.h>
#include <stats-window.h>

ItemsWidget::ItemsWidget(QWidget *parent):
    QTreeWidget(parent)
{
    incomes.setExpanded(true);
    expenses.setExpanded(true);
}

void ItemsWidget::addNewItem(const Item::Type& type)
{
    itemManager.addItem(promptNewItem(type));
    updateEntries();
}

void ItemsWidget::removeSelectedItem()
{
    try {
        itemManager.removeItem(getSelected());
        updateEntries();
    } catch (std::runtime_error) {}
}

void ItemsWidget::editSelectedItem()
{
    try {
        auto old = getSelected();
        auto edited = promptNewItem(old.type(), old);
        itemManager.editItem(old, edited);
        updateEntries();
    } catch (std::runtime_error) {}
}

void ItemsWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    for (auto item: itemManager.sortedMonthItems()) {
        QStringList data = {item.name(), item.category(),
                          QString::number(item.value(), 'f', 2)};

        auto parent = item.type() == Item::Type::income ? &incomes : &expenses;
        new QTreeWidgetItem(parent, data, item.type());
    }
}

void ItemsWidget::changeMonth()
{
    bool ok;
    QString month = QInputDialog::getText(
                this, "Mudar mês", "Qual mês você quer acessar?",
                QLineEdit::Normal, itemManager.month(), &ok);

    if (ok) {
        try {
            itemManager.month(month);
            updateEntries();
        } catch (std::runtime_error e) {
            QMessageBox::warning(this, "Erro", e.what());
        }
    }
}

void ItemsWidget::showMonthlyStats()
{
    StatsWindow sw(this);
    sw.setItemsToShow(itemManager.sortedMonthItems(), itemManager.month());
    sw.exec();
}

Item ItemsWidget::promptNewItem(const Item::Type& type, const Item& hint)
{
    // FIXME if user cancels on one of the dialogs, it continues

    QString title = type == Item::Type::income ? "Receita:" : "Despesa:";

    auto name = QInputDialog::getText(this, title, "Nome do item:",
                                      QLineEdit::Normal, hint.name());

    auto category = QInputDialog::getText(this, title, "Categoria do item:",
                                          QLineEdit::Normal, hint.category());

    auto value = QInputDialog::getDouble(
                this, title, "Valor do item:", hint.value(),
                0, 999999, 2);

    return Item(name, category, value, type);
}

Item ItemsWidget::getSelected() const
{
    auto selected = selectedItems();

    if (selected.size() > 0) {
        auto type = static_cast<Item::Type>(selected[0]->type());
        return Item(selected[0]->text(0), selected[0]->text(1),
                selected[0]->text(2).toDouble(), type);
    } else {
        throw std::runtime_error("No selected item");
    }
}
