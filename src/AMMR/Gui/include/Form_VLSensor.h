#ifndef FORM_VLSENSOR_H
#define FORM_VLSENSOR_H

#include <QtCore/QObject>
#include <QLabel>
#include <QMutex>
#include <QGraphicsScene>
#include <QtWidgets/QGraphicsPixmapItem>
#include <thread>
#include <opencv2/core/core.hpp>

#include "AMMR/AMMR.h"

namespace Ui {
class Form_AMMR;
}

class Form_VLSensor : public QObject
{
    Q_OBJECT

public:
    Form_VLSensor(Ui::Form_AMMR *_ui, QObject *parent = nullptr);
    ~Form_VLSensor(){};
    void SetAMMR(AMMR *_AMMR)
    {
        mpAMMR = _AMMR;
        mpAMR = _AMMR->mpAMR;
    }
    void Display();

private slots:
    void on_LiDAR1_Btn_InvertZ_toggled(bool state);
    void on_LiDAR1_Btn_ShowLines_toggled(bool state);
    void on_LiDAR1_Slider_Range_valueChanged(int nSliderValue);
    void on_LiDAR2_Btn_InvertZ_toggled(bool state);
    void on_LiDAR2_Btn_ShowLines_toggled(bool state);
    void on_LiDAR2_Slider_Range_valueChanged(int nSliderValue);

private:
    inline void GenerateScanInfoText(tLiDARInfo *pLiDARInfo, QString &strInfo);
    inline void GenerateCameraInfoText(tCameraInfo *pCameraInfo, QString &strInfo);
    void isOK(bool checked, QWidget *widget);
    void Checked(QWidget *widget);
    void UnChecked(QWidget *widget);

// Vision, LiDAR form
private:
    int mnColorWidth, mnColorHeight;
    QGraphicsScene mgsColorScene;
    QGraphicsPixmapItem *mgpColorItem;

    int mnDepthWidth, mnDepthHeight;
    QGraphicsScene mgsDepthScene;
    QGraphicsPixmapItem *mgpDepthItem;

    bool mbLiDAR1Invert, mbLiDAR1Lines;
    int mnLiDAR1Width, mnLiDAR1Height, mnLiDAR1Res, mnLiDAR1ImgSize;
    QGraphicsScene mgsLiDAR1Scene;
    QGraphicsPixmapItem *mgpLiDAR1Item;

    bool mbLiDAR2Invert, mbLiDAR2Lines;
    int mnLiDAR2Width, mnLiDAR2Height, mnLiDAR2Res, mnLiDAR2ImgSize;
    QGraphicsScene mgsLiDAR2Scene;
    QGraphicsPixmapItem *mgpLiDAR2Item;

// System
private:
    Ui::Form_AMMR *ui;
    AMMR *mpAMMR;
    AMR *mpAMR;
    QMutex mlLiDARView;
};

#endif // FORM_VLSENSOR_H