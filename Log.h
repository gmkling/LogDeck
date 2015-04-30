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

enum log_level
{
    info=1,
    warn,
    error,
    fatal,
    game,
    maxLevel
};

class Log {
    
    string pathToLog;
    std::stringstream logLineStream;
    std::ofstream * logFile;

public:
    
    // constructors - this where most of the output stream cofig/setup happens
    Log(string logPath);
    
    // Operation
    // default logLevel functions
    // five because, wth
    void infoMsg(string s);
    void warnMsg(string s);
    void errorMsg(string s);
    void fatalMsg(string s);
    void gameMsg(string s);
    
    // user interfaces with just this func (?)
    void log(log_level level, string msg);

    // utility
    string getTimeString(void);
    string getLinePrefix(void); // <timeStamp><dateStamp>
    void closeLog(void);
    bool checkStreamState(void);
    string getLogFilePath(void);

private:
    // internal implementations
    bool logPrint(string s);
    double logLineNumber=0;
};

#endif /* defined(__LogDeck__Log__) */
