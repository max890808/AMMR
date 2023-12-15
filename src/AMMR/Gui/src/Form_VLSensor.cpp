#include "Form_VLSensor.h"
#include <ui_Form_AMMR.h>

Form_VLSensor::Form_VLSensor(Ui::Form_AMMR *_ui, QObject *parent):QObject(parent)
{ 
    ui = _ui;

    mnColorWidth = ui->Color_Graphics->width();
    mnColorHeight = ui->Color_Graphics->height();
    mgpColorItem = mgsColorScene.addPixmap(QPixmap(mnColorWidth, mnColorHeight));
    ui->Color_Graphics->setScene(&mgsColorScene);
    ui->Color_Text_Info->setText(QString(""));

    mnDepthWidth = ui->Depth_Graphics->width();
    mnDepthHeight =ui->Depth_Graphics->height();
    mgpDepthItem = mgsDepthScene.addPixmap(QPixmap(mnDepthWidth, mnDepthHeight));
    ui->Depth_Graphics->setScene(&mgsDepthScene);
    ui->Depth_Text_Info->setText(QString(""));

    // LiDAR 1
    mnLiDAR1Width = ui->LiDAR1_Graphics->width();
    mnLiDAR1Height =ui->LiDAR1_Graphics->height();
    mnLiDAR1ImgSize = (mnLiDAR1Width>mnLiDAR1Height)?mnLiDAR1Height:mnLiDAR1Width;
    mgpLiDAR1Item = mgsLiDAR1Scene.addPixmap(QPixmap(mnLiDAR1Width, mnLiDAR1Height));
    ui->LiDAR1_Graphics->setScene(&mgsLiDAR1Scene);
    ui->LiDAR1_Text_Info->setText(QString(""));

    mbLiDAR1Invert = ui->LiDAR1_Btn_InvertZ->isChecked();
    mbLiDAR1Lines = ui->LiDAR1_Btn_ShowLines->isChecked();

    mnLiDAR1Res = ui->LiDAR1_Slider_Range->value();
    string strMeters1 = "± "+to_string(mnLiDAR1Res)+" m";
    ui->LiDAR1_Label_Range ->setText(QString::fromStdString(strMeters1));

    // LiDAR 2
    mnLiDAR2Width = ui->LiDAR2_Graphics->width();
    mnLiDAR2Height =ui->LiDAR2_Graphics->height();
    mnLiDAR2ImgSize = (mnLiDAR2Width>mnLiDAR2Height)?mnLiDAR2Height:mnLiDAR2Width;
    mgpLiDAR2Item = mgsLiDAR2Scene.addPixmap(QPixmap(mnLiDAR2Width, mnLiDAR2Height));
    ui->LiDAR2_Graphics->setScene(&mgsLiDAR2Scene);
    ui->LiDAR2_Text_Info->setText(QString(""));

    mbLiDAR2Invert = ui->LiDAR2_Btn_InvertZ->isChecked();;
    mbLiDAR2Lines = ui->LiDAR2_Btn_ShowLines->isChecked();

    mnLiDAR2Res = ui->LiDAR2_Slider_Range->value();
	string strMeters2 = "± "+to_string(mnLiDAR2Res)+" m";
	ui->LiDAR2_Label_Range ->setText(QString::fromStdString(strMeters2));
}

void Form_VLSensor::on_LiDAR1_Btn_InvertZ_toggled(bool state)
{
    mlLiDARView.lock();
    mbLiDAR1Invert = state;
    mlLiDARView.unlock();
}

void Form_VLSensor::on_LiDAR1_Btn_ShowLines_toggled(bool state)
{
    mlLiDARView.lock();
    mbLiDAR1Lines = state;
    mlLiDARView.unlock();
}

void Form_VLSensor::on_LiDAR1_Slider_Range_valueChanged(int nSliderValue)
{
    string strMeters;

    mlLiDARView.lock();
    mnLiDAR1Res = nSliderValue;
	strMeters = "± "+to_string(nSliderValue)+" m";
    mlLiDARView.unlock();

    ui->LiDAR1_Label_Range ->setText(QString::fromStdString(strMeters));
}

void Form_VLSensor::on_LiDAR2_Btn_InvertZ_toggled(bool state)
{
    mlLiDARView.lock();
    mbLiDAR2Invert = state;
    mlLiDARView.unlock();
}

