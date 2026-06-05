import java.util.Scanner;

interface Operation {
    double calculate(double num1, double num2);
}

class Addition implements Operation {
    @Override
    public double calculate(double num1, double num2) {
        return num1 + num2;
    }
}

class Subtraction implements Operation {
    @Override
    public double calculate(double num1, double num2) {
        return num1 - num2;
    }
}

class Multiplication implements Operation {
    @Override
    public double calculate(double num1, double num2) {
        return num1 * num2;
    }
}

class Division implements Operation {
    @Override
    public double calculate(double num1, double num2) {
        return num1 / num2;
    }
}

public class CalcInterface {
    public static void main(String[] args) {
        boolean running = true;
        Scanner scanner = new Scanner(System.in);
        while (running) {
        try {
        System.out.println("1, For addition.\n2, For Subtraction.\n3, For Multiplication.\n4, for Division.\n5, For exit.");
        System.out.print("Choose option: ");
        int option = Integer.parseInt(scanner.nextLine());
      
        if (option == 5) {
              running=false;
              continue;
        }       

        Operation op = null;

        op = switch (option) {
            case 1 -> new Addition();
            case 2 -> new Subtraction();
            case 3 -> new Multiplication();
            case 4 -> new Division();
            default -> null;
        };

        if (op != null) {
            System.out.print("Enter first number: ");
            double a = Double.parseDouble(scanner.nextLine());
            System.out.print("Enter second number: ");
            double b = Double.parseDouble(scanner.nextLine());

            double result = op.calculate(a, b);
            System.out.println("\nResult: " + result + "\n");
        }          

        } catch(NumberFormatException e) {
            System.err.println("\nPlease enter value only!\n");
        }
        }
        System.out.println("\nThank you for using calculator!\n");
        scanner.close();
    }
}
