#ifndef NO_FOCUS_DELEGATE_H
#define NO_FOCUS_DELEGATE_H

#include <QObject>
#include <QAbstractItemDelegate>
#include <QStyledItemDelegate>
class NofocusDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit NofocusDelegate(QObject *parent = 0);

protected:
    void paint(QPainter *painter,const QStyleOptionViewItem &option,const QModelIndex &index)const;
};

#endif // NO_FOCUS_DELEGATE_H
