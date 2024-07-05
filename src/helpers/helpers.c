#include <stdint.h>
#include <stdlib.h>
#include "helpers.h"

uint8_t getRandomNumber(void)
{
    return rand() % 7;
}