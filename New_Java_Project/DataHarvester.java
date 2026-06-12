class DataDealer implements DataProcessor {
    @Override
    public String processName(String receivedName) {
        if (receivedName == null && receivedName.length() < 4) return "****";
        int length = receivedName.length();
        String firstSegment = receivedName.substring(0, 3);
        String endSegment = receivedName.substring(length -3, length);
        String middleSegment = "*".repeat(length -6);
        return firstSegment + middleSegment + endSegment;
    }
    public int processAge(int receivedAge) {
        return receivedAge;
    }
    public double processHeight(double receivedHeight) {
        return receivedHeight;
    }
    public long processPin(long receivedPin) {
        return receivedPin;
    }
}
public class DataHarvester {
    public static void main(String[] args) {
        DataProcessor processData;
        processData = new DataDealer();
        String finalData = processData.processName("SecretData");
        System.out.println(finalData);
        //processData.processPin(77274332);
        //processData.processHeight(5.11);
        //processData.processAge(24);
    }
}
