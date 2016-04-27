// Copyright (c) 1980 The Regents of the University of California.
// This file is free software, distributed under the BSD license.

#include <stdio.h>
#include "trek.h"

// CHECK IF A DEVICE IS OUT
//
// The indicated device is checked to see if it is disabled.  If
// it is, an attempt is made to use the starbase device.  If both
// of these fails, it returns non-zero (device is REALLY out),
// otherwise it returns zero (I can get to it somehow).
//
// It prints appropriate messages too.
//
int check_out(int device)
{
    int dev;

    dev = device;

    // check for device ok
    if (!damaged(dev))
	return 0;

    // report it as being dead
    out(dev);

    // but if we are docked, we can go ahead anyhow
    if (Ship.cond != DOCKED)
	return 1;
    printf("  Using starbase %s\n", Device[dev].name);
    return 0;
}
