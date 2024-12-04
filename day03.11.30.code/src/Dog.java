public class Dog extends Animal{
    public Dog(int age, String color) {
        super(age, color);
    }
    public void eat( String something){
        System.out.println(getAge()+"岁的"+getColor()+"颜色的狗两只前腿死死抱住"+something+"猛吃");
    }
    public void behavier(){
        System.out.println("dog看家");
    }

}
