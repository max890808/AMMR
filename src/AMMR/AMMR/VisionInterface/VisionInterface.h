/**
 * @file VisionInterface.h
 * @brief Vision Interface header file
 * 
 */

#ifndef VISIONINTERFACE_H
#define VISIONINTERFACE_H

#include "ImageGetter/ImageGetter.h"
#include "ArUcoProcessing/ArUcoProcessing.h"

#include <thread>

/**
 * @brief The class for Vision interface
 * 
 */
class VisionInterface
{
public:
  VisionInterface();
  ~VisionInterface();

  // subclas
  ImageGetter *mpImageGetter;
	ArUcoProcessing * mpArUcoProcessing;
  
  //ros
  void StartSubFromRGBD(string strColorTopic, string strDepthTopic, string strColorInfo, string strDepthInfo);

  //sub_check
  bool mbStart_sub_flag = false;
};

#endif // VISIONINTERFACE_H