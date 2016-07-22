#ifndef DATETIMEDELEGATE_H
#define DATETIMEDELEGATE_H
#include "pagewidget_global.h"
#include <QStyledItemDelegate>

class PAGEWIDGETSHARED_EXPORT DateTimeDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:    
    explicit DateTimeDelegate(const QString timeFormat = "yyyy.MM.dd hh:mm:ss", QObject *parent =0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:

private:
    QString _timeFormat;
};

#endif // DATETIMEDELEGATE_H
