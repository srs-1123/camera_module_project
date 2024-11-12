#include "camera_module.h"

int main() {
    CameraModule camera;
    camera.captureFrame("photo.jpg");
    return 0;
}