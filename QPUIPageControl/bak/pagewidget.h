#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include "pagewidget_global.h"
#include "customwidget.h"
#include "sqlworkthread.h"
class IconButton;
class QLineEdit;
class QLabel;
class QTableView;
class QHBoxLayout;
class QVBoxLayout;
class SqlWorkThread;
class QSqlQueryModel;

class PAGEWIDGETSHARED_EXPORT PageWidget : public CustomWidget
{
    Q_OBJECT
    Q_PROPERTY(QString firstBtnIcon READ firstBtnIcon WRITE setFirstBtnIcon DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString prevBtnIcon READ prevBtnIcon WRITE setPrevBtnIcon DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString nextBtnIcon READ nextBtnIcon WRITE setNextBtnIcon DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString lastBtnIcon READ lastBtnIcon WRITE setLastBtnIcon DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(int recordIndex READ recordIndex WRITE setRecordIndex)
    Q_PROPERTY(int recordStep READ recordStep WRITE setRecordStep)
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName)
public:
    explicit PageWidget(QWidget *parent = 0);
    ~PageWidget();
    void setPageData();
    void setPageCount();
    bool queryPageData();


    QString firstBtnIcon() const;
    void setFirstBtnIcon(const QString &firstBtnIcon);

    QString prevBtnIcon() const;
    void setPrevBtnIcon(const QString &prevBtnIcon);

    QString nextBtnIcon() const;
    void setNextBtnIcon(const QString &nextBtnIcon);

    QString lastBtnIcon() const;
    void setLastBtnIcon(const QString &lastBtnIcon);

    int recordIndex() const;
    void setRecordIndex(int recordIndex);

    int recordStep() const;
    void setRecordStep(int recordStep);

    QString tableName() const;
    void setTableName(const QString &tableName);

public slots:
    void showModelData(QSqlQueryModel *model);
    void showCountData(int count);
    void firstBtnClicked();
    void prevBtnClicked();
    void nextBtnClicked();
    void lastBtnClicked();
    void OnSwitchPageButtonClick();// switch button clicked
/***********201506151137增加信号-zzl********/
    void getTargetID();//获取目标Id
    void turnDetail();//双击跳转到详细页面
    void updateData();//刷新数据
signals:
    void turnIndex(int);
    void returnTargetId(int);//双击获取ID信号
/***********201506151137增加信号-zzl********/
protected:
    void initilizeUI();
    void initilizeSignal();
protected:
    void keyPressEvent(QKeyEvent*event);

private:
    void constructOperateLayout();
    void constructTableView();

private:
    void UpdateStatus();        //刷新按钮状态

    //basic window element
    IconButton *firstBtn;
    IconButton *prevBtn;
    IconButton *nextBtn;
    IconButton *lastBtn;

    QLineEdit *switchPageLE;
    QLabel *totalPageLb;
    QLabel *currentPageLb;
    QLabel *totalRecordLb;
    QTableView *dataView;

    QHBoxLayout *operateLayout;
    QHBoxLayout *layoutA;
    QHBoxLayout *layoutB;
    QVBoxLayout *mainLayout;

    //auxiliary window element
    QLabel *totalPageTextLb;
    QLabel *pageTextLb;
    QLabel *totalRecordTextLb;
    QLabel *recordTextLb;

    //data member
    int _totalPage;
    int _totalRecord;
    int _currentPage;
    int _recordStep;
    int _recordIndex;       //从哪一条开始查的？
    QString _tableName;
//    QSqlQueryModel *model;

    //Q_PROPETRY
    QString _firstBtnIcon;
    QString _prevBtnIcon;
    QString _nextBtnIcon;
    QString _lastBtnIcon;

//    SqlWorkThread *threadA;
//    SqlWorkThread *threadB;
};

#endif // PAGEWIDGET_H
