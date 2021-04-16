
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifndef __GNUC__
#define inline
#endif

/*!
 * Radio choice. Please uncomment the wanted radio and comment the others
 * or add/change wanted radio definition on the compiler Defines option
 */

#define USE_SX1276_78_RADIO

#include "board.h"
#include "utility.h"

#endif // __PLATFORM_H__
