#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

// Function to calculate Probability Distribution Function (PDF) of the input image
void PDF(Mat image, int histogram[]) {
    // Initialize all intensity values to 0
    for(int i = 0; i < 256; i++) {
        histogram[i] = 0;
    }

    // Calculate the number of pixels for each intensity value
    for(int y = 0; y < image.rows; y++) {
        for(int x = 0; x < image.cols; x++) {
            histogram[(int)image.at<uchar>(y,x)]++;
        }
    }
}

// Function to calculate Cumulative Distribution Function (CDF) of the input image
void CDF(int histogram[], int cumulativeHistogram[]) {
    cumulativeHistogram[0] = histogram[0];
    for(int i = 1; i < 256; i++) {
        cumulativeHistogram[i] = histogram[i] + cumulativeHistogram[i-1];
    }
}

// Function to display histogram
void histogramDisplay(int histogram[], const char* name) {
    int newHistogram[256];
    for(int i = 0; i < 256; i++) {
        newHistogram[i] = histogram[i];
    }
    // Histogram size
    int histogramWidth = 600;
    int histogramHeight = 300;
    // Creating "bins" for the range of 256 intensity values
    int binWidth = cvRound((double) histogramWidth/256);
    Mat histogramImage(histogramHeight, histogramWidth, CV_8UC1, Scalar(255, 255, 255));
    // Finding maximum intensity level in the histogram
    int maximumIntensity  = newHistogram[0];
    for(int i = 1; i < 256; i++){
        if(maximumIntensity < newHistogram[i]){
            maximumIntensity = newHistogram[i];
        }
    }
    // Normalizing histogram in terms of rows (y)
    for(int i = 0; i < 256; i++) {
        newHistogram[i] = ((double)newHistogram[i]/maximumIntensity)*histogramImage.rows;
    }
    // Drawing the intensity level line
    for(int i = 0; i < 256; i++) {
        line(histogramImage, Point(binWidth*(i), histogramHeight ), Point(binWidth*(i), histogramHeight - newHistogram[i]), Scalar(0,0,0), 1, 8, 0);
    }
    // Display
    namedWindow(name, WINDOW_AUTOSIZE);
    imshow(name, histogramImage);
}

int main()
{
    VideoCapture camera(0);
    Mat RGBimage;
    while(true){
        camera >> RGBimage;
        Mat image;
        cvtColor(RGBimage, image, COLOR_BGR2GRAY);
        imshow("Gray", image);
        char a;
        a == waitKey(33);
        if (a == 27){
            break;
        }
    }
	
    // Call function to create histogram
    int histogram[256];
    PDF(image, histogram);

    // Get the image size
    int size = image.rows * image.cols;
    float alpha = 255.0 / size;

    // Probability distribution for intensity levels
    float PRk[256];
    for(int i = 0; i < 256; i++) {
        PRk[i] = (double)histogram[i] / size;
    }

    // Call function to create cumulative histogram
    int cumulativeHistogram[256];
    CDF(histogram,cumulativeHistogram);

    // Scaling operation
    int Sk[256];
    for(int i = 0; i < 256; i++)
    {
        Sk[i] = cvRound((double)cumulativeHistogram[i] * alpha);
    }

    // Initializing equalized histogram
    float PSk[256];
    for(int i = 0; i < 256; i++) {
        PSk[i] = 0;
    }

    // Mapping operation
    for(int i = 0; i < 256; i++) {
        PSk[Sk[i]] += PRk[i];
    }

    // Rounding to get final values
    int finalValues[256];
    for(int i = 0; i < 256; i++) {
        finalValues[i] = cvRound(PSk[i]*255);
    }

    // Creating equalized image
    Mat finalImage = image.clone();
    
    for(int y = 0; y < image.rows; y++) {
        for(int x = 0; x < image.cols; x++) {
            finalImage.at<uchar>(y,x) = saturate_cast<uchar>(Sk[image.at<uchar>(y,x)]); 
        }
    }
    // Displaying source image
    namedWindow("Original Image");
    imshow("Original Image", image);

    // Displaying source image histogram
    histogramDisplay(histogram, "Original Histogram");

    // Displaying histogram equalized image
    namedWindow("Equalized Image");
    imshow("Equalized Image",finalImage);

    // Displaying equalized image histogram
    histogramDisplay(finalValues, "Equalized Histogram");

    // Saving image as a file
    imwrite("EqualizedImage.jpg", finalImage);
    waitKey();
    return 0;
}
