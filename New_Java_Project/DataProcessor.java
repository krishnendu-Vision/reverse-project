public interface DataProcessor {
    String processName(String receivedName);
    int processAge(int receivedAge);
    double processHeight(double receivedHeight);
    long processPin(long receivedPin);
}
