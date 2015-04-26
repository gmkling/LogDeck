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
    if(!logFile->is_open()||(!checkStreamState()))
    {
        throw(std::runtime_error("LogDeck: unable to open log for output."));
    }
    
    // we have a good logPath, save it.
    pathToLog=logPath;
    
    //logStart = system_clock::now();
}

void Log::closeLog(void)
{
    logFile->close();
}

bool Log::checkStreamState(void)
{
    return logFile->good();    
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

void Log::log(int level, string msg)
{
    // Arg checking
    if(level>4||level<0) // hard coded to levels 0,1,2,3,4
    {
        return; // no-op if log level is invalid
    }

    // do we need to check if the string is valid? How?

    if (level==0)
    {
        // info msg
    }
    else if (level==1)
    {
        //  warn msg
    } 
    else if (level==2)
    {
        // error msg
    }     
     
    else if (level==3)
    {
        // fatal msg
    }
    
    else if (level==4)
    {
        // game  msg
    }
}


