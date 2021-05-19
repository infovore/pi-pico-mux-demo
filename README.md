# Pi Pico Muxtest

## Hardware

A Pi Pico, 10 LEDs (and resistors), and a 4067-style multiplexer. (I'm using a 74HC4067).

## Connections

* Multiplexer pins 6-15 go to LEDs 0-10 respectively
* Multiplexer EN to GND
* Multiplexer SIGNAL to GP6
* Multiplexer S0-23 to GP2-GP5 respectively

## What you should see

LEDs 0-10 light up sequentially, left to right, then right to left. (The old 'Knight Rider' demo).
## Configuration

This is setup as a 'standard' Pi Pico style CMake project. The Visual Studio Code CMake plugin is doing a lot of heavy-lifting for me. I have it configured to use `arm-none-eabi-gcc`; it will configure the project automatically, and then "build" will emit a UF2 file I can send to my Pico.

You'll need the `PICO_SDK_PATH` environment variable setup correctly.
