#include <opencv2/opencv.hpp>
using namespace cv;

int main( int argc, char** argv )
{
 	char* ImageFile = argv[1];	              //image file 
 	Mat image;			                     //mat object for storing data
 	image = imread( ImageFile, IMREAD_COLOR );	         //read the image file
 	if( argc != 2 || !image.data )		
 	{
 	  	printf( " No image data \n " );
 	  	return -1;
 	}
 	Mat gray_image;
 	cvtColor( image, gray_image, COLOR_BGR2GRAY );             //convert image from colour to grey
 	imwrite( "/home/crmgogo/Pictures/greyImage.png", gray_image );
 	namedWindow( ImageFile, WINDOW_AUTOSIZE );	
 	namedWindow( "Gray image", WINDOW_AUTOSIZE );
 	imshow( ImageFile, image );	                   //show window containing images
 	imshow( "Gray image", gray_image );
 	waitKey(0);	     //to exit
 	return 0;
}
