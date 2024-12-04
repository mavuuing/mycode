import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

import static java.lang.Math.random;

public class dome01 {
    private int  a;
    private int b;
    private int c;
    public dome01(int a) {
        this.a = a;
    }

    public dome01() {
    }


    public static void main(String[] args) {
    //开平方根函数
//        int n;
//        int i;
//        Scanner sc=new Scanner(System.in);
//        n=sc.nextInt();//如果是sc.nextLine()则是字符串类型
//        for ( i = 2; i < Math.sqrt(n); i++) {
//            if(n%i==0){
//                System.out.println(n+"不是素数");
//                break;
//            }
//
//        } System.out.println(i+"是素数");

//        Random random=new Random();
//        int num=random.nextInt(100);
//        System.out.println(num);
        Date dt = new Date();  //创建表示当前日期与时间等信息的对象
        System.out.println(dt);
        //创建格式化日期与时间的对象
        SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        System.out.println(f.format(dt));  //格式化date对象

        Calendar calendar = Calendar.getInstance();  //日历类封装了较多的信息
        System.out.println(calendar);
        int temp = Calendar.YEAR;  //符号常量
        System.out.println(calendar.get(temp));  //获得年份
        System.out.println(calendar.getTime());  //获得日历对象里的日期与时间信息
        //获取时间戳的三种方法
        System.out.println(System.currentTimeMillis());
        System.out.println(Calendar.getInstance().getTimeInMillis());  //
        System.out.println(new Date().getTime());

    }



}
