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

// define the logging level

#define LOGDECK_LEVEL_4

#include "LogDeck.h"
  
void testLinePrefix(Log & l)
{
    std::cout<<"*************************************"<<std::endl;
    std::cout<<"  TESTING LINE PREFIX ON STD::COUT "<<std::endl;
    std::cout<<"*************************************"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"The time according to getTimeString: "<<l.getTimeString()<<std::endl;
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    sleep(0.1);
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    sleep(5);    
    std::cout<<"The time prefix according to getLinePrefix: "<<l.getLinePrefix()<<std::endl;
    std::cout<<"Reported path from getLogFilePath: "<<l.getLogFilePath()<<std::endl;
    std::cout<<"************ TEST COMPLETE ************"<<std::endl;
}

void testLoggingMethods(Log & l)
{
    std::cout<<"*************************************"<<std::endl;
    std::cout<<"  TESTING LOG METHODS TO FILE "<<std::endl;
    std::cout<<"*************************************"<<std::endl;
    std::cout<<std::endl;
    l.log(Log_info, "Testing 123");
    l.log(Log_warn, "WARNING TEXT");
    l.log(Log_error, "This is an *error*");
    l.log(Log_fatal, "TOTAL FAILURE IMMINENT");
    l.log(Log_game, "Some bs about the game, blah blah");
    std::cout<<"************ TEST COMPLETE ************"<<std::endl;
}

void testLoggingMacros(Log & l)
{
    std::cout<<"*************************************"<<std::endl;
    std::cout<<"  TESTING MACROS"<<std::endl;
    std::cout<<"*************************************"<<std::endl;
    std::cout<<std::endl;
 
    // put in the macros 
    LOG_FATAL("Fatal log");
    LOG_ERROR("Error log");
    LOG_WARN("Warning log");
    LOG_INFO("Info log");
    LOG_DEBUG("Debug log");
    LOG_GAME("Game log");
    std::cout<<"************ TEST COMPLETE ************"<<std::endl;
}

int main(int argc, char * argv[])
{
    Log l("./test.txt");  
    testLinePrefix(l); 
    testLoggingMethods(l);
    testLoggingMacros(l);
    l.closeLog();
    std::cout<<"Done with LogDeck tests."<<std::endl;
    return 0;
}


