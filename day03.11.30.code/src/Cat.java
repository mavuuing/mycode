public class Cat extends Animal {
    public Cat(int age, String color) {
        super(age, color);
    }
    public void eat( String something){
        System.out.println(getAge()+"岁的"+getColor()+"颜色的猫眯着眼睛侧着头吃"+something);
    }
    public void behavier(){
        System.out.println("猫抓老鼠");
    }

}
