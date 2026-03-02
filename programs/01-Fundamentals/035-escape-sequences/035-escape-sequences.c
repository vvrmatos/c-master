#include <stdio.h>

int main(void) {
    printf("=== Escape Sequences ===\n\n");
    
    printf("Common escape sequences:\n");
    printf("  \\n  = newline\n");
    printf("  \\t  = horizontal tab\t<- after tab\n");
    printf("  \\r  = carriage return (moves cursor to line start)\n");
    printf("  \\\\  = backslash: \\\n");
    printf("  \\'  = single quote: \'\n");
    printf("  \\\"  = double quote: \"\n");
    printf("  \\0  = null character (string terminator)\n");
    
    printf("\nLess common escapes:\n");
    printf("  \\a  = alert (bell)");
    printf("\a");
    printf(" <- bell rang\n");
    printf("  \\b  = backspace: ABC\\b\\b = AB\bC\n");
    printf("  \\f  = form feed (new page)\n");
    printf("  \\v  = vertical tab\n");
    printf("  \\?  = question mark: \\? = \?\n");
    
    printf("\nOctal escape sequences (\\nnn):\n");
    printf("  \\101 = %c (octal 101 = 'A')\n", '\101');
    printf("  \\141 = %c (octal 141 = 'a')\n", '\141');
    printf("  \\060 = %c (octal 60 = '0')\n", '\060');
    printf("  \\012 = newline (octal 12 = 10)\n");
    
    printf("\nHexadecimal escape sequences (\\xNN):\n");
    printf("  \\x41 = %c (hex 41 = 'A')\n", '\x41');
    printf("  \\x61 = %c (hex 61 = 'a')\n", '\x61');
    printf("  \\x30 = %c (hex 30 = '0')\n", '\x30');
    printf("  \\x0A = newline (hex 0A = 10)\n");
    
    printf("\nPractical examples:\n");
    printf("  Tab-separated:\tvalue1\tvalue2\tvalue3\n");
    printf("  Quoted string: \"Hello, World!\"\n");
    printf("  File path: C:\\\\Users\\\\Admin\\\\file.txt\n");
    printf("  Progress: [####      ] 40%%\r");
    printf("  Progress: [######    ] 60%%\n");
    
    printf("\nNull terminator demonstration:\n");
    char str[] = "Hello\0World";
    printf("  char str[] = \"Hello\\0World\";\n");
    printf("  printf(str) = \"%s\"\n", str);
    printf("  Only 'Hello' prints - \\0 terminates the string\n");
    
    printf("\nSecurity-relevant escapes:\n");
    printf("  Shellcode byte: \\x90 (NOP = %d)\n", '\x90');
    printf("  Null byte: \\x00 (terminates strings)\n");
    printf("  Return: \\x0d\\x0a (CRLF = Windows newline)\n");
    
    return 0;
}
