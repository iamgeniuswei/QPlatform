#ifndef QPUITIMELINELIST_H
#define QPUITIMELINELIST_H

#include <QWidget>
#include <QListWidget>

class QPUITimeLineList : public QListWidget
{
    Q_OBJECT
public:
    explicit QPUITimeLineList(QWidget *parent = 0);

signals:

public slots:
    void itemClickedSlot(QListWidgetItem *item);
    void currentItemChangedSlot(QListWidgetItem * current, QListWidgetItem * previous);
};

#endif // QPUITIMELINELIST_H
