#ifndef ASSETMINTERFACE_H
#define ASSETMINTERFACE_H

#include <QString>
#include <QDebug>

class AssetMInterface {
public:

    virtual QString AName(QString)=0;
    virtual QString AType(QString)=0;
    virtual QString ADiscription(QString)=0;
    virtual QString ASrNo(QString)=0;
    virtual QString AManufature(QString)=0;
    virtual QString AOwner(QString)=0;
    virtual QString AModel(QString)=0;
    virtual QString ACondition(QString)=0;
    virtual QString ALocation(QString)=0;
    virtual QString ASite(QString)=0;
    virtual QString AImage(QString)=0;
    virtual void get(QMap<QString,QString>)=0;
};

#endif // ASSETMINTERFACE_H


//Virtual function


//Base class//
