#ifndef ASSETMMAINWINDOW_H
#define ASSETMMAINWINDOW_H

#include <QMainWindow>
#include "assetminformation.h"
#include "assetmrecord.h"
#include "AssetMInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AssetMMainWindow; }
QT_END_NAMESPACE

class AssetMMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    AssetMMainWindow(QWidget *parent = nullptr);
    ~AssetMMainWindow();

private slots:
    void on_MainWindowClose_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonView_clicked();

    void on_comboBox_location_currentIndexChanged(int index);

    void on_pushButtonUpload_clicked();

private:
    Ui::AssetMMainWindow *ui;
    std::unique_ptr<AssetMInterface>am=std::unique_ptr<AssetMInformation>(new AssetMInformation());   //base class pointer asscess derived class data
//    AssetMRecord


};
#endif // ASSETMMAINWINDOW_H
