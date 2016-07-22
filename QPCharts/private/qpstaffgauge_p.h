#ifndef QPSTAFFGAUGE_P
#define QPSTAFFGAUGE_P
#include <QObject>
#include <QPen>
#include <QFont>
class QPStaffGauge;
class QPStaffGaugePrivate
{
    Q_DECLARE_PUBLIC(QPStaffGauge)
public:
    QPStaffGaugePrivate(QPStaffGauge *parent = 0):
        showHorizontalLine(1), showVerticalLine(0), showHorizontalLabel(1), showVerticalLabel(0), q_ptr(parent)
    {}
    uint showHorizontalLine : 1;
    uint showVerticalLine : 1;
    uint showHorizontalLabel : 1;
    uint showVerticalLabel : 1;
    QPen linePen;
    QPen labelPen;
    QString verticalLabel;
    QString horizonLabel;
    QFont labelFont;

    void init();
private:
    QPStaffGauge *const q_ptr;
};
#endif // QPSTAFFGAUGE_P

