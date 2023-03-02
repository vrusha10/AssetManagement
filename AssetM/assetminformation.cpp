#include "assetminformation.h"
#include "Sdbase/AssetMdbmanagerservice.h"
#include "Sdbase/AssetMdbmanagerserviceinterface.h"
#include <QString>
#include <QDebug>
std::unique_ptr<AssetMdbmanagerserviceinterface>dm=std::unique_ptr<AssetMdbmanagerservice>(AssetMdbmanagerservice::creatInstance());


AssetMInformation::AssetMInformation(){}
QString AssetMInformation::AName(QString name)
{
    QString Name =name;
    return name;
}

QString AssetMInformation::AType(QString type)
{
    QString Type =type;
    return Type;
}

QString AssetMInformation::ADiscription(QString discription)
{
    QString Discription =discription;
    return Discription;
}

QString AssetMInformation::ASrNo(QString srno)
{
    QString SrNo =srno;
    return SrNo;
}

QString AssetMInformation::AManufature(QString manufature)
{
    QString Manufature =manufature;
    return Manufature;
}

QString AssetMInformation::AOwner(QString owner)
{
    QString Owner =owner;
    return Owner;
}

QString AssetMInformation::AModel(QString model)
{
    QString Model =model;
    return Model;
}

QString AssetMInformation::ACondition(QString condition)
{
    QString Condition =condition;
    return Condition;
}

QString AssetMInformation::ALocation(QString location)
{
    QString Location =location;
    return Location;
}

QString AssetMInformation::ASite(QString site)
{
    QString Site =site;
    return Site;
}

QString AssetMInformation::AImage(QString image)
{
    QString Image=image;
    return Image;
}

/************Passing MainWindow data using map************/
void AssetMInformation::get(QMap<QString, QString>maindata)
{
    QMap<QString,QString>d;
    d=maindata;
//    foreach (auto value, d)
//    {
//        qDebug()<<value<<" ";      //check here our data is passed or not
//    }
    dm->getData(d);
}
/************Passing MainWindow data using map************/
