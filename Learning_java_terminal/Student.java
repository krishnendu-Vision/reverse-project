class Info {
    String name;
    int roll;

    //Constructor.
    Info(String name, int roll) {
        this.name=name;
        this.roll=roll;
    }

    @Override
    public String toString() {
        return "Student name: " + name + ",\nStudent roll: " + roll;
    }
}

public class Student {
    public static void main(String[] args) {
        Info show = new Info("Krishnendu", 1);
        System.out.println(show);
    }
}
