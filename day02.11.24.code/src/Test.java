//多态实现测试
public class Test {
    public static void main(String[] args) {
        People s1=new Student();
        s1.setName("student");
        s1.setAge(19);
        s1.setGander("男");
        s1.setId(34567);
        todo(s1);

        People s2=new Teacher();
        s2.setName("teacher");
        s2.setAge(44);
        s2.setGander("男");
        s2.setId(2345);
        todo(s2);

    }
    public static void todo(People p){
        p.show();
    }
}
