public class PingpongSporter extends Sporter implements English {
    public PingpongSporter() {
    }

    public PingpongSporter(String name, int age) {
        super(name, age);
    }

    @Override
    public void study() {
        System.out.println("乒乓球运动员学习如何打乒乓球");
    }

    @Override
    public void speakEnglish() {
        System.out.println("乒乓球运动员学习说英语");

    }
}
