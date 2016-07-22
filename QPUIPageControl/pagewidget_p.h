#ifndef PAGEWIDGET_P_H
#define PAGEWIDGET_P_H
#include <QObject>
class QPUIPageControl;
class QTableView;
class QPUIPageControlToolBar;
class QVBoxLayout;
class QMenu;
class QSqlQueryModel;
class QHeaderView;
class QPUIPageControlPrivate
{
    Q_DECLARE_PUBLIC(QPUIPageControl)
public:
    QPUIPageControlPrivate(QPUIPageControl *parent = 0)
        :q_ptr(parent),\
          mainLayout(nullptr), \
          dataView(nullptr),\
          dataOperation(nullptr),\
          commandMenu(nullptr),\
          headView(nullptr),\
          _totalPage(0), \
          _totalRecord(0), \
          _currentPage(0), \
          _recordIndex(0), \
          _recordStep(100), \
          _dataModel(nullptr)
    {

    }

    ~QPUIPageControlPrivate()
    {

    }
    void init();

public:
    QVBoxLayout *mainLayout;
    QTableView *dataView;
    QPUIPageControlToolBar *dataOperation;
    QMenu *commandMenu;
    //data member
    QSqlQueryModel *_dataModel;
    QSqlQueryModel *tempModel;
    QHeaderView  *headView;
    int _totalPage;
    int _totalRecord;
    int _currentPage;
    int _recordStep;
    int _recordIndex;
    QString _tableName;
    QString _realTableName;
    QString _condition;
    QString _connName;
    QStringList _headerLabel;

private:
    QPUIPageControl *const q_ptr;
};

#endif // PAGEWIDGET_P_H
