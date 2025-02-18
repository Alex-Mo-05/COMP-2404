import java.util.Scanner;
public class TaxProgram {
    public static void main(String args[]) {
        double income, fedTax, provTax;
        int dependents;

        Scanner input = new Scanner(System.in);
        System.out.print("Please enter your taxable income: ");
        income = input.nextDouble();
        System.out.println();
        System.out.print("Please enter your number of dependents: ");
        dependents = input.nextInt();
        System.out.println();
        fedTax = 0.0;
        provTax = 0.0;

        if (income <= 29590){
            fedTax = income * 0.17;
        }
        else if (income < 59180){
            fedTax = 29590 * 0.17 + (income-29590) * 0.26;
        }
        else {
            fedTax = 29590 * 0.17 + (29590) * 0.26 + (income-59180) * 0.29;
        }

        double base = fedTax * .425;
        double deductions = 160.5 + 328 * dependents;
        if (base <= deductions){
            provTax = 0;
        }
        else {
            provTax =  base - deductions;
        }
        System.out.println("Here is your tax breakdown: \n");
        String variable = String.format("$%,.2f", income);
        System.out.println(String.format("%-14s%14s", "Income", variable));
        System.out.println(String.format("Dependants%18d", dependents));
        System.out.println("----------------------------");
        variable = String.format("$%,.2f", fedTax);
        System.out.println(String.format("%-14s%14s", "Federal Tax", variable));
        variable = String.format("$%,.2f", provTax);
        System.out.println(String.format("%-14s%14s", "Provincial Tax", variable));
        System.out.println("============================");
        variable = String.format("$%,.2f", fedTax + provTax);
        System.out.print(String.format("%-14s%14s", "Provincial Tax", variable));


    }
}