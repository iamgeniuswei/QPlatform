#ifndef TESTSCORLLAREA_H
#define TESTSCORLLAREA_H

#include <QWidget>

namespace Ui {
class TestScorllArea;
}

class TestScorllArea : public QWidget
{
    Q_OBJECT

public:
    explicit TestScorllArea(QWidget *parent = 0);
    ~TestScorllArea();

private:
    Ui::TestScorllArea *ui;
};

#endif // TESTSCORLLAREA_H
