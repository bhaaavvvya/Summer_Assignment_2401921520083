public class Main 
{
    public static void main(String[] args) 
    {
        Outer x = new Outer();
        x.display();

        Outer.Inner y = x.new Inner();
        y.display();
    }
}
