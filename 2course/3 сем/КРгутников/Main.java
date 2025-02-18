package pack;

import java.util.Scanner;

public class Main {
	public static void main(String [] args)
	{
		System.out.println("¬ведите данные входного потока:");
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine())
		{
			String s = in.nextLine();
			String str = EditingStr(s);
			System.out.println(str);
		}
		in.close();
		System.exit(0);
	}
	
	static String EditingStr(String s)
	{
		StringBuffer s_buffer = new StringBuffer(s.subSequence(0, s.length()));
		int length = s_buffer.length();
		int i = 0;
		int counter_zeros = 0;
		int left_zero = 0;
		while (i != length - 1)
		{
			char symbol = s_buffer.charAt(i);
			if (symbol == ' ')
			{
				if (counter_zeros == 0)
					left_zero = i;
				counter_zeros++;
				i++;
				continue;
			}
			if (counter_zeros == 1)
				counter_zeros = 0;
			if (counter_zeros >= 2)
			{
				s_buffer.replace(left_zero, i, " ");
				length -= i - left_zero;
				length++;
				i -= counter_zeros + 1;
				counter_zeros = 0;
				continue;
			}

			if (symbol == '\\')
			{
				i++;
				symbol = s_buffer.charAt(i);
				if (symbol == 't')
				{
					s_buffer.replace(i - 1, i, "  ");
					i++;
					continue;
				}
				else
				{
					i++;
					continue;
				}
			}
			i++;
		}
		s = s_buffer.toString();
		return s;
	}

}


