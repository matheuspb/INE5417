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
    try {
        itemManager.addItem(promptNewItem(type));
        updateEntries();
    } catch (std::runtime_error) {}
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
    sw.showTotals(itemManager.totalIncome(), itemManager.totalExpenses(),
                  itemManager.totalCategories(), itemManager.month());
    sw.exec();
}

void ItemsWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    auto items = itemManager.sortedMonthItems();

    for (auto item: items) {
        QStringList data = {item.name(), item.category(),
                          QString::number(item.value(), 'f', 2)};

        auto parent = item.type() == Item::Type::income ? &incomes : &expenses;
        new QTreeWidgetItem(parent, data, item.type());
    }
}

Item ItemsWidget::promptNewItem(const Item::Type& type, const Item& hint)
{
    QString title = type == Item::Type::income ? "Receita:" : "Despesa:";

    bool ok;

    auto name = QInputDialog::getText(
                this, title, "Nome do item:", QLineEdit::Normal,
                hint.name(), &ok);
    if (!ok) throw std::runtime_error("User canceled dialog");

    auto category = QInputDialog::getText(
                this, title, "Categoria do item:", QLineEdit::Normal,
                hint.category(), &ok);
    if (!ok) throw std::runtime_error("User canceled dialog");

    auto value = QInputDialog::getDouble(
                this, title, "Valor do item:", hint.value(),
                0, 999999, 2, &ok);
    if (!ok) throw std::runtime_error("User canceled dialog");

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
