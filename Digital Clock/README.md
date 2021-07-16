The Digital Clock is a DLD (Digital Logical Design) based project developed on MS14 software. This project is a software-based demonstration of a Digital Clock that acts as a clock and acts as a stopwatch when turned on. 

DESCRIPTION:
The entire project of the digital clock can be divided into three major sections:
1.	The second section (0-59)
2.	Minute section (00:00-59:59)
3.	Hours section (00:00:00-23:59:59)
Second Section:
In the first section, we use two counters ICs (7490) so that this site generates the output from 00-59 with the frequency of 1Hz. Then with the help of the next IC’s, IC (7447) and seven-segment, it displays the count, and both of these IC’s are common anode types. When all these necessary connections are made, we check the output of the circuit.
Minute Section:
In the Minute section, we repeat the same circuit of the second section, but the output is from 00-59 with a frequency of 1Hz. Once the necessary connections are made, we check the outputs.
Hour Section:
Now in this section, we design the circuit so that after a specific time interval, i.e. 23:59:59, it automatically sets the circuit to 00, indicating hours. Here the frequency is one pulse in 1 hour, and again after making necessary connections, we check the output.
Once all these three sections are done, we assemble and combine the sections in a common circuit and check the output of the final circuit, and it should be our desired output. 

