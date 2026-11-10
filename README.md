This repository contains a virtual ECU (vECU) project for lab exercise. It includes the startup code, SIU pin setup, PIT timer configuration, ADC stubs, and a simple OS abstraction layer used by the embedded-style application.

## Project structure

- `main.c` - main application entry point and task hooks
- `source/siu.c` - SIU pin configuration for inputs/outputs/analog pins
- `components/` - HAL and abstraction layer code
- `vtarget/` - target runtime configuration files for the vECU UI
- `bin/Debug/` - build output directory

## Build

This project is configured to build with GCC from the workspace root.

Example command:

```bash
gcc -shared -fPIC *.c components/*.c source/*.c \
  -I components -I source \
  -o bin/Debug/vEcuImpl.bin
```

## Notes

- The SIU configuration file contains the required pin mappings for switches, buttons, LEDs, and analog inputs.
- The current build may fail until the unfinished placeholder code is completed.

## Typical workflow

1. Configure the required SIU pins in `source/siu.c`.
2. Implement the task logic in `main.c`.
3. Initialize peripherals in `peripheralsInit()`.
4. Build the project and run it in the vECU UI.

## License

