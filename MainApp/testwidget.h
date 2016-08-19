#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
class QLabel;
class QHBoxLayout;
class TestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = 0);

signals:

public slots:

    QLabel *getText() const;
    QLabel *getSep() const;
private:
    QLabel *text;
    QLabel *sep;
    QHBoxLayout *layout;
};

#endif // TESTWIDGET_H
