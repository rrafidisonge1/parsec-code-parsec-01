#include "my_lib.h"
#include "opencv2/opencv.hpp"
float nr=0;



Mat seuillage(Mat frame)
{



for (int i=0;i<frame.rows;i++){
                        for (int j=0;j<frame.cols;j++){
                                uchar r,v,b;

                                b=frame.at<Vec3b>(i,j)[0];
                                v=frame.at<Vec3b>(i,j)[1];
                                r=frame.at<Vec3b>(i,j)[2];
                                nr=b/sqrt((r*r)+(b*b)+(v*v));

                if(nr>0.7)
                        {
                                frame.at<Vec3b>(i,j)[0]=0;
                                frame.at<Vec3b>(i,j)[1]=0;
                                frame.at<Vec3b>(i,j)[2]=b;

                        }
                else{
                        frame.at<Vec3b>(i,j)[0]=b;
                        frame.at<Vec3b>(i,j)[1]=v;
                        frame.at<Vec3b>(i,j)[2]=r;
                }
        
}
}

         return (frame);



}

Mat contours (Mat frame) 
{
	Mat frame_out,in_gray;
	cvtColor(frame,in_gray,CV_BGR2GRAY);
	frame_out.create(frame.rows,frame.cols,CV_8UC1);
		for (int i=1;i<frame.rows;i++)                 
		{
			for (int j=1;j<frame.cols;j++)
			{
					short temp;
				temp = (-1)*in_gray.at<uchar>(i,j-1)+(-1)*in_gray.at<uchar>(i-1,j)+(-1)*in_gray.at<uchar>(i,j+1)+(-1)*in_gray.at<uchar>(i+1,j)+4*in_gray.at<uchar>(i,j);
frame_out.at<uchar>(i,j)=(uchar)abs(temp);
		if(frame_out.at<uchar>(i,j)>23) frame_out.at<uchar>(i,j)=255;
		else { frame_out.at<uchar>(i,j)=0;
		     }
			}
		}
return(frame_out);
}



Mat NoiretBlanc(Mat frame){
Mat in_gray;
	cvtColor(frame,in_gray,CV_BGR2GRAY);
return in_gray;
}

Mat median(Mat frame){
Mat frame_out;
medianBlur(frame, frame_out,5);

return frame_out;



}



