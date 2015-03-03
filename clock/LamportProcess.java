/**
 * LamportProcess: This class is analogous to a process in a distributed computing environment.
 * 
 *
 */

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class LamportProcess implements Runnable {
	private int receiverID;
	MulticastSocket s;
	InetAddress group;
	int counter = 1;
	String processName;
	volatile int localClock = 0;
	int eventCount = -1;

	public LamportProcess(int id) {
		this.receiverID = id;
		initialize();
	}
	
	/**
	 * Initializes multicast socket for the process
	 */
	public void initialize() {
		try {
			processName = "P" + receiverID;
			group = InetAddress.getByName("239.1.2.3");
			s = new MulticastSocket(3456);
			s.joinGroup(group);
			System.out.println("Initialized - " + processName + " (clock time: " + localClock + ")");
		} catch (Exception ex) {
			ex.printStackTrace();
		} // end catch
	}// end main

	private static Message parseMessage(String message) throws InvalidMessageException {
		Message msg = new Message(message);
		return msg.parse();
	}

	/**
	 * This is where the local event, send-receive events - calculate their clock time
	 * This is where IR1, IR2 applied to calculate the clock time in each process
	 */
	@Override
	public void run() {
		try {
			while(true) {
				byte[] buf = new byte[100];
				DatagramPacket recv = new DatagramPacket(buf, buf.length);
				s.receive(recv);
				String rawMessage = new String(buf);
				Message msg = parseMessage(rawMessage);
				
				if(msg.getMessage().equalsIgnoreCase("STOP")) {
					System.out.println("------ END of " + processName + " (clock time: "+ localClock + ") ------" );
					break;
				}

				int incomingMessage = Integer.parseInt(msg.getMessage());
				if(eventCount < incomingMessage) {				
					eventCount = incomingMessage;
					if(msg.getTo().equals(msg.getFrom()) && (receiverID == (Integer.parseInt(msg.getTo())))) {
						localClock += 1; //IR1
						System.out.println("Local event at <P" + msg.getTo() + ">, clock time: " + localClock);
					}
					
					else if(receiverID == (Integer.parseInt(msg.getTo()))) {
						localClock = Math.max(localClock, msg.getSenderClockTime()); //IR2
						localClock += 1; //IR1
						System.out.println("From: P" + msg.getFrom() + "(" + msg.getSenderClockTime() + "), To: P" + msg.getTo() + "(" + localClock + "), Message: <" + msg.getMessage().trim() + ">.");
					}
				}
			}
		} catch (Exception ex) {
			
		} finally {
			if(null != s && !s.isClosed())
				s.close();
		}
		
	}

	/**
	 * 
	 * @return local clock time
	 */
	public int getLocalClock() {
		return localClock;
	}

	/**
	 * 
	 * @return increments local clock, returns the local clock
	 */
	public int incrementClock() {
		localClock+=1;
		return localClock;
	}
} // end class