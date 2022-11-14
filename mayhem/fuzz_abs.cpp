#include <fuzzer/FuzzedDataProvider.h>
#include <stdint.h>
#include <stdio.h>

#include <climits>

#include "yocto_math.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  FuzzedDataProvider provider(data, size);

  int          x = provider.ConsumeIntegral<int>();
  int          y = provider.ConsumeIntegral<int>();
  int          z = provider.ConsumeIntegral<int>();
  int          w = provider.ConsumeIntegral<int>();
  yocto::vec4i v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;

  yocto::abs(v);

  return 0;
}