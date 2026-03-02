---
title: "Master Plan — 2000 C Programs"
type: meta
updated: 2026-03-02
---

# Master Plan — 2000 C Programs

> 200 batches × 10 programs each. Systems programming & security focused. Every detail of C.

## Execution Rules

1. Each batch = 10 programs (`.c` + `.md` pairs)
2. `.c` files: **no comments** — clean, compilable code
3. `.md` files: YAML frontmatter, concept, code block, output, takeaways, challenge, related links
4. Mark each batch complete in `PROGRESS.md` immediately after creation
5. Compile and test every `.c` file after each batch: `gcc -Wall -Wextra -std=c17`
6. Each program is self-contained and compilable with `gcc <file>.c -o <file>`

---

## Phase 1: Foundation (001–200) — Batches 1–20

### 01-Fundamentals (001–200)

| Batch | Programs | Status | Topic |
|-------|----------|--------|-------|
| 1 | 001–010 | ⬜ | Hello World, main(), Compilation, Preprocessor |
| 2 | 011–020 | ⬜ | Integer Types, Floating Point, Characters, Variables |
| 3 | 021–030 | ⬜ | Type Properties, sizeof, Limits, Qualifiers, Storage |
| 4 | 031–040 | ⬜ | Constants, Literals, #define, enum, const |
| 5 | 041–050 | ⬜ | printf Deep Dive, Format Specifiers, Field Width |
| 6 | 051–060 | ⬜ | scanf & Input, getchar/putchar, Buffer Handling |
| 7 | 061–070 | ⬜ | Arithmetic Operators, Precedence, Type Promotion |
| 8 | 071–080 | ⬜ | Comparison & Logical Operators, Boolean Logic |
| 9 | 081–090 | ⬜ | Bitwise Operators, Bit Manipulation Patterns |
| 10 | 091–100 | ⬜ | Conditionals: if, else, switch, ternary |
| 11 | 101–110 | ⬜ | Loops: while, do-while, for, break, continue |
| 12 | 111–120 | ⬜ | Arrays I: Declaration, Initialization, Access |
| 13 | 121–130 | ⬜ | Arrays II: 2D Arrays, Strings, VLA |
| 14 | 131–140 | ⬜ | Strings I: Basics, strlen, strcpy, strcat |
| 15 | 141–150 | ⬜ | Strings II: strtok, atoi, sprintf, ctype.h |
| 16 | 151–160 | ⬜ | Pointers I: Declaration, &, *, NULL |
| 17 | 161–170 | ⬜ | Pointers II: Arithmetic, Arrays, Pointer to Pointer |
| 18 | 171–180 | ⬜ | Functions I: Declaration, Parameters, Return |
| 19 | 181–190 | ⬜ | Functions II: Pass by Pointer, Recursion, Function Pointers |
| 20 | 191–200 | ⬜ | Memory & Preprocessor: malloc/free, #define, argc/argv |

---

## Batch Details — 01-Fundamentals

### Batch 1 (001–010): Hello World & Compilation Basics

| ID | Title | Description |
|----|-------|-------------|
| `001` | Hello World | First C program, printf, main function |
| `002` | Main Function Anatomy | int main(void), return 0, entry point |
| `003` | Return Values from Main | EXIT_SUCCESS, EXIT_FAILURE, error codes |
| `004` | Compilation Process | Preprocessing, compiling, assembling, linking |
| `005` | Preprocessor & #include | Header files, #include <> vs "" |
| `006` | Comments | Single-line //, multi-line /* */ |
| `007` | Compilation Errors vs Warnings | -Wall, -Wextra, -Werror |
| `008` | Multiple Source Files | Separate compilation, extern |
| `009` | Header Files Basics | .h files, include guards |
| `010` | Makefiles Introduction | Basic Makefile, compilation automation |

### Batch 2 (011–020): Variables & Data Types I

| ID | Title | Description |
|----|-------|-------------|
| `011` | Integer Type (int) | Basic integer, range, typical size |
| `012` | Integer Variants | short, long, long long |
| `013` | Unsigned Integers | unsigned int, unsigned long, range |
| `014` | Character Type (char) | Character storage, ASCII |
| `015` | Character as Integer | char is a small integer, arithmetic |
| `016` | Floating Point (float) | Single precision, IEEE 754 |
| `017` | Floating Point (double) | Double precision, default for literals |
| `018` | Long Double | Extended precision |
| `019` | Variable Declaration & Initialization | Declaring vs initializing |
| `020` | Multiple Variable Declaration | Same line declarations, pitfalls |

