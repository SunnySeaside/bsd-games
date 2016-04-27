// Copyright (c) 1982 The Regents of the University of California.
// This file is free software, distributed under the BSD license.

#include "mille.h"

int is_repair (CARD card)
{
    return card == C_GAS || card == C_SPARE || card == C_REPAIRS || card == C_INIT;
}

int safety (CARD card)
{
    switch (card) {
	case C_EMPTY:
	case C_GAS:
	case C_GAS_SAFE:
	    return C_GAS_SAFE;
	case C_FLAT:
	case C_SPARE:
	case C_SPARE_SAFE:
	    return C_SPARE_SAFE;
	case C_CRASH:
	case C_REPAIRS:
	case C_DRIVE_SAFE:
	    return C_DRIVE_SAFE;
	case C_GO:
	case C_STOP:
	case C_RIGHT_WAY:
	case C_LIMIT:
	case C_END_LIMIT:
	    return C_RIGHT_WAY;
    }
    return 0;
}
