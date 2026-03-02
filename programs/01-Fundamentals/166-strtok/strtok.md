# strtok - String Tokenization

## Overview
`strtok` splits a string into tokens based on delimiter characters. It's commonly used for parsing CSV data, command lines, and other delimited formats.

## Function Signature
```c
char *strtok(char *str, const char *delim);
```

## Parameters
- **str**: String to tokenize (first call) or NULL (subsequent calls)
- **delim**: String containing delimiter characters

## Return Value
- Pointer to next token
- NULL when no more tokens

## Critical Behaviors

### ⚠️ Modifies Original String
```c
char str[] = "a,b,c";  // Must be modifiable array
strtok(str, ",");      // Replaces ',' with '\0'
// str is now "a\0b\0c"
```

### ⚠️ Uses Static Buffer (Not Thread-Safe)
```c
// Cannot tokenize two strings simultaneously
strtok(str1, ",");  // Starts str1
strtok(str2, ",");  // LOSES str1 position!
```

### ⚠️ Skips Empty Tokens
```c
char str[] = "a,,b";
// Returns "a", "b" - NOT "a", "", "b"
```

## Usage Pattern
```c
char str[] = "token1,token2,token3";
char *tok = strtok(str, ",");  // First call with string
while (tok != NULL) {
    process(tok);
    tok = strtok(NULL, ",");    // Subsequent calls with NULL
}
```

## Thread-Safe Alternative: strtok_r
```c
char *saveptr;
char *tok = strtok_r(str, ",", &saveptr);
while (tok != NULL) {
    tok = strtok_r(NULL, ",", &saveptr);
}
```

## Compilation
```bash
gcc -o strtok strtok.c
./strtok
```

---

# Kata Challenge: CSV Parser

## Objective
Build a CSV parser using strtok (with awareness of its limitations).

## Requirements
1. Parse CSV rows into fields
2. Handle multiple rows
3. Store parsed data in a structure
4. Handle edge cases (empty fields, quoted fields)

## Starter Code
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FIELDS 10
#define MAX_ROWS 100
#define MAX_FIELD_LEN 64

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LEN];
    int field_count;
} CSVRow;

typedef struct {
    CSVRow rows[MAX_ROWS];
    int row_count;
    char headers[MAX_FIELDS][MAX_FIELD_LEN];
    int header_count;
} CSVData;

// Parse a single CSV row
CSVRow parse_row(char *line) {
    CSVRow row = {0};
    // TODO: Use strtok to split by comma
    // TODO: Handle edge cases
    return row;
}

// Parse entire CSV content
CSVData parse_csv(char *content) {
    CSVData data = {0};
    // TODO: Split into lines first, then parse each row
    return data;
}

// Get field by header name
const char *get_field(CSVData *data, int row, const char *header) {
    // TODO: Find column index from header, return field
    return NULL;
}

int main(void) {
    char csv[] = "name,age,city\n"
                 "John,25,New York\n"
                 "Jane,30,Los Angeles\n"
                 "Bob,35,Chicago";
    
    CSVData data = parse_csv(csv);
    
    printf("Parsed %d rows with %d columns\n", 
           data.row_count, data.header_count);
    
    // Print table
    for (int i = 0; i < data.row_count; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < data.rows[i].field_count; j++) {
            printf("[%s] ", data.rows[i].fields[j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## Expected Output
```
Parsed 3 rows with 3 columns
Row 1: [John] [25] [New York]
Row 2: [Jane] [30] [Los Angeles]
Row 3: [Bob] [35] [Chicago]
```

## Bonus Challenges
1. Handle quoted fields: "Hello, World" as single field
2. Support different delimiters (TSV, etc.)
3. Write data back to CSV format
4. Implement strtok_r for thread safety

## Test Cases
- "a,b,c" → 3 fields
- "a,,c" → "a" and "c" (strtok skips empty)
- Empty string → 0 fields