### Batch 3 (021–030): Variables & Data Types II

| ID | Title | Description |
|----|-------|-------------|
| `021` | sizeof Operator | Type and variable sizes |
| `022` | Integer Limits | limits.h: INT_MAX, INT_MIN, etc. |
| `023` | Float Limits | float.h: FLT_MAX, DBL_MAX, etc. |
| `024` | signed vs unsigned | Type modifiers, behavior |
| `025` | const Qualifier | Immutable variables |
| `026` | volatile Qualifier | Compiler optimization prevention |
| `027` | auto Storage Class | Automatic variables (default) |
| `028` | static Variables | Persistence, internal linkage |
| `029` | register Hint | Optimization suggestion |
| `030` | extern Declaration | External linkage, shared variables |

### Batch 4 (031–040): Constants & Literals

| ID | Title | Description |
|----|-------|-------------|
| `031` | Integer Literals | Decimal notation |
| `032` | Octal, Hex, Binary Literals | 0777, 0xFF, 0b1010 |
| `033` | Floating Point Literals | 3.14, 3.14f, 3.14e10 |
| `034` | Character Literals | 'A', 'a', '0' |
| `035` | Escape Sequences | \n, \t, \\, \', \" |
| `036` | String Literals | "Hello", string concatenation |
| `037` | #define Macros | Symbolic constants |
| `038` | const vs #define | Comparison, pros/cons |
| `039` | Enumeration (enum) | Named integer constants |
| `040` | Enum Advanced | Explicit values, flags |

### Batch 5 (041–050): printf & Output

| ID | Title | Description |
|----|-------|-------------|
| `041` | printf Basics | Basic output, format strings |
| `042` | Format Specifier %d %i | Signed integers |
| `043` | Format Specifier %u | Unsigned integers |
| `044` | Format Specifier %f %F | Floating point |
| `045` | Format Specifier %e %E | Scientific notation |
| `046` | Format Specifier %g %G | Shortest representation |
| `047` | Format Specifier %c | Characters |
| `048` | Format Specifier %s | Strings |
| `049` | Format Specifier %x %X %o | Hex and octal |
| `050` | Format Specifier %p | Pointers |

### Batch 6 (051–060): printf Advanced & scanf

