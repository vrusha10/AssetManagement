#include "assetmreport.h"
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QString>


AssetMReport::AssetMReport()
{
   // qDebug()<<" Report Making Page";
}

bool AssetMReport::pdfData(int col,QString fill[])                  /*int column,QString fill[]*/
{
    bool success=true;
    int i=0;
    for(i=0;i<col;i++)
    {
        storedReport[i]=fill[i];
    }
     QPdfWriter pdf("/Users/Vrushabh/Desktop/AssetReport/Report.pdf");   //create new folder in your desktop and copy this folder path
     QPainter painter(&pdf);

     QFont f(QFont("Arial", 30));
     painter.drawText(100,0,"Asset Information");

     painter.setFont(f);
     //     painter.drawText(1900,800,"Asset Report");

     QFont f1("Calibric",12);
     painter.setFont(f1);
/*****************************Add Index*****************************/
     painter.drawText(100,600,"Name");
     painter.drawText(100,1000,"Type");
     painter.drawText(100,1400,"Description");
     painter.drawText(100,1800,"SerialNo");
     painter.drawText(100,2200,"Model");
     painter.drawText(100,2600,"Manufacture");
     painter.drawText(100,3000,"Location");
     painter.drawText(100,3400,"Site");
     painter.drawText(100,3800,"Condition");
     painter.drawText(100,4200,"Image");
     painter.drawText(100,4600,"Owner");
/*****************************Add Index*****************************/

/*****************************Add Colon After Name*****************************/
     painter.drawText(1300,600,":");
     painter.drawText(1300,1000,":");
     painter.drawText(1300,1400,":");
     painter.drawText(1300,1800,":");
     painter.drawText(1300,2200,":");
     painter.drawText(1300,2600,":");
     painter.drawText(1300,3000,":");
     painter.drawText(1300,3400,":");
     painter.drawText(1300,3800,":");
     painter.drawText(1300,4200,":");
     painter.drawText(1300,4600,":");
/*****************************Add Colon After Name*****************************/
/****************************Add TableData After Colon******************************/
    painter.drawText(1500,600,fill[0]);
    painter.drawText(1500,1000,fill[1]);
    painter.drawText(1500,1400,fill[2]);
    painter.drawText(1500,1800,fill[3]);
    painter.drawText(1500,2200,fill[4]);
    painter.drawText(1500,2600,fill[5]);
    painter.drawText(1500,3000,fill[6]);
    painter.drawText(1500,3400,fill[7]);
    painter.drawText(1500,3800,fill[8]);
    painter.drawText(1500,4200,fill[9]);
    painter.drawText(1500,4600,fill[10]);
    QPixmap image(fill[11]);
    painter.drawPixmap(5000,1600,image);
    painter.end();
    qDebug()<<" Generated Pdf";
    return success;
/*****************************Add TableData After Colon*****************************/

}
