#include <iostream>
#include <opencv2/opencv.hpp>
#include <sys/stat.h>


int main(int argc, char **argv) {

    if(argc < 2){
        std::cout << "Zadejte cestu k video souboru jako argument pri spusteni" << std::endl;
        return -1;
    }

    cv::VideoCapture cap(argv[1]);
    std::string outputDirectory;
    cv::Mat frame;
    size_t i(0);

    if(argc >= 3){
        outputDirectory = argv[2];
        outputDirectory.append("/");
    }else{
        outputDirectory = "output/";
    }

    mkdir(argv[2], 0777);

    while(true){
        std::string output = outputDirectory;
        cv::Mat grayscale;
        cap >> frame;
        ++i;

        if(frame.empty()){
            break;
        }

        cv::cvtColor(frame, grayscale, CV_BGR2GRAY);
        cv::imwrite( output.append(std::to_string(i).append(".jpg")), grayscale);
    }

    return 0;
}