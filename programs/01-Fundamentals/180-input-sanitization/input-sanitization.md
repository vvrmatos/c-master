# Input Sanitization - Cleaning User Input

## Overview
Input sanitization is the process of cleaning and validating user input to ensure it meets expected criteria. This is crucial for security (preventing injection attacks) and data integrity.

## Why Sanitize Input?
- **Security**: Prevent buffer overflows, injection attacks
- **Data Quality**: Ensure consistent data format
- **Validation**: Verify input meets requirements
- **User Experience**: Provide meaningful error messages

## Common Sanitization Techniques

### 1. Whitelist (Allow only specific chars)
```c
void sanitize_alpha(const char *in, char *out) {
    int j = 0;
    for (int i = 0; in[i]; i++) {
        if (isalpha(in[i])) out[j++] = in[i];
    }
    out[j] = '\0';
}
```

### 2. Blacklist (Remove specific chars)
```c
void remove_chars(char *str, const char *bad) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (!strchr(bad, str[i])) str[j++] = str[i];
    }
    str[j] = '\0';
}
```

### 3. Trim whitespace
```c
void trim(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (end > start && isspace(str[end])) end--;
    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}
```

### 4. Length limiting
```c
void limit_length(char *str, size_t max) {
    if (strlen(str) > max) str[max] = '\0';
}
```

## Sanitization for Different Contexts

| Context | Allow | Remove/Escape |
|---------|-------|---------------|
| Username | alnum, _ | Everything else |
| Email | alnum, @, ., -, _ | Everything else |
| Filename | alnum, ., -, _ | /, \, :, *, etc |
| Number | digits, -, . | Non-numeric |

---

# Kata Challenge: User Input Validator

## Objective
Write a comprehensive input sanitization library with multiple validators.

## Requirements
1. Implement these sanitization functions:
   - `sanitize_username()` - alphanumeric and underscore only
   - `sanitize_email()` - valid email characters
   - `sanitize_numeric()` - digits only
   - `sanitize_filename()` - safe filename characters
2. Each function should:
   - Return sanitized string
   - Report what was removed
3. Add a validation mode that rejects invalid input instead of sanitizing

## Example
```
Input: "john.doe@email!#$%.com"

sanitize_email: "john.doe@email.com"
Removed: "!#$%"

Input: "my file<>:name.txt"
sanitize_filename: "my filename.txt"
Removed: "<>:"
```

## Hints
- Use `isalnum()`, `isalpha()`, `isdigit()`
- Consider using `strchr()` to check allowed chars
- Keep track of removed characters in separate buffer

## Bonus
- Add escape function for HTML entities
- Implement case normalization (to lower/upper)
- Add password strength validator
- Support Unicode/UTF-8 (advanced)
