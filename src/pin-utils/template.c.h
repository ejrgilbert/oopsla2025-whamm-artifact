#include <stdio.h>
#include <stdlib.h>

#include "TEMPLATE.h"

int main(void) {
  /* Initialize the Wasm runtime. */
  wasm_rt_init();

  w2c_TEMPLATE *module = malloc(sizeof(w2c_TEMPLATE));

  /* Construct the module instance. */
  wasm2c_TEMPLATE_instantiate(module);

  w2c_TEMPLATE_0x5Fstart(module);

  /* Free the module. */
  wasm2c_TEMPLATE_free(module);
  free(module);

  wasm_rt_free();

  return 0;
}
