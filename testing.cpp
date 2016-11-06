#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2\core\core.hpp>
#include "opencv2/opencv.hpp"
int main(int argc, char** argv)
{
cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

//CvCapture* capture = cvCreateFileCapture("20051210-w50s.flv");
CvCapture* capture = cvCreateFileCapture("Intel.avi");
/* if(!capture)
    {
        std::cout <<"Video Not Opened\n";
        return -1;
    }*/
IplImage* frame = NULL;

while(1) {

    frame = cvQueryFrame(capture);
    //std::cout << "Inside loop\n";
    if (!frame)
        break;
    cvShowImage("Example3", frame);
    char c = cvWaitKey(33);
    if (c == 27) break;
}
cvReleaseCapture(&capture);
cvDestroyWindow("Example3");
std::cout << "Hello!";
return 0;
}
