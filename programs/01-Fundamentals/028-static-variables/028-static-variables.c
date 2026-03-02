#include <stdio.h>

void counter_without_static(void) {
    int count = 0;
    count++;
    printf("  Without static: count = %d\n", count);
}

void counter_with_static(void) {
    static int count = 0;
    count++;
    printf("  With static:    count = %d\n", count);
}

static int module_private = 42;

static void helper_function(void) {
    printf("  I'm a static function - only visible in this file!\n");
}

int get_unique_id(void) {
    static int next_id = 1000;
    return next_id++;
}

void demonstrate_initialization(void) {
    static int initialized_once = 0;
    static int call_count = 0;
    
    call_count++;
    
    if (initialized_once == 0) {
        printf("  First call - initializing...\n");
        initialized_once = 1;
    } else {
        printf("  Already initialized (call #%d)\n", call_count);
    }
}

int main(void) {
    printf("=== Static Variables ===\n\n");
    
    printf("--- Static vs Auto in Functions ---\n");
    printf("Calling each function 3 times:\n\n");
    
    for (int i = 0; i < 3; i++) {
        counter_without_static();
        counter_with_static();
        printf("\n");
    }
    
    printf("--- Static Preserves Value Between Calls ---\n");
    printf("Unique IDs generated: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", get_unique_id());
    }
    printf("\n");
    
    printf("\n--- Static for Internal Linkage ---\n");
    printf("module_private = %d (only accessible in this file)\n", module_private);
    helper_function();
    
    printf("\n--- Default Initialization ---\n");
    static int default_init;
    printf("Static variables default to zero: %d\n", default_init);
    printf("(Auto variables would have garbage!)\n");
    
    printf("\n--- One-Time Initialization Pattern ---\n");
    for (int i = 0; i < 3; i++) {
        demonstrate_initialization();
    }
    
    printf("\n--- Static Variable Properties ---\n");
    printf("1. Lifetime: entire program execution\n");
    printf("2. Scope: block where declared (for local static)\n");
    printf("3. Initialized once (before main for global static)\n");
    printf("4. Default value: zero (not garbage)\n");
    printf("5. Stored in data segment (not stack)\n");
    
    printf("\n--- Two Meanings of 'static' ---\n");
    printf("1. Inside function: persistent local variable\n");
    printf("2. At file scope: internal linkage (private to file)\n");
    
    return 0;
}
