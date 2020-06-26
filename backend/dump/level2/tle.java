// Java program to demonstrate 
// sleep() method of TimeUnit Class 

import java.util.concurrent.*; 

class GFG { 
	public static void main(String args[]) 
	{ 
		// Get time to sleep 
		long timeToSleep = 100L; 

		// Create a TimeUnit object 
		TimeUnit time = TimeUnit.SECONDS; 

		try { 

			System.out.println("Going to sleep for "
							+ timeToSleep 
							+ " seconds"); 

			// using sleep() method 
			time.sleep(timeToSleep); 

			System.out.println("Slept for "
							+ timeToSleep 
							+ " seconds"); 
		} 

		catch (InterruptedException e) { 
			System.out.println("Interrupted "
							+ "while Sleeping"); 
		} 
	} 
} 
