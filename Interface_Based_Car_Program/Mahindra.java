public class Mahindra implements Car {
  private int keyCode;
  private boolean isEngineStarted;
  protected byte lessEqual = 0;
  protected int greaterThanEqual = 50000;
  protected int lessThanEqual = 99999;

  public Mahindra(int keyCode) {
    if (keyCode<=lessEqual) return;
    if (keyCode>=greaterThanEqual && keyCode<=lessThanEqual) {
      if (keyCode==78650) {
        this.keyCode=keyCode;
        this.isEngineStarted=true;
      }
      else {
        this.isEngineStarted=false;
        System.out.println("Key code not matched!");
        return;
      }
    }
    else {
      System.out.println("keyCode must be within, 50000 to 99999");
    }
  }

  @Override
  public void engine() {
    if (this.isEngineStarted) {
      System.out.println("Mahindra car engine started!");
    }
    else {
      System.out.println("Engine not started!");
    }
  }

  @Override
  public void brake() {
    if(this.isEngineStarted) {
    System.out.println("Break is applied!");
    }
    else {
      System.out.println("Car is already stopped!");
    }
  }
  
  @Override
  public void steering() {
    System.out.println("Car steering working well!");
  }

  @Override
  public void fuel() {
    System.out.println("Fuel is full!");
  }

  @Override
  public void exit() {
    System.out.println("Dashboard system exiting!");
    this.isEngineStarted=false;
  }
}
