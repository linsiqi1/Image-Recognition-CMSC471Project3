//
//  main.cpp
//  Project3
//
//  Created by Siqi Lin on 5/09/16.
//  Copyright © 2016 Siqi Lin. All rights reserved.
//

#include <iostream>
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/ml/ml.hpp>


using namespace std;
using namespace cv;
using namespace cv::ml;

/****************************************
 -train_data() will take the input data and train the data
 -return the training data in a matrix form
 *****************************************/
Mat train_data()
{
    //Intialization
    int image_area = 100 * 100;
    int num_files = 50;
    int training_row = 0;
    Mat training_mat(250,image_area,CV_32FC1);
    
    
    //Loop through the images in one group
    for(int i = 1 ; i < num_files; i++)
    {
        String current_index = to_string(i);
        Mat img_matrix;
        //Read the first nine images
        if(i < 10)
        {
            img_matrix = imread("Data/01/0"+current_index+".jpg",0);
        }
        else //read the rest of the images
        {
            
            img_matrix = imread("Data/01/"+current_index+".jpg",0);
        }
        if(!img_matrix.data )// Check for invalid input
        {
            cerr <<  "Could not open or find the image" <<endl ;
            exit (EXIT_FAILURE);
        }
        int ii = 0; // Current column in training_mat
        for (int i = 0; i<img_matrix.rows; i++)
        {
            for (int j = 0; j < img_matrix.cols; j++)
            {
                training_mat.at<float>(training_row,ii++) = img_matrix.at<uchar>(i,j);
            }
        }
        training_row++;
    }
    
    //Loop through the images in one group
    for(int i = 1 ; i < num_files; i++)
    {
        String current_index = to_string(i);
        Mat img_matrix;
        //Read the first nine images
        if(i < 10)
        {
            img_matrix = imread("Data/02/0"+current_index+".jpg",0);
        }
        else //read the rest of the images
        {
            
            img_matrix = imread("Data/02/"+current_index+".jpg",0);
        }
        if(!img_matrix.data )// Check for invalid input
        {
            cout <<  "Could not open or find the image" <<endl ;
            exit (EXIT_FAILURE);
        }
        int ii = 0; // Current column in training_mat
        for (int i = 0; i<img_matrix.rows; i++)
        {
            for (int j = 0; j < img_matrix.cols; j++)
            {
                training_mat.at<float>(training_row,ii++) = img_matrix.at<uchar>(i,j);
            }
        }
        
        training_row++;
    }
    
    //Loop through the images in one group
    for(int i = 1 ; i < num_files; i++)
    {
        String current_index = to_string(i);
        Mat img_matrix;
        //Read the first nine images
        if(i < 10)
        {
            img_matrix = imread("Data/03/0"+current_index+".jpg",0);
        }
        else //read the rest of the images
        {
            
            img_matrix = imread("Data/03/"+current_index+".jpg",0);
        }
        if(!img_matrix.data )// Check for invalid input
        {
            cout <<  "Could not open or find the image" <<endl ;
            exit (EXIT_FAILURE);
        }
        int ii = 0; // Current column in training_mat
        for (int i = 0; i<img_matrix.rows; i++)
        {
            for (int j = 0; j < img_matrix.cols; j++)
            {
                training_mat.at<float>(training_row,ii++) = img_matrix.at<uchar>(i,j);
            }
        }
        training_row++;
    }
    //Loop through the images in one group
    for(int i = 1 ; i < num_files; i++)
    {
        String current_index = to_string(i);
        Mat img_matrix;
        //Read the first nine images
        if(i < 10)
        {
            img_matrix = imread("Data/04/0"+current_index+".jpg",0);
        }
        else //read the rest of the images
        {
            
            img_matrix = imread("Data/04/"+current_index+".jpg",0);
        }
        if(!img_matrix.data )// Check for invalid input
        {
            cerr <<  "Could not open or find the image" <<endl ;
            exit (EXIT_FAILURE);
        }
        int ii = 0; // Current column in training_mat
        for (int i = 0; i<img_matrix.rows; i++)
        {
            for (int j = 0; j < img_matrix.cols; j++)
            {
                training_mat.at<float>(training_row,ii++) = img_matrix.at<uchar>(i,j);
            }
        }
        
        training_row++;
    }
    
    //Loop through the images in one group
    for(int i = 1 ; i < num_files; i++)
    {
        String current_index = to_string(i);
        Mat img_matrix;
        //Read the first nine images
        if(i < 10)
        {
            img_matrix = imread("Data/05/0"+current_index+".jpg",0);
        }
        else //read the rest of the images
        {
            
            img_matrix = imread("Data/05/"+current_index+".jpg",0);
        }
        if(!img_matrix.data )// Check for invalid input
        {
            cerr <<  "Could not open or find the image" <<endl ;
            exit (EXIT_FAILURE);
        }
        int ii = 0; // Current column in training_mat
        for (int i = 0; i<img_matrix.rows; i++)
        {
            for (int j = 0; j < img_matrix.cols; j++)
            {
                training_mat.at<float>(training_row,ii++) = img_matrix.at<uchar>(i,j);
            }
        }
        
        training_row++;
    }
    
    
    return training_mat;
}

