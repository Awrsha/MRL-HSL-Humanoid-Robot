#include <iostream>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int reflect(int M, int x)
{
    if (x < 0)
    {
        return -x - 1;
    }
    if (x >= M)
    {
        return 2 * M - x - 1;
    }
    return x;
}

int circular(int M, int x)
{
    if (x < 0)
        return x + M;
    if (x >= M)
        return x - M;
    return x;
}

void noBorderProcessing(Mat src, Mat dst, float Kernel[][3])
{

    float sum;
    for (int y = 1; y < src.rows - 1; y++)
    {
        for (int x = 1; x < src.cols - 1; x++)
        {
            sum = 0.0;
            for (int k = -1; k <= 1; k++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    sum = sum + Kernel[j + 1][k + 1] * src.at<uchar>(y - j, x - k);
                }
            }
            dst.at<uchar>(y, x) = sum;
        }
    }
}

void reflectedIndexing(Mat src, Mat dst, float Kernel[][3])
{
    float sum, x1, y1;
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            sum = 0.0;
            for (int k = -1; k <= 1; k++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    x1 = reflect(src.cols, x - j);
                    y1 = reflect(src.rows, y - k);
                    sum = sum + Kernel[j + 1][k + 1] * src.at<uchar>(y1, x1);
                }
            }
            dst.at<uchar>(y, x) = sum;
        }
    }
}

void circularIndexing(Mat src, Mat dst, float Kernel[][3])
{
    float sum, x1, y1;
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            sum = 0.0;
            for (int k = -1; k <= 1; k++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    x1 = circular(src.cols, x - j);
                    y1 = circular(src.rows, y - k);
                    sum = sum + Kernel[j + 1][k + 1] * src.at<uchar>(y1, x1);
                }
            }
            dst.at<uchar>(y, x) = sum;
        }
    }
}

int main()
{
    Mat src, dst, dst2, dst3;
    /// Load an image
    src = imread("test.jpg", 0);

    if (!src.data)
    {
        return -1;
    }

    float Kernel[3][3] = {
        {0.0625, 0.125, 0.0625},
        {0.125, 0.25, 0.125},
        {0.0625, 0.125, 0.0625}};

    dst = src.clone();
    dst2 = src.clone();
    for (int y = 0; y < src.rows; y++)
        for (int x = 0; x < src.cols; x++)
            dst.at<uchar>(y, x) = 0.0;
    circularIndexing(src, dst, Kernel);
    namedWindow("Circular Indexing");
    imshow("Circular Indexing", dst);
    noBorderProcessing(src, dst2, Kernel);
    namedWindow("No Border Processing");
    imshow("No Border Processing", src);

    cout << "Rows: " << src.rows << endl;
    cout << "Cols: " << src.cols << endl;
    cout << "Rows: " << dst.rows << endl;
    cout << "Cols: " << dst.cols << endl;

    waitKey(0);

    return 0;
}
