//
//  LogDeck.h
//  LogDeck - Simple C++ logging 
//
//  Created by Garry Kling on 5/02/2015.
//
//

#ifndef __LogDeck__LogDeck__
#define __LogDeck__LogDeck__

#include "Log.h"

// Get our levels straight
// You can change the mixture here if you like

#ifdef LOGDECK_LEVEL_1
    #define LOGGING_LEVEL_FATAL
#endif

#ifdef LOGDECK_LEVEL_2
    #define LOGGING_LEVEL_FATAL
    #define LOGGING_LEVEL_ERROR
#endif

#ifdef LOGDECK_LEVEL_3
    #define LOGGING_LEVEL_FATAL
    #define LOGGING_LEVEL_ERROR
    #define LOGGING_LEVEL_WARN
#endif

#ifdef LOGDECK_LEVEL_4
    #define LOGGING_LEVEL_FATAL
    #define LOGGING_LEVEL_ERROR
    #define LOGGING_LEVEL_WARN
    #define LOGGING_LEVEL_INFO
    #define LOGGING_LEVEL_DEBUG
    #define LOGGING_LEVEL_GAME
#endif

// Do the actual defining of the logging interfaces

#ifdef LOGGING_LEVEL_FATAL
    #define LOG_FATAL(msg) l.log(Log_fatal, msg)
#else
    #define LOG_FATAL(...) 
#endif

#ifdef LOGGING_LEVEL_ERROR
    #define LOG_ERROR(msg) l.log(Log_error, msg)
#else
    #define LOG_ERROR(...) 
#endif

#ifdef LOGGING_LEVEL_WARN
    #define LOG_WARN(msg) l.log(Log_warn, msg)
#else
    #define LOG_WARN(...)
#endif

#ifdef LOGGING_LEVEL_INFO
    #define LOG_INFO(msg) l.log(Log_info, msg)    
#else
    #define LOG_INFO(...)
#endif

#ifdef LOGGING_LEVEL_DEBUG
    #define LOG_DEBUG(msg) l.log(Log_debug, msg)
#else
    #define LOG_DEBUG(...)
#endif

#ifdef LOGGING_LEVEL_GAME
    #define LOG_GAME(msg) l.log(Log_game, msg)
#else
    #define LOG_GAME(...)
#endif


#endif /* __LogDeck__LogDeck__ */
