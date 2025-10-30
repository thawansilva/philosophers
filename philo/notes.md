# Objective
Learn how to deal with process and threads, create threads and use mutexes

# Input
1. number of philophers (that is the same number of forks)
2. time_to_die (milliseconds): a philosopher die if he hasn't started eating within
the time_to_die since the last meal or the start of the simulation;
3. time_to_eat: time that a philopher eats, he must have two forks
4. time_to_sleep: time that a philopher will spend sleeping;
5. number_of_times_each_philopher_must_eat: if all philophers have eaten at least
number_of_times_each_philopher_must_eat times, the program stops. If it's not passed
the program stops when a philopher die;

# Restrictions
1. it needs two forks to eat
2. it should receive between 4 and 5 args
3. state changes messages should be show as follows:
- timestamp_in_ms X has taken a fork
- timestamp_in_ms X is eating
- timestamp_in_ms X is sleeping
- timestamp_in_ms X is thinking
- timestamp_in_ms X died
4. The message announcing the death of the philopher should be displayed within 
 10ms of their actually death
5. os philophers devem evitar morrer
