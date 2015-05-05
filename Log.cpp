//
//  Log.cpp
//  LogDeck - Simple C++ logging 
//
//  Created by Garry Kling on 4/16/15.
//
//

#include "LogDeck.h"

Log::Log(string logPath)
{
    logFile = new std::ofstream;

    if(logPath.empty()) 
    {   // do we need to check for NULL, other cases?
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
    
    // get current time

    gettimeofday(&timeStart, NULL);
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
    // this should be configurable in future 
    time_t t;
    std::string s;
    
    time(&t);
    s = ctime(&t);
    s = s.substr(0, s.size()-1);
    
    return s;
}


std::string Log::getLinePrefix()
{
    // collect line number, time/date stamp
    std::stringstream linePrefix;
    gettimeofday(&curTime, NULL);
    sec = (curTime.tv_sec - timeStart.tv_sec);
    mSec = (curTime.tv_usec - timeStart.tv_usec)/1.0e05;
    
    linePrefix.str("");
    linePrefix.fill('0');
    linePrefix.width(8);
    linePrefix << logLineNumber++ <<" ["<<getTimeString()<<" ";
    linePrefix.fill('0');
    linePrefix.precision(8);
    //linePrefix << sec <<"."<< mSec <<"] ";
    // milliseconds since start of program
    linePrefix << sec+mSec <<"] ";
    return linePrefix.str();
    
}

void Log::log(log_severity level, string msg)
{
    // Arg checking
    if(level>=Log_maxLevel||level<Log_info) // make sure we are logging on a valid level
    {
        return; // no-op if log level is invalid
    }

    switch(level)
    {
        case log_severity::Log_info:
            logPrint(getLinePrefix()+"<INFO>: "+msg);
            break;
        case log_severity::Log_warn:
            logPrint(getLinePrefix()+"<WARN>: "+msg);
            break;
        case log_severity::Log_error:
            logPrint(getLinePrefix()+"<ERROR>: "+msg);
            break;
        case log_severity::Log_fatal:
            logPrint(getLinePrefix()+"<FATAL>: "+msg);
            break;
        case log_severity::Log_debug:
            logPrint(getLinePrefix()+"<DEBUG>: "+msg);
            break;
        case log_severity::Log_game:
            logPrint(getLinePrefix()+"<GAME>: "+msg);
            break;
        case log_severity::Log_maxLevel:
            break;
        default:
            return;
    }
}

// internal interface to the logStream
void Log::logPrint(string s)
{
    // Where the rubber meets the road
    *logFile<<s<<std::endl;

}
