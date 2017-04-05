README for A4 - Ezra Lazar and Adam Zielonko

To build:

	$ make clean

(one of:)
	$ make
	$ make SCHEDFLAG=FCFS
	$ make SCHEDFLAG=SML
	$ make SCHEDFLAG=DML

	$ make qemu

To run tests:

	$ sanity <number>

(If built for SML:)
	$ SMLsanity


Analysis of tests:

	During development, we noticed that "CPU-bound processes" (i.e. processes that run 100 million noops, with or without yielding after one million iterations) run too quickly for the scheduler to affect the order in which processes run. "IO-bound processes" (i.e. processes that sleep(1) 100 times) run slowly enough that they consistently finish after CPU-bound processes, regardless of the scheduling policy.

	As such, we predict that, for every scheduling policy, the output would appear similar to the following:

	pid 4 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
	pid 6 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
	pid 7 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
	pid 9 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
	pid 10 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
	pid 12 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
	pid 13 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
	pid 15 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
	pid 16 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
	pid 18 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
	pid 5 completed. type: 2. sleep time: 0. ready time: 0. runtime: 6
	pid 8 completed. type: 2. sleep time: 0. ready time: 0. runtime: 6
	pid 11 completed. type: 2. sleep time: 0. ready time: 0. runtime: 6
	pid 14 completed. type: 2. sleep time: 0. ready time: 0. runtime: 6
	pid 17 completed. type: 2. sleep time: 0. ready time: 0. runtime: 6
	Stats for CPU-boud processes:
	Average time spent sleeping: 0
	Average time spent ready: 0
	Average time spent running: 0
	Stats for short-task based CPU-bound processes:
	Average time spent sleeping: 0
	Average time spent ready: 0
	Average time spent running: 0
	Stats for IO-bound processes:
	Average time spent sleeping: 0
	Average time spent ready: 0
	Average time spent running: 6

	In actuality, a test of each scheduling process returned the following results:
	(All tests run as sanity 5)

		DEFAULT:

		pid 4 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
		pid 6 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 7 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 9 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 10 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 12 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 13 completed. type: 1. sleep time: 10. ready time: 0. runtime: 0
		pid 15 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 16 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 18 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 5 completed. type: 2. sleep time: 2. ready time: 0. runtime: 46
		pid 8 completed. type: 2. sleep time: 4. ready time: 0. runtime: 46
		pid 11 completed. type: 2. sleep time: 4. ready time: 0. runtime: 46
		pid 14 completed. type: 2. sleep time: 34. ready time: 0. runtime: 20
		pid 17 completed. type: 2. sleep time: 34. ready time: 0. runtime: 20
		Stats for CPU-boud processes:
		Average time spent sleeping: 0
		Average time spent ready: 0
		Average time spent running: 0
		Stats for short-task based CPU-bound processes:
		Average time spent sleeping: 2
		Average time spent ready: 0
		Average time spent running: 0
		Stats for IO-bound processes:
		Average time spent sleeping: 15
		Average time spent ready: 0
		Average time spent running: 35

		FCFS:

		pid 4 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 6 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 7 completed. type: 1. sleep time: 3. ready time: 0. runtime: 0
		pid 9 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 10 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
		pid 12 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 13 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 15 completed. type: 0. sleep time: 1. ready time: 5. runtime: 0
		pid 18 completed. type: 0. sleep time: 8. ready time: 0. runtime: 0
		pid 16 completed. type: 1. sleep time: 12. ready time: 3. runtime: 0
		pid 5 completed. type: 2. sleep time: 8. ready time: 1. runtime: 67
		pid 8 completed. type: 2. sleep time: 9. ready time: 0. runtime: 67
		pid 11 completed. type: 2. sleep time: 5. ready time: 0. runtime: 45
		pid 14 completed. type: 2. sleep time: 6. ready time: 0. runtime: 44
		pid 17 completed. type: 2. sleep time: 13. ready time: 0. runtime: 38
		Stats for CPU-boud processes:
		Average time spent sleeping: 2
		Average time spent ready: 1
		Average time spent running: 0
		Stats for short-task based CPU-bound processes:
		Average time spent sleeping: 3
		Average time spent ready: 0
		Average time spent running: 0
		Stats for IO-bound processes:
		Average time spent sleeping: 8
		Average time spent ready: 0
		Average time spent running: 52

		SML:

		pid 4 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 6 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 7 completed. type: 1. sleep time: 2. ready time: 12. runtime: 0
		pid 9 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 10 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 12 completed. type: 0. sleep time: 1. ready time: 0. runtime: 0
		pid 13 completed. type: 1. sleep time: 2. ready time: 0. runtime: 0
		pid 15 completed. type: 0. sleep time: 2. ready time: 0. runtime: 0
		pid 5 completed. type: 2. sleep time: 6. ready time: 0. runtime: 79
		pid 8 completed. type: 2. sleep time: 17. ready time: 0. runtime: 68
		pid 16 completed. type: 1. sleep time: 48. ready time: 0. runtime: 0
		pid 11 completed. type: 2. sleep time: 4. ready time: 0. runtime: 105
		pid 14 completed. type: 2. sleep time: 3. ready time: 0. runtime: 105
		pid 17 completed. type: 2. sleep time: 1. ready time: 0. runtime: 100
		pid 18 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		Stats for CPU-boud processes:
		Average time spent sleeping: 1
		Average time spent ready: 0
		Average time spent running: 0
		Stats for short-task based CPU-bound processes:
		Average time spent sleeping: 10
		Average time spent ready: 2
		Average time spent running: 0
		Stats for IO-bound processes:
		Average time spent sleeping: 6
		Average time spent ready: 0
		Average time spent running: 91

		DML:

		pid 4 completed. type: 1. sleep time: 2. ready time: 0. runtime: 0
		pid 5 completed. type: 2. sleep time: 2. ready time: 0. runtime: 0
		pid 6 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 7 completed. type: 1. sleep time: 116. ready time: 0. runtime: 0
		pid 8 completed. type: 2. sleep time: 120. ready time: 0. runtime: 0
		pid 9 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 10 completed. type: 1. sleep time: 1. ready time: 0. runtime: 0
		pid 11 completed. type: 2. sleep time: 3. ready time: 0. runtime: 110
		pid 12 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 13 completed. type: 1. sleep time: 2. ready time: 0. runtime: 0
		pid 14 completed. type: 2. sleep time: 0. ready time: 0. runtime: 155
		pid 15 completed. type: 0. sleep time: 0. ready time: 0. runtime: 0
		pid 16 completed. type: 1. sleep time: 0. ready time: 0. runtime: 0
		pid 17 completed. type: 2. sleep time: 111. ready time: 25. runtime: 76
		pid 18 completed. type: 0. sleep time: 18. ready time: 0. runtime: 0
		Stats for CPU-boud processes:
		Average time spent sleeping: 3
		Average time spent ready: 0
		Average time spent running: 0
		Stats for short-task based CPU-bound processes:
		Average time spent sleeping: 24
		Average time spent ready: 0
		Average time spent running: 0
		Stats for IO-bound processes:
		Average time spent sleeping: 47
		Average time spent ready: 5
		Average time spent running: 68


	Similarly, when building SMLsanity, we had to modify the procedure each child process executed, as the procedure described in the assignment executed too quickly for the scheduling policy to affect. As such, instead of 100 million noops, each process executes 100 thousand yields. This revealed the desired behaviour of HIGH (2) priority processes exiting first, followed by MEDIUM (1) priority processes, and finally LOW (0) priority processes. Sample output can be seen below:
	
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 2 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 1 exiting.
	Process with priority 0 exiting.
	Process with priority 0 exiting.
	Process with priority 0 exiting.
	Process with priority 0 exiting.
	Process with priority 0 exiting.
	Process with priority 0 exiting.


	After analyzing the results, our assumptions seem to have held for all scheduling policies except DML, where IO-bound processes did not necessarily finish executing after CPU-bound processes.
