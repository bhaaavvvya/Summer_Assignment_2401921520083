public class Box 
{
    protected int l;
    protected int b;

    Box()
    {
        l = 0;
        b = 0;
    }

    Box(int x, int y)
    {
        l = x;
        b = y;
    }

    void printArea()
    {
        System.out.println("Area: " + (l * b));
    }
}
