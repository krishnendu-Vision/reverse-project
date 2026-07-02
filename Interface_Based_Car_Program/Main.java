import java.util.Scanner;

public class Main {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    boolean running = true;
    
    System.out.println("Enter secret key to start engine!");
    System.out.print("Enter key: ");
    int inputKey = Integer.parseInt(scanner.nextLine());
    Car myCar = new Mahindra(inputKey); 

    while(running) {
    System.out.println("---Mahindra Car Dashboard---");
    System.out.println("1, for engine state!");
    System.out.println("2, for break state!");
    System.out.println("3, for steering state!");
    System.out.println("4, for fuel state!");
    System.out.println("5, for exit!");

    System.out.print("Select option: ");
    String option = scanner.nextLine();

    switch(option) {
      case "1" -> myCar.engine();
      case "2" -> myCar.brake();
      case "3" -> myCar.steering();
      case "4" -> myCar.fuel();
      case "5" -> {
        myCar.exit();
        running=false;
      }
      default -> System.out.println("Please choose valid option!");
    }
    }
    scanner.close();
    }
  }
