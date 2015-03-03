/**
 * Message: The message entity.
 * 
 *
 */

public class Message {
	private String rawMessage;
	private String from;
	private String to;
	private int senderClockTime;
	private String message;

	public Message(String rawMessage) {
		this.rawMessage = rawMessage;
	}
	
	public Message parse() throws InvalidMessageException {
		if(null == rawMessage) {
			throw new InvalidMessageException("Message is null or empty.");
		}
		
		String[] parts = rawMessage.split("-");
		setFrom(parts[0]);
		setTo(parts[1]);
		setSenderClockTime(Integer.parseInt(parts[2]));
		setMessage(parts[3].trim());
		
		return this;
	}

	public String getFrom() {
		return from;
	}

	public void setFrom(String from) {
		this.from = from;
	}

	public String getTo() {
		return to;
	}

	public void setTo(String to) {
		this.to = to;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public int getSenderClockTime() {
		return senderClockTime;
	}

	public void setSenderClockTime(int senderClockTime) {
		this.senderClockTime = senderClockTime;
	}
}
