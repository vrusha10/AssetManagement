#pragma once

#include "AssetMdbmanagerserviceinterface.h"
#include<iostream>
#include<QSqlDatabase>
#include<QString>
class AssetMdbmanagerservice:public AssetMdbmanagerserviceinterface
{ 
private:
   AssetMdbmanagerservice();
   static AssetMdbmanagerservice *single;


public:

    static AssetMdbmanagerservice *creatInstance();
    bool getData(QMap<QString,QString> sdata);
    bool isOpen() const;
    bool createTable(const QString&);
    bool dataExist(const QString& name) const;
    bool removeAllData();
  QSqlDatabase sd;
};


//Derived class Db






//    bool addPerson(const QString& name);
//    bool removePerson(const QString& name);
//        void printAllPersons() const;
