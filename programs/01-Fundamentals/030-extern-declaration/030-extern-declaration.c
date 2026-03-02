#include <stdio.h>

int global_counter = 100;

extern int external_var;

void increment_counter(void);
void show_external(void);

int external_var = 42;

void increment_counter(void) {
    global_counter++;
}

void show_external(void) {
    printf("  external_var = %d\n", external_var);
}

int main(void) {
    printf("=== The extern Declaration ===\n\n");
    
    printf("--- What is extern? ---\n");
    printf("extern declares a variable without defining it.\n");
    printf("It says: 'This variable exists somewhere else.'\n");
    
    printf("\n--- Declaration vs Definition ---\n");
    printf("int x = 10;       // Definition: allocates memory, initializes\n");
    printf("extern int x;     // Declaration: just announces existence\n");
    printf("extern int x = 10; // Definition (extern ignored when initialized)\n");
    
    printf("\n--- Using extern with Global Variables ---\n");
    printf("global_counter starts at: %d\n", global_counter);
    increment_counter();
    increment_counter();
    printf("After 2 increments:       %d\n", global_counter);
    
    printf("\n--- External Variable in Same File ---\n");
    show_external();
    external_var = 999;
    printf("  After modification: external_var = %d\n", external_var);
    
    printf("\n--- Common Multi-File Pattern ---\n");
    printf("// === config.h ===\n");
    printf("extern int debug_level;      // Declaration\n");
    printf("extern const char *app_name; // Declaration\n");
    printf("\n// === config.c ===\n");
    printf("#include \"config.h\"\n");
    printf("int debug_level = 1;         // Definition\n");
    printf("const char *app_name = \"MyApp\"; // Definition\n");
    printf("\n// === main.c ===\n");
    printf("#include \"config.h\"\n");
    printf("// Can now use debug_level and app_name\n");
    
    printf("\n--- Linkage Types ---\n");
    printf("| Declaration          | Linkage   | Visible To        |\n");
    printf("|----------------------|-----------|-------------------|\n");
    printf("| int x;               | External  | All files         |\n");
    printf("| extern int x;        | External  | All files         |\n");
    printf("| static int x;        | Internal  | This file only    |\n");
    printf("| void func() { int x; } | None    | This function only |\n");
    
    printf("\n--- extern with Functions ---\n");
    printf("Functions are implicitly extern by default:\n");
    printf("  void func(void);        // Implicitly extern\n");
    printf("  extern void func(void); // Same thing, explicit\n");
    printf("  static void func(void); // Internal linkage\n");
    
    printf("\n--- Best Practices ---\n");
    printf("1. Declare extern variables in header files\n");
    printf("2. Define them in exactly one .c file\n");
    printf("3. Use static for file-private variables\n");
    printf("4. Minimize global variables (prefer passing parameters)\n");
    
    printf("\n--- One Definition Rule ---\n");
    printf("A variable can be DECLARED multiple times (extern)\n");
    printf("but DEFINED only once across all files.\n");
    printf("Violating this causes linker errors.\n");
    
    return 0;
}
