public class test3 {

    static Integer a = 10;
    static Integer b = 15;

    public static void main(String args[]) {
        //Integer a = 10;
        //Integer b = 15;
        swapf(a, b);
        System.out.println(a);
        System.out.println(b);
    }

    public static void swapf(Integer a, Integer b) {
        Integer temp = a;
        a = b;
        b = a;
    }

}
