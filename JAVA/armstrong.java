//An Armstrong number is a positive m-digit number that is equal to the sum of the mth powers of their digits. 
//It is also known as pluperfect, or Plus Perfect, or Narcissistic number.
import java.util.Scanner;

public class armstrong {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int number = in.nextInt(), Inputfromuser, rem, result = 0, n = 0;
        Inputfromuser = number;
        for (;Inputfromuser != 0; Inputfromuser /= 10)
        {
            n++;
        }
        Inputfromuser = number;
        for (;Inputfromuser != 0; Inputfromuser /= 10)
        {
            rem = Inputfromuser % 10;
            result += Math.pow(rem, n);
        }
        if(result == number)
            System.out.println(number + " is an Armstrong number.");
        else
            System.out.println(number + " is not an Armstrong number.");
    }
}
