# C Language Mini Projects for Beginners

A collection of small, hands-on C programs written while learning the language from the ground up. Each file is a standalone project that focuses on a specific set of beginner concepts: `printf`/`scanf`, variables and data types, conditionals, `switch` statements, loops, functions, strings, and the standard math library.

The projects are intentionally simple. They are learning artifacts, not production software, so some of them are deliberately unfinished or contain bugs that are part of the learning journey. The **Project Status** table below is honest about which programs build and run today and which ones still need work.

**Author:** Victor Mwendwa

---

## Table of Contents

- [What You Need](#what-you-need)
- [Installation Guide](#installation-guide)
  - [Windows](#windows)
  - [macOS](#macos)
  - [Linux](#linux)
  - [VS Code Setup](#vs-code-setup)
- [How to Compile and Run](#how-to-compile-and-run)
  - [The General Pattern](#the-general-pattern)
  - [Compile Everything at Once](#compile-everything-at-once)
- [Project Overview](#project-overview)
- [The Projects in Detail](#the-projects-in-detail)
  1. [Age Checker & Room Assigner](#1-age-checker--room-assigner-agecheckerroomassignerc)
  2. [Basic Calculator](#2-basic-calculator-basiccalculatorc)
  3. [Compound Interest Calculator](#3-compound-interest-calculator-compouninterestcalcc)
  4. [Circle & Sphere Computations](#4-circle--sphere-computations-computationsc)
  5. [Weekly Study Plan](#5-weekly-study-plan-dailyweekplanc)
  6. [Rock Paper Scissors](#6-rock-paper-scissors-rockpaperscissorsc)
  7. [Shopping Cart](#7-shopping-cart-shoppingcartc)
  8. [Gamified String Story](#8-gamified-string-story-stringgamifiedc)
  9. [Temperature Converter](#9-temperature-converter-temperatureconverterc)
  10. [Student Input Profile](#10-student-input-profile-userinputlessonc)
  11. [Weight Converter](#11-weight-converter-weightconverterc)
- [Repository Structure](#repository-structure)
- [Known Issues & Learning Notes](#known-issues--learning-notes)
- [Troubleshooting](#troubleshooting)
- [Suggested Learning Order](#suggested-learning-order)
- [Sign-Off](#sign-off)

---

## What You Need

At minimum you need:

| Requirement | Why |
| --- | --- |
| A C compiler (GCC recommended) | Turns each `.c` file into an executable program |
| A text editor or IDE | VS Code is recommended, but Notepad++, Sublime Text, or a terminal editor works too |
| A terminal | To compile and run the programs |
| `math.h` (ships with GCC) | Used by the compound interest and geometry programs |

There is **no package manager, framework, or external library** to install. Every include in this repository (`stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`, `math.h`, `time.h`) is part of the standard C library that comes with the compiler.

> **Note on the `-lm` flag:** On Linux, programs that use `math.h` (`pow`, `sqrt`, etc.) usually need `-lm` at the end of the compile command. On Windows with MinGW it is normally unnecessary, but adding it does no harm.

---

## Installation Guide

### Windows

The `.vscode` configuration in this repository expects GCC at `C:/MinGW/bin/gcc.exe`, so **MinGW** is the path of least resistance on Windows.

**Option A — MinGW-w64 via MSYS2 (recommended, modern):**

1. Download and install [MSYS2](https://www.msys2.org/).
2. Open the MSYS2 UCRT64 terminal and run:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
3. Add the toolchain to your PATH. The default location is:
   ```
   C:\msys64\ucrt64\bin
   ```
4. Verify in a new terminal:
   ```powershell
   gcc --version
   ```

**Option B — MinGW.org (matches the existing `.vscode` config):**

1. Install MinGW so that `gcc.exe` lives at `C:\MinGW\bin\gcc.exe`.
2. Add `C:\MinGW\bin` to the Windows **PATH**.
3. Verify:
   ```powershell
   gcc --version
   ```
   If you see a version line, you are ready. If PowerShell says `gcc is not recognized`, the PATH entry is missing or the terminal was not restarted.

**Option C — w64devkit (portable, no installer):**

1. Download [w64devkit](https://github.com/skeeto/w64devkit/releases).
2. Extract it anywhere, for example `C:\w64devkit`.
3. Run `w64devkit.exe` to get a shell that already has GCC and GDB on the PATH.

### macOS

Install the Apple Command Line Tools, which include `clang` (a GCC-compatible compiler):

```bash
xcode-select --install
```

Verify:

```bash
gcc --version    # on macOS this usually reports Apple clang
```

If you prefer real GCC:

```bash
brew install gcc
```

### Linux

**Debian / Ubuntu / Mint:**

```bash
sudo apt update
sudo apt install build-essential
```

**Fedora:**

```bash
sudo dnf install gcc make
```

**Arch:**

```bash
sudo pacman -S gcc
```

Verify:

```bash
gcc --version
```

### VS Code Setup

1. Install [Visual Studio Code](https://code.visualstudio.com/).
2. Install the **C/C++** extension from Microsoft (`ms-vscode.cpptools`).
3. Optionally install **Code Runner** (`formulahendry.code-runner`) for a one-click Run button.
4. Open this folder in VS Code (`File → Open Folder`).
5. The included `.vscode/c_cpp_properties.json` points IntelliSense at `C:/MinGW/bin/gcc.exe`. If your compiler lives somewhere else, update `compilerPath` to match your installation.
6. `.vscode/launch.json` is set up for a GDB debug session (requires `gdb` on your PATH).
7. There is **no `tasks.json`**, so the built-in `Ctrl+Shift+B` build task is not configured. Use the terminal commands below, or add your own task.

> `.vscode` is listed in `.gitignore`, so these editor settings are local to your machine and will not be committed.

---

## How to Compile and Run

### The General Pattern

Compile a single file:

```bash
gcc filename.c -o programName
```

Run it:

**Windows (PowerShell or CMD):**

```powershell
.\programName.exe
```

**macOS / Linux:**

```bash
./programName
```

If the program uses `math.h`, add `-lm` on Linux/macOS:

```bash
gcc compounInterestCalc.c -o compound -lm
./compound
```

> **Important:** this folder path contains spaces (`C:\Art Folder\...`). Always wrap the path in quotes when compiling from outside the folder. The examples below assume you are already inside the project folder, where quoting is not needed.

Each program is interactive. After you start it, type your answers and press **Enter**.

### Compile Everything at Once

Because each file has its own `main()`, you must compile them **separately** — do not pass all `.c` files to a single `gcc` command, or the linker will complain about multiple definitions of `main`.

**PowerShell (Windows):**

```powershell
Get-ChildItem -Filter *.c |
  Where-Object { $_.Name -ne 'tempCodeRunnerFile.c' } |
  ForEach-Object {
    $name = [System.IO.Path]::GetFileNameWithoutExtension($_.Name)
    gcc $_.FullName -o "$name.exe" -lm
    if ($LASTEXITCODE -eq 0) { Write-Host "Built $name.exe" }
    else { Write-Host "FAILED: $($_.Name)" }
  }
```

**Bash (macOS / Linux):**

```bash
for f in *.c; do
  [ "$f" = "tempCodeRunnerFile.c" ] && continue
  name="${f%.c}"
  gcc "$f" -o "$name" -lm && echo "Built $name" || echo "FAILED: $f"
done
```

> `tempCodeRunnerFile.c` is excluded on purpose — it is an auto-generated scratch file with no `main()` and will not link.

To remove all build artifacts:

**PowerShell:**

```powershell
Get-ChildItem -Filter *.exe | Remove-Item
```

**Bash:**

```bash
rm -f $(ls *.c | sed 's/\.c$//')
```

---

## Project Overview

| # | File | Project | Core Concepts | Builds Today? |
| --- | --- | --- | --- | --- |
| 1 | `ageCheckerRoomAssigner.c` | Age Checker & Room Assigner | Functions, `if`/`else if`, string input | Yes |
| 2 | `basicCalculator.c` | Basic Calculator | Menu, `switch`, arithmetic, division guards | No (missing brace) |
| 3 | `compounInterestCalc.c` | Compound Interest Calculator | `math.h`, `pow`, `double` math | Yes |
| 4 | `computations.c` | Circle & Sphere Computations | `pow`, `const`, geometry formulas | Yes |
| 5 | `dailyWeekPlan.c` | Weekly Study Plan | `switch`, `fgets`, validation flags | Yes |
| 6 | `RockPaperScissors.c` | Rock Paper Scissors | Function stubs, `rand`, game loops | No (skeleton only) |
| 7 | `shoppingCart.c` | Shopping Cart | `bool`, strings, totals, ternary | No (missing `;`) |
| 8 | `stringGamified.c` | Gamified String Story | `fgets`, string cleanup, Mad Libs | Yes |
| 9 | `temperatureConverter.c` | Temperature Converter | `if`/`else`, float formulas | Yes |
| 10 | `userInputLesson.c` | Student Input Profile | `fgets`, `scanf`, ternaries | Yes |
| 11 | `weightConverter.c` | Weight Converter | Menu, conversion factors | Yes |

"Builds Today?" reflects whether the file compiles with GCC as it currently stands. The two-column detail below explains every issue so each one can be fixed as an exercise.

---

## The Projects in Detail

### 1. Age Checker & Room Assigner (`ageCheckerRoomAssigner.c`)

**Purpose:** Simulates the check-in desk for a weekend psychology seminar at Matopeni School. Students enter their name and age, and the program assigns them to a room based on age bands.

**What it demonstrates:**
- Declaring and calling a function that takes a parameter (`void studAgeCheck(int studAge)`).
- Multi-branch `if` / `else if` / `else` logic, ordered from the highest age band to the lowest.
- Reading a name with `fgets` and stripping the trailing newline safely with `strcspn`.
- Reading numbers with `scanf`, including the address-of operator.
- Basic input validation (empty name and invalid age).

**Room rules:**

| Age | Room |
| --- | --- |
| 18 and above | Room 6 |
| Exactly 17 | Room 5 |
| 15 to 16 | Room 4 |
| 13 to 14 | Room 3 |
| 10 to 12 | Room 2 |
| Below 10 | Room 1 |

**How it works:**

1. `main` reads the student's full name with `fgets` and replaces the trailing newline with `'\0'` using `name[strcspn(name, "\n")] = '\0';`.
2. It rejects an empty name and stops with a return code of `1`.
3. It reads the age with `scanf("%d", &studAge);` and rejects any age below `1`.
4. It calls `studAgeCheck(studAge)`, which walks the ordered `if` / `else if` chain and prints the matching room.
5. Because the highest band is checked first, every range is reachable. There are no overlapping conditions.

**Expected flow:**

```
Enter your name : Victor
Enter your age : 18
Hello Victor, You are to go to Room 6
```

More examples:

```
Enter your name : Amina
Enter your age : 17
Hello Amina, You are to go to Room 5
```

```
Enter your name : Brian
Enter your age : 9
Hello Brian, You are to go to Room 1
```

**Current status:** Builds and runs. The earlier version had several beginner bugs, which are now fixed:

1. `char name[] = '';` became `char name[50] = "";` so the name buffer has real storage.
2. `if(studAgeCheck >= 17)` compared the function pointer instead of the parameter; it now uses `studAge`.
3. The unreachable `== 17` branch is now reachable because the top branch checks `> 17`.
4. `scanf("%d", studAge);` now passes the address: `scanf("%d", &studAge);`.
5. `studAgeCheck();` now receives its argument: `studAgeCheck(studAge);`.
6. The age bands are ordered correctly, so Rooms 1 through 6 can all be assigned.
7. The name is now used in the greeting instead of being read and ignored.

---

### 2. Basic Calculator (`basicCalculator.c`)

**Purpose:** A menu-driven calculator that performs addition, subtraction, multiplication, or division on two numbers.

**What it demonstrates:**
- A numbered menu printed with a single `printf`.
- Nested decision-making: an `if`/`else if` chain selects the operation, then a `switch` performs it.
- `double` arithmetic with `%lf` for input and `%.1lf` for output.
- Guarding division against zero (and the special `0 / 0` case).
- Commented-out placeholders for future operations (modulo, power, square root, factorial, trigonometry, logarithms).

**Expected flow:**

```
 === The Basic Calculator ===
 1. Add
 2. Subtract
 3. Multiply
 4. Divide
0. Exit
Do enter your choice of operation : 1
Enter the first number : 12
Enter the second number : 8
Result : 12.0 + 8.0 = 20.0
```

**Current status:** Does not compile. `gcc` reports `expected '}' before 'else'` at line 72. The `if (userChoice >= 1 && userChoice <= 4) { ... }` block is never closed before the `else`. Add a closing `}` after the `switch` statement (after line 71).

**Other observations:**
- The division branch `else if (num1 == 0)` prints `0 / 0` after already failing the `num2 != 0` check. That path triggers undefined behaviour mathematically; the message "the result MUST be 0" is incorrect. It should print a single "cannot divide by zero" error.
- The program runs once and exits. There is no loop to perform a second calculation (the commented-out `programStatus` hints this was planned).
- Invalid menu choices are handled correctly by the final `else`.

---

### 3. Compound Interest Calculator (`compounInterestCalc.c`)

**Purpose:** Calculates the future value of an investment using the compound interest formula:

```
A = P × (1 + r/n)^(n×t)
```

Where:

| Symbol | Meaning | Program variable |
| --- | --- | --- |
| `P` | Principal (starting amount) | `principal` |
| `r` | Annual interest rate, as a decimal | `rate` (converted from percent) |
| `n` | Times compounded per year | `timesCompounded` |
| `t` | Number of years | `years` |
| `A` | Final amount | `total` |

**What it demonstrates:**
- Including and using `math.h` for `pow()`.
- Mixing `int` and `double` variables.
- Converting a percentage to a decimal (`rate = rate / 100`).
- Chained `scanf` calls for multiple inputs.

**Expected flow:**

```
Compund Interest Calculator
Enter the principal (P): 1000
Enter the interest rate % (r): 5
Enter the number of year (t) : 10
Enter number of times compounded per year (n): 12
After the 10 years, the total will be $1647.01
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- The program does not validate `timesCompounded`. Entering `0` causes division by zero inside `pow`, producing `inf`.
- The output has no trailing newline, so the shell prompt appears on the same line.
- Typo in the title: "Compund" should be "Compound".
- Try adding input validation and a loop to compare different compounding frequencies.

---

### 4. Circle & Sphere Computations (`computations.c`)

**Purpose:** Given a radius, calculates three measurements:

- **Area of a circle:** `πr²`
- **Surface area of a sphere:** `4πr²`
- **Volume of a sphere:** `(4/3)πr³`

**What it demonstrates:**
- `const` values (`const double PI = 3.14159;`).
- `pow()` for squaring and cubing.
- Floating-point division and operator precedence: `(4.0 / 3.0)` is used instead of `(4 / 3)` so the result is not truncated to `1`.
- Formatting output to two decimal places with `%.2lf`.

**Expected flow (for radius `3`):**

```
Enter the radius: 3
Area: 28.27
Surface area: 113.10
Volume of Sphere : 113.10
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- The last two `printf` calls are missing `\n`, so their output runs together on one line.
- `PI` is hard-coded to 5 decimal places. For better precision, include `math.h` and use `M_PI` (or define `3.141592653589793`).
- There is no validation for a negative radius.

---

### 5. Weekly Study Plan (`dailyWeekPlan.c`)

**Purpose:** Asks for the user's name, then prints the study or activity plan for a chosen day of the week. It is a personal weekly schedule for learning C.

**Day codes:**

| Key | Plan |
| --- | --- |
| `M` | Learn C basics from freeCodeCamp |
| `T` | Work on functions |
| `W` | Build a random number guessing game |
| `R` | Do the daily activity: temperature converter |
| `F` | Collect links to other C content |
| `S` | Networking day at the Nairobi Hackathon |
| `U` | Rest and meditation day |

**What it demonstrates:**
- Reading a full line with `fgets` and removing the newline safely (it checks `strlen(name) > 0` first).
- Reading a single character with `scanf("%c", ...)`.
- `switch` with `break` and `default`.
- A `validDay` flag used after the `switch` to decide the final message.

**Expected flow:**

```
Enter your name: Victor
Enter a day of the week ( M, T, W, R, F, S, U): W
 Craft a random guessing number
Dear Victor,your plan for the day has been processed successfully
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- Input is case-sensitive: lowercase `m` falls into `default`. Normalize with `toupper()` from `ctype.h`.
- The cleanup line removes the last character of the name even if the input was not newline-terminated (for example, if the name filled the buffer). A safer approach is `name[strcspn(name, "\n")] = '\0';`.
- The program could loop so the user can check several days without restarting.

---

### 6. Rock Paper Scissors (`RockPaperScissors.c`)

**Purpose:** Intended to be a playable Rock Paper Scissors game against the computer, using `rand()` for the computer's move and a `checkWinner` function to compare choices.

**What it demonstrates (when finished):**
- Function declarations and definitions (`getComputerChoice`, `getUserChoice`, `checkWinner`).
- Random numbers via `stdlib.h` + `time.h` (`srand(time(NULL))`, `rand() % 3`).
- Passing arguments and returning values.
- Comparing two choices and reporting a win, loss, or draw.

**Current status:** Skeleton only. It does not compile because the function declarations inside `main` are not terminated with semicolons, `printf("")` appears as a statement before any executable code after a declaration, and the function bodies are empty.

**Suggested implementation plan:**
1. Move the prototypes above `main` and end each with `;`:
   ```c
   int getComputerChoice(void);
   int getUserChoice(void);
   void checkWinner(int userChoice, int computerChoice);
   ```
2. In `main`, seed the generator: `srand((unsigned)time(NULL));`.
3. `getComputerChoice` returns `rand() % 3` (0 = rock, 1 = paper, 2 = scissors).
4. `getUserChoice` prints a menu and returns 0, 1, or 2.
5. `checkWinner` prints the result: equal choices are a draw; rock beats scissors, paper beats rock, scissors beats paper.
6. Wrap the round in a `do { ... } while (playAgain)` loop.

---

### 7. Shopping Cart (`shoppingCart.c`)

**Purpose:** A single-item checkout: the user names an item, enters a unit price and a quantity, and the program computes the total.

**What it demonstrates:**
- Reading a string with `fgets` and stripping the newline.
- `stdbool.h` and a `bool` flag (`hasPaid`).
- `float` arithmetic for money.
- A ternary operator used for the final message.

**Expected flow:**

```
What item would you like to buy?: Stanley Cup
What is the price for each?: 26.23
How many would you like?: 7
Here is the resultant summation:$ 183.61
Our esteemed customer,you have successfully purchased 7 Stanley Cup/s.Do have a lovely nice day!
```

**Current status:** Does not compile. Two problems:

1. Line 20 is missing a semicolon: `item[strlen(item)- 1] = '\0'` → add `;`.
2. `hasPaid` is initialized to `false` and never set to `true`, so the ternary always prints the error branch. Set it to `true` after a successful calculation, or replace the flag with a direct success message.

**Notes and possible improvements:**
- `#include <string.h>` is currently unused except for `strlen` (needed), so keep it.
- The newline removal can read `item[-1]` if `fgets` fails or reads an empty line. Guard with `if (strlen(item) > 0)` or use `item[strcspn(item, "\n")] = '\0';`.
- Money should ideally use integer cents or `double`, not `float`, to avoid rounding errors.
- The cart supports only one item. A natural next step is an array of items with a running total inside a loop.

---

### 8. Gamified String Story (`stringGamified.c`)

**Purpose:** A Mad Libs-style word game. The user supplies adjectives, a noun, a verb, and an adverb, and the program inserts them into a pre-written story.

**What it demonstrates:**
- Several string buffers and `fgets` for each prompt.
- Removing the trailing newline after every `fgets`.
- String substitution with `printf` placeholders (`%s`).
- The importance of prompt order versus sentence order.

**Expected flow:**

```
Enter an adjective (Hint : Description): cute
Enter an noun (Hint :An animal or person): girl
Enter an adjective (Hint : Description): fast
Enter an verb (Hint : Ends with  -ing): interesting
Enter an adverb (Hint : Description of a verb): admire

In our reknowned school the top girl is always cute.
.Moroever, she is interesting and fast to score in class assignments.We all admire her prowess and aim to be better than her.
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- The prompts and the story use the words in a different order. The second adjective prompt fills `adjective2`, but the story prints `verb` before `adjective2`, so the sentence reads oddly. Reorder the `printf` arguments or reorder the prompts.
- "reknowned" should be "renowned", and "Moroever" should be "Moreover".
- There is a stray leading period before "Moreover" and no space after it.
- The same newline-removal edge case applies: guard with `strlen(...) > 0` or use `strcspn`.

---

### 9. Temperature Converter (`temperatureConverter.c`)

**Purpose:** Converts a temperature between Celsius and Fahrenheit.

**Formulas used:**

```
F = (C × 9/5) + 32
C = (F − 32) × 5/9
```

**What it demonstrates:**
- A two-option character menu (`C` or `F`).
- `if` / `else if` / `else` validation.
- Floating-point arithmetic and formatted output with `%.1f`.

**Expected flow:**

```
Temperature Converter
C. Celsius to Fahrenheit
F. Fahrenheit to Celsius
Is the temperature in Celsius(C) or Fahrenheit (F)?:  C
Enter the Temperature in Celsius : 100
Based on the conversion set above,then 100.0 Celsius is equal to 212.0 Fahrenheit
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- Only uppercase `C` and `F` are accepted. Use `toupper(choice)` (from `ctype.h`) to accept lowercase too.
- Add a `\n` after the output.
- Consider adding Kelvin as a third option.

---

### 10. Student Input Profile (`userInputLesson.c`)

**Purpose:** Collects a university student's name, age, KCSE mean score, and KCSE grade, then prints a short profile.

**What it demonstrates:**
- Reading mixed input types: `fgets` for a string, `scanf` for `int`, `float`, and `char`.
- Using `scanf(" %c", &grade)` with a leading space so leftover whitespace/newlines are skipped.
- Ternary operators used for simple validation messages.
- Formatting floats with `%.2f`.

**Expected flow:**

```
Enter your name: Victor
Enter your curent age: 19
Enter your KCSE Mean Score:
8.75
Enter your KCSE Grade:
B+
My name is Victor
I am 19 years old
This is the score i amassed in the KCSE: 8.75
I had a grade of B+ in the KCSE
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- The ternary operators only **print** a message; they do not re-prompt or stop the program. An age of `10` still continues after printing "Kindly enter your curent age again". A `while` loop with a real condition would be better.
- `strlen(name) == 0` rarely triggers because `fgets` keeps the newline; after stripping, an empty Enter becomes `""` only if the strip logic is adjusted. Use `name[strcspn(name, "\n")] = '\0';` for robust handling.
- `name[strlen(name)-1] = '\0';` can underflow if no characters are read. Guard it.
- Typos: "curent" → "current", "Unversity" → "University".
- The prompt for the mean score says "KCSE Mean Score" but the variable is named `gpa`; renaming it to `meanScore` would be clearer.

---

### 11. Weight Converter (`weightConverter.c`)

**Purpose:** Converts weight between kilograms and pounds.

**Conversion factor used:** `1 kg = 2.20462 lb`

**What it demonstrates:**
- A numbered menu and `scanf` for the choice.
- Two-way `if` / `else if` / `else` branching.
- Multiplication and division with `float`.

**Expected flow:**

```
Weight Conversion Calculator
1. Kilograms to Pounds
2. Pounds to Kilograms
Enter your choice to execute(1 0r 2): 1
Enter the weight in Kilograms: 70
70.0 is equal to 154.3 pounds
```

**Current status:** Compiles and runs.

**Notes and possible improvements:**
- In the pounds-to-kilograms branch, the output label is wrong: it prints `"%.1f is equal to %.1f pounds"` when the second value is actually in **kilograms**. Change the unit to `kilograms`.
- Typo in the menu prompt: "1 0r 2" → "1 or 2".
- The prompt `"Enter the weight in pounds\n"` is missing a colon.
- There is no validation for negative weights.
- A `switch` statement would be a clean alternative to the `if` chain.

---

## Repository Structure

```
C-language Mini Projects for beginners/
├── .git/
├── .gitignore                  # currently ignores .vscode
├── .vscode/
│   ├── c_cpp_properties.json   # IntelliSense + compiler path (C:/MinGW/bin/gcc.exe)
│   ├── launch.json             # GDB debug configuration
│   └── settings.json
├── README.md                   # this file
├── ageCheckerRoomAssigner.c    # 1. age-based room assignment
├── basicCalculator.c           # 2. four-function calculator
├── compounInterestCalc.c       # 3. compound interest
├── computations.c              # 4. circle and sphere geometry
├── dailyWeekPlan.c             # 5. weekly study planner
├── RockPaperScissors.c         # 6. game skeleton (unfinished)
├── shoppingCart.c              # 7. single-item shopping cart
├── stringGamified.c            # 8. Mad Libs story generator
├── tempCodeRunnerFile.c        # scratch file auto-created by Code Runner (no main)
├── temperatureConverter.c      # 9. Celsius <-> Fahrenheit
├── userInputLesson.c           # 10. student profile input demo
└── weightConverter.c           # 11. kilograms <-> pounds
```

**`tempCodeRunnerFile.c`** deserves a note: it is generated automatically by the VS Code Code Runner extension and contains only a commented `switch` template. It is not a project, has no `main()`, and will fail to link if you compile it. Safe to delete or exclude from build scripts.

---

## Known Issues & Learning Notes

There are two kinds of files in this repository: complete, runnable programs and works-in-progress. Rather than hide the rough edges, they are documented here so they can be used as debugging practice.

### Does not compile yet

| File | First error | Fix direction |
| --- | --- | --- |
| `basicCalculator.c` | `expected '}' before 'else'` | Close the `else if (userChoice >= 1 && userChoice <= 4)` block after the `switch` |
| `RockPaperScissors.c` | `expected declaration specifiers before 'printf'` | Add semicolons to prototypes, move them outside `main`, implement the three functions |
| `shoppingCart.c` | `expected ';' before 'printf'` | Add the missing semicolon on the newline-stripping line, set `hasPaid = true` on success |
| `tempCodeRunnerFile.c` | `undefined reference to 'WinMain@16'` | Not a program — delete it or exclude it from builds |

`ageCheckerRoomAssigner.c` previously appeared in this table. It now builds and runs after the fixes described in its section above.

### Compiles but has logic or presentation bugs

| File | Issue |
| --- | --- |
| `computations.c` | Missing newlines cause the surface area and volume to print on the same line |
| `weightConverter.c` | Pounds-to-kilograms result is labelled "pounds" |
| `stringGamified.c` | Words are printed in a different order than they are collected |
| `userInputLesson.c` | Validation ternaries only print a warning and then continue |
| `compounInterestCalc.c` | No guard against `n = 0` (division by zero) |

### Cross-cutting lessons

1. **`fgets` keeps the newline.** Every string input in this repo strips the last character. The robust pattern is:
   ```c
   name[strcspn(name, "\n")] = '\0';
   ```
2. **`scanf` needs addresses.** Use `scanf("%d", &age)`, not `scanf("%d", age)`.
3. **Check `fgets` return values.** If input fails, `strlen(name)` may be `0`, and `name[strlen(name) - 1]` becomes an out-of-bounds write.
4. **Integer division truncates.** Write `9.0 / 5.0` or `(4.0 / 3.0)` when you need a fractional result.
5. **Division by zero is undefined.** Always check the divisor before dividing.
6. **`if` branches are evaluated top to bottom.** An early broad condition such as `age >= 13` makes later narrower conditions unreachable.
7. **One `main` per executable.** Compile each `.c` file separately.

---

## Troubleshooting

**`gcc` is not recognized as an internal or external command**

Your compiler is not on the PATH. Add its `bin` folder (for example `C:\MinGW\bin` or `C:\msys64\ucrt64\bin`) to the PATH, then close and reopen the terminal.

**`undefined reference to 'pow'` / `'sqrt'`**

Add `-lm` to the end of the compile command:

```bash
gcc compounInterestCalc.c -o compound -lm
```

**`multiple definition of 'main'`**

You passed more than one `.c` file to a single `gcc` invocation. Compile each file separately.

**`undefined reference to 'WinMain@16'`**

You compiled `tempCodeRunnerFile.c`, which has no `main()`. Exclude it from your build.

**The program closes immediately on Windows**

Run it from a terminal (`.\program.exe`) rather than double-clicking the `.exe`. The terminal stays open and shows the output.

**Garbled or skipped input when mixing `scanf` and `fgets`**

`scanf` leaves the newline in the input buffer. Either read the whole line with `fgets` and parse it, or consume the leftover newline (for example `scanf(" %c", &c)` with a leading space, or a loop that reads until `\n`).

**`launch.json` cannot find `gdb`**

Install a toolchain that ships GDB (MinGW-w64, w64devkit, or MSYS2) and make sure `gdb` is on the PATH, or set `miDebuggerPath` to the full path of `gdb.exe`.

**IntelliSense shows red squiggles but the code compiles**

Open `C:\Art Folder\C-language Mini Projects for beginners\.vscode\c_cpp_properties.json` and confirm `compilerPath` points to your actual `gcc.exe`.

---

## Suggested Learning Order

If you are using this repository to learn C, this order builds concepts gradually:

1. **`userInputLesson.c`** — input, output, variables, and data types.
2. **`temperatureConverter.c`** and **`weightConverter.c`** — conditionals and arithmetic.
3. **`computations.c`** — `math.h`, `const`, and geometry formulas.
4. **`compounInterestCalc.c`** — multi-input calculations with `pow`.
5. **`dailyWeekPlan.c`** — `switch`, character input, validation flags.
6. **`stringGamified.c`** — string buffers and `fgets`.
7. **`basicCalculator.c`** — menu design, `switch`, and defensive division.
8. **`shoppingCart.c`** — booleans, totals, and ternary expressions.
9. **`ageCheckerRoomAssigner.c`** — functions, input validation, and ordered multi-branch age logic.
10. **`RockPaperScissors.c`** — your first full game: randomness, functions, and loops.

Once those are comfortable, extend them: add loops so programs can run again, split logic into functions, and add input validation everywhere.

---

## Sign-Off

I have reviewed this repository, documented each project, and verified the build instructions against the current source files. The programs marked as runnable compile and execute as described, including the completed Age Checker & Room Assigner; the programs marked as works-in-progress are documented honestly with the fixes they need, and are left as exercises for continued learning.

**Signed off by:**

**Victor Mwendwa**
*Author & Maintainer*

*Documented on 6 November 2026*
