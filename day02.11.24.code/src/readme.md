* java 基础语法

  - == 和 equals 的区别:
     - == 比较的是变量(栈)内存中存放的对象的(堆)内存地址，(用来判断两个对象的地址是否相同)，即是否是指相同一个对象。比较的是真正意义上的指针操作。
     - (equals 用来比较的是两个对象的内容是否相等)，由于所有的类都是继承自 java.lang.Object 类的，所以适用于所有对象，如果没有对该方法进行覆盖的话，调用的仍然是 Object 类中的方法，而 Object 中的 equals 方法返回的却是 == 的判断。
    
  - java 异常处理>抛出异常
     - throws （可以单独使用）关键字通常被应用在声明方法时，用来指定可能抛出的异常。多个异常可以使用逗号分隔。
         - 用法： 方法声明[throws<异常类型>{方法1实现... }<异常类型>{方法2实现... }<异常类型>{方法3实现... }...]
     - throw  （要么和try-catch或者和throws一起用）关键字出现在方法体中，用于抛出一个具体的异常对象。
         - 用法： if(异常条件) { throw<异常对象>; }或者try{...}catch(异常类型<异常对象>){...}
     - 注意：
         - throw 语句抛出的是异常对象，而 throws 语句抛出的是异常类型。
         - throw 语句只能在方法体内使用，而 throws 语句可以在方法体内也可以在方法体外使用。

  - java 异常处理>自定义异常类
    class MyException1 extends Exception {
    double num;
    MyException1(double a) {  num = a  ; }
    public String toString() {   return num+"<0! 值必须大于0";    }
    }
    class MyException2 extends Exception {
    double num;
    MyException2(double a) {   num = a;   }
    public String toString() {   return num+">100!/r/n值必须小于100";    }
    }
    public class Test {      //定义一个异常处理方法checkScore
    static void checkScore(double a) throws MyException1,MyException2 {
    if(a<0)
    throw new MyException1(a);  //抛出异常后就会跳出方法体
    if(a>100)
    throw new MyException2(a);
    System.out.println("数据符合要求");
    }

  - java 类的定义与使用
    - 构造方法：每个类至少有一个构造方法，如果没有编写构造方法，编译器会自动添加一个无参数的构造方法。
      - eg: Frind f=new Frind(); 对象f就是由Frind类构造出来的。
    - 类的访问控制：
      - public 类：可以在任何一个包中任何一个人类中被访问和继承。
      - private 类：只能在本类中被访问和继承。
      - default 类：只能在本包中被访问和继承。
      - protected 类：只能在本包中被访问和继承，也可以在不同包的子类中被访问和继承。
    - 类的继承：
      - 关键字extends。
        - eg: class A extends B{}  类A继承了类B的所有属性和方法。
      - 子类除了继承父类的属性和方法外，还可以添加自己的属性和方法。
      - 子类可以重写父类的方法。不继承构造方法。
      - Java 不支持多重继承，一个类只能继承一个父类。但是可以实现多个接口。
      - 方法覆盖：
        - 子类方法的名称和父类方法的名称必须相同。
        - 子类方法不能缩小比父类方法的访问权限。
        - 子类方法不能抛出比父类方法更多的异常。
      - 关键字super:
        - 在子类中使用super关键字来调用父类的构造方法。
          - eg: super();  调用父类的构造方法。
          - eg: super(参数列表);  调用父类的构造方法。
          - eg: super.方法名;  调用父类的方法。
          - eg: super.属性名;  调用父类的属性。
        
    - 类的多态：
      - 多态是同一个行为具有多个不同表现形式或形态的能力。
      - 多态的实现方式：
        - 继承：子类继承父类的方法。
          - eg: class A extends B{}  类A继承了类B的所有属性和方法。
        - 接口：实现接口的类。
        - 抽象类：实现抽象类的子类。
    - 类的封装：其实就是将类的属性和方法封装起来，不允许外部直接访问。
      - 关键字private。
      - 关键字protected。
      - 关键字public。
    
    - 类的抽象：有抽象方法得就是抽象类
      - 抽象类：
        - 抽象类不能被实例化。
          - 解释：抽象类不能被实例化，但可以被声明，因为抽象类中可能包含抽象方法，抽象方法没有方法体，所以不能被实例化。
          - 什么是实例化？
            - 实例化就是创建对象。
          - 什么是声明？
            - 声明就是告诉编译器，这个类的存在。
            - 声明eg：Frind f=new Frind(); new Frind()就是实例对象，Frind f就是声明。
        - 抽象类可以包含抽象方法和非抽象方法。
          - 抽象方法：
            - 抽象方法只有方法头，没有方法体。
            - 抽象方法必须在抽象类中。
            - 抽象方法必须在子类中被实现。
            - 抽象方法不能被final和static修饰。
            - 抽象方法不能被private和synchronized修饰。
            - 抽象方法不能被native和strictfp修饰。  
        - 抽象类可以包含属性、构造方法、方法。
        - 抽象类可以继承抽象类。
          - 抽象子类必须要实现抽象类中的所有抽象方法。 
        - 抽象类可以实现接口。
        - 抽象类可以继承非抽象类。
        - 抽象类可以继承抽象类。 
    - 类的接口(相关关键字interface，implements实现接口)：一个类可以实现多个接口，从而实现多继承。
      - 用法： interface 接口名 {  }     class 类名 implements 接口名 {  }
      - 定义：如果一个抽象类中所有方法都是抽象的，那么这个抽象类就可以被称为接口。 
    - 何时用抽象类or接口？
      - 看动机：
        - 需要有代码复用，用抽象类。
        - 当你关注一个操作的时候，用接口。
    - 类的实现：方法需要重写
   