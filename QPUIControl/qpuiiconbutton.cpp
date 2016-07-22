#include "qpuiiconbutton.h"
#include "private/qpuiiconbutton_p.h"
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
QPUIIconButton::QPUIIconButton(QWidget *parent) : QPushButton(parent), d_ptr(new QPUIIconButtonPrivate(this))
{

}

QString QPUIIconButton::iconPath() const
{
    Q_D(const QPUIIconButton);
    return d->iconPath;
}

void QPUIIconButton::setIconPath(const QString &_iconPath)
{
    Q_D(QPUIIconButton);
    d->iconPath = _iconPath;
    setBtnIcon(d->iconPath);
}

void QPUIIconButton::setBtnIcon(const QString &_iconPath, int num)
{
    Q_D(QPUIIconButton);
    d->iconList.clear();
    if(num > 0)
    {
        QPixmap tmpPixmap(_iconPath);
        d->iconListSize = num;
        for(int i=0; i!= num; i++)
        {
            d->iconList.append(tmpPixmap.copy(i*(tmpPixmap.width()/num), \
                                           0,\
                                           tmpPixmap.width()/num,\
                                           tmpPixmap.height()));
        }
        if(d->iconList.size() == num)
        {
            d->currentIcon = d->iconList.at(0);
            setFixedSize(d->currentIcon.size());
        }
    }
}

void QPUIIconButton::setBtnStatus(QPUIIconButton::BUTTONSTATUS _status)
{
    Q_D(QPUIIconButton);
    if(isEnabled() && d->iconList.size() == d->iconListSize)
    {
        switch (_status) {
        case NORMAL:
            d->currentIcon = d->iconList.at(0);
            break;
        case ENTER:
            d->currentIcon = d->iconList.at(1);
            break;
        case LEAVE:
            d->currentIcon = d->iconList.at(0);
            break;
        case PRESS:
            d->currentIcon = d->iconList.at(2);
            break;
        case RELEASE:
            break;
        case DISABLE:
            d->currentIcon = d->iconList.at(3);
        default:
            break;
        }
    }
    update();
}

void QPUIIconButton::paintEvent(QPaintEvent *)
{
    Q_D(QPUIIconButton);
    QPainter painter(this);
    painter.drawPixmap(rect(), d->currentIcon);
}

void QPUIIconButton::enterEvent(QEvent *)
{
    setBtnStatus(ENTER);
}

void QPUIIconButton::leaveEvent(QEvent *)
{
    setBtnStatus(LEAVE);
}

void QPUIIconButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton)
    {
        e->ignore();
        return;
    }
    if(hitButton(e->pos()))
    {
        setBtnStatus(PRESS);
        setDown(true);
        e->accept();
    }
    else
        e->ignore();
}

void QPUIIconButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton)
    {
        e->ignore();
        return;
    }
    if(!isDown())
    {
        e->ignore();
        return;
    }
    //TODO
    if(rect().contains(e->pos()))
    {
        setDown(false);
        if(this->isEnabled())
        {
            emit clicked();
        }
        if(rect().contains(e->pos()) && isDown())
            setBtnStatus(ENTER);
        else
            setBtnStatus(NORMAL);
        e->accept();
    }
    else
    {
        setBtnStatus(LEAVE);
        e->ignore();
    }
}

