//
//  Log.cpp
//  LogDeck - Simple C++ logging 
//
//  Created by Garry Kling on 4/16/15.
//
//

#include "Log.h"

Log::Log(string logPath)
{
    logFile = new std::ofstream;

    if(logPath.empty()) { /* do we need to check for NULL, other cases? */
        // no path provided, proceed with default
        string defaultName = getTimeString();
        // clear out the junk - replace spaces and : with _
        std::replace(defaultName.begin(), defaultName.end(), ':', '_');
        std::replace(defaultName.begin(), defaultName.end(), ' ', '_'); 
        logPath=defaultName; 
    }

    // open the stream - append to the end if it exists, open for output
    logFile->open(logPath, std::ios_base::app|std::ios_base::out); 
    // quick check of the stream
    if(!logFile->is_open())
    {
        throw(std::runtime_error("LogDeck: unable to open log for output."));
    }

    // done
}

void Log::closeLog(void)
{

}


std::string Log::getLogFilePath()
{
    return pathToLog;
}

std::string Log::getTimeString(void)
{
    // currently the time format is just HH:MM:SS
    time_t t = time(0);
    struct tm * now = localtime( & t );
    std::string s = asctime(now); //<<"-"<<clock();

    return s;
}


std::string Log::getLinePrefix()
{
   
    // collect line number, time/date stamp
    std::stringstream linePrefix;
    linePrefix.str("");

    // date and time
    // if we need something more detailed, look into using the chrono header
    linePrefix << logLineNumber++ <<" ["<<getTimeString()<<"] ";
    return linePrefix.str();
    
}

