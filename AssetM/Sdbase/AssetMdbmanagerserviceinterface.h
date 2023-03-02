#pragma once

#include<iostream>
#include<QSqlDatabase>
#include<QString>
class AssetMdbmanagerserviceinterface
{
public:

    virtual bool getData(QMap<QString,QString>)=0;
    virtual bool isOpen() const=0;
    virtual bool createTable(const QString&)=0;
    virtual bool dataExist(const QString& name) const=0;
    virtual bool removeAllData()=0;
};



//Base class pure virtual function
