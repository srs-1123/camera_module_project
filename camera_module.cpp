#include "camera_module.h"
#include <iostream>

CameraModule::CameraModule(int deviceIndex) : cap(deviceIndex) {
    if (!cap.isOpened()) {
        std::cerr << "カメラを開くことができませんでした" << std::endl;
        exit(EXIT_FAILURE);
    }
}

CameraModule::~CameraModule() {
    cap.release();
    cv::destroyAllWindows();
}

bool CameraModule::captureFrame(const std::string& filename) {
    cv::Mat frame;
    bool ret = cap.read(frame);

    if (ret) {
        cv::imwrite(filename, frame);
        std::cout << "写真を保存しました: " << filename << std::endl;
    } else {
        std::cerr << "フレームをキャプチャできませんでした" << std::endl;
    }

    return ret;
}