#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int g_slider_min;
int g_slider_max;

void on_trackbar(int, void*)
{
    cout << "Current Threshold Value: " << g_slider_min << endl;
}

int main()
{
    // Initialize variables
    Mat edges;
    VideoCapture cap = VideoCapture(0);
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open video capture device." << endl;
        return -1;
    }

    // Set initial values for trackbars
    g_slider_min = 0;
    g_slider_max = 255;

    // Create a window for displaying the thresholded image
    namedWindow("Threshold", WINDOW_AUTOSIZE);

    // Create a trackbar for adjusting the threshold value
    createTrackbar("Threshold", "Threshold", &g_slider_min, g_slider_max, on_trackbar);

    // Main loop for processing frames
    for (;;) {
        Mat frame;
        cap >> frame;

        // Convert the frame to grayscale
        cvtColor(frame, edges, COLOR_BGR2GRAY);

        // Apply Gaussian blur to the grayscale image
        GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);

        // Apply Canny edge detection using the current threshold value
        Canny(edges, edges, g_slider_min, 30, 3);

        // Display the thresholded image
        imshow("Threshold", edges);

        // Check for key press to exit
        if (waitKey(30) >= 0)
            break;
    }

    return 0;
}
