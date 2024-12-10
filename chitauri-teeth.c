#include <stdio.h>

void main() {
  int t = 1;
  for (;;t++) {
    fprintf(stderr, "t = 0x%x\n", t);
    putchar(
        0xfa
        & ((
            (t 
             & t >> 6
             & ((t % (1 << 14)) < (1 << 13)? 
               t ^ t >> 8
               : t >> 8) 
             / (t <= 0? 1 : (1 + t % 32))
             ^ (t % 30 & t)
            )
            | (((t >> 18) && (t <= (1 << 18) + (1 << 17))) * t << 1)
           )
          + ((t * (t >> 18)) & 0xe0)
          | ((t / 10) & (t >> 14) & (t >> 15) & 0xaa)
          )
        );
  }
}
