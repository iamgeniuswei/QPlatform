#ifndef QPUIICONBUTTON_P
#define QPUIICONBUTTON_P
#include <QObject>

class QPUIIconButton;
class QPUIIconButtonPrivate
{
    Q_DECLARE_PUBLIC(QPUIIconButton)
public:
    QPUIIconButtonPrivate(QPUIIconButton *parent)
        :q_ptr(parent), iconListSize(4)
    {}
public:
    QPixmap currentIcon;
    QList<QPixmap> iconList;
    int iconListSize;
    QString iconPath;
private:
    QPUIIconButton *const q_ptr;
};
#endif // QPUIICONBUTTON_P

