// 
// main.cpp
// LogDeck - Simple C++ logging
//
// Created by Garry Kling on 4/19/2015
//

// simple driver programs to test/demo LogDeck features

#include <iostream>
#include <string>
#include <sstream>

#include "Log.h"
  

int main(int argc, char * argv[])
{
    Log l("./test.txt");
    std::cout<<"The time according to getTimeString: "<<l.getTimeString()<<std::endl;
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    sleep(0.1);
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    sleep(5);    
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    std::cout<<"Reported path from getLogFilePath: "<<l.getLogFilePath()<<std::endl;

    l.closeLog();
    return 0;
}



