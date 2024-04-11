#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int threshold_value = 0;
int threshold_type = 3;
int max_value = 255;
int max_type = 4;
int max_binary_value = 255;

Mat src, src_gray, dst;
const char* window_name = "Threshold";
const char* GuidTable_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* GuidTable_value = "Value";

static void Threshold_Demo(int, void*)
{
    threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
    imshow(window_name, dst);
}

int main(int argc, char** argv)
{
    String imageName("test.jpg");

    if (argc > 1)
    {
        imageName = argv[1];
    }

    src = imread(imageName, IMREAD_COLOR);

    if (src.empty())
    {
        cout << "Cannot read the image: " << imageName << endl;
        return -1;
    }

    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    namedWindow(window_name, WINDOW_AUTOSIZE);
    createTrackbar(GuidTable_type, window_name, &threshold_type, max_type, Threshold_Demo);
    createTrackbar(GuidTable_value, window_name, &threshold_value, max_value, Threshold_Demo);

    Threshold_Demo(0, 0);
    waitKey();
    
    return 0;
}
