#include <stdio.h>
#include <time.h>
#include "lfsr.h"
#include "random.h"

Random::Random() {
  UInt32 tim;
  UInt32 seed;
  UInt32 taps;
  tim = time(NULL);
  seed = tim;
  taps = (1 << 24) | (1 << 21) | (1 << 2) | (1 << 0);
  rng = Lfsr(seed, taps);

  }

Random::Random(UInt32 s) {
  UInt32 seed;
  UInt32 taps;
  seed = s;
  taps = (1 << 24) | (1 << 21) | (1 << 2) | (1 << 0);
  rng = Lfsr(seed, taps);
  }

Random::~Random() {
  }

void Random::Seed(UInt32 s) {
  rng.Seed(s);
  rng.Shift(0x1f);
  }

void Random::Seed(UInt32 s, UInt32 t) {
  rng.Seed(s);
  rng.Taps(t);
  rng.Shift(0x3f);
  }

UInt32 Random::bitsize(UInt32 n) {
  UInt32 bits;
  UInt32 max;
  bits = 1;
  max = 2;
  while (n > max) {
    bits++;
    max <<= 1;
    }
  return bits;
  }

UInt32 Random::Next(UInt32 range) {
  UInt32 ret;
  UInt32 seed;
  seed = rng.Next(bitsize(range));
  ret = seed % range;
  return ret;
  }

