#include <stdio.h>

void demonstrate_auto(void) {
    auto int x = 10;
    int y = 20;
    
    printf("  auto int x = %d\n", x);
    printf("  int y = %d (implicitly auto)\n", y);
    printf("  Both are identical - auto is the default!\n");
}

void show_lifetime(void) {
    for (int i = 0; i < 3; i++) {
        auto int counter = 0;
        counter++;
        printf("  Iteration %d: counter = %d (always 1, recreated each time)\n", 
               i + 1, counter);
    }
}

void nested_scope(void) {
    auto int x = 100;
    printf("  Outer x = %d\n", x);
    
    {
        auto int x = 200;
        printf("  Inner x = %d (shadows outer)\n", x);
    }
    
    printf("  Back to outer x = %d\n", x);
}

int main(void) {
    printf("=== The auto Storage Class ===\n\n");
    
    printf("--- What is auto? ---\n");
    printf("auto declares automatic storage duration.\n");
    printf("It's the DEFAULT for local variables - rarely written explicitly.\n\n");
    
    printf("--- Explicit vs Implicit auto ---\n");
    demonstrate_auto();
    
    printf("\n--- auto Variable Characteristics ---\n");
    printf("1. Created when block is entered\n");
    printf("2. Destroyed when block exits\n");
    printf("3. Not initialized by default (contains garbage)\n");
    printf("4. Stored on the stack\n");
    printf("5. Scope limited to declaring block\n");
    
    printf("\n--- Lifetime Demonstration ---\n");
    show_lifetime();
    
    printf("\n--- Scope Demonstration ---\n");
    nested_scope();
    
    printf("\n--- Uninitialized auto Variables ---\n");
    auto int uninitialized;
    printf("  Uninitialized auto int may contain: %d (garbage!)\n", uninitialized);
    printf("  ALWAYS initialize your variables!\n");
    
    printf("\n--- Why auto is Rarely Used ---\n");
    printf("1. It's the default - explicit auto is redundant\n");
    printf("2. C++ repurposed 'auto' for type inference\n");
    printf("3. Modern style: just write 'int x' not 'auto int x'\n");
    
    printf("\n--- Storage Classes Summary ---\n");
    printf("| Keyword  | Scope    | Lifetime    | Default Init |\n");
    printf("|----------|----------|-------------|-------------|\n");
    printf("| auto     | Block    | Block       | Garbage     |\n");
    printf("| static   | Block    | Program     | Zero        |\n");
    printf("| extern   | Global   | Program     | Zero        |\n");
    printf("| register | Block    | Block       | Garbage     |\n");
    
    return 0;
}
