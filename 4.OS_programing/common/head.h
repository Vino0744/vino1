/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Nov 2024 04:45:45 PM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//--- head file of user ---

#include "./color.h"

#ifdef _D
#define DBG(fmt, args) printf(fmt, ##args)
#else
#define DEBUG(fmt, args)
#endif

#endif
