#include "assetmmainwindow.h"
#include "./ui_assetmmainwindow.h"
#include "assetmrecord.h"  //we need to open record page
#include<QFileDialog>
#include<QString>
#include<QMessageBox>
#include<QMap>
QMap<QString,QString>m;

AssetMMainWindow::AssetMMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AssetMMainWindow)
{
    ui->setupUi(this);
}

AssetMMainWindow::~AssetMMainWindow()
{
    delete ui;
}


void AssetMMainWindow::on_MainWindowClose_clicked()
{
    close();
}

/**********************Information Fill*************************/
void AssetMMainWindow::on_pushButtonSave_clicked()
{
         QString name=ui->lineEdit_name->text();
         m.insert("Name",name);
         am->AName(m["name"]);
         ui->lineEdit_name->clear();

         QString type=ui->lineEdit_type->text();
         m.insert("Type",type);
         am->AType(m["type"]);
         ui->lineEdit_type->clear();

         QString manufacture=ui->lineEdit_Manufacture->text();
         m.insert("Manufacture",manufacture);
         am->AManufature(m["manufacture"]);
         ui->lineEdit_Manufacture->clear();

         QString description=ui->lineEdit_description->text();
         m.insert("Description",description);
         am->ADiscription(m["description"]);
         ui->lineEdit_description->clear();

         QString srno=ui->lineEdit_srNo->text();
         m.insert("SerialNo",srno);
         am->ASrNo(m["srno"]);
         ui->lineEdit_srNo->clear();

         QString model=ui->lineEdit_Model->text();
         m.insert("Model",model);
         am->AModel(m["model"]);
         ui->lineEdit_Model->clear();

         QString owner=ui->lineEdit_Owner->text();
         m.insert("Owner",owner);
         am->AOwner(m["owner"]);
         ui->lineEdit_Owner->clear();

         QString condition=ui->comboBox_condition->currentText();
         m.insert("Condition",condition);
         am->ACondition(m["condition"]);

         QString location=ui->comboBox_location->currentText();
         m.insert("Location",location);
         am->ALocation(m["location"]);

//         QString site=ui->lineEdit_Site->text();
//         m.insert("Site",site);
//          am->ASite(m["site"]);
//         ui->lineEdit_Site->clear();
         am->get(m);

         if(name=="" ||type==""||manufacture==""||description==""||srno==""||model==""||owner==""||condition==""||location=="")
         {
             QMessageBox::warning(this,"","Please Fill Information");
         }
         else {
             QMessageBox::information(this,"","Information Saved Sucessfully");
         }
}
/**********************Information Fill*************************/

/**********************Clicked and Open New Window*************************/
void AssetMMainWindow::on_pushButtonView_clicked()
{
   AssetMRecord *view;   //go to new window
   view=new AssetMRecord();
   hide();
   view->show();
   view->dataSql();
//   qDebug()<<" SQl To Record ";
}
/**********************Clicked and Open New Window*************************/


/**********************combobox to LineEdit integration*************************/
void AssetMMainWindow::on_comboBox_location_currentIndexChanged(int index)
{
    if(index==1)
    {
        QString s1="Tower S4,Magarpatta City To Koregaon Park,Back Side Road Cybercity,Magarpatta,Hadapsar Pune,Maharashtra - 411028";
        ui->lineEdit_Site->setText(s1);
        m.insert("Site",s1);
        am->ASite(m["s1"]);
    }
    if(index==2)
    {
        QString s2="#203,2nd Floor Rockdale Compound,Diamond Block,Somajiguda,Hyderabad,Telangana- 500082";
        ui->lineEdit_Site->setText(s2);
        m.insert("Site",s2);
        am->ASite(m["s2"]);
    }
}

/**********************combobox to LineEdit integration*************************/

/*******************Image*******************/

void AssetMMainWindow::on_pushButtonUpload_clicked()
{
    QString picpath=QFileDialog::getOpenFileName(this,tr("(open file"),"c://","JPG File(*.jpg);;PNG File(*.png)");
     ui->label_2->setPixmap(picpath);
     ui->label_2->setScaledContents(true);
     m.insert("Image",picpath);
     if(picpath=="")
     {
        QMessageBox::warning(this,"","Pic Not Uploaded");
     }
     else {
        QMessageBox::information(this,"","Pic Uploaded Sussesfully");
     }
}

/*******************Image*******************/
