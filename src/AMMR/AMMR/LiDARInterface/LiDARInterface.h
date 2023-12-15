/**
 * @file LiDARInterface.h
 * @brief LiDAR Interface header file
 * 
 */

#ifndef LIDARINTERFACE_H
#define LIDARINTERFACE_H

#include "LiDARGetter/LiDARGetter.h"

#include <thread>

/**
 * @brief The class for LiDAR interface
 * 
 */
class LiDARInterface
{
public:
  LiDARInterface();
  ~LiDARInterface();

  // subclass
  LiDARGetter *mpLiDARGetter;

  //ros
  void StartSubFromLiDAR(string strScanTopic);

  //sub_check
  bool mbStart_sub_flag = false;
};

#endif // LIDARINTERFACE_H