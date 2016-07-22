#include "no_focus_delegate.h"

#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>

NofocusDelegate::NofocusDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void NofocusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem itemOption(option);
    if(itemOption.state & QStyle::State_HasFocus)
    {
        itemOption.state=itemOption.state^QStyle::State_HasFocus;
    }
    QStyledItemDelegate::paint(painter,itemOption,index);
}