/****************************************
 -set_labels() to set up labels for each image
 *****************************************/
int* set_labels(int *labels_array)
{

    for(int i= 0; i < 250; i++)
    {
        if (i< 50)
            labels_array[i]=1;
        else if(i>=50 && i<100){
            labels_array[i] = 2;
        }
        else if(i>=100 && i< 150)
        {
            labels_array[i] = 3;
        }
        else if(i>=150 && i<200)
        {
            labels_array[i] = 4;
        }
        else if(i>= 200 && i<250)
        {
            labels_array[i] = 5;
        }
    }

    return labels_array;
}

/****************************************************************
 -output_prediction() will output what the image is illustrating
 *****************************************/
void output_prediction(int label)
{
    if(label == 1)
    {
        cout << "The input image is a smile" << endl;
    }
    else if(label == 2)
    {
        cout << "The input image is a hat" << endl;
    }
    else if(label == 3)
    {
        cout << "The input image is a dollar" << endl;

    }
    else if(label == 4)
    {
        cout << "The input image is a hash" << endl;

    }
    else if(label == 5)
    {
        cout << "The input image is a heart" << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    
   
    if(argc < 2)
    {
        cerr << "Please enter the file name through command line" << endl;
        exit(EXIT_FAILURE);
    }
    
    int image_area = 100 * 100;
    Mat training_mat(250,image_area,CV_32FC1);
    int labels_array[250];
    int predict_label;
    
    //if input image is not valid
    Mat img_mat = imread(argv[1],0);
    if(!img_mat.data )    {
        cerr <<  "----Could not open or find the image" <<endl ;
        exit(EXIT_FAILURE);
    }
    
    //set up the training set and labels
    training_mat = train_data();
    set_labels(labels_array);

    
    Mat labels = Mat(250, 1, CV_32SC1, labels_array);
    
    //Set up the parameters
    Ptr<ml::SVM> svm = ml::SVM::create();
    //svm type is C_SVC
    svm->setType(100);
    //5-Poly
    svm->setKernel(5);
    svm->setGamma(3);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
    
    
    //Training the training set
    svm->train(training_mat, ROW_SAMPLE,labels);
    
    
    //convert the input image to a 1D matrix
    Mat img_mat_1d = Mat(1,image_area, CV_32FC1);
    //Loop through each element of the image
    int matrix_col=0;
    for (int i = 0; i<img_mat.rows; i++)
    {
        for (int j = 0; j < img_mat.cols; j++)
        {
            img_mat_1d.at<float>(0,matrix_col++) = img_mat.at<uchar>(i,j);
        }
    }
    
    //Make the prediction
    predict_label =  svm->predict(img_mat_1d);
    output_prediction(predict_label);

    return 0;
    
}

