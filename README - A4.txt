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

	{ NOTE: copy some sample output here. }

	In actuality, a test of each scheduling process returned the following results:

	DEFAULT:

		{ NOTE: copy results here. }

	FCFS:

		{ NOTE: copy results here. }

	SML:

		{ NOTE: copy results here. }

	DML:

		{ NOTE: copy results here. }


	Similarly, when building SMLsanity, we had to modify the procedure each child process executed, as the procedure described in the assignment executed too quickly for the scheduling policy to affect. As such, instead of 100 million noops, each process executes 100 thousand yields. This revealed the desired behaviour of HIGH (2) priority processes exiting first, followed by MEDIUM (1) priority processes, and finally LOW (0) priority processes. Sample output can be seen below:
	
	{ NOTE: copy results here. }
