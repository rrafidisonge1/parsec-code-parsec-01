
#include "my_lib.h"





int main(int, char**)
{
        cudaError_t error;
        float msecTotal = 0.0f;

        cudaEvent_t start,stop,start_compute,stop_compute;
        error = cudaEventCreate(&start);
        error = cudaEventCreate(&stop);
        error = cudaEventCreate(&start_compute);
        error = cudaEventCreate(&stop_compute);

        VideoCapture cap(0); // open the default camera
        if(!cap.isOpened())  // check if we succeeded
                return -1;


        float nr=0;
int k=0;
   
        while(1){
    
           char c=(char)waitKey(25);  
           Mat frame, frame_out;
            // Capture frame-by-frame
            cap >> frame;
if (frame.empty())
              break;
             imshow("Frame", frame);
            

           if(c==98||k==11){
	   
            k=11;
          
           Mat contour1 = contours(frame);
           imshow("contour",contour1); 
          
 }

if( c==99||k==12){
k=12 ;
Mat seuillage1 = seuillage(frame);     //change le bleu en rouge  
imshow("seuillage",seuillage1);
}

if( c=='p'||k==13){
k=13 ;
Mat NB = NoiretBlanc(frame);       
imshow("NB",NB);
}           
            
               

if( c=='f'||k==14){
k=14 ;
Mat median1 = median(frame);       
imshow("median",median1);
}           
           
                        
                

// Record the stop_compute event
error = cudaEventRecord(stop_compute, NULL);
//        // Wait for the stop event to complete
error = cudaEventSynchronize(stop_compute);
error = cudaEventElapsedTime(&msecTotal, start_compute, stop_compute);
//printf("Compute Time : %f msec\n",msecTotal);

//imshow("output", frame_out);

// Record the stop event
error = cudaEventRecord(stop, NULL);
//        // Wait for the stop event to complete
error = cudaEventSynchronize(stop);

error = cudaEventElapsedTime(&msecTotal, start, stop);
//printf("Total Time : %f msec\n",msecTotal);
if (c==27)break;
 //imshow("Frame", frame);
        }
        // the camera will be deinitialized automatically in VideoCapture destructor
cap.release();
destroyAllWindows();        
return 0;

        
}
