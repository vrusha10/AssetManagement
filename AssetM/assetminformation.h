#ifndef ASSETMINFORMATION_H
#define ASSETMINFORMATION_H

#include "AssetMInterface.h"
//#include "Sdbase/AssetMdbmanagerservice.h"
//#include "Sdbase/AssetMdbmanagerserviceinterface.h"

class AssetMInformation:public AssetMInterface
{
public:
    AssetMInformation();
    QString AName(QString);
    QString AType(QString);
    QString ADiscription(QString);
    QString ASrNo(QString);
    QString AManufature(QString);
    QString AOwner(QString);
    QString AModel(QString);
    QString ACondition(QString);
    QString ALocation(QString);
    QString ASite(QString);
    QString AImage(QString);
    void get(QMap<QString,QString>);


};

#endif // ASSETMINFORMATION_H



//Derived Class//
