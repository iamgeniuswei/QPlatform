#ifndef DATETIMEDELEGATEWITHUSECS_H
#define DATETIMEDELEGATEWITHUSECS_H

#include <QStyledItemDelegate>
#include "pagewidget_global.h"
class PAGEWIDGETSHARED_EXPORT DateTimeDelegateWithUSecs : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DateTimeDelegateWithUSecs(const QString timeFormat = "yyyy.MM.dd hh:mm:ss", QObject *parent =0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

private:
    QString _timeFormat;

};

#endif // DATETIMEDELEGATEWITHUSECS_H
