#include "datetimedelegate.h"
#include <QDateTime>
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItemV3>
#include <QStyleOptionViewItemV2>
#include <QApplication>
DateTimeDelegate::DateTimeDelegate(const QString timeFormat, QObject *parent) :
    QStyledItemDelegate(parent)
{
    _timeFormat = timeFormat;
}

void DateTimeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int dtVal = index.model()->data(index, Qt::DisplayRole).toInt();
    QDateTime time = QDateTime::fromTime_t(dtVal);
    QString indexValue = tr("Data not set");

    if(time.isValid()
         && !time.isNull())
    {
        indexValue = time.toString(_timeFormat);
    }
    if(0 == time.toTime_t())
    {
        indexValue = "0";
    }
    painter->save();
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, QBrush(QColor(155,189,239)));
        painter->setPen(Qt::white);
        QStyleOptionViewItem myOption = option;
        myOption.showDecorationSelected = true;
        myOption.displayAlignment = Qt::AlignCenter|Qt::AlignVCenter;
        QApplication::style()->drawItemText(painter, myOption.rect, myOption.displayAlignment, QApplication::palette(), true, indexValue);
        painter->restore();

    }
    else
    {
        painter->setPen(Qt::black);
        QStyleOptionViewItem myOption = option;
        myOption.showDecorationSelected = true;
        myOption.displayAlignment = Qt::AlignCenter|Qt::AlignVCenter;
        QApplication::style()->drawItemText(painter, myOption.rect, myOption.displayAlignment, QApplication::palette(), true, indexValue);
        painter->restore();
    }
}