| ID | Title | Description |
|----|-------|-------------|
| `051` | Field Width | Minimum width specifier |
| `052` | Precision | Decimal places, string truncation |
| `053` | Flags (-, +, space) | Left align, sign, space |
| `054` | Flags (0, #) | Zero padding, alternate form |
| `055` | printf Return Value | Characters printed |
| `056` | scanf Basics | Reading formatted input |
| `057` | scanf for Integers | %d, %i, %u |
| `058` | scanf for Floats | %f, %lf |
| `059` | scanf for Characters & Strings | %c, %s, buffer overflow |
| `060` | scanf Return Value | Successful conversions |

### Batch 7 (061–070): Input Deep Dive

| ID | Title | Description |
|----|-------|-------------|
| `061` | getchar() | Read single character |
| `062` | putchar() | Write single character |
| `063` | fgets() | Safe line input |
| `064` | puts() | Simple string output |
| `065` | Input Buffer Issues | Newline leftover, clearing |
| `066` | Input Validation | Checking scanf return |
| `067` | EOF and Sentinel Input | End-of-file detection |
| `068` | sscanf() | Parse strings |
| `069` | sprintf() | Format to string |
| `070` | snprintf() | Safe formatted string |

### Batch 8 (071–080): Arithmetic Operators

| ID | Title | Description |
|----|-------|-------------|
| `071` | Addition and Subtraction | + and - operators |
| `072` | Multiplication | * operator |
| `073` | Division | / operator, integer vs float |
| `074` | Integer Division Behavior | Truncation toward zero |
| `075` | Modulus Operator | % remainder |
| `076` | Increment ++ | Pre and post increment |
| `077` | Decrement -- | Pre and post decrement |
| `078` | Compound Assignment | +=, -=, *=, /=, %= |
| `079` | Unary Plus and Minus | + and - unary |
| `080` | Operator Precedence | PEMDAS in C |

### Batch 9 (081–090): Type Conversion & Promotion

| ID | Title | Description |
|----|-------|-------------|
| `081` | Implicit Type Conversion | Automatic promotion |
| `082` | Integer Promotion | char/short to int |
| `083` | Usual Arithmetic Conversions | Mixed type expressions |
| `084` | Explicit Type Casting | (type) cast operator |
| `085` | Casting Pitfalls | Loss of precision, overflow |
| `086` | Signed/Unsigned Conversion | Behavior and dangers |
| `087` | Float to Integer | Truncation behavior |
| `088` | Integer to Float | Precision considerations |
| `089` | Pointer Casting Basics | void* conversion |
| `090` | Safe Casting Patterns | Defensive programming |

### Batch 10 (091–100): Comparison & Logical Operators

| ID | Title | Description |
|----|-------|-------------|
| `091` | Equality Operators | == and != |
| `092` | Relational Operators | <, >, <=, >= |
| `093` | Logical AND | && operator |
| `094` | Logical OR | \|\| operator |
| `095` | Logical NOT | ! operator |
| `096` | Short-Circuit Evaluation | && and \|\| behavior |
| `097` | Truthiness in C | 0 is false, non-zero is true |
| `098` | Compound Boolean Expressions | Combining conditions |
| `099` | Common Comparison Mistakes | = vs ==, floating point |
| `100` | _Bool and stdbool.h | Boolean type in C99 |

### Batch 11 (101–110): Bitwise Operators

| ID | Title | Description |
|----|-------|-------------|
| `101` | Bitwise AND | & operator |
| `102` | Bitwise OR | \| operator |
| `103` | Bitwise XOR | ^ operator |
| `104` | Bitwise NOT | ~ operator |
| `105` | Left Shift | << operator |
| `106` | Right Shift | >> operator |
| `107` | Setting Bits | \|= with mask |
| `108` | Clearing Bits | &= with inverted mask |
| `109` | Toggling Bits | ^= with mask |
| `110` | Checking Bits | & with mask |

### Batch 12 (111–120): Conditionals

| ID | Title | Description |
|----|-------|-------------|
| `111` | if Statement | Basic conditional |
| `112` | if-else Statement | Two-branch conditional |
| `113` | else-if Ladder | Multiple conditions |
| `114` | Nested if Statements | Conditionals inside conditionals |
| `115` | Ternary Operator ?: | Conditional expression |
| `116` | switch Statement | Multi-way branch |
| `117` | switch with break | Preventing fall-through |
| `118` | switch Fall-Through | Intentional cascading |
| `119` | switch with default | Catch-all case |
| `120` | switch vs if-else | When to use which |

### Batch 13 (121–130): Loops

| ID | Title | Description |
|----|-------|-------------|
| `121` | while Loop | Condition-first loop |
| `122` | do-while Loop | Body-first loop |
| `123` | for Loop | Counter-controlled loop |
| `124` | for Loop Variations | Multiple variables, omitted parts |
| `125` | Nested Loops | Loops inside loops |
| `126` | break Statement | Early loop exit |
| `127` | continue Statement | Skip to next iteration |
| `128` | Infinite Loops | for(;;) and while(1) |
| `129` | Loop Patterns | Count up, count down, step |
| `130` | Common Loop Mistakes | Off-by-one, infinite loops |

### Batch 14 (131–140): Arrays Basics

| ID | Title | Description |
|----|-------|-------------|
| `131` | Array Declaration | Type name[size]; |
| `132` | Array Initialization | Initializer lists |
| `133` | Array Access | Indexing with [] |
| `134` | Array Bounds | No bounds checking |
| `135` | Array Size with sizeof | sizeof(arr)/sizeof(arr[0]) |
| `136` | Array Iteration | Looping through arrays |
| `137` | Partial Initialization | Remaining elements are 0 |
| `138` | Designated Initializers | C99 [index] = value |
| `139` | Array Assignment | Cannot assign arrays |
| `140` | Array Comparison | Must compare element by element |

### Batch 15 (141–150): Arrays Advanced

| ID | Title | Description |
|----|-------|-------------|
| `141` | 2D Array Declaration | Type name[rows][cols]; |
| `142` | 2D Array Initialization | Nested initializer lists |
| `143` | 2D Array Access | arr[row][col] |
| `144` | 2D Array Iteration | Nested loops |
| `145` | Row-Major Order | Memory layout |
| `146` | Arrays of Arrays | Understanding 2D as 1D |
| `147` | Variable Length Arrays | VLA in C99 |
| `148` | VLA Limitations | Stack allocation, no initialization |
| `149` | Multidimensional Arrays | 3D and beyond |
| `150` | Array as Function Parameter | Decay to pointer |

### Batch 16 (151–160): Strings Basics

| ID | Title | Description |
|----|-------|-------------|
| `151` | Strings in C | Character arrays with null terminator |
| `152` | String Initialization | char str[] = "hello"; |
| `153` | Null Terminator | '\0' character |
| `154` | String Printing | printf %s, puts |
| `155` | String Input | fgets vs scanf |
| `156` | strlen() | String length |
| `157` | strcpy() | String copy |
| `158` | strncpy() | Bounded copy |
| `159` | strcat() | String concatenation |
| `160` | strncat() | Bounded concatenation |

### Batch 17 (161–170): Strings Advanced

| ID | Title | Description |
|----|-------|-------------|
| `161` | strcmp() | String comparison |
| `162` | strncmp() | Bounded comparison |
| `163` | strchr() | Find character |
| `164` | strrchr() | Find last character |
| `165` | strstr() | Find substring |
| `166` | strtok() | String tokenization |
| `167` | atoi(), atol(), atof() | String to number |
| `168` | strtol(), strtod() | Safer conversion |
| `169` | sprintf() for Strings | Number to string |
| `170` | String Literals vs Arrays | Read-only vs modifiable |

### Batch 18 (171–180): Character Handling

| ID | Title | Description |
|----|-------|-------------|
| `171` | ctype.h Overview | Character classification |
| `172` | isalpha(), isdigit() | Letter and digit tests |
| `173` | isalnum(), isspace() | Alphanumeric and whitespace |
| `174` | isupper(), islower() | Case tests |
| `175` | toupper(), tolower() | Case conversion |
| `176` | isprint(), iscntrl() | Printable and control |
| `177` | ispunct(), isgraph() | Punctuation and graphic |
| `178` | isxdigit() | Hex digit test |
| `179` | Character Input Loop | Reading until condition |
| `180` | Input Sanitization | Cleaning user input |

### Batch 19 (181–190): Pointers Basics

| ID | Title | Description |
|----|-------|-------------|
| `181` | Pointer Concept | Address and indirection |
| `182` | Pointer Declaration | Type *ptr; |
| `183` | Address-of Operator & | Getting address |
| `184` | Dereference Operator * | Accessing value |
| `185` | Pointer Initialization | NULL and valid addresses |
| `186` | NULL Pointer | Null pointer constant |
| `187` | Pointer Assignment | Copying addresses |
| `188` | Pointers to Different Types | Type matters |
| `189` | void Pointer | Generic pointer |
| `190` | Pointer Size | sizeof pointer |

### Batch 20 (191–200): Pointers & Memory

| ID | Title | Description |
|----|-------|-------------|
| `191` | Pointer Arithmetic | Incrementing pointers |
| `192` | Pointers and Arrays | Array name as pointer |
| `193` | Pointer Indexing | ptr[i] vs *(ptr+i) |
| `194` | Pointer Comparison | Comparing addresses |
| `195` | Pointer to Pointer | Double indirection |
| `196` | Pass by Pointer | Modifying via pointer |
| `197` | Return Pointer from Function | Careful with local variables |
| `198` | malloc() Basics | Dynamic allocation |
| `199` | free() Basics | Memory deallocation |
| `200` | Command Line Arguments | argc and argv |

---

## Future Phases (201+)

### Phase 2: Advanced Topics (201–400)
- Structs & Unions
- File I/O
- Dynamic Memory Deep Dive
- Preprocessor Advanced  

### Phase 3: Systems Programming (401–600)
- POSIX API
- Processes & Signals
- Threading (pthreads)
- Socket Programming

### Phase 4: Security Focus (601–800)
- Buffer Overflows
- Format String Vulnerabilities
- Shellcode Writing
- Exploit Development

### Phase 5: Projects (801–1000)
- Network Tools
- System Utilities
- Security Tools
- Complete Applications

---

## Resources

- **K&R**: The C Programming Language (2nd Edition)
- **Modern C**: Jens Gustedt
- **C Programming: A Modern Approach**: K. N. King
- **Expert C Programming**: Peter van der Linden
- **Hacking: The Art of Exploitation**: Jon Erickson
