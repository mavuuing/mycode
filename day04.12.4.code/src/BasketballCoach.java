public class BasketballCoach extends Coash{
    public BasketballCoach() {
    }

    public BasketballCoach(String name, int age) {
        super(name, age);
    }

    @Override
    public void teacher() {
        System.out.println("蓝球教练在教如何打乒乓球");
    }

}
