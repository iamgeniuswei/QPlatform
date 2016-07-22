#ifndef QPUILINEEDIT_H
#define QPUILINEEDIT_H

#include <QLineEdit>
class QPUILineEditPrivate;
class QPUILineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit QPUILineEdit(QWidget *parent = 0);
//    explicit

signals:

public slots:

protected slots:
    void regularValidation(const QString& );

private:
    QPUILineEditPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUILineEdit)
};

#endif // QPUILINEEDIT_H
