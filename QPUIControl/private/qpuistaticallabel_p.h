#ifndef QPUISTATICALLABEL_P
#define QPUISTATICALLABEL_P
#include "qpuiview_p.h"
class QPUIStaticalLabel;
class QLabel;
class QPUIStaticalLabelPrivate : public QPUIViewPrivate
{
public:
    QPUIStaticalLabelPrivate(QPUIStaticalLabel *parent = 0)
        : q_ptr(parent), QPUIViewPrivate(parent),staticalType(nullptr), staticalData(nullptr), staticalValue(0)
    {}
    void init();
public:
    QLabel *staticalType;
    QLabel *staticalData;
    int staticalValue;

private:
    QPUIStaticalLabel *const q_ptr;
};

#endif // QPUISTATICALLABEL_P

