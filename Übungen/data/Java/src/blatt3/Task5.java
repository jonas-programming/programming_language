package blatt3;

import java.util.ArrayList;

public class Task5 {

	public static void main(String[] args) {
		if(args.length > 0) {
			String input = args[0];
			ArrayList<Character> stack = new ArrayList<Character>();
			for (int i = 0; i < input.length(); i++) {
				char cur = input.charAt(i);
				char top = (stack.size() > 0)?stack.get(stack.size() -1): '0';
				if (cur == '(' || cur == '[' || cur == '{' || cur == '<') {
					stack.add(cur);
				}else if ((cur == '}' && top == '{') || (cur == ')' && top == '(') || (cur == ']' && top == '[') || (cur == '>' && top == '<')) {
					stack.remove(stack.size() - 1);
				}else {
					stack.add('0');
					break;
				}
			}
			System.out.println((stack.size() == 0)? true: false);
		} else {
			System.out.println("No argument given");
		}

	}

}
