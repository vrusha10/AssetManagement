#include "assetmrecord.h"
#include "ui_assetmrecord.h"
#include "assetmmainwindow.h"   //go back mainwindow
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include<QStandardItem>
#include <QAbstractItemModel>
#include <QMessageBox>


AssetMMainWindow *r;            //go back to mainwindow
std::unique_ptr<AssetMdbmanagerservice>rsql=std::unique_ptr<AssetMdbmanagerservice>(AssetMdbmanagerservice::creatInstance());     //passing db file data sql to assetrecord
std::unique_ptr<AssetMReport>pt(new AssetMReport());

AssetMRecord::AssetMRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssetMRecord)
{
    ui->setupUi(this);
}

AssetMRecord::~AssetMRecord()
{
    delete ui;
}

/**************************** go Back To MainWindow ********************************/
void AssetMRecord::on_RecordPageClose_clicked()
{
     hide();
     r=new AssetMMainWindow(this);
     r->show();
}
/**************************** go Back To MainWindow ********************************/

/**************************** Passing SqlDb data to tableview ********************************/
void AssetMRecord::dataSql()
{
     qDebug()<<"Data Table Display";
     rsql->sd.open();
     QSqlQuery *query=new QSqlQuery(rsql->sd);
     query->prepare("select * from AssetMInformation");
     query->exec();
//     tdata->setTable("AssetMInformation");
     tdata->setQuery (*query);
//     tdata->setEditStrategy(QSqlTableModel::OnManualSubmit);
//     tdata->select();
     ui->tableView->setModel(tdata);
     ui->tableView->show();
     rsql->sd.close();
//     qDebug()<<(tdata->rowCount());
//     qDebug()<<(tdata->columnCount());


//     QSqlDatabase sd = QSqlDatabase::addDatabase("QSQLITE");
//      sd.setDatabaseName("sd.db");
//     //rsql->sd.open();
//      QSqlTableModel *tdata = new QSqlTableModel();
//       rsql->sd.open();
////       tdata->setTable(*tdata);
////      tdata->setData(rsql);

//      tdata->setTable("AssetMInformation");
//      tdata->setEditStrategy(QSqlTableModel::OnManualSubmit);
//      tdata->select();
//      tdata->setHeaderData(0, Qt::Horizontal, tr("Row1"));
//      tdata->setHeaderData(1, Qt::Horizontal, tr("Row2"));

//      ui->tableView->setModel(tdata);
//      ui->tableView->show();
//      rsql->sd.close();
}
/**************************** Passing SqlDb data to tableview ********************************/


void AssetMRecord::on_pushButton_Report_clicked()
{
    int rc=tdata->rowCount();
    int cc=tdata->columnCount();
    int tableindex=ui->tableView->selectionModel()->currentIndex().row();
    QString count[100];
    for(int i=0;i<cc;i++)
    {
        count[i]=ui->tableView->model()->data(ui->tableView->model()->index(tableindex,i)).toString();
//      count[i]=ui->tableView->tdata()->storedReport(ui->tableView->model()->index(tableindex,i).toString());
    }
    qDebug()<<"Data Access in table";

    if(pt->pdfData(cc,count)==true)
    {
        QMessageBox::information(this,"","Data Printed Sucessfully");
    }
    else {
        QMessageBox::warning(this,"","Choose Asset Name");
    }
}

void AssetMRecord::on_Back_Button_clicked()
{
    close();
}

