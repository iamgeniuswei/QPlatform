#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include "pagewidget_global.h"
#include "qpuiwidget.h"

class QPUIPageControlPrivate;
class QPQueryModel;
class QTableView;
class QMenu;
class QAbstractItemDelegate;
class PAGEWIDGETSHARED_EXPORT QPUIPageControl : public QPUIWidget
{
    Q_OBJECT
    Q_PROPERTY(int recordIndex READ recordIndex WRITE setRecordIndex)
    Q_PROPERTY(int recordStep READ recordStep WRITE setRecordStep)
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName)
    Q_PROPERTY(QString realTableName READ realTableName WRITE setRealTableName)
    Q_PROPERTY(QString condition READ condition WRITE setCondition)
    Q_PROPERTY(QString connName READ connName WRITE setConnName)
    Q_PROPERTY(QStringList headerLabel READ headerLabel WRITE setHeaderLabel)
public:
    explicit QPUIPageControl(QWidget *parent = 0);
    ~QPUIPageControl();
    void setPageData();
    void setPageCount();
    bool queryPageData();

    QVariant getSelectedFieldValue(int column);

    int recordIndex() const;
    void setRecordIndex(const int recordIndex);

    int recordStep() const;
    void setRecordStep(const int recordStep);

    QString tableName() const;
    void setTableName(const QString &tableName);

    QString realTableName() const;
    void setRealTableName(const QString &realTable);

    QString condition() const;
    void setCondition(const QString &condition);

    QString connName() const;
    void setConnName(const QString &connName);

    QStringList headerLabel() const;
    void setHeaderLabel(const QStringList &headerLabel);
    void setCommandMenu(QMenu *menu);
    QTableView *getTableView();



signals:
    void updateTotalRecord(int page, int record);
    void updateCurrentRecord(int start, int end);
    void getTargetIDByClicked(int);
    void getTargetIDByDoubleClicked(int);
    void getTargetIDByRightClicked(int);
    void updateBtnStatus(int status);


public slots:
    void showModelData(QPQueryModel *model);
    void showCountData(int count);
    void showErrorMsg();

    void showFirstPage();
    void showPrevPage();
    void showNextPage();
    void showLastPage();
    void switchPageTo(int page);

    void getRowIDByClicked();//get target Id
    void getRowIDByDoubleClicked();
    void mouseRightClicked(const QPoint &pos);
    void setItemDelegateForColumn(int column, QAbstractItemDelegate * delegate);
    void searchInitSlot();
    void viewSort(int column);

protected:
    void initilizeUI();
    void initilizeSignal();

private:
    void UpdateStatus();        //update button states

    QPUIPageControlPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPUIPageControl)
};

#endif // PAGEWIDGET_H
