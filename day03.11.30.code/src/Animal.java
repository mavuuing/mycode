public class Animal {
    private int age;
    private String color;
    public Animal(int age,String color){
        this.age=age;
        this.color=color;

    }
    public void eat( String something){
        System.out.println("动物在吃"+something);
    }

    public int getAge() {
        return age;
    }

    public String getColor() {
        return color;
    }
}
