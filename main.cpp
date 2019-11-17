#include <iostream>
#include <opencv2/opencv.hpp>
#include <sys/stat.h>


int main(int argc, char **argv) {

    if(argc < 2){
        std::cout << "Zadejte cestu k video souboru jako argument pri spusteni" << std::endl;
        return -1;
    }

    cv::VideoCapture cap(argv[1]);
    const char *outputDirectory;

    if(argc >= 3){
        outputDirectory = argv[2];
    }else{
        outputDirectory = "output";
    }

    mkdir(outputDirectory, 0777);



    return 0;
}