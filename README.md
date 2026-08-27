🐍 SNAKE GAME - AVR Embedded Systems Project

 Embedded Systems Implementation

📋 Executive Summary

This project is a  Snake game implementation for the ATmega32 AVR microcontroller, demonstrating embedded systems programming concepts including:

Hardware Abstraction Layer (HAL) architecture

Memory-mapped I/O and bit manipulation

Real-time input handling with debouncing

Double-buffered display rendering

Custom LCD character generation (CGRAM programming)

Modular software design with separation of concerns

The system features a 4×20 LCD for game rendering, a 7-segment display for score tracking, buzzer for audio feedback, and a 5-button control interface—all integrated through a robust, layered software architecture.


🛠️ Technical Specifications

Hardware Specifications
Component	Specification	Interface
MCU	ATmega32	40-pin DIP, 8MHz
LCD	LM044L	4×20, HD44780 compatible
Display Mode	8-bit parallel	PORTD (Data), PORTC (Ctrl)
7-Segment	Common Cathode	PORTB, BCD to 7-seg decoder
Buzzer	Active	5V, PORTC Pin 3
Buttons	Tactile Switch	PORTA Pins 0-4, Pull-up enabled

Software Specifications
Metric	Value
Programming Language	C
Frame Rate	4 FPS (Adjustable)
Max Snake Length	50 Segments
Score Range	0-255 (8-bit)
Debounce Time	50ms
Timing Analysis
Operation	Duration	Frequency
Frame Update	250ms	4 Hz
LCD Write	2ms	Per character
Buzzer Beep	100ms	On food eat
Button Debounce	50ms	On press

💻 Code Architecture
Key Data Structures

🎨 Visual Design
Character Set
Code	Character	Use	Design
0	█	Snake Body	Full block, 5×8 pixels
1	♦	Food	Diamond shape, centered
2	►	Head (Right)	Arrow shape with detail
3	◄	Head (Left)	Mirror of right arrow
4	▲	Head (Up)	Upward arrow
5	▼	Head (Down)	Downward arrow


7-Segment Score Display: 

🎯 Performance Optimizations
Memory Optimization
Static allocation - No dynamic memory allocation

Buffer pooling - Reuse memory for display buffer

Bit-packing - Minimize structure padding

Const data - Store ROM data in Flash

Speed Optimization
Direct register access - Avoid function call overhead

Inline bit operations - Macro-based bit manipulation

Frame buffering - Minimize LCD writes

Polling instead of interrupts - Reduce overhead

Code Size Optimization
Function inlining - Use static inline for small functions

Switch-case optimization - Compiler optimized jump tables

Lookup tables - Pre-calculated values

Modular design - Only compile used functions

🔄 State Machine
Game States

                    ┌───────────────┐
                    │    IDLE       │◄───┐
                    | (Start Screen)│    |
                    └──────┬────────┘    |
                           │ UP Pressed  |
                           ▼             |
                    ┌─────────────┐      |
                    │   RESET     │      |
                    │ (Init Game) │      | 
                    └──────┬──────┘      |
                           │             |
                           ▼             |  Reset
                    ┌─────────────┐      |
                    │   PLAYING   │─ ─ ► |
                    │ (Active)    │      │
                    └──────┬──────┘      │
                           │             │ 
                           │ Snake Dead  │
                           ▼             │
                    ┌─────────────┐      │
                    │  GAME OVER  │──────┘
                    │ (Wait Reset)│
                    └─────────────┘


🏆 Project Achievements
Technical Achievements
✅ Modular architecture - Clean separation of concerns
✅ Custom LCD characters - Enhanced visual experience
✅ Double-buffered rendering - Smooth display updates
✅ Input debouncing - Reliable button detection
✅ Real-time performance - Consistent 4 FPS gameplay

Skills Demonstrated
🔹 Embedded C programming
🔹 AVR microcontroller architecture
🔹 Memory-mapped I/O and register manipulation
🔹 Peripheral interfacing (LCD, 7-seg, buzzer)
🔹 State machine design
🔹 Real-time systems programming
🔹 Software architecture and design patterns
🔹 Code optimization techniques



