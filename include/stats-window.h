#ifndef STATS_WINDOW_H
#define STATS_WINDOW_H

#include <QDialog>
#include <QList>

#include <item.h>

namespace Ui {
class StatsWindow;
}

class StatsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatsWindow(QWidget *parent = 0);
    ~StatsWindow();

    void setItemsToShow(const QList<Item>&, const QString);

private:
    Ui::StatsWindow *ui;
};

#endif // STATS_WINDOW_H
