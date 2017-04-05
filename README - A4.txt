README for A4 - Ezra Lazar and Adam Zielonko

** we discovered a bit too late that the cpu-bound loops were being optimized out, so we didn't realize our statistics recording was incorrect. tasks should have longer running times and effectively no sleep time **

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


test runs:

	predictions
		default: earlier-created tasks finish first. since the tasks all get created at the same time, so they'll be done in order of being added to the ptable
		fcfs: same as default since tasks are all created at the same time
		sml: since priority doesn't get set, other tasks won't preempt the running task, so all tasks will run to completion
		dml: everything gets a relatively fair share when do. due to the sleep time of IO-bound processes, they'll finish last
		smlsanity: when doing cpu-bound tasks only, all high-priority tasks get completed first

	actual results:

		DEFAULT:

			$ sanity 5
			pid 4 completed. type: 1. sleep time: 143. ready time: 143. runtime: 0 
			pid 6 completed. type: 0. sleep time: 174. ready time: 151. runtime: 0 
			pid 5 completed. type: 2. sleep time: 407. ready time: 0. runtime: 59 
			pid 7 completed. type: 1. sleep time: 431. ready time: 150. runtime: 0 
			pid 9 completed. type: 0. sleep time: 463. ready time: 147. runtime: 0 
			pid 8 completed. type: 2. sleep time: 707. ready time: 0. runtime: 46 
			pid 10 completed. type: 1. sleep time: 730. ready time: 150. runtime: 0 
			pid 12 completed. type: 0. sleep time: 752. ready time: 148. runtime: 0 
			pid 11 completed. type: 2. sleep time: 994. ready time: 0. runtime: 70 
			pid 13 completed. type: 1. sleep time: 1026. ready time: 153. runtime: 0 
			pid 15 completed. type: 0. sleep time: 1053. ready time: 149. runtime: 0 
			pid 14 completed. type: 2. sleep time: 1314. ready time: 2. runtime: 51 
			pid 16 completed. type: 1. sleep time: 1332. ready time: 155. runtime: 0 
			pid 18 completed. type: 0. sleep time: 1349. ready time: 145. runtime: 0 
			pid 17 completed. type: 2. sleep time: 1477. ready time: 0. runtime: 17 
			Stats for CPU-boud processes:
			Average time spent sleeping: 758
			Average time spent ready: 148
			Average time spent running: 0
			Stats for short-task based CPU-bound processes:
			Average time spent sleeping: 732
			Average time spent ready: 150
			Average time spent running: 0
			Stats for IO-bound processes:
			Average time spent sleeping: 979
			Average time spent ready: 0
			Average time spent running: 48

		FCFS:

			$ sanity 5
			pid 4 completed. type: 1. sleep time: 155. ready time: 150. runtime: 0 
			pid 6 completed. type: 0. sleep time: 178. ready time: 148. runtime: 0 
			pid 5 completed. type: 2. sleep time: 441. ready time: 1. runtime: 46 
			pid 7 completed. type: 1. sleep time: 455. ready time: 158. runtime: 0 
			pid 9 completed. type: 0. sleep time: 474. ready time: 152. runtime: 0 
			pid 8 completed. type: 2. sleep time: 723. ready time: 0. runtime: 48 
			pid 10 completed. type: 1. sleep time: 756. ready time: 150. runtime: 0 
			pid 12 completed. type: 0. sleep time: 767. ready time: 150. runtime: 0 
			pid 11 completed. type: 2. sleep time: 1019. ready time: 0. runtime: 57 
			pid 13 completed. type: 1. sleep time: 1052. ready time: 139. runtime: 0 
			pid 15 completed. type: 0. sleep time: 1058. ready time: 149. runtime: 0 
			pid 14 completed. type: 2. sleep time: 1364. ready time: 0. runtime: 22 
			pid 16 completed. type: 1. sleep time: 1341. ready time: 155. runtime: 0 
			pid 18 completed. type: 0. sleep time: 1348. ready time: 146. runtime: 0 
			pid 17 completed. type: 2. sleep time: 1471. ready time: 0. runtime: 29 
			Stats for CPU-boud processes:
			Average time spent sleeping: 765
			Average time spent ready: 149
			Average time spent running: 0
			Stats for short-task based CPU-bound processes:
			Average time spent sleeping: 751
			Average time spent ready: 150
			Average time spent running: 0
			Stats for IO-bound processes:
			Average time spent sleeping: 1003
			Average time spent ready: 0
			Average time spent running: 40


		SML:

			$ sanity 5
			pid 21 completed. type: 0. sleep time: 307. ready time: 302. runtime: 0 
			pid 22 completed. type: 1. sleep time: 638. ready time: 157. runtime: 42 
			pid 23 completed. type: 2. sleep time: 693. ready time: 157. runtime: 73 
			pid 24 completed. type: 0. sleep time: 931. ready time: 326. runtime: 0 
			pid 25 completed. type: 1. sleep time: 1285. ready time: 155. runtime: 35 
			pid 26 completed. type: 2. sleep time: 1332. ready time: 179. runtime: 70 
			pid 27 completed. type: 0. sleep time: 1564. ready time: 314. runtime: 0 
			pid 28 completed. type: 1. sleep time: 1877. ready time: 146. runtime: 74 
			pid 29 completed. type: 2. sleep time: 1953. ready time: 176. runtime: 83 
			pid 30 completed. type: 0. sleep time: 2168. ready time: 309. runtime: 0 
			pid 31 completed. type: 1. sleep time: 2485. ready time: 155. runtime: 66 
			pid 32 completed. type: 2. sleep time: 2583. ready time: 152. runtime: 76 
			pid 33 completed. type: 0. sleep time: 2768. ready time: 304. runtime: 0 
			pid 34 completed. type: 1. sleep time: 2959. ready time: 134. runtime: 64 
			pid 35 completed. type: 2. sleep time: 3036. ready time: 127. runtime: 2 
			Stats for CPU-boud processes:
			Average time spent sleeping: 1547
			Average time spent ready: 311
			Average time spent running: 0
			Stats for short-task based CPU-bound processes:
			Average time spent sleeping: 1848
			Average time spent ready: 149
			Average time spent running: 56
			Stats for IO-bound processes:
			Average time spent sleeping: 1919
			Average time spent ready: 158
			Average time spent running: 60

		DML:

			$ sanity 5
			pid 4 completed. type: 1. sleep time: 149. ready time: 148. runtime: 0 
			pid 5 completed. type: 2. sleep time: 171. ready time: 0. runtime: 70 
			pid 7 completed. type: 1. sleep time: 163. ready time: 143. runtime: 0 
			pid 8 completed. type: 2. sleep time: 487. ready time: 0. runtime: 49 
			pid 11 completed. type: 2. sleep time: 502. ready time: 0. runtime: 52 
			pid 10 completed. type: 1. sleep time: 454. ready time: 153. runtime: 0 
			pid 6 completed. type: 0. sleep time: 468. ready time: 148. runtime: 0 
			pid 9 completed. type: 0. sleep time: 743. ready time: 147. runtime: 0 
			pid 12 completed. type: 0. sleep time: 459. ready time: 154. runtime: 0 
			pid 14 completed. type: 2. sleep time: 792. ready time: 2. runtime: 70 
			pid 15 completed. type: 0. sleep time: 751. ready time: 143. runtime: 0 
			pid 13 completed. type: 1. sleep time: 741. ready time: 160. runtime: 0 
			pid 17 completed. type: 2. sleep time: 1148. ready time: 0. runtime: 28 
			pid 18 completed. type: 0. sleep time: 1041. ready time: 148. runtime: 0 
			pid 16 completed. type: 1. sleep time: 1122. ready time: 152. runtime: 0 
			Stats for CPU-boud processes:
			Average time spent sleeping: 692
			Average time spent ready: 148
			Average time spent running: 0
			Stats for short-task based CPU-bound processes:
			Average time spent sleeping: 525
			Average time spent ready: 151
			Average time spent running: 0
			Stats for IO-bound processes:
			Average time spent sleeping: 620
			Average time spent ready: 0
			Average time spent running: 53
			
		SMLSanity
		
			$ SMLsanity
			Process with priority 2 exiting.
			Process with priority 2 exiting.
			Process with priority 2 exiting.
			Process with priority 1 exiting.
			Process with priority 1 exiting.
			Process with priority 1 exiting.
			Process with priority 2 exiting.
			Process with priority 2 exiting.
			Process with priority 2 exiting.
			Process with priority 2 exiting.
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


analysis:
	invalid stats for runtimes, but the amount of time sleeping is significantly higher in IO-bound tasks.
	default: tasks complete roughly in order by pid as expected. some tasks are done out-of-order likely due to IO tasks sleeping and being passed over by the scheduler
	fcfs: same as default, as expected
	sml: tasks are run in order as expected. with no preemption, even the IO tasks stay as the selected task and don't give up the cpu
	dml: order of completion varies the most, signifying all tasks share the cpu relatively equally
	smlsanity: didn't complete as expected, since there was some interleaving of priority 2 and 1 tasks