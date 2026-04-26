# Philosophers

A multithreaded C implementation of the classic Dining Philosophers Problem using POSIX threads (pthreads) and mutex synchronization.

## Overview

The Dining Philosophers Problem is a classic synchronization problem that illustrates challenges in concurrent programming. This project simulates philosophers sitting at a round table, where each philosopher alternates between eating, thinking, and sleeping. Each philosopher needs two forks to eat, and there is one fork between each pair of adjacent philosophers.

## Project Structure

```
philo/
├── Makefile              # Build configuration
├── includes/
│   └── philo.h          # Header file with structures and declarations
└── src/
    ├── main.c           # Entry point and program initialization
    ├── init_table.c     # Table and philosopher initialization
    ├── validate_input.c # Argument validation
    ├── start_routines.c # Thread creation and synchronization
    ├── philo_routine.c  # Philosopher behavior (eat, sleep, think)
    ├── waiter_routine.c # Monitoring for philosopher death
    └── utils_philo.c    # Utility functions
```

## Compilation

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

**Requirements:**
- GCC or Clang compiler
- POSIX threads library (pthreads)
- Unix-like operating system

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters

- **number_of_philosophers** (int): Number of philosophers at the table (1-200)
- **time_to_die** (milliseconds): Time a philosopher can survive without eating
- **time_to_eat** (milliseconds): Time required for a philosopher to eat
- **time_to_sleep** (milliseconds): Time a philosopher sleeps after eating
- **number_of_times_each_philosopher_must_eat** (int, optional): If specified, the program ends when all philosophers have eaten this many times

### Example

```bash
./philo 5 800 200 200
./philo 4 410 200 200 10
```

## How It Works

### Key Components

1. **Philosophers (Threads)**: Each philosopher runs in its own thread, continuously cycling through:
   - **Thinking**: The default state
   - **Eating**: Requires acquiring both adjacent forks (mutex locks)
   - **Sleeping**: Releases forks and rests

2. **Synchronization**:
   - **Forks (Mutexes)**: Each fork is a pthread_mutex that prevents two philosophers from eating simultaneously
   - **Write Lock**: Prevents race conditions when printing state
   - **Death Lock**: Protects the death flag
   - **Meal Lock**: Protects meal count tracking

3. **Waiter (Monitor Thread)**: Continuously checks if any philosopher has died (not eaten within `time_to_die`)

### State Transitions

```
Thinking → Trying to grab forks → Eating (if successful) → Sleeping → Thinking
                ↓ (timeout)
              DEAD
```

## Data Structures

### t_philo (Philosopher)
Represents an individual philosopher with:
- Thread ID and pthread_t handle
- Fork references (left and right mutexes)
- Meal tracking (count, last meal time)
- State (eating flag)
- Timing parameters

### t_table (Dining Table)
Manages the overall simulation with:
- Array of philosopher structures
- Shared synchronization primitives (mutexes)
- Death flag
- Array of fork mutexes

## Implementation Notes

- **Thread Safety**: All shared data is protected by appropriate mutexes
- **Deadlock Prevention**: The implementation carefully manages fork acquisition order
- **Timing**: Uses `gettimeofday()` for accurate millisecond-precision timing
- **Resource Management**: All mutexes and threads are properly created and destroyed

## Exit Codes

- **0**: Normal exit (all philosophers completed required meals or no death occurred)
- **1**: Invalid arguments provided

## Possible Improvements

- Add command-line flags for verbose output
- Implement statistics tracking (meals eaten, eating duration)
- Add visualization of philosopher states
- Experiment with different fork acquisition strategies

## Author

Created as part of the 42 School curriculum (Philosophers project).
