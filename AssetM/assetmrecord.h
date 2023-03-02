#ifndef ASSETMRECORD_H
#define ASSETMRECORD_H

#include <QDialog>
#include "Sdbase/AssetMdbmanagerservice.h"
#include "Sdbase/AssetMdbmanagerserviceinterface.h"
#include "assetmreport.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class AssetMRecord;
}

class AssetMRecord : public QDialog
{
    Q_OBJECT

public:
    explicit AssetMRecord(QWidget *parent = nullptr);
    ~AssetMRecord();
    void dataSql();
    QSqlQuery *query=new QSqlQuery();

private slots:
    void on_RecordPageClose_clicked();
    void on_pushButton_Report_clicked();
//    void reorddata(QMap<QString,QString>);

    void on_Back_Button_clicked();

private:
    Ui::AssetMRecord *ui;
    QSqlQueryModel *tdata=new QSqlQueryModel();
};

#endif // ASSETMRECORD_H
