#include <iostream>
#include <stdexcept>
#include <camera_driver/camera.h>

int main() {
    // Create a Camera instance
    Camera camera("Camera", "USB", 0, 60);

    // Get camera specs
    CameraInfo cameraInfo = camera.GetCameraSpecs();

    // Print camera info
    std::cout << "Camera Info:" << std::endl;
    std::cout << "Name: " << cameraInfo.name << std::endl;
    std::cout << "Type: " << cameraInfo.type << std::endl;
    std::cout << "Index: " << cameraInfo.index << std::endl;
    std::cout << "FPS: " << cameraInfo.fps << std::endl;

    try
    {
        cv::VideoCapture videoCapture(0);
        while (true)
        {
            // Capture a frame from the camera (assuming the camera is at index 0)
            cv::Mat frame = camera.CaptureFrame(videoCapture, cameraInfo.index);

            // Display the captured frame for 5 seconds
            camera.DisplayFrame("Camera Feed", frame);
        }
        
    }
    catch(std::exception &e)
    {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}