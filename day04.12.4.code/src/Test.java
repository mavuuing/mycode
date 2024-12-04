public class Test {
    public static void main(String[] args) {
        PingpongSporter pps=new PingpongSporter("刘诗雯",23);
        System.out.println(pps.getName()+","+pps.getAge());
        pps.study();
        pps.speakEnglish();

        PingpongCoach ppc=new PingpongCoach("刘文",44);
        System.out.println(ppc.getName()+","+ppc.getAge());
        ppc.speakEnglish();
        ppc.teacher();

        BasketballCoach bbc=new BasketballCoach("问问",89);
        System.out.println(bbc.getName()+","+bbc.getAge());
        bbc.teacher();


    }
}
