// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
#define PERMISSIVE_HOLD

// Spacebar is tricky and sometimes chatter
#undef DEBOUNCE
#define DEBOUNCE 25
