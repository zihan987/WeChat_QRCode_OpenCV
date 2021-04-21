#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp> 
#include <opencv2/core/utility.hpp>
#include <opencv2/wechat_qrcode.hpp>

using namespace std; 
using namespace cv; 

int main(int argc, char** argv) {
    string input_path;
    string output_path;

    if(3 == argc){
        input_path = argv[1];
        output_path = argv[2];
    }
    else{
        cout << "Please input ./demo [input_path] [output_path]";
        return -1;
    }
    
    Mat img;
    img = imread(input_path, 1);
    if ( !img.data )
    {
        cout << "No image data" << endl;
        return -1;
    }
    
    //修改路径，模型文件下载链接看readme
    Ptr<wechat_qrcode::WeChatQRCode> detector;
    string detect_prototxt = "Your Path/detect.prototxt";
    string detect_caffe_model = "Your Path/detect.caffemodel";
    string sr_prototxt = "Your Path/sr.prototxt";
    string sr_caffe_model = "Your Path/sr.caffemodel";
    detector = makePtr<wechat_qrcode::WeChatQRCode>(detect_prototxt, detect_caffe_model, sr_prototxt, sr_caffe_model);

    vector<Mat> Pt;
    vector<String> web;
    chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();
    web = detector->detectAndDecode(img, Pt);
    chrono::time_point<chrono::system_clock> t2 = chrono::system_clock::now();
    float dur = (float)chrono::duration_cast<chrono::microseconds>(t2 - t1).count() / 1000;
    cout << "WeChat_QRCode time:" << dur << "ms" << endl;
    
    for (int i = 0; i < web.size(); i++)
    {
        cout << "Number_" << i + 1 << ": " << web[i] << endl;
        Point p1 = Point((int)Pt[i].at<float>(0, 0), (int)Pt[i].at<float>(0, 1));
        Point p2 = Point((int)Pt[i].at<float>(1, 0), (int)Pt[i].at<float>(1, 1));
        Point p3 = Point((int)Pt[i].at<float>(2, 0), (int)Pt[i].at<float>(2, 1));
        Point p4 = Point((int)Pt[i].at<float>(3, 0), (int)Pt[i].at<float>(3, 1));
        line(img, p1, p2, Scalar(0, 0, 255), 5);
        line(img, p2, p3, Scalar(0, 0, 255), 5);
        line(img, p3, p4, Scalar(0, 0, 255), 5);
        line(img, p4, p1, Scalar(0, 0, 255), 5);
        putText(img, web[i], p1, 0, 0.6, Scalar(128, 128, 0), 2);
    }
    
    imwrite(output_path, img);
    return 0;
}

