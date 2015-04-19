//
//  Log.cpp
//  LogDeck - Simple C++ logging 
//
//  Created by Garry Kling on 4/16/15.
//
//

#include "Log.h"

std::string Log::getLogFilePath()
{
    return pathToLog;
}

Log::Log(std::string LogPath)
{
    
}



std::string Log::getLinePrefix()
{
    // the tm struct
    time_t t = time(0);
    struct tm * now = localtime( & t );
    
    // milliseconds
//    using namespace std::chrono;
//    milliseconds ms = duration_cast< milliseconds >(
//                                                    high_resolution_clock::now().time_since_epoch()
//                                                    );
    
    // collect line number, time/date stamp
    std::stringstream linePrefix;
    linePrefix.str("");

    // date and time
    // if we need something more detailed, look into using the chrono header
    linePrefix << logLineNumber++ <<" ["<<asctime(now)<<"] ";
    return linePrefix.str();
    
}

