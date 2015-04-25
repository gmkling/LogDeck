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
    
    //logStart = system_clock::now();
    // done
}

void Log::closeLog(void)
{
    logFile->close();
}


std::string Log::getLogFilePath()
{
    return pathToLog;
}

std::string Log::getTimeString(void)
{
    // currently the time format is just HH:MM:SS
    
    time_t t;
    std::string s;
    
    time(&t);
    s = ctime(&t);
    s = s.substr(0, s.size()-1);
   
    
    // I don't think system_clock is cross platform. Assert fails in <chrono>
    //using namespace std::chrono; 
    //system_clock::time_point now = system_clock::now();
    //milliseconds ms = duration_cast<milliseconds>(now-logStart);
    // s = s.append("-").append(std::to_string(ms.count()));
   
    return s;
}


std::string Log::getLinePrefix()
{
    // collect line number, time/date stamp
    std::stringstream linePrefix;
    
    linePrefix.str("");
    linePrefix.fill('0');
    linePrefix.width(8);
    linePrefix << logLineNumber++ <<" ["<<getTimeString()<<"] ";
    return linePrefix.str();
    
}

