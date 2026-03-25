####################################################################
#
# Makefile for CMPT 125 Spring 2026, SFU Surrey.
#
#####################################################################

#
# Assignment 5 makefile
#

# Set the C++ compiler options:
#   -std=c++17 
#    compiles using the C++17 standard
#   -Wall
#    turns on all warnings
#   -Wextra 
#    turns on even more warnings
#   -Werror
#    causes warnings to be errors 
#   -Wfatal-errors
#    stops the compiler after the first error
#   -Wno-sign-compare
#    turns off warnings for comparing signed and unsigned numbers
#   -Wnon-virtual-dtor
#    warns about non-virtual destructors
#   -g
#    puts debugging info into the executables (makes them larger)
#   -fsanitize=address
#    turns on address sanitization; don't use if using macOS leaks
#   -fsanitize=leak
#    turns on leak sanitization
#    (some compilers don't support -fsanitize)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor #-fsanitize=address -fsanitize=leak #-g
