import java.io.*;
import java.util.*;
public class ReadFile{

public static void main(String args[]) throws IOException {
try {
	if(args.length == 0){
	System.out.println("Proper way of executing program \n1)Give path of input file as first argument ");
	return;
	}
	String filename = args[0].toString();
	File input = new File(filename);
	RandomAccessFile i = new RandomAccessFile(input, "r");
	int in;
	int in1[] = new int[22];
	int p =0;
	do
	{
	in = i.read();
	if(in == 32 || in == 10)
	{
		continue;
	}
	in1[p] = Character.getNumericValue(in);
	System.out.println(in1[p]);
	p++;
	}while(in != -1);

}
catch (Exception e) {
// TODO Auto-generated catch block
	e.printStackTrace();
}
}
}
