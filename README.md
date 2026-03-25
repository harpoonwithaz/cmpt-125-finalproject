## Final Project: Connect Four (Plus!)

In this project, your task is to create a 
**[Connect Four](https://en.wikipedia.org/wiki/Connect_Four)** 
game on a board with 6 rows and 7 columns. In addition to 
[the usual rules](https://en.wikipedia.org/wiki/Connect_Four), 
each player gets a special **anvil** piece (described below).

See the marking scheme below for the features and functionality.

## Working with a Partner

You can do this project on your own, or with a partner.

If you want to work with a partner, you must sign up for a team on Canvas.

If you do work with a partner, both you and your partner must do an equal amount
of work, and you must *both* understand the whole program (even parts you did
not write!). Markers will also expect that projects done by teams of 2 to have
more features/functionality/polish than single-person projects.

Teams of more than 2 are **not** permitted under any circumstances.

## Project Report

Along with the code for your project, please also fill out and submit a
[a5_report.txt](a5_report.txt) file. Fill in each section as described in the
file.

## General Implementation Constraints

Please use only standard C++ techniques as discussed in the course. Only use
code written by you (and your partner, if you have one). If you do use C++
features not discussed in the course please cite the source and be prepared to
explain how they work and why you used them.

You can `#include` any header files you need as long as they are from standard
C++. Do **not** use any other libraries or frameworks from outside standard C++.

## Hints

- Get a screen-printing function working first. That will help you test the rest
of your code.
- Before making a smart computer strategy, make one that, say, makes a random
legal move. That's useful for testing that your game logic is working.
- While you are not *required* to use classes/OOP for this assignment, you can
if you think it would be useful. 
- Consider using an `enum class` for the different types of pieces.

## Submitting Your Work

On Canvas, please submit `a5.zip`, containing `a5.cpp` and `a5_report.txt`,
anything else needed to compiler and run your project (it's fine if all your
source code is in `a5.cpp`). Make sure your program can be compiled by typing
`make a5` with the [assignment makefile](makefile), and that it runs by typing
`./a5`.

Be sure to include the filled-in [a5_report.txt](a5_report.txt) file.

## Basic Requirements

- **Your programs must compile using the [assignment makefile](makefile)**. A
standard Linux/Unix compiler will be used, e.g. g++or c++. If your program
doesn't compile, then the marker might spend a minute or two checking it to see
if the problem is a simple mistake or typo. But if they can't quickly and easily
fix it, then they will mark it as 0. Ensuring your program compiles is your
responsibility. Please note that if you choose to develop your programs without
using the [assignment makefile](makefile), you are still responsible for
ensuring it compiles and runs properly with it.
- **The student info and statement of originality is in each file**. If either
is missing/incomplete, then the program might not be marked.

## Checking for Memory Errors

Memory-related errors are common in C++ programming, and so here are some tools
to help you find them.

### Valgrind (Linux)

`valgrind` helps find memory leaks and other memory errors. After you install
it, you can run it like this:

```bash
$ valgrind ./a5
  
// ... lots of output ... 
```

A program is considered to have no memory error if:

- In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
  lost` must all be 0.
- The `ERROR SUMMARY` reports 0 errors.
- It is usually okay if **still reachable** reports a non-zero number of bytes.

### Leaks (macOS)

`leaks` is a tool that comes with macOS and that can help you find memory leaks
and other memory errors. You can run it like this:

```bash
$ leaks -atExit -- ./a5
  
// ... lots of output ...

leaks Report Version: 4.0, multi-line stacks
Process 52960: 187 nodes malloced for 15 KB
Process 52960: 0 leaks for 0 total leaked bytes.
```

### Compiler Sanitizers

The compiler has some built-in tools to help find memory errors. You can use
them like this:

```bash
$ g++ -fsanitize=address -fsanitize=leak -g a5.cpp -o a5
```

On some systems `-fsanitize=leak` is not supported, so in that case use just
`-fsanitize=address`.

Also, tools like `leaks` might not work if you compile with
`-fsanitize=address`. So remove that option when you use `leaks`.

## Marking Scheme

If you're working with a partner, then both partners will get the same marks.

## Game Interaction

**1 mark** Asking the player if they want to play against the computer or
against another person. If they choose to play against another person, then they
should be asked for the names of the two players, and they take turns playing
moves with no computer involved.

**1 mark** Asking the player at the start if they want to go first or second, or
to randomly decide.

**1 mark** Clearly printing the state of the board after each move, and a legend
saying what all the characters mean.

**1 mark** If the board is "big", i.e. pieces are printed as 3x3 (or bigger)
squares of characters, rather than single characters. For example, a regular
piece could be:

```
xxx
xxx
xxx
```

An anvil could be:

```
xxx
xAx
xxx
```

**1 mark** An easy-to-understand way to make moves, e.g. the player picks the
column they want to drop their piece in.

**2 marks** Re-asking the player for a move if they make an invalid move, e.g.
dropping a piece in a full column, giving a non-existent column, or giving input
that is not a valid column name/number.

**1 mark** Correctly recognizing when a player has won the game, or if the game
is a tie, and announcing the winner or if it's a tie.

**1 mark** Asking the user if they want to play again after the game ends.

## Computer Strategy

**5 marks** For a computer that plays as intelligently. At the very least it
should always win if it is possible to win on the next turn. It should also try
to never make a move that would let the opponent win on the next turn. If you
want it to play even better, do some research on the **minimax algorithm**.

## The Anvil Piece

**3 marks** Implementing the anvil piece. Each player can play at most one anvil
per game, and it counts as a piece of their color. When dropped it destroys all
the pieces in the column (even the opponent's anvil, if it's there), and then
stays at the bottom of the column like a regular piece. You *cannot* drop an
anvil in a column that is already full. If dropped into an empty column, it goes
to the bottom of the column like a regular piece.

## Overall User Interface

**3 marks** Overall user interface quality. It should be clear, easy to read,
and visually appealing with perfect spelling and grammar. Obviously low-effort
interfaces may lose marks.

**1 mark** A "title screen" that includes the name of the game and the basic
rules for playing, including a description of how the anvil piece works.

## Other

**1 mark** for including the filled-in [a5_report.txt](a5_report.txt) file. All
the parts are filled in as described there. Missing or low-effort files may lose
marks.

**1 mark** for being able to compile the program  by typing `make a5` with the
[assignment makefile](makefile), and that it runs correctly by typing `./a5`.

## Deductions

- up to **-10 marks** if you use an external library or framework that is not
standard C++.
- up to **-2 mark** if your program does not compile using the [assignment
makefile](makefile). Depends on the severity of the error.
- up to **-5 marks** if your program has any memory leaks or other memory errors
(e.g. found using `valgrind` or `leaks`).
- up to **-1 mark** if your file does not have the correct name, or you submit
it in an incorrect format.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
the header of your file.
- **a score of 0** if you submit a "wrong" non-working file, and then *after the
due date* submit the "right" file. If you can provide evidence that you
finished the assignment on time, then it may be marked (probably with a late
penalty).
- Other deductions may be possible, depending on particular case.
