#ifndef CAMERA_MODULE_H
#define CAMERA_MODULE_H

#include <opencv2/opencv.hpp>
#include <string>

class CameraModule {
public:
    CameraModule(int deviceIndex = 0);
    ~CameraModule();
    bool captureFrame(const std::string& filename);

private:
    cv::VideoCapture cap;
};

#endif // CAMERA_MODULE_H