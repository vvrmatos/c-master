#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

volatile sig_atomic_t shutdown_requested = 0;

void signal_handler(int signum) {
    (void)signum;
    shutdown_requested = 1;
}

int main(void) {
    printf("=== The volatile Qualifier ===\n\n");
    
    printf("--- What volatile Does ---\n");
    printf("volatile tells the compiler:\n");
    printf("  1. Don't optimize away reads/writes to this variable\n");
    printf("  2. Always read from memory, never use cached value\n");
    printf("  3. Value may change unexpectedly (hardware, signals, etc.)\n");
    
    printf("\n--- Example: Signal Handler ---\n");
    signal(SIGINT, signal_handler);
    printf("volatile sig_atomic_t shutdown_requested = 0;\n");
    printf("Press Ctrl+C to set shutdown_requested = 1\n");
    printf("(We'll simulate this for the demo)\n\n");
    
    shutdown_requested = 1;
    
    printf("Without volatile, this loop might never exit:\n");
    printf("  while (!shutdown_requested) { /* wait */ }\n");
    printf("Compiler might optimize to: while(1) {} if it caches the value!\n");
    
    printf("\n--- Common Use Cases ---\n");
    printf("1. Signal handlers (sig_atomic_t)\n");
    printf("2. Memory-mapped hardware registers\n");
    printf("3. Variables shared between threads*\n");
    printf("   (*but prefer atomics or mutexes for threads)\n");
    printf("4. Variables modified by interrupts (embedded systems)\n");
    
    printf("\n--- Syntax Examples ---\n");
    printf("volatile int sensor_value;\n");
    printf("volatile uint32_t *hardware_register;\n");
    printf("volatile const int *read_only_register;\n");
    
    printf("\n--- volatile Does NOT Mean ---\n");
    printf("- Thread-safe (use atomics for that)\n");
    printf("- Memory barriers (use proper synchronization)\n");
    printf("- Atomic operations (use _Atomic or stdatomic.h)\n");
    
    printf("\n--- Demonstration ---\n");
    volatile int counter = 0;
    
    printf("volatile int counter = 0;\n");
    printf("Initial value: %d\n", counter);
    
    counter = 42;
    printf("After assignment: %d\n", counter);
    
    printf("\nKey point: Each read goes to memory, not a register.\n");
    printf("Without volatile, compiler might skip repeated reads.\n");
    
    printf("\n--- Memory-Mapped I/O Example (Embedded) ---\n");
    printf("// Hardware status register at address 0x40000000\n");
    printf("volatile uint32_t *STATUS = (volatile uint32_t *)0x40000000;\n");
    printf("while (*STATUS & BUSY_FLAG) { /* wait for hardware */ }\n");
    printf("// Without volatile, compiler might read STATUS only once!\n");
    
    return 0;
}
