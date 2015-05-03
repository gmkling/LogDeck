//
//  Log.h
//  LogDeck - Simple C++ logging 
//
//  Created by Garry Kling on 4/16/15.
//
//

#ifndef __LogDeck__Log__
#define __LogDeck__Log__

#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <ctime>
#include <stdexcept>

using std::string;

// log levels

enum log_severity
{
    Log_info=1,
    Log_warn,
    Log_error,
    Log_fatal,
    Log_debug,
    Log_game,
    Log_maxLevel
};

class Log {
    
    string pathToLog;
    std::stringstream logLineStream;
    std::ofstream * logFile;

public:
    
    // constructors - this where most of the output stream cofig/setup happens
    Log(string logPath);
    
    // user interfaces with just this func (?)
    void log(log_severity level, string msg);

    // utility
    string getTimeString(void);
    string getLinePrefix(void); // <timeStamp><dateStamp>
    void closeLog(void);
    bool checkStreamState(void);
    string getLogFilePath(void);

private:
    // internal implementations
    void logPrint(string s);
    double logLineNumber=0;
};

#endif /* defined(__LogDeck__Log__) */