void Form_VLSensor::on_LiDAR2_Btn_ShowLines_toggled(bool state)
{
    mlLiDARView.lock();
    mbLiDAR2Lines = state;
    mlLiDARView.unlock();
}

void Form_VLSensor::on_LiDAR2_Slider_Range_valueChanged(int nSliderValue)
{
    string strMeters;

    mlLiDARView.lock();
    mnLiDAR2Res = nSliderValue;
	strMeters = "± "+to_string(nSliderValue)+" m";
    mlLiDARView.unlock();

    ui->LiDAR2_Label_Range ->setText(QString::fromStdString(strMeters));
}

/**
 * @brief Display
 * @note  Color: BGR888 -> RGB888
 * @note  Depth: 16UC1 -> 8UC1
 * 
 */
void Form_VLSensor::Display()
{
    // Color
    cv::Mat cvColor;
    mpAMMR->mpVisionInterface->mpImageGetter->GetColorImg(cvColor);
    if(!cvColor.empty())
    {
        cv::cvtColor(cvColor, cvColor, cv::COLOR_BGR2RGB);
        QPixmap pixColor = QPixmap::fromImage(QImage(cvColor.data, cvColor.cols, cvColor.rows, cvColor.step, QImage::Format_RGB888));
        pixColor = pixColor.scaled(QSize(mnColorWidth, mnColorHeight), Qt::KeepAspectRatio);
        mgpColorItem->setPixmap(pixColor);
    }

    tCameraInfo tColorInfo;
    if(mpAMMR->mpVisionInterface->mpImageGetter->GetColorInfo(&tColorInfo))
    {
        QString strInfo;
        GenerateCameraInfoText(&tColorInfo, strInfo);
        ui->Color_Text_Info->setText(strInfo);
    }

    // Depth
    cv::Mat cvDepth;
    mpAMMR->mpVisionInterface->mpImageGetter->GetDepthImg(cvDepth);
    if(!cvDepth.empty())
    {
        cvDepth.convertTo(cvDepth, CV_8UC1, 1/256.0);
        QPixmap pixDepth = QPixmap::fromImage(QImage(cvDepth.data, cvDepth.cols, cvDepth.rows, cvDepth.step, QImage::Format_Grayscale8));
        pixDepth = pixDepth.scaled(QSize(mnDepthWidth, mnDepthHeight), Qt::KeepAspectRatio);
        mgpDepthItem->setPixmap(pixDepth);
    }

    tCameraInfo tDepthInfo;
    if(mpAMMR->mpVisionInterface->mpImageGetter->GetDepthInfo(&tDepthInfo))
    {
        QString strInfo;
        GenerateCameraInfoText(&tDepthInfo, strInfo);
        ui->Depth_Text_Info->setText(strInfo);
    }

    // LiDAR
    cv::Mat cvLiDAR1, cvLiDAR2;
    if(mlLiDARView.try_lock())
    {
        cvLiDAR1 = mpAMMR->mpLiDARInterface1->mpLiDARGetter->GetScanImage(mbLiDAR1Invert, mbLiDAR1Lines, mnLiDAR1Res, mnLiDAR1ImgSize);
        cvLiDAR2 = mpAMMR->mpLiDARInterface2->mpLiDARGetter->GetScanImage(mbLiDAR2Invert, mbLiDAR2Lines, mnLiDAR2Res, mnLiDAR2ImgSize);

        mlLiDARView.unlock();
    }

    if(!cvLiDAR1.empty())
    {
        cvtColor(cvLiDAR1,cvLiDAR1,CV_BGR2RGB);
        QPixmap pixLiDAR1 = QPixmap::fromImage(QImage(cvLiDAR1.data, cvLiDAR1.cols, cvLiDAR1.rows, cvLiDAR1.step, QImage::Format_RGB888));
        pixLiDAR1 = pixLiDAR1.scaled(QSize(mnLiDAR1Width, mnLiDAR1Height), Qt::KeepAspectRatio);
        mgpLiDAR1Item->setPixmap(pixLiDAR1);
    }

    if(!cvLiDAR2.empty())
    {
        cvtColor(cvLiDAR2,cvLiDAR2,CV_BGR2RGB);
        QPixmap pixLiDAR2 = QPixmap::fromImage(QImage(cvLiDAR2.data, cvLiDAR2.cols, cvLiDAR2.rows, cvLiDAR2.step, QImage::Format_RGB888));
        pixLiDAR2 = pixLiDAR2.scaled(QSize(mnLiDAR2Width, mnLiDAR2Height), Qt::KeepAspectRatio);
        mgpLiDAR2Item->setPixmap(pixLiDAR2);
    }

    tLiDARInfo tLiDAR1Info, tLiDAR2Info;
    if(mpAMMR->mpLiDARInterface1->mpLiDARGetter->GetInfo(&tLiDAR1Info))
    {
        QString strInfo;
        GenerateScanInfoText(&tLiDAR1Info, strInfo);
        ui->LiDAR1_Text_Info->setText(strInfo);
    }

    if(mpAMMR->mpLiDARInterface2->mpLiDARGetter->GetInfo(&tLiDAR2Info))
    {
        QString strInfo;
        GenerateScanInfoText(&tLiDAR2Info, strInfo);
        ui->LiDAR2_Text_Info->setText(strInfo);
    }
}

