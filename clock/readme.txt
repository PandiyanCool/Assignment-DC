Lamport Scalar Clock
====================
1. Pre-requisites:

    a. JDK is installed.

    b. Ensure command 'java', 'javac' are available in PATH.
		
		Set JAVA_HOME as follows using syntax
		
		Example: export JAVA_HOME=<path-to-jdk>
		export PATH=$JAVA_HOME/bin:$PATH


2. Run the following sequence of command to get the class files:
    javac *.java

3. Run the below command:
    java LamportScalarClock        (This runs 5 processes, with 10 events by default)
	
	java LamportScalarClock 2 8    (This runs 2 processes, with 8 events)

Sample output:
=================

pandiyan@pandiyan-VirtualBox:~/Desktop/assignment/clock/src$ javac *.java

pandiyan@pandiyan-VirtualBox:~/Desktop/assignment/clock/src$ java LamportScalarClock
Initialized - P1 (clock time: 0)
Initialized - P2 (clock time: 0)
Initialized - P3 (clock time: 0)
Initialized - P4 (clock time: 0)
Initialized - P5 (clock time: 0)
Sending message (sender-receiver-senderClock-eventCounter): 5-4-1-1
From: P5(1), To: P4(2), Message: <1>.
Sending message (sender-receiver-senderClock-eventCounter): 2-4-1-2
From: P2(1), To: P4(3), Message: <2>.
Sending message (sender-receiver-senderClock-eventCounter): 5-3-2-3
From: P5(2), To: P3(3), Message: <3>.
Sending message (sender-receiver-senderClock-eventCounter): 3-4-4-4
From: P3(4), To: P4(5), Message: <4>.
Sending message (sender-receiver-senderClock-eventCounter): 4-1-6-5
From: P4(6), To: P1(7), Message: <5>.
Sending message (sender-receiver-senderClock-eventCounter): 2-2-1-6
Local event at <P2>, clock time: 2
Sending message (sender-receiver-senderClock-eventCounter): 5-3-3-7
From: P5(3), To: P3(5), Message: <7>.
Sending message (sender-receiver-senderClock-eventCounter): 1-5-8-8
From: P1(8), To: P5(9), Message: <8>.
Sending message (sender-receiver-senderClock-eventCounter): 4-5-7-9
From: P4(7), To: P5(10), Message: <9>.
Sending message (sender-receiver-senderClock-eventCounter): 3-3-5-10
Local event at <P3>, clock time: 6
------ END of P5 (clock time: 10) ------
------ END of P1 (clock time: 8) ------
------ END of P2 (clock time: 2) ------
------ END of P3 (clock time: 6) ------
------ END of P4 (clock time: 7) ------
pandiyan@pandiyan-VirtualBox:~/Desktop/assignment/clock/src$
