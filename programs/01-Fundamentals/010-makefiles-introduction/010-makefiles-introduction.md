---
id: "010"
title: "Makefiles Introduction"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - make
  - makefile
  - build-automation
difficulty: beginner
source: "GNU Make Manual"
---

# 010 — Makefiles Introduction

## Concept

**Make** is a build automation tool. Instead of typing long compiler commands, you define **rules** in a **Makefile**, then just type `make`.

**Makefile Anatomy:**
```makefile
target: dependencies
	command
```

- **target**: What you want to build (file or phony name)
- **dependencies**: Files needed to build the target
- **command**: Shell command to build (MUST be indented with TAB, not spaces!)

**Variables:**
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c17
```

**Automatic Variables:**
- `$@` — The target name
- `$<` — First dependency
- `$^` — All dependencies

**Phony Targets** (not actual files):
```makefile
.PHONY: clean all

clean:
	rm -f *.o program
```

**Why Make matters:**
- Recompiles only what changed (checks modification times)
- Handles complex dependency chains
- Standard in Unix/Linux development
- Essential for security tools and system software

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== Makefiles Introduction ===\n\n");
    
    printf("A Makefile automates compilation.\n\n");
    
    printf("Basic Makefile structure:\n");
    printf("  target: dependencies\n");
    printf("  [TAB]command\n\n");
    
    printf("Example Makefile:\n");
    printf("  CC = gcc\n");
    printf("  CFLAGS = -Wall -Wextra\n");
    printf("  \n");
    printf("  program: main.o utils.o\n");
    printf("  \t$(CC) main.o utils.o -o program\n");
    printf("  \n");
    printf("  main.o: main.c\n");
    printf("  \t$(CC) $(CFLAGS) -c main.c\n");
    printf("  \n");
    printf("  clean:\n");
    printf("  \trm -f *.o program\n\n");
    
    printf("Usage:\n");
    printf("  make          # Build default target\n");
    printf("  make clean    # Run clean target\n");
    printf("  make -j4      # Parallel build (4 jobs)\n");
    
    return 0;
}
```

## Output

```
=== Makefiles Introduction ===

A Makefile automates compilation.

Basic Makefile structure:
  target: dependencies
  [TAB]command

Example Makefile:
  CC = gcc
  CFLAGS = -Wall -Wextra
  
  program: main.o utils.o
  	$(CC) main.o utils.o -o program
  
  main.o: main.c
  	$(CC) $(CFLAGS) -c main.c
  
  clean:
  	rm -f *.o program

Usage:
  make          # Build default target
  make clean    # Run clean target
  make -j4      # Parallel build (4 jobs)
```

## Complete Makefile Example

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = 

# Files
SRCS = main.c utils.c network.c
OBJS = $(SRCS:.c=.o)
TARGET = myprogram

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean build artifacts
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

# Debug build
.PHONY: debug
debug: CFLAGS += -g -DDEBUG
debug: clean all
```

## Key Takeaways

- Makefiles automate the build process
- **TAB character** is required (not spaces) before commands
- Make only rebuilds files that changed
- Use variables for compiler (`CC`) and flags (`CFLAGS`)
- `.PHONY` marks targets that aren't files
- `make -j N` enables parallel building
- Essential skill for C development

## Challenge

Create a Makefile for a two-file project (main.c and helper.c). Include clean and all targets. Test that modifying one file only recompiles that file.

## Related

- [[004-compilation-process]] — What the Makefile automates
- [[008-multiple-source-files]] — Why makefiles are needed
- [[009-header-files-basics]] — Header dependencies in Makefiles