inline void Form_VLSensor::GenerateScanInfoText(tLiDARInfo *pLiDARInfo, QString &strInfo)
{
    strInfo = QString("Range -\n");
    strInfo += QString("  Min: ")+QString::number(pLiDARInfo->fRangeMin, 'd', 2)+QString("\n");
    strInfo += QString("  Max: ")+QString::number(pLiDARInfo->fRangeMax, 'd', 2)+QString("\n\n");
    strInfo += QString("# of scan -\n");
    strInfo += QString("  All: ")+QString::number(pLiDARInfo->nNumScan, 'd', 2)+QString("\n");
    strInfo += QString("  Valid: ")+QString::number(pLiDARInfo->nValidScan, 'd', 2)+QString("\n\n");
    strInfo += QString("Angle -\n");
    strInfo += QString("  Start: ")+QString::number(pLiDARInfo->fAngleStart, 'd', 2)+QString("\n");
    strInfo += QString("  End: ")+QString::number(pLiDARInfo->fAngleEnd, 'd', 2)+QString("\n");
    strInfo += QString("  : ")+QString::number(pLiDARInfo->fAngleIncrement, 'd', 2);
}

inline void Form_VLSensor::GenerateCameraInfoText(tCameraInfo *pCameraInfo, QString &strInfo)
{
    strInfo = QString("Resolution -\n");
    strInfo += QString("  ")+QString::number(pCameraInfo->nWidth)+QString("x")+QString::number(pCameraInfo->nHeight)+QString("\n\n");
    strInfo += QString("Intrinsic -\n");
    strInfo += QString("  FX: ")+QString::number(pCameraInfo->fFX, 'd', 2)+QString("\n");
    strInfo += QString("  FY: ")+QString::number(pCameraInfo->fFY, 'd', 2)+QString("\n");
    strInfo += QString("  CX: ")+QString::number(pCameraInfo->fCX, 'd', 2)+QString("\n");
    strInfo += QString("  CY: ")+QString::number(pCameraInfo->fCY, 'd', 2)+QString("\n");
    strInfo += QString("  K1: ")+QString::number(pCameraInfo->fK1, 'd', 2)+QString("\n");
    strInfo += QString("  K2: ")+QString::number(pCameraInfo->fK2, 'd', 2)+QString("\n");
    strInfo += QString("  P1: ")+QString::number(pCameraInfo->fP1, 'd', 2)+QString("\n");
    strInfo += QString("  P2: ")+QString::number(pCameraInfo->fP2, 'd', 2)+QString("\n");
    strInfo += QString("  K3: ")+QString::number(pCameraInfo->fK3, 'd', 2);
}

void Form_VLSensor::isOK(bool checked, QWidget *widget)
{
	if (checked == true)
		Checked(widget);
	else
		UnChecked(widget);
}

void Form_VLSensor::Checked(QWidget *widget)
{
	widget->setStyleSheet("background-color: rgb(125, 255, 125);");
}

void Form_VLSensor::UnChecked(QWidget *widget)
{
	widget->setStyleSheet("background-color: rgb(255, 125, 125);");
}
