package blatt1;

Class Fehlersuche {						// lexikalisch - class must be lower case
	int final Variable; 				// statisch - no final because of reassignment below 
										// dynamisch - Variable need to be static for use in main method
										// syntax - final keyword has to be before type declaration - final int Variable
	void* 1teMethode(int i) { 			// lexikalisch - void without *  
										// lexikalisch - function names could not start with a number
		System.out.println(i);
		return;
	}
	
	public static void main(String arg[]) {
		if(len(arg) > 0) Variable = 7 	// statisch - len is not defined for argument String[]
										// Reassignment to constants
										// Use of non static variable in static context
										// Syntax - missing ; 
		for(j = 1; j < Variable; i++) {	// statisch - i is not defined in this scope
										// syntax - j needs to be initialized with a type 
			do {
				j++;
			} while(1)					// Syntax - missing ; 
										// statisch - while expects boolean as argument got number
		}
	}
}
