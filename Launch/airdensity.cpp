#include "types.h"

Double AirDensity(Double altitude) {
  if (altitude < 5500) {
    return 1.0 - (0.5 * (altitude / 5500));
    }
  if (altitude < 16000) {
    return 0.5 - (0.4 * ((altitude - 5500) / 10500));
    }
  if (altitude < 32000) {
    return 0.1 - (0.09 * ((altitude - 16000) / 16000));
    }
  if (altitude < 50000) {
    return 0.01 - (0.009 * ((altitude - 32000) / 18000));
    }
  if (altitude < 100000) {
    return 0.001 - (0.001 * ((altitude - 50000) / 50000));
    }
  return 0;
  }

